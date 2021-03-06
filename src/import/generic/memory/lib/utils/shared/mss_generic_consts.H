/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/shared/mss_generic_consts.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
/* [+] Evan Lojewski                                                      */
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
/// @file mss_generic_consts.H
/// @brief Common constants to be shared
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_GENERIC_CONSTS_H_
#define _MSS_GENERIC_CONSTS_H_

#include <cstdint>

namespace mss
{

///
/// @brief Common constants
///
enum common_consts
{
    DEFAULT_POLL_LIMIT = 50,  ///< the number of poll attempts in the event we can't calculate another
    MEMCMP_EQUAL = 0,         ///< Equal comparison value for memcmp
    BAD_BITS_RANKS = 4,       ///< Bad bit attribute's number of ranks
    BAD_DQ_BYTE_COUNT = 10,      ///< Bad bit attribute's number of byte
};

///
/// @brief Common timings
///
enum common_timings
{
    DELAY_1NS               = 1,
    DELAY_10NS              = 10 ,      ///< general purpose 10  ns delay for HW mode
    DELAY_100NS             = 100,      ///< general purpose 100 ns delay for HW mode
    DELAY_1US               = 1000,     ///< general purpose 1 usec delay for HW mode
    DELAY_10US              = 10000,    ///< general purpose 1 usec delay for HW mode
    DELAY_100US             = 100000,   ///< general purpose 100 usec delay for HW mode
    DELAY_1MS               = 1000000,  ///< general purpose 1 ms delay for HW mode
};

///
/// @brief Common conversions
///
enum conversions
{
    CONVERT_PS_IN_A_NS      = 1000,     ///< 1000 pico in an nano
    CONVERT_PS_IN_A_US      = 1000000,  ///< 1000000 picos in a micro
    MHZ_TO_KHZ              = 1000,
    SEC_IN_HOUR             = 60 * 60,  ///< seconds in an hour, used for scrub times
    NIBBLES_PER_BYTE = 2,
    BITS_PER_NIBBLE = 4,
    BITS_PER_BYTE = 8,
};

enum generic_sizes
{
    NUM_MAX_FREQS = 5,             ///< Used for ATTR_MAX_ALLOWED_DIMM_FREQ
    MARK_STORE_COUNT = 8,          ///< Elements in a VPD mark/store array
};

///
/// @brief FFDC generic codes
///
enum generic_ffdc_codes
{
    // Starting at 0x1%%% to avoid
    // any collisions with values
    // from controller specific ffdc codes
    SET_ATTR_DIMM_TYPE = 0x1000,
    SET_ATTR_DRAM_GEN = 0x1001,
    SET_ATTR_HYBRID = 0x1002,
    SET_ATTR_HYBRID_MEDIA = 0x1003,
    SET_ATTR_MASTER_RANKS = 0x1004,
    SET_ATTR_RANKS_CONFIGED  = 0x1005,
    GET_FIELD = 0x1006,
    READ_SPD_FIELD = 0x1007,
    BASE_CFG_PARAM_SELECT = 0x1008,
    DIMM_MODULE_PARAM_SELECT = 0x1009,
    BASE_CFG_FACTORY = 0x100A,
    DIMM_MODULE_FACTORY = 0x100B,
    GET_TAAMIN = 0x100C,
    GET_TCKMIN = 0x100D,
    GET_TCKMAX = 0x100E,
    GET_TIMEBASES_FTB = 0x100F,
    GET_TIMEBASES_MTB = 0x1010,
    GET_SUPPORTED_REV = 0x1011,
    TRASMIN = 0x1012,
    TRCMIN = 0x1013,
    TRFC1MIN = 0x1014,
    TRFC2MIN = 0x1015,
    TRFC4MIN = 0x1016,
    TFAWMIN = 0x1017,
    TWTR_S_MIN = 0x1018,
    TWRMIN = 0x1019,
    TWTR_L_MIN = 0x101A,
    DEVICE_TYPE = 0x101B,
    BASE_MODULE_TYPE = 0x101C,
    BAD_SPD_DATA = 0x101D,
    SET_FIELD = 0x101E,
    SELECT_SUPPORTED_FREQ = 0x101F,
    FREQ_SCOREBOARD_REMOVE_FREQS_ABOVE_LIMIT = 0x1020,
    FREQ_SCOREBOARD_REMOVE_FREQS_ABOVE_LIMIT_VECTOR = 0x1021,
    FREQ_SCOREBOARD_REMOVE_FREQS_NOT_ON_LIST = 0x1022,
    FREQ_SCOREBOARD_MAX_SUPPORTED_FREQ = 0x1023,
    FREQ_SCOREBOARD_SUPPORTED_FREQS = 0x1024,
    LIMIT_FREQ_BY_VPD = 0x1025,
    SET_DIMM_TYPE = 0x1026,
    SET_DRAM_GEN = 0x1027,
    SET_HYBRID = 0x1027,
    SET_HYBRID_MEDIA = 0x1028,
    SET_MRANKS = 0x1029,
    SET_DIMM_RANKS_CNFG = 0x1039,
    DDIMM_RAWCARD_DECODE = 0x103a,
    SET_DRAM_WIDTH = 0x1040,

