/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_dmi_erepair.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//Fapi Support
#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <util/utilmbox_scratch.H>

//HWP
#include    <p9_io_dmi_restore_erepair.H>
#include    <p9_io_cen_restore_erepair.H>
#include    <p9_io_erepairAccessorHwpFuncs.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


namespace ISTEP_12
{
void* call_dmi_erepair (void *io_pArgs)
{
    IStepError l_StepError;
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_erepair entry" );

    errlHndl_t l_errPtr = NULL;
    fapi2::ReturnCode l_rc;
    std::vector<uint8_t> l_endp1_txFaillanes;
    std::vector<uint8_t> l_endp1_rxFaillanes;
    std::vector<uint8_t> l_endp2_txFaillanes;
    std::vector<uint8_t> l_endp2_rxFaillanes;
    uint32_t l_count = 0;

    TargetHandleList           l_dmiTargetList;
    TargetHandleList           l_memTargetList;
    TargetHandleList::iterator l_mem_iter;

    // find all DMI chiplets of all procs
    getAllChiplets(l_dmiTargetList, TYPE_DMI);

    for (TargetHandleList::const_iterator
         l_dmi_iter = l_dmiTargetList.begin();
         l_dmi_iter != l_dmiTargetList.end();
         ++l_dmi_iter)
    {
        // make a local copy of the DMI target
        TARGETING::Target *l_dmi_target = *l_dmi_iter;
        ATTR_CHIP_UNIT_type l_dmiNum = l_dmi_target->getAttr<ATTR_CHIP_UNIT>();

        // find all the Centaurs that are associated with this DMI
        getChildAffinityTargets(l_memTargetList, l_dmi_target,
                       CLASS_CHIP, TYPE_MEMBUF);

        if(l_memTargetList.size() != 1)
        {
            continue;
        }

        // There will always be 1 Centaur associated with a DMI
        l_mem_iter = l_memTargetList.begin();

        // make a local copy of the MEMBUF target
        TARGETING::Target *l_mem_target = *l_mem_iter;
        ATTR_POSITION_type l_memNum = l_mem_target->getAttr<ATTR_POSITION>();

        // struct containing custom parameters that is fed to HWP
        // call the HWP with each target(if parallel, spin off a task)
        const fapi2::Target< fapi2::TARGET_TYPE_DMI >  l_fapi_endp1_target
                     (l_dmi_target);

        const fapi2::Target< fapi2::TARGET_TYPE_MEMBUF_CHIP > l_fapi_endp2_target
                      (l_mem_target);

        // Get the repair lanes from the VPD
        l_endp1_txFaillanes.clear();
        l_endp1_rxFaillanes.clear();
        l_endp2_txFaillanes.clear();
        l_endp2_rxFaillanes.clear();

        l_rc = erepairGetRestoreLanes(l_fapi_endp1_target,
                                      l_fapi_endp2_target,
                                      3, //DMI Is associated with clock group 3
                                      l_endp1_txFaillanes,
                                      l_endp1_rxFaillanes,
                                      l_endp2_txFaillanes,
                                      l_endp2_rxFaillanes);

        if(l_rc)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "Unable to"
                      " retrieve DMI eRepair data from the VPD");
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X", TARGETING::get_huid(l_mem_target));

            // Convert fapi returnCode to Error handle
            l_errPtr = rcToErrl(l_rc);

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_dmi_target).addToLog(l_errPtr);
            ErrlUserDetailsTarget(l_mem_target).addToLog(l_errPtr);

            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errPtr);

            // Commit Error
            errlCommit(l_errPtr, HWPF_COMP_ID);
            break;
        }

        if(l_endp1_txFaillanes.size() || l_endp1_rxFaillanes.size())
        {
            // call the p9_io_dmi_restore_erepair HWP to restore eRepair
            // lanes of DMI

            TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                   "p9_io_dmi_restore_erepair HWP"
                                   " ( dmi 0x%x, mem 0x%x ) : ",
                                   l_dmiNum,
                                   l_memNum );

            FAPI_INVOKE_HWP(l_errPtr,
                            p9_io_dmi_restore_erepair,
                            l_fapi_endp1_target,
                            l_endp1_rxFaillanes,
                            l_endp1_txFaillanes);
            if(l_errPtr)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                             "ERROR 0x%.8X : p9_io_dmi_restore_erepair HWP"
                             "( dmi 0x%x, mem 0x%x ) ",
                             l_errPtr->reasonCode(),
                             l_dmiNum,
                             l_memNum);

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_dmi_target).addToLog(l_errPtr);

                // Create IStep error log and cross ref error that occurred
                l_StepError.addErrorDetails( l_errPtr);

                // Commit Error
                errlCommit(l_errPtr, HWPF_COMP_ID);
                break;
            }

            for(l_count = 0; l_count < l_endp1_txFaillanes.size(); l_count++)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"Successfully"
                          " restored Tx lane %d, of DMI-Bus, of DMI",
                          l_endp1_txFaillanes[l_count]);
            }

            for(l_count = 0; l_count < l_endp1_rxFaillanes.size(); l_count++)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"Successfully"
                          " restored Rx lane %d, of DMI-Bus, of DMI",
                          l_endp1_rxFaillanes[l_count]);
            }
        } // end of if(l_endp1_txFaillanes.size() || l_endp1_rxFaillanes.size())

        if(l_endp2_txFaillanes.size() || l_endp2_rxFaillanes.size())
        {
            // call the p9_io_cen_restore_erepair HWP to restore eRepair
            // lanes of membuf

            TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                   "p9_io_cen_restore_erepair HWP"
                                   " ( dmi 0x%x, mem 0x%x ) : ",
                                   l_dmiNum,
                                   l_memNum );
            FAPI_INVOKE_HWP(l_errPtr,
                            p9_io_cen_restore_erepair,
                            l_fapi_endp2_target,
                            l_endp2_rxFaillanes,
                            l_endp2_txFaillanes);
            if (l_errPtr)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                             "ERROR 0x%.8X : p9_io_cen_restore_erepair HWP"
                              "( dmi 0x%x, mem 0x%x ) ",
                              l_errPtr->reasonCode(),
                              l_dmiNum,
                              l_memNum);

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_mem_target).addToLog(l_errPtr);

                // Create IStep error log and cross ref error that occurred
                l_StepError.addErrorDetails( l_errPtr);

                // Commit Error
                errlCommit(l_errPtr, HWPF_COMP_ID);
                break;
            }

            for(l_count = 0; l_count < l_endp2_txFaillanes.size(); l_count++)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"Successfully"
                          " restored Tx lane %d, of DMI-Bus, of membuf",
                          l_endp2_txFaillanes[l_count]);
            }

            for(l_count = 0; l_count < l_endp2_rxFaillanes.size(); l_count++)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"Successfully"
                          " restored Rx lane %d, of DMI-Bus, of membuf",
                          l_endp2_rxFaillanes[l_count]);
            }
        } // end of if(l_endp2_txFaillanes.size() || l_endp2_rxFaillanes.size())
    } // end for l_dmi_target


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_erepair exit" );


    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
