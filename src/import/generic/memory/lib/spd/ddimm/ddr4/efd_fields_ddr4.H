/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/ddimm/ddr4/efd_fields_ddr4.H $ */
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
/// @file efd_fields_ddr4.H
/// @brief DDIMM Extended Functional Data (EFD) common fields
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _EFD_FIELDS_DDR4_H_
#define _EFD_FIELDS_DDR4_H_


#include <cstdint>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mss_field.H>

namespace mss
{

namespace efd
{

///
/// @class Fields class - specialization for DDR4 custom_microchip_fields
/// @tparam D device type (DDR4, etc.)
/// @tparam E EFD type (ie custom EFD type 1)
///
template<mss::spd::device_type D, mss::efd::id E>
class fields;

///
/// @class Fields class - specialization for DDR4 custom_microchip_fields
/// @note Stores all field information for the custom microchip DDR4 DDIMM
///
template<>
class fields<mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>
{
    private:

        enum
        {

            // Byte 0: Host Speed Supported
            HOST_SPEED_SUPPORTED_BYTE = 0,
            HOST_SPEED_SUPPORTED_START = 1,
            HOST_SPEED_SUPPORTED_LEN = 7,

            // Byte 2: Master Ranks Supported
            MASTER_RANKS_SUPPORTED_BYTE = 2,
            MASTER_RANKS_SUPPORTED_START = 4,
            MASTER_RANKS_SUPPORTED_LEN = 4,

            // Byte 3: Channels supported byte0
            CHANNELS_SUPPORTED_BYTE0_BYTE = 3,
            CHANNELS_SUPPORTED_BYTE0_START = 0,
            CHANNELS_SUPPORTED_BYTE0_LEN = 8,

            // Byte 4: Channels supported byte1
            CHANNELS_SUPPORTED_BYTE1_BYTE = 4,
            CHANNELS_SUPPORTED_BYTE1_START = 0,
            CHANNELS_SUPPORTED_BYTE1_LEN = 8,

            // Byte 5: Channels supported byte2
            CHANNELS_SUPPORTED_BYTE2_BYTE = 5,
            CHANNELS_SUPPORTED_BYTE2_START = 0,
            CHANNELS_SUPPORTED_BYTE2_LEN = 8,

            // Byte 6: Channels supported byte3
            CHANNELS_SUPPORTED_BYTE3_BYTE = 6,
            CHANNELS_SUPPORTED_BYTE3_START = 0,
            CHANNELS_SUPPORTED_BYTE3_LEN = 8,

            // Byte 7: DIMMs supported
            DIMMS_SUPPORTED_BYTE = 7,
            DIMMS_SUPPORTED_START = 6,
            DIMMS_SUPPORTED_LEN = 2,

            // Byte 16: PHY ODT impedance
            PHY_ODT_IMPEDANCE_BYTE = 16,
            PHY_ODT_IMPEDANCE_START = 3,
            PHY_ODT_IMPEDANCE_LEN = 5,

            // Byte 17: PHY Drive impedance pull up
            PHY_DRIVE_IMPEDANCE_PULL_UP_BYTE = 17,
            PHY_DRIVE_IMPEDANCE_PULL_UP_START = 2,
            PHY_DRIVE_IMPEDANCE_PULL_UP_LEN = 6,

            // Byte 18: PHY Drive impedance pull down
            PHY_DRIVE_IMPEDANCE_PULL_DOWN_BYTE = 18,
            PHY_DRIVE_IMPEDANCE_PULL_DOWN_START = 2,
            PHY_DRIVE_IMPEDANCE_PULL_DOWN_LEN = 6,

            // Byte 19: PHY Drive Impedance
            PHY_DRIVE_IMPEDANCE_BYTE = 19,
            PHY_DRIVE_IMPEDANCE_START = 0,
            PHY_DRIVE_IMPEDANCE_LEN = 8,

            // Byte 20: PHY Slew Rate DQ_DQS
            PHY_SLEW_RATE_DQ_DQS_BYTE = 20,
            PHY_SLEW_RATE_DQ_DQS_START = 0,
            PHY_SLEW_RATE_DQ_DQS_LEN = 8,

            // Byte 21: ATX impedance
            ATX_IMPEDANCE_BYTE = 21,
            ATX_IMPEDANCE_START = 4,
            ATX_IMPEDANCE_LEN = 4,

