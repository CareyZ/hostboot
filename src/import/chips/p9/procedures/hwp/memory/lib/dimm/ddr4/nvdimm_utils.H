/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/nvdimm_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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

///
/// @file nvdimm_utils.H
/// @brief Subroutines to support nvdimm backup/restore process
///
// *HWP HWP Owner: Tsung Yeung <tyeung@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/shared/mss_const.H>
#include <lib/ccs/ccs.H>

namespace mss
{

namespace nvdimm
{

///
/// @brief Wrapper to read MAINT_ADDR_MODE_EN
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @param[out] o_state MAINT_ADDR_MODE_EN state
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode get_maint_addr_mode_en( const fapi2::Target<T>& i_target,
        mss::states& o_state );

///
/// @brief change maintenance address mode
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @param[in] i_state the state to change to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode change_maint_addr_mode_en( const fapi2::Target<T>& i_target,
        const mss::states i_state );

///
/// @brief change ECC check and correct mode
/// Specialization for TARGET_TYPE_MCA
/// @param[in] i_target the target associated with this subroutine
/// @param[in] i_state the state to change to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode change_ecc_check_correct_disable( const fapi2::Target<T>& i_target,
        const mss::states i_state );

///
/// @brief cleanup after targeted scrub
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode targeted_scrub_cleanup( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Helper for self_refresh_exit().
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
/// @note Uses memdiag to read the port to force CKE back to high.
/// Stolen from mss_lab_memdiags.C
///
template< fapi2::TargetType T >
fapi2::ReturnCode self_refresh_exit_helper( const fapi2::Target<T>& i_target );

///
/// @brief Disable refresh and put target into self-refresh
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode self_refresh_entry( const fapi2::Target<T>& i_target );

///
/// @brief Take the target out of self-refresh and restart refresh
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode self_refresh_exit( const fapi2::Target<T>& i_target );

///
/// @brief Latch write vref at per-dram basis
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///

template< fapi2::TargetType T >
fapi2::ReturnCode pda_vref_latch( const fapi2::Target<T>& i_target );

///
/// @brief Disable powerdown mode in rc09
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode rc09_disable_powerdown( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst);

///
/// @brief Load the rcd control words
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @Note This is similar to rcd_load_ddr4() but with minor changes to support
///       with NVDIMMs
///
fapi2::ReturnCode rcd_load_nvdimm( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& io_inst);

///
/// @brief Restore the rcd after restoring the nvdimm data
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_MCA>
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @Note Restoring the RCD after NVDIMM restore requires a special procedure
///       The procedure from draminit would actually fail to restore the CWs
///
fapi2::ReturnCode rcd_restore( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Execute post restore ZQCAL
/// @param[in] i_target the target associated with this cal
/// @return FAPI2_RC_SUCCESS iff setup was successful
/// @Note The original zqcal has delay that violates the refresh interval.
///       Since we now have data in the DRAMs, the command will be executed
///       with delay following the spec.
///
fapi2::ReturnCode post_restore_zqcal( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

///
/// @brief Full post-restore transition for NVDIMM
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode post_restore_transition( const fapi2::Target<T>& i_target );

}//ns nvdimm

}//ns mss
