/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9a_mcc_omi_scan.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
#include "p9a_mcc_omi_scan.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_8 = 8;

fapi2::ReturnCode p9a_mcc_omi_scan(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT(6);
        fapi2::variable_buffer l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE(6);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT.insertFromRight<uint64_t>(literal_8, 0, 6);
        l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE.insertFromRight<uint64_t>(0x3f, 0, 6);
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN0.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN1.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN2.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC01.CHAN3.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
                                       l_MC01_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE));
        fapi2::variable_buffer l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT(6);
        fapi2::variable_buffer l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE(6);
        l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT.insertFromRight<uint64_t>(literal_8, 0, 6);
        l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE.insertFromRight<uint64_t>(0x3f, 0, 6);
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC23.CHAN0.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                                       l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
                                       l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC23.CHAN1.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                                       l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
                                       l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC23.CHAN2.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                                       l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
                                       l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE));
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "MC23.CHAN3.ATCL.CL.CLSCOM.MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT",
                                       l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT,
                                       l_MC23_CHAN0_ATCL_CL_CLSCOM_MCPERF0_WR_RSVD_LOWER_OR_STATIC_LIMIT_CARE));

    };
fapi_try_exit:
    return fapi2::current_err;
}