            // Byte 22: ATX Slew rate
            ATX_SLEW_RATE_BYTE = 22,
            ATX_SLEW_RATE_START = 0,
            ATX_SLEW_RATE_LEN = 8,

            // Byte 23: CK Impedance
            CK_IMPEDANCE_BYTE = 23,
            CK_IMPEDANCE_START = 4,
            CK_IMPEDANCE_LEN = 4,

            // Byte 24: CK Slew rate
            CK_SLEW_RATE_BYTE = 24,
            CK_SLEW_RATE_START = 0,
            CK_SLEW_RATE_LEN = 8,

            // Byte 25: Alert ODT Impedance
            ALERT_ODT_IMPEDANCE_BYTE = 25,
            ALERT_ODT_IMPEDANCE_START = 4,
            ALERT_ODT_IMPEDANCE_LEN = 4,

            // Byte 26: DRAM RTT Nom
            DRAM_RTT_NOM_BYTE = 26,
            DRAM_RTT_NOM_START = 0,
            DRAM_RTT_NOM_LEN = 8,

            // Byte 27: DRAM RTT Nom rank0
            DRAM_RTT_NOM_RANK0_BYTE = 27,
            DRAM_RTT_NOM_RANK0_START = 4,
            DRAM_RTT_NOM_RANK0_LEN = 4,

            // Byte 28: DRAM RTT Nom rank1
            DRAM_RTT_NOM_RANK1_BYTE = 28,
            DRAM_RTT_NOM_RANK1_START = 4,
            DRAM_RTT_NOM_RANK1_LEN = 4,

            // Byte 29: DRAM RTT Nom rank2
            DRAM_RTT_NOM_RANK2_BYTE = 29,
            DRAM_RTT_NOM_RANK2_START = 4,
            DRAM_RTT_NOM_RANK2_LEN = 4,

            // Byte 30: DRAM RTT Nom rank3
            DRAM_RTT_NOM_RANK3_BYTE = 30,
            DRAM_RTT_NOM_RANK3_START = 4,
            DRAM_RTT_NOM_RANK3_LEN = 4,

            // Byte 31: DRAM RTT WR
            DRAM_RTT_WR_BYTE = 31,
            DRAM_RTT_WR_START = 0,
            DRAM_RTT_WR_LEN = 8,

            // Byte 32: DRAM RTT WR rank0
            DRAM_RTT_WR_RANK0_BYTE = 32,
            DRAM_RTT_WR_RANK0_START = 4,
            DRAM_RTT_WR_RANK0_LEN = 4,

            // Byte 33: DRAM RTT WR rank1
            DRAM_RTT_WR_RANK1_BYTE = 33,
            DRAM_RTT_WR_RANK1_START = 4,
            DRAM_RTT_WR_RANK1_LEN = 4,

            // Byte 34: DRAM RTT WR rank2
            DRAM_RTT_WR_RANK2_BYTE = 34,
            DRAM_RTT_WR_RANK2_START = 4,
            DRAM_RTT_WR_RANK2_LEN = 4,

            // Byte 35: DRAM RTT WR rank3
            DRAM_RTT_WR_RANK3_BYTE = 35,
            DRAM_RTT_WR_RANK3_START = 4,
            DRAM_RTT_WR_RANK3_LEN = 4,

            // Byte 36: DRAM RTT Park
            DRAM_RTT_PARK_BYTE = 36,
            DRAM_RTT_PARK_START = 0,
            DRAM_RTT_PARK_LEN = 8,

            // Byte 37: DRAM RTT Park rank0
            DRAM_RTT_PARK_RANK0_BYTE = 37,
            DRAM_RTT_PARK_RANK0_START = 4,
            DRAM_RTT_PARK_RANK0_LEN = 4,

            // Byte 38: DRAM RTT Park rank1
            DRAM_RTT_PARK_RANK1_BYTE = 38,
            DRAM_RTT_PARK_RANK1_START = 4,
            DRAM_RTT_PARK_RANK1_LEN = 4,

            // Byte 39: DRAM RTT Park rank2
            DRAM_RTT_PARK_RANK2_BYTE = 39,
            DRAM_RTT_PARK_RANK2_START = 4,
            DRAM_RTT_PARK_RANK2_LEN = 4,