    SET_SI_VREF_DRAM_WR = 0x1041,
    SET_SI_MC_RCV_IMP_DQ_DQS = 0x1042,
    SET_SI_MC_DRV_IMP_DQ_DQS_PULL_UP = 0x1043,
    SET_SI_MC_DRV_IMP_DQ_DQS_PULL_DOWN = 0x1044,
    SET_SI_MC_DRV_SLEW_RATE_DQ_DQS = 0x1045,
    SET_SI_MC_DRV_IMP_CMD_ADDR = 0x10466,
    SET_SI_MC_DRV_SLEW_RATE_CMD_ADDR = 0x1047,
    SET_SI_MC_DRV_IMP_CLK = 0x1048,
    SET_SI_MC_DRV_SLEW_RATE_CLK = 0x1049,
    SET_SI_MC_RCV_IMP_ALERT_N = 0x1050,
    SET_SI_DRAM_RTT_NOM = 0x1051,
    SET_SI_DRAM_RTT_WR = 0x1052,
    SET_SI_DRAM_RTT_PARK = 0x1053,
    SET_SI_DRAM_PREAMBLE = 0x1054,
    SET_SI_MC_DRV_EQ_DQ_DQS = 0x1055,
    SET_SI_DRAM_DRV_IMP_DQ_DQS = 0x1056,
    SET_SI_VREF_DQ_TRAIN_RANGE = 0x1057,
    SET_SI_VREF_DQ_TRAIN_VALUE = 0x1058,
    SET_SI_ODT_WR = 0x1059,
    SET_SI_ODT_RD = 0x1060,
    SET_SI_GEARDOWN_MODE = 0x1061,
    PRE_DATA_ENGINE_CTOR = 0x1062
};

///
/// @brief Supported proc types
/// @note Processor types by system generation and sub numbering
///
enum class proc_type
{
    NIMBUS  = 0x0900,
    CUMULUS = 0x0901,
    AXONE   = 0x0902,
};

///
/// @brief Supported memory controller types
///
enum class mc_type
{
    NIMBUS   = 0,
    CENTAUR  = 1,
    EXPLORER = 2,
};

///
/// @brief JEDEC supported DDR speeds
/// @note Includes DDR4 and DDR5 only
///
enum ddr_dimm_speeds
{
    // Supported frequencies
    DIMM_SPEED_1600 = 1600,
    DIMM_SPEED_1866 = 1866,
    DIMM_SPEED_2133 = 2133,
    DIMM_SPEED_2400 = 2400,
    DIMM_SPEED_2666 = 2666,
    DIMM_SPEED_2933 = 2933,
    DIMM_SPEED_3200 = 3200,
    DIMM_SPEED_3600 = 3600,
    DIMM_SPEED_4000 = 4000,
    DIMM_SPEED_4400 = 4400,
    DIMM_SPEED_4800 = 4800,

