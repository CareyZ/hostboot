/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/shared/exp_consts.H $ */
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
/// @file explorer_check_for_ready.H
/// @brief explorer_check_for_ready HWP declaration
///
// *HWP HWP Owner: Andre A. Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: CI

#ifndef MSS_EXP_CONSTS_H
#define MSS_EXP_CONSTS_H

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

constexpr mss::mc_type DEFAULT_MC_TYPE = mss::mc_type::EXPLORER;

namespace exp
{

constexpr uint32_t OCMB_ADDR_SHIFT = 3;

///
/// @brief enum list of explorer eff attributes to set
///
enum attr_eff_engine_fields
{
    // Template recursive base case
    ATTR_EFF_BASE_CASE = 0,

    // Attrs to set
    BYTE_ENABLES = 1,
    NIBBLE_ENABLES = 2,
    SPD_TAA_MIN = 3,
    FOUR_RANK_MODE = 4,
    DDP_COMPATIBILITY = 5,
    TSV_8H_SUPPORT = 6,
    PSTATES = 7,
    MRAM_SUPPORT = 8,
    HEIGHT_3DS = 9,
    SPD_CL_SUPPORTED = 10,

    // Dispatcher set to last enum value
    ATTR_EFF_DISPATCHER = SPD_CL_SUPPORTED,
};

///
/// @brief common explorer sizes
///
enum sizes
{
    MAX_DIMM_PER_PORT = 2,
    MAX_RANK_PER_DIMM = 4,
};

///
/// @brief explorer ffdc codes
///
enum ffdc_codes
{
    EXP_I2C_GET_FIELD = 0x0000,
    EXP_I2C_SET_FIELD = 0x0001,
    READ_HOST_FW_RESPONSE_STRUCT = 0x0003,
    READ_SENSOR_CACHE_STRUCT = 0x0004,

    SET_BYTE_ENABLES = 0x1041,
    SET_NIBBLE_ENABLES = 0x1042,
    SET_TAA_MIN = 0x1043,
    SET_FOUR_RANK_MODE = 0x1044,
    SET_DDP_COMPATIBILITY = 0x1045,
    SET_TSV_8H_SUPPORT = 0x1046,
    SET_VREF_DQ_TRAIN_RANGE = 0x1047,
    SET_PSTATES = 0x1048,
    SET_MRAM_SUPPORT = 0x1049,
    SET_3DS_HEIGHT = 0x1050,
    SET_SPD_CL_SUPPORTED = 0x1051,
};

namespace i2c
{

/// @brief List of explorer I2C commands
///
enum cmd_id : uint8_t
{
    FW_BOOT_CONFIG     = 0x01,
    FW_STATUS          = 0x02,
    FW_REG_ADDR_LATCH  = 0x03,
    FW_REG_READ        = 0x04,
    FW_REG_WRITE       = 0x05,
    FW_DOWNLOAD        = 0x06,
    FW_CONT_REG_READ   = 0x07,
    FW_CONT_REG_WRITE  = 0x08,
};

///
/// @brief common explorer sizes
///
enum sizes
{
    // 32-bit commands
    FW_BOOT_CONFIG_BYTE_LEN = 4,
    FW_STATUS_BYTE_LEN      = 5,

    FW_WRITE_REG_DATA_SIZE  = 0x08,
    FW_REG_ADDR_LATCH_SIZE  = 0x04,
    FW_I2C_SCOM_READ_SIZE   = 0x05,

    // Largest R/W length for bytes of data
    MIN_DATA_BYTES_LEN = 1,
    MAX_DATA_BYTES_LEN = 32,
};

///
/// @brief General I2C status codes
/// @note Shared I2C status codes for EXP_FW_REG_READ, EXP_FW_REG_WRITE,
/// EXP_FW_CONT_REG_READ, and EXP_FW_CONT_REG_WRITE
///
enum status_codes
{
    SUCCESS              = 0x00,
    ADDRESS_OUT_OF_RANGE = 0x01,
    ADDRESS_PROHIBITED   = 0x02,
};

///
/// @brief status codes for FW_BOOT_CONFIG
///
enum fw_boot_cfg_status
{
    FW_BOOT_CFG_SUCCESS                 = status_codes::SUCCESS,

    // Loopback fail
    FW_BOOT_CFG_LB_FAIL                 = 0x01,
    // Transport layer fail
    FW_BOOT_CFG_UNSUPPORTED_TL          = 0x02,
    // DL (data link) layer fail
    FW_BOOT_CFG_UNSUPPORTED_DL          = 0x03,
    // SERDES (serializer/deserializer) FREQ fail
    FW_BOOT_CFG_UNSUPPORTED_SERDES_FREQ = 0x04,
};

///
/// @brief I2C boot stage options
/// @note certain cmds work in certain boot stages
///
enum boot_stages
{
    BOOT_ROM_STAGE  = 0x01,
    FW_UPGRADE_MODE = 0x02,
    RUNTIME_FW      = 0x03,
};

///
/// @brief Useful constants for i2c scom functionality
///
/// @note FIRST_BYTE_MASK = allows us to mask off first by of
///       an address to check if its an IBM SCOM
///       LAST_THREE_BYTES_MASK = used as part of formula to translate
///       a given address to an IBM scom address
///       OCBM_UNCACHED_OFFSET = Also used as part of formula for translating
///       a given address to the correct IBM or microchip form
///       IBM_SCOM_OFFSET_LHS and IBM_SCOM_OFFSET_RHS are used in formula
///       for calculating IBM scom address for left and right side of addr
///       IBM_SCOM_INDICATOR is the indicator bit in the first byte of an
///       address that tells us if it is a IBM scom or not
///
enum i2c_scom_consts : uint32_t
{
    FIRST_BYTE_MASK       = 0xFF000000,
    LAST_THREE_BYTES_MASK = 0x00FFFFFF,
    OCMB_UNCACHED_OFFSET  = 0xA0000000,
    IBM_SCOM_OFFSET_LHS   = 0x08000000,
    IBM_SCOM_OFFSET_RHS   = 0x08000004,
    IBM_SCOM_INDICATOR    = IBM_SCOM_OFFSET_LHS,
};

///
/// @brief Simple enum allows code to pick between left and right
///
/// This is used when deciding if we are writing/reading from left
/// side of IBM address or right side. This is needed because IBM
/// scoms are 64 bits while the OCMB only has 32 bit regs.
enum addrSide
{
    LHS = 0x00,
    RHS = 0x01
};


}// i2c

namespace omi
{

///
/// @brief HOST-FW Commands and Responses
///
enum cmd_and_response_id
{
    FW_DDR_INTERFACE_INIT = 0x01,
    FW_TEMP_SENSOR_INIT = 0x02,
    FW_ERR_LOGGING_INTERFACE_INIT = 0x03,
    FW_GO_COMMAND = 0x04,
    FW_ADAPTER_PROPERTIES_GET = 0x05,
    FW_STATUS_GET = 0x06,
    FW_TEMPERATURE_GET = 0x07,
    FW_ERROR_LOG_GET = 0x08,
    FW_SPD_DATA_SET = 0x09,
    FW_BINARY_UPGRADE = 0x0A,
    FW_FLASH_LOADER_VERSION_INFO = 0x0B,
};

///
/// @brief Response argument parameters
///
enum response_arg
{
    SUCCESS = 0,
    ERROR_CODE = 1,
};

}// omi

}// exp
}// mss

#endif