            // Byte 40: DRAM RTT Park rank3
            DRAM_RTT_PARK_RANK3_BYTE = 40,
            DRAM_RTT_PARK_RANK3_START = 4,
            DRAM_RTT_PARK_RANK3_LEN = 4,

            // Byte 41: DRAM DIC
            DRAM_DIC_BYTE = 41,
            DRAM_DIC_START = 4,
            DRAM_DIC_LEN = 4,

            // Byte 42: DRAM Preamble
            DRAM_PREAMBLE_BYTE = 42,
            WRITE_PREAMBLE_START = 6,
            WRITE_PREAMBLE_LEN = 1,
            READ_PREAMBLE_START = 7,
            READ_PREAMBLE_LEN = 1,

            // Byte 43: PHY Equalization
            PHY_EQUALIZATION_BYTE = 43,
            PHY_EQUALIZATION_START = 6,
            PHY_EQUALIZATION_LEN = 2,

            // Byte 44: Initial WR VREF DQ setting
            WR_VREF_DQ_BYTE = 44,
            WR_VREF_DQ_RANGE_START = 1,
            WR_VREF_DQ_RANGE_LEN = 1,
            WR_VREF_DQ_VALUE_START = 2,
            WR_VREF_DQ_VALUE_LEN = 6,

            // Byte 45: ODT WR Map CS Byte1
            ODT_WR_MAP1_BYTE = 45,
            ODT_WR_MAP_RANK3_START = 0,
            ODT_WR_MAP_RANK3_LEN = 4,
            ODT_WR_MAP_RANK2_START = 4,
            ODT_WR_MAP_RANK2_LEN = 4,

            // Byte 46: ODT WR Map CS Byte0
            ODT_WR_MAP0_BYTE = 46,
            ODT_WR_MAP_RANK1_START = 0,
            ODT_WR_MAP_RANK1_LEN = 4,
            ODT_WR_MAP_RANK0_START = 4,
            ODT_WR_MAP_RANK0_LEN = 4,

            // Byte 47: ODT RD Map CS Byte1
            ODT_RD_MAP1_BYTE = 47,
            ODT_RD_MAP_RANK3_START = 0,
            ODT_RD_MAP_RANK3_LEN = 4,
            ODT_RD_MAP_RANK2_START = 4,
            ODT_RD_MAP_RANK2_LEN = 4,

            // Byte 48: ODT RD Map CS Byte0
            ODT_RD_MAP0_BYTE = 48,
            ODT_RD_MAP_RANK1_START = 0,
            ODT_RD_MAP_RANK1_LEN = 4,
            ODT_RD_MAP_RANK0_START = 4,
            ODT_RD_MAP_RANK0_LEN = 4,

            // Byte 49: Geardown during training
            GEARDOWN_DURING_TRAINING_BYTE = 49,
            GEARDOWN_DURING_TRAINING_START = 7,
            GEARDOWN_DURING_TRAINING_LEN = 1,

            // Byte 50: PMIC0 SWA Volt
            PMIC0_SWA_BYTE = 50,
            PMIC0_SWA_SETTING_START = 0,
            PMIC0_SWA_SETTING_LEN = 7,
            PMIC0_SWA_RANGE_START = 7,
            PMIC0_SWA_RANGE_LEN = 1,

            // Byte 51: PMIC0 SWB Volt
            PMIC0_SWB_BYTE = 51,
            PMIC0_SWB_SETTING_START = 0,
            PMIC0_SWB_SETTING_LEN = 7,
            PMIC0_SWB_RANGE_START = 7,
            PMIC0_SWB_RANGE_LEN = 1,

            // Byte 52: PMIC0 SWC Volt
            PMIC0_SWC_BYTE = 52,
            PMIC0_SWC_SETTING_START = 0,
            PMIC0_SWC_SETTING_LEN = 7,
            PMIC0_SWC_RANGE_START = 7,
            PMIC0_SWC_RANGE_LEN = 1,

            // Byte 53: PMIC0 SWD Volt
            PMIC0_SWD_BYTE = 53,
            PMIC0_SWD_SETTING_START = 0,
            PMIC0_SWD_SETTING_LEN = 7,
            PMIC0_SWD_RANGE_START = 7,
            PMIC0_SWD_RANGE_LEN = 1,