    // Max/Mins for specific generations here
    DDR4_MIN_SPEED = 1600,
    DDR4_MAX_SPEED = 3200,
    DDR5_MIN_SPEED = 3200,
    DDR5_MAX_SPEED = 4800,
};

enum states
{
    LOW = 0,
    HIGH = 1,
    START = 1,
    STOP = 0,
    START_N = 0,
    STOP_N = 1,
    ON = 1,
    OFF = 0,
    ON_N = 0,
    OFF_N = 1,
    YES = 1,
    NO = 0,
    YES_N = 0,
    NO_N = 1,
    // Uses "_" in the name for INVALID as INVALID is defined as a macro in the
    // FSP code. If we just use INVALID as an enum name, then the preprocessor
    // compile phase changes it to be the macro.
    _INVALID_ = 0xFF,
    NO_CHIP_SELECT_ACTIVE = 0xFF,
};


namespace spd
{

///
/// @brief SPD revisions - not tied any particular module
///
enum rev : uint8_t
{
    V0_0 = 0x00, ///< represents Rev 0.0
    V1_0 = 0x10, ///< represents Rev 1.0
    V1_1 = 0x11, ///< represents Rev 1.1
    V1_2 = 0x12, ///< represents Rev 1.2

    // These module revisions can vary independently
    // so we track the largest decoded revision here.
    GEN_SEC_MAX = V1_1,
    RDIMM_MAX = V1_1,
    LRDIMM_MAX = V1_2,
    DDIMM_MAX = V0_0,
};

///
/// @brief SPD module parameters
/// @note helps distinguish SPD decoder sections
///
enum parameters
{
    UNINITIALIZED,
    BASE_CNFG,
    RDIMM_MODULE,
    LRDIMM_MODULE,
    NVDIMM_MODULE,
    DDIMM_MODULE,
};

///
/// @brief DRAM generation selector
/// @note values set to SPD settings
///
enum device_type
{
    DDR4 = 0x0c,
};

///
/// @brief DIMM type selector
/// @note values set to SPD settings
///
enum dimm_type
{
    RDIMM = 0b0001,
    LRDIMM = 0b0100,
    DDIMM = 0b1010,
    SORDIMM = 0b1000,
    MINIRDIMM = 0b0101,
};

enum guard_band : uint16_t
{
    // Used for caclulating spd timing values - from JEDEC rounding algorithm
    // Correction factor is 1% (for DDR3) or 2.5% (for DDR4)
    // when doing integer math, we add-in the inverse correction factor
    // Formula used for derivation:
    // Guardband = 1000 * (1000* correction_factor) - 1
    INVERSE_DDR4_CORRECTION_FACTOR = 974, ///< DDR4 correction factor
};

}// spd

namespace efd
{


///
/// @brief EFD Module identifier
/// @note helps distinguish the EFD identifier
///
enum id
{
    DDR4_CUSTOM_MICROCHIP = 0x11,
};

}//efd

///
/// @brief DIMM nibble mask
/// @note nibble0: 4 high bits, nibble1: 4 low bits
///
enum nibble_mask
{
    MASK_NIBBLE0 = 0xf0,
    MASK_NIBBLE1 = 0x0f,
};

///
/// @brief throttle_type used to set bulk_pwr_throttls to run POWER or THERMAL throttling
/// @note OCC will be using the POWER option
///
enum class throttle_type
{
    POWER = 0,
    THERMAL = 1,
};

///
/// @brief Trait classes for proc_type
///
template< proc_type P >
class procTraits;

///
/// @brief Trait classes for proc_type - NIMBUS specialization
///
template< >
struct procTraits<proc_type::NIMBUS>
{
    enum
    {
        MC_PER_MODULE = 2,
        MCS_PER_MC = 2,
        MCS_PER_PROC = MC_PER_MODULE * MCS_PER_MC,
        PORTS_PER_MCBIST = 4,
        PORTS_PER_MCS = 2,
        DIMMS_PER_PORT = 2,
        DIMMS_PER_MCS = PORTS_PER_MCS * DIMMS_PER_PORT,
        DIMMS_PER_MCBIST = PORTS_PER_MCBIST * DIMMS_PER_PORT,
    };
};

///
/// @brief Trait classes for proc_type - AXONE specialization
///
/// TODO: Need to add mc_type
template< >
struct procTraits<proc_type::AXONE>
{
    enum
    {
        EXP_PORTS_PER_OCMB = 1,
        DIMMS_PER_PORT = 2,
    };
};


}// mss

#endif
