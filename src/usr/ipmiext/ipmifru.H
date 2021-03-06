/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ipmiext/ipmifru.H $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2018                        */
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

#ifndef __IPMI_IPMIFRU_H
#define __IPMI_IMPIFRU_H

/**
 * @file ipmifru.H
 * @brief IPMI FRU inventory declariation
 */

#include <stdint.h>
#include <ipmi/ipmiif.H>
#include <console/consoleif.H>


/**
 *
 *
 */
namespace IPMIFRU
{
    void writeData(uint8_t i_deviceId, uint8_t *i_data,
            uint32_t i_dataSize, uint32_t i_offset = 0);

     /*
     * @brief Read the IPMI FRU Record
     * @param[in] deviceId - The device ID to be read
     * @param[in/out] data - The buffer pointing to the data read
     */
    void readData(uint8_t i_deviceId, uint8_t *io_data);

    enum msg_type
    {
        MSG_WRITE_FRU_DATA, // async message - no reply
        MSG_READ_FRU_DATA,  // sync message  - has reply
        // Used to check range. Leave as last.
        MSG_LAST_TYPE = MSG_READ_FRU_DATA,
    };
    enum record_info
    {
        MAX_RECORD_SIZE = 256,
    };
}


class IpmiFRU
{
  public:

    /**
     * Thread start routine for the resource provider
     * @param[in] void*, unused
     */
    static void* start(void* unused);

    /**
     * Default constructor
     */
    IpmiFRU(void);

    /**
     * Destructor
     */
    ~IpmiFRU(void);

    /**
     * @brief Get the message queue associated with this FRU
     * @param[in] void
     * @return, a msg_q_t which is the message queue
     */
    inline msg_q_t msgQueue(void) const
        { return iv_msgQ; }

  private:

    /**
     * Entry point for the fru ipmi thread
     */
    void execute(void);

    /**
     * @brief Handle a message with fru inventory data; msg is async
     * @param[in] i_msg
     */
    void sendWriteFruData(msg_t *i_msg);

    /**
     * @brief Handle a message with fru inventory data; msg is sync
     * #param[in] i_msg
     */
    void sendReadFruData(msg_t *i_msg);


    /**
     * ipmi fru msg queue
     */
    msg_q_t iv_msgQ;

    // Disallow copying this class.
    IpmiFRU& operator=(const IpmiFRU&);
    IpmiFRU(const IpmiFRU&);
};

#endif