            // Byte 54: PMIC1 SWA Volt
            PMIC1_SWA_BYTE = 54,
            PMIC1_SWA_SETTING_START = 0,
            PMIC1_SWA_SETTING_LEN = 7,
            PMIC1_SWA_RANGE_START = 7,
            PMIC1_SWA_RANGE_LEN = 1,

            // Byte 55: PMIC1 SWB Volt
            PMIC1_SWB_BYTE = 55,
            PMIC1_SWB_SETTING_START = 0,
            PMIC1_SWB_SETTING_LEN = 7,
            PMIC1_SWB_RANGE_START = 7,
            PMIC1_SWB_RANGE_LEN = 1,

            // Byte 56: PMIC1 SWC Volt
            PMIC1_SWC_BYTE = 56,
            PMIC1_SWC_SETTING_START = 0,
            PMIC1_SWC_SETTING_LEN = 7,
            PMIC1_SWC_RANGE_START = 7,
            PMIC1_SWC_RANGE_LEN = 1,

            // Byte 57: PMIC1 SWD Volt
            PMIC1_SWD_BYTE = 57,
            PMIC1_SWD_SETTING_START = 0,
            PMIC1_SWD_SETTING_LEN = 7,
            PMIC1_SWD_RANGE_START = 7,
            PMIC1_SWD_RANGE_LEN = 1,
        };

    public:
        // Syntatic sugar to make member variable declaration easier
        using field_t = mss::field_t<mss::endian::LITTLE>;

        // First field - SPD byte
        // Second field - start bit
        // Third field - bit length

        // Byte 0: Host Speed Supported
        static constexpr field_t HOST_SPEED_SUPPORTED{HOST_SPEED_SUPPORTED_BYTE, HOST_SPEED_SUPPORTED_START, HOST_SPEED_SUPPORTED_LEN};

        // Byte 2: Master Ranks Supported
        static constexpr field_t MASTER_RANKS_SUPPORTED{MASTER_RANKS_SUPPORTED_BYTE, MASTER_RANKS_SUPPORTED_START, MASTER_RANKS_SUPPORTED_LEN};

        // Byte 3: Channels supported byte0
        static constexpr field_t CHANNELS_SUPPORTED_BYTE0{CHANNELS_SUPPORTED_BYTE0_BYTE, CHANNELS_SUPPORTED_BYTE0_START, CHANNELS_SUPPORTED_BYTE0_LEN};

        // Byte 4: Channels supported byte1
        static constexpr field_t CHANNELS_SUPPORTED_BYTE1{CHANNELS_SUPPORTED_BYTE1_BYTE, CHANNELS_SUPPORTED_BYTE1_START, CHANNELS_SUPPORTED_BYTE1_LEN};

        // Byte 5: Channels supported byte2
        static constexpr field_t CHANNELS_SUPPORTED_BYTE2{CHANNELS_SUPPORTED_BYTE2_BYTE, CHANNELS_SUPPORTED_BYTE2_START, CHANNELS_SUPPORTED_BYTE2_LEN};

        // Byte 6: Channels supported byte3
        static constexpr field_t CHANNELS_SUPPORTED_BYTE3{CHANNELS_SUPPORTED_BYTE3_BYTE, CHANNELS_SUPPORTED_BYTE3_START, CHANNELS_SUPPORTED_BYTE3_LEN};

        // Byte 7: DIMMs supported
        static constexpr field_t DIMMS_SUPPORTED{DIMMS_SUPPORTED_BYTE, DIMMS_SUPPORTED_START, DIMMS_SUPPORTED_LEN};

        // Byte 16: PHY ODT impedance
        static constexpr field_t PHY_ODT_IMPEDANCE{PHY_ODT_IMPEDANCE_BYTE, PHY_ODT_IMPEDANCE_START, PHY_ODT_IMPEDANCE_LEN};

        // Byte 17: PHY Drive impedance pull up
        static constexpr field_t PHY_DRIVE_IMPEDANCE_PULL_UP{PHY_DRIVE_IMPEDANCE_PULL_UP_BYTE, PHY_DRIVE_IMPEDANCE_PULL_UP_START, PHY_DRIVE_IMPEDANCE_PULL_UP_LEN};

        // Byte 18: PHY Drive impedance pull down
        static constexpr field_t PHY_DRIVE_IMPEDANCE_PULL_DOWN{PHY_DRIVE_IMPEDANCE_PULL_DOWN_BYTE, PHY_DRIVE_IMPEDANCE_PULL_DOWN_START, PHY_DRIVE_IMPEDANCE_PULL_DOWN_LEN};

