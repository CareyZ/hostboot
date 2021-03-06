/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/eff_config/explorer_attr_engine_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file explorer_attr_engine_traits.H
/// @brief Trait class definitions for explorer attrs
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:CI

#ifndef _MSS_EXPLORER_ATTR_ENGINE_TRAITS_H_
#define _MSS_EXPLORER_ATTR_ENGINE_TRAITS_H_

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <generic/memory/lib/data_engine/data_engine.H>
#include <generic/memory/lib/spd/spd_facade.H>
#include <lib/mss_explorer_attribute_getters.H>
#include <lib/mss_explorer_attribute_setters.H>

namespace mss
{

///
/// @brief Forward declartion of traits for setTimingTraits
/// @class setTimingTraits
/// @note attr_eff_engine_fields, SPD_TAA_MIN
///
template< >
struct setTimingTraits< exp::attr_eff_engine_fields, exp::SPD_TAA_MIN >
{
    static constexpr const char* TIMING_NAME = "tAAmin";

    static spd_facade_fptr get_timing_in_mtb;
    static spd_facade_fptr get_timing_in_ftb;
};

///
/// @brief Alias for function pointer to spd_facade timing methods for SPD_TAA_MIN
///
spd_facade_fptr setTimingTraits<exp::attr_eff_engine_fields,
                exp::SPD_TAA_MIN>::get_timing_in_mtb = &spd::facade::min_taa;

///
/// @brief Alias for function pointer to spd_facade timing methods for SPD_TAA_MIN
///
spd_facade_fptr setTimingTraits<exp::attr_eff_engine_fields,
                exp::SPD_TAA_MIN>::get_timing_in_ftb =  &spd::facade::fine_offset_min_taa;

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_eff_engine_fields, ATTR_EFF_BASE_CASE specialization
/// NOP for base case needed to trigger partial specialization of attr_engine
///
template<>
struct attrEngineTraits<exp::attr_eff_engine_fields, exp::ATTR_EFF_BASE_CASE> {};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_eff_engine_fields, BYTE_ENABLES specialization
///
template<>
struct attrEngineTraits<exp::attr_eff_engine_fields, exp::BYTE_ENABLES>
{
    using attr_type = fapi2::ATTR_MEM_EFF_BYTE_ENABLES_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_BYTE_ENABLES_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_BYTE_ENABLES;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_byte_enables(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return attr::set_byte_enables(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return i_spd_data.byte_enables(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_eff_engine_fields, NIBBLE_ENABLES specialization
///
template<>
struct attrEngineTraits<exp::attr_eff_engine_fields, exp::NIBBLE_ENABLES>
{
    using attr_type = fapi2::ATTR_MEM_EFF_NIBBLE_ENABLES_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_NIBBLE_ENABLES_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_NIBBLE_ENABLES;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_nibble_enables(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return attr::set_nibble_enables(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return i_spd_data.nibble_enables(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_eff_engine_fields, SPD_TAA_MIN specialization
///
template<>
struct attrEngineTraits<exp::attr_eff_engine_fields, exp::SPD_TAA_MIN>
{
    using attr_type = fapi2::ATTR_MEM_EXP_SPD_TAA_MIN_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EXP_SPD_TAA_MIN_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_TAA_MIN;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_exp_spd_taa_min(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return attr::set_exp_spd_taa_min(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return  mss::calc_spd_time_in_ps<exp::attr_eff_engine_fields, exp::SPD_TAA_MIN>(i_spd_data, o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_eff_engine_fields, FOUR_RANK_MODE specialization
///
template<>
struct attrEngineTraits<exp::attr_eff_engine_fields, exp::FOUR_RANK_MODE>
{
    using attr_type = fapi2::ATTR_MEM_EFF_FOUR_RANK_MODE_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_FOUR_RANK_MODE_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_FOUR_RANK_MODE;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_four_rank_mode(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return attr::set_four_rank_mode(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        constexpr auto FOUR_RANK_MODE_BIT = 7; // From SPEC
        uint8_t l_spd_four_rank_mode = 0;
        FAPI_TRY(i_spd_data.compatabilty_modes(l_spd_four_rank_mode));

        o_setting = fapi2::buffer<uint8_t>(l_spd_four_rank_mode).getBit<FOUR_RANK_MODE_BIT>();

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_eff_engine_fields, DDP_COMPATIBILITY specialization
///
template<>
struct attrEngineTraits<exp::attr_eff_engine_fields, exp::DDP_COMPATIBILITY>
{
    using attr_type = fapi2::ATTR_MEM_EFF_DDP_COMPATIBILITY_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_DDP_COMPATIBILITY_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_DDP_COMPATIBILITY;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_ddp_compatibility(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return attr::set_ddp_compatibility(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        constexpr auto DDP_COMPATIBILITY_BIT = 6; // From SPEC
        uint8_t l_spd_ddp_compatibility = 0;
        FAPI_TRY(i_spd_data.compatabilty_modes(l_spd_ddp_compatibility));

        o_setting = fapi2::buffer<uint8_t>(l_spd_ddp_compatibility).getBit<DDP_COMPATIBILITY_BIT>();

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_eff_engine_fields, TSV_8H_SUPPORT specialization
///
template<>
struct attrEngineTraits<exp::attr_eff_engine_fields, exp::TSV_8H_SUPPORT>
{
    using attr_type = fapi2::ATTR_MEM_EFF_TSV_8H_SUPPORT_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_TSV_8H_SUPPORT_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_TSV_8H_SUPPORT;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_tsv_8h_support(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return attr::set_tsv_8h_support(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return i_spd_data.compatabilty_modes(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_eff_engine_fields, PSTATES specialization
///
template<>
struct attrEngineTraits<exp::attr_eff_engine_fields, exp::PSTATES>
{
    using attr_type = fapi2::ATTR_MEM_EFF_PSTATES_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_PSTATES_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_PSTATES;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_pstates(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return attr::set_pstates(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        return i_spd_data.num_p_states(o_setting);
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_eff_engine_fields, MRAM_SUPPORT specialization
///
template<>
struct attrEngineTraits<exp::attr_eff_engine_fields, exp::MRAM_SUPPORT>
{
    using attr_type = fapi2::ATTR_MEM_EFF_MRAM_SUPPORT_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EFF_MRAM_SUPPORT_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_MRAM_SUPPORT;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_mram_support(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return attr::set_mram_support(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        constexpr auto MRAM_SUPPORT_BIT = 4; // From SPEC
        uint8_t l_spd_ddp_compatibility = 0;
        FAPI_TRY(i_spd_data.compatabilty_modes(l_spd_ddp_compatibility));

        o_setting = fapi2::buffer<uint8_t>(l_spd_ddp_compatibility).getBit<MRAM_SUPPORT_BIT>();

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_eff_engine_fields, HEIGHT_3DS specialization
///
template<>
struct attrEngineTraits<exp::attr_eff_engine_fields, exp::HEIGHT_3DS>
{
    using attr_type = fapi2::ATTR_MEM_EXP_3DS_HEIGHT_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EXP_3DS_HEIGHT_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_3DS_HEIGHT;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_exp_3ds_height(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return attr::set_exp_3ds_height(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {

        return fapi2::FAPI2_RC_SUCCESS;
    }
};

///
/// @brief Traits for attr_engine
/// @class attrEngineTraits
/// @note attr_eff_engine_fields, SPD_CL_SUPPORTED specialization
///
template<>
struct attrEngineTraits<exp::attr_eff_engine_fields, exp::SPD_CL_SUPPORTED>
{
    using attr_type = fapi2::ATTR_MEM_EXP_SPD_CL_SUPPORTED_Type;
    using attr_integral_type = std::remove_all_extents<attr_type>::type;
    static constexpr fapi2::TargetType TARGET_TYPE = fapi2::ATTR_MEM_EXP_SPD_CL_SUPPORTED_TargetType;
    static constexpr exp::ffdc_codes FFDC_CODE = exp::SET_SPD_CL_SUPPORTED;

    ///
    /// @brief attribute getter
    /// @param[in] i_target the fapi2 target
    /// @param[out] o_setting array to populate
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& o_setting)
    {
        return attr::get_exp_spd_cl_supported(i_target, o_setting);
    }

    ///
    /// @brief attribute setter
    /// @param[in] i_target the fapi2 target
    /// @param[in] i_setting array to set
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode set_attr(const fapi2::Target<TARGET_TYPE>& i_target,
                                      attr_type& i_setting)
    {
        return attr::set_exp_spd_cl_supported(i_target, i_setting);
    }

    ///
    /// @brief Computes setting for attribute
    /// @param[in] i_spd_data EFD data
    /// @param[out] o_setting value we want to set attr with
    /// @return FAPI2_RC_SUCCESS iff okay
    ///
    static fapi2::ReturnCode get_value_to_set(const spd::facade& i_spd_data,
            attr_integral_type& o_setting)
    {
        uint64_t l_val = 0;
        FAPI_TRY(i_spd_data.supported_cas_latencies(l_val));
        o_setting = static_cast<attr_integral_type>(l_val);

    fapi_try_exit:
        return fapi2::current_err;
    }
};

///
/// @brief Value traits for attr_eff_engine_fields
/// @class attrEngineTraits
/// @note attr_eff_engine_fields
///
template < >
struct attrEnumTraits<exp::attr_eff_engine_fields>
{
    static constexpr size_t DISPATCHER = exp::ATTR_EFF_DISPATCHER;
};

}//mss

#endif