        // Byte 19: PHY Drive Impedance
        static constexpr field_t PHY_DRIVE_IMPEDANCE{PHY_DRIVE_IMPEDANCE_BYTE, PHY_DRIVE_IMPEDANCE_START, PHY_DRIVE_IMPEDANCE_LEN};

        // Byte 20: PHY Slew Rate DQ_DQS
        static constexpr field_t PHY_SLEW_RATE_DQ_DQS{PHY_SLEW_RATE_DQ_DQS_BYTE, PHY_SLEW_RATE_DQ_DQS_START, PHY_SLEW_RATE_DQ_DQS_LEN};

        // Byte 21: ATX impedance
        static constexpr field_t ATX_IMPEDANCE{ATX_IMPEDANCE_BYTE, ATX_IMPEDANCE_START, ATX_IMPEDANCE_LEN};

        // Byte 22: ATX Slew rate
        static constexpr field_t ATX_SLEW_RATE{ATX_SLEW_RATE_BYTE, ATX_SLEW_RATE_START, ATX_SLEW_RATE_LEN};

        // Byte 23: CK Impedance
        static constexpr field_t CK_IMPEDANCE{CK_IMPEDANCE_BYTE, CK_IMPEDANCE_START, CK_IMPEDANCE_LEN};

        // Byte 24: CK Slew rate
        static constexpr field_t CK_SLEW_RATE{CK_SLEW_RATE_BYTE, CK_SLEW_RATE_START, CK_SLEW_RATE_LEN};

        // Byte 25: Alert ODT Impedance
        static constexpr field_t ALERT_ODT_IMPEDANCE{ALERT_ODT_IMPEDANCE_BYTE, ALERT_ODT_IMPEDANCE_START, ALERT_ODT_IMPEDANCE_LEN};

        // Byte 26: DRAM RTT Nom
        static constexpr field_t DRAM_RTT_NOM{DRAM_RTT_NOM_BYTE, DRAM_RTT_NOM_START, DRAM_RTT_NOM_LEN};

        // Byte 27: DRAM RTT Nom rank0
        static constexpr field_t DRAM_RTT_NOM_RANK0{DRAM_RTT_NOM_RANK0_BYTE, DRAM_RTT_NOM_RANK0_START, DRAM_RTT_NOM_RANK0_LEN};

        // Byte 28: DRAM RTT Nom rank1
        static constexpr field_t DRAM_RTT_NOM_RANK1{DRAM_RTT_NOM_RANK1_BYTE, DRAM_RTT_NOM_RANK1_START, DRAM_RTT_NOM_RANK1_LEN};

        // Byte 29: DRAM RTT Nom rank2
        static constexpr field_t DRAM_RTT_NOM_RANK2{DRAM_RTT_NOM_RANK2_BYTE, DRAM_RTT_NOM_RANK2_START, DRAM_RTT_NOM_RANK2_LEN};

        // Byte 30: DRAM RTT Nom rank3
        static constexpr field_t DRAM_RTT_NOM_RANK3{DRAM_RTT_NOM_RANK3_BYTE, DRAM_RTT_NOM_RANK3_START, DRAM_RTT_NOM_RANK3_LEN};

        // Byte 31: DRAM RTT WR
        static constexpr field_t DRAM_RTT_WR{DRAM_RTT_WR_BYTE, DRAM_RTT_WR_START, DRAM_RTT_WR_LEN};

        // Byte 32: DRAM RTT WR rank0
        static constexpr field_t DRAM_RTT_WR_RANK0{DRAM_RTT_WR_RANK0_BYTE, DRAM_RTT_WR_RANK0_START, DRAM_RTT_WR_RANK0_LEN};

        // Byte 33: DRAM RTT WR rank1
        static constexpr field_t DRAM_RTT_WR_RANK1{DRAM_RTT_WR_RANK1_BYTE, DRAM_RTT_WR_RANK1_START, DRAM_RTT_WR_RANK1_LEN};

        // Byte 34: DRAM RTT WR rank2
        static constexpr field_t DRAM_RTT_WR_RANK2{DRAM_RTT_WR_RANK2_BYTE, DRAM_RTT_WR_RANK2_START, DRAM_RTT_WR_RANK2_LEN};

        // Byte 35: DRAM RTT WR rank3
        static constexpr field_t DRAM_RTT_WR_RANK3{DRAM_RTT_WR_RANK3_BYTE, DRAM_RTT_WR_RANK3_START, DRAM_RTT_WR_RANK3_LEN};

        // Byte 36: DRAM RTT Park
        static constexpr field_t DRAM_RTT_PARK{DRAM_RTT_PARK_BYTE, DRAM_RTT_PARK_START, DRAM_RTT_PARK_LEN};

        // Byte 37: DRAM RTT Park rank0
        static constexpr field_t DRAM_RTT_PARK_RANK0{DRAM_RTT_PARK_RANK0_BYTE, DRAM_RTT_PARK_RANK0_START, DRAM_RTT_PARK_RANK0_LEN};

        // Byte 38: DRAM RTT Park rank1
        static constexpr field_t DRAM_RTT_PARK_RANK1{DRAM_RTT_PARK_RANK1_BYTE, DRAM_RTT_PARK_RANK1_START, DRAM_RTT_PARK_RANK1_LEN};

        // Byte 39: DRAM RTT Park rank2
        static constexpr field_t DRAM_RTT_PARK_RANK2{DRAM_RTT_PARK_RANK2_BYTE, DRAM_RTT_PARK_RANK2_START, DRAM_RTT_PARK_RANK2_LEN};

        // Byte 40: DRAM RTT Park rank3
        static constexpr field_t DRAM_RTT_PARK_RANK3{DRAM_RTT_PARK_RANK3_BYTE, DRAM_RTT_PARK_RANK3_START, DRAM_RTT_PARK_RANK3_LEN};

        // Byte 41: DRAM DIC
        static constexpr field_t DRAM_DIC{DRAM_DIC_BYTE, DRAM_DIC_START, DRAM_DIC_LEN};

        // Byte 42: DRAM Preamble
        static constexpr field_t WRITE_PREAMBLE{DRAM_PREAMBLE_BYTE, WRITE_PREAMBLE_START, WRITE_PREAMBLE_LEN};
        static constexpr field_t READ_PREAMBLE{DRAM_PREAMBLE_BYTE, READ_PREAMBLE_START, READ_PREAMBLE_LEN};

        // Byte 43: PHY Equalization
        static constexpr field_t PHY_EQUALIZATION{PHY_EQUALIZATION_BYTE, PHY_EQUALIZATION_START, PHY_EQUALIZATION_LEN};

        // Byte 44: Initial WR VREF DQ setting
        static constexpr field_t WR_VREF_DQ_RANGE{WR_VREF_DQ_BYTE, WR_VREF_DQ_RANGE_START, WR_VREF_DQ_RANGE_LEN};
        static constexpr field_t WR_VREF_DQ_VALUE{WR_VREF_DQ_BYTE, WR_VREF_DQ_VALUE_START, WR_VREF_DQ_VALUE_LEN};

        // Byte 45: ODT WR Map CS Byte1
        static constexpr field_t ODT_WR_MAP_RANK3{ODT_WR_MAP1_BYTE, ODT_WR_MAP_RANK3_START, ODT_WR_MAP_RANK3_LEN};
        static constexpr field_t ODT_WR_MAP_RANK2{ODT_WR_MAP1_BYTE, ODT_WR_MAP_RANK2_START, ODT_WR_MAP_RANK2_LEN};

        // Byte 46: ODT WR Map CS Byte0
        static constexpr field_t ODT_WR_MAP_RANK1{ODT_WR_MAP0_BYTE, ODT_WR_MAP_RANK1_START, ODT_WR_MAP_RANK1_LEN};
        static constexpr field_t ODT_WR_MAP_RANK0{ODT_WR_MAP0_BYTE, ODT_WR_MAP_RANK0_START, ODT_WR_MAP_RANK0_LEN};

        // Byte 47: ODT RD Map CS Byte1
        static constexpr field_t ODT_RD_MAP_RANK3{ODT_RD_MAP1_BYTE, ODT_RD_MAP_RANK3_START, ODT_RD_MAP_RANK3_LEN};
        static constexpr field_t ODT_RD_MAP_RANK2{ODT_RD_MAP1_BYTE, ODT_RD_MAP_RANK2_START, ODT_RD_MAP_RANK2_LEN};

        // Byte 48: ODT RD Map CS Byte0
        static constexpr field_t ODT_RD_MAP_RANK1{ODT_RD_MAP0_BYTE, ODT_RD_MAP_RANK1_START, ODT_RD_MAP_RANK1_LEN};
        static constexpr field_t ODT_RD_MAP_RANK0{ODT_RD_MAP0_BYTE, ODT_RD_MAP_RANK0_START, ODT_RD_MAP_RANK0_LEN};

        // Byte 49: Geardown during training
        static constexpr field_t GEARDOWN_DURING_TRAINING{GEARDOWN_DURING_TRAINING_BYTE, GEARDOWN_DURING_TRAINING_START, GEARDOWN_DURING_TRAINING_LEN};

        // Byte 50: PMIC0 SWA Volt
        static constexpr field_t PMIC0_SWA_SETTING{PMIC0_SWA_BYTE, PMIC0_SWA_SETTING_START, PMIC0_SWA_SETTING_LEN};
        static constexpr field_t PMIC0_SWA_RANGE{PMIC0_SWA_BYTE, PMIC0_SWA_RANGE_START, PMIC0_SWA_RANGE_LEN};

        // Byte 51: PMIC0 SWB Volt
        static constexpr field_t PMIC0_SWB_SETTING{PMIC0_SWB_BYTE, PMIC0_SWB_SETTING_START, PMIC0_SWB_SETTING_LEN};
        static constexpr field_t PMIC0_SWB_RANGE{PMIC0_SWB_BYTE, PMIC0_SWB_RANGE_START, PMIC0_SWB_RANGE_LEN};

        // Byte 52: PMIC0 SWC Volt
        static constexpr field_t PMIC0_SWC_SETTING{PMIC0_SWC_BYTE, PMIC0_SWC_SETTING_START, PMIC0_SWC_SETTING_LEN};
        static constexpr field_t PMIC0_SWC_RANGE{PMIC0_SWC_BYTE, PMIC0_SWC_RANGE_START, PMIC0_SWC_RANGE_LEN};

        // Byte 53: PMIC0 SWD Volt
        static constexpr field_t PMIC0_SWD_SETTING{PMIC0_SWD_BYTE, PMIC0_SWD_SETTING_START, PMIC0_SWD_SETTING_LEN};
        static constexpr field_t PMIC0_SWD_RANGE{PMIC0_SWD_BYTE, PMIC0_SWD_RANGE_START, PMIC0_SWD_RANGE_LEN};

        // Byte 54: PMIC1 SWA Volt
        static constexpr field_t PMIC1_SWA_SETTING{PMIC1_SWA_BYTE, PMIC1_SWA_SETTING_START, PMIC1_SWA_SETTING_LEN};
        static constexpr field_t PMIC1_SWA_RANGE{PMIC1_SWA_BYTE, PMIC1_SWA_RANGE_START, PMIC1_SWA_RANGE_LEN};

        // Byte 55: PMIC1 SWB Volt
        static constexpr field_t PMIC1_SWB_SETTING{PMIC1_SWB_BYTE, PMIC1_SWB_SETTING_START, PMIC1_SWB_SETTING_LEN};
        static constexpr field_t PMIC1_SWB_RANGE{PMIC1_SWB_BYTE, PMIC1_SWB_RANGE_START, PMIC1_SWB_RANGE_LEN};

        // Byte 56: PMIC1 SWC Volt
        static constexpr field_t PMIC1_SWC_SETTING{PMIC1_SWC_BYTE, PMIC1_SWC_SETTING_START, PMIC1_SWC_SETTING_LEN};
        static constexpr field_t PMIC1_SWC_RANGE{PMIC1_SWC_BYTE, PMIC1_SWC_RANGE_START, PMIC1_SWC_RANGE_LEN};

        // Byte 57: PMIC1 SWD Volt
        static constexpr field_t PMIC1_SWD_SETTING{PMIC1_SWD_BYTE, PMIC1_SWD_SETTING_START, PMIC1_SWD_SETTING_LEN};
        static constexpr field_t PMIC1_SWD_RANGE{PMIC1_SWD_BYTE, PMIC1_SWD_RANGE_START, PMIC1_SWD_RANGE_LEN};
};

} // ns efd
} // ns mss
#endif
