/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/dump/dumpif.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2019                        */
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
#ifndef __DUMPIF_H
#define __DUMPIF_H

#include <hdat/hdat.H>

/** @file  dumpif.H
 *  @brief Provides the external interfaces for dump.
 *            - copy dump data from src to destination
 *            - Send Mbox Msg for dump status
 */

namespace DUMP
{

    /**
     * @brief DUMP Message Types 
     */

    enum DUMP_MSG_TYPE
    {
        DUMP_MSG_START_MSG_TYPE = 0x000000B1,
        DUMP_MSG_END_MSG_TYPE = 0x000000B2,
        DUMP_MSG_ERROR_MSG_TYPE = 0x000000B3,

    };

    // The following are #defines  needed for Dump Testing.. These are the
    // default memory locations for MDST, MDDT, MDRT when running withoutPHYPab
    // The data range is defined in vmmconst.h so this test space is saved.

    /* Chunk of physical memory used for Dump Source Table */
    #define DUMP_TEST_SRC_MEM_ADDR  DUMP_TEST_MEMORY_ADDR
    #define DUMP_TEST_SRC_MEM_SIZE  MEGABYTE

    /* Chunk of physical memory used for Dump Destination Table */
    #define DUMP_TEST_DST_MEM_ADDR (DUMP_TEST_SRC_MEM_ADDR +  \
    DUMP_TEST_SRC_MEM_SIZE)


    #define DUMP_TEST_DST_MEM_SIZE  MEGABYTE

    /* Chunk of physical memory used for Dump Results Table */
    #define DUMP_TEST_RESULTS_MEM_ADDR (DUMP_TEST_DST_MEM_ADDR + \
    DUMP_TEST_DST_MEM_SIZE)


    #define DUMP_TEST_RESULTS_MEM_SIZE   MEGABYTE

    // Data location where the src, destination tables point to. (The actual
    // data)
    #define DUMP_TEST_SRC_DATA_AREA (DUMP_TEST_RESULTS_MEM_ADDR +   \
    DUMP_TEST_RESULTS_MEM_SIZE)


    #define DUMP_TEST_DST_DATA_AREA (DUMP_TEST_SRC_DATA_AREA + \
    DUMP_TEST_DATA_SIZE)

    #define DUMP_TEST_DATA_SIZE           MEGABYTE

    // default enums to point out the start and end of the DUMP Tables in memory
    #define DUMP_TEST_TABLE_START DUMP_TEST_SRC_MEM_ADDR
    #define DUMP_TEST_TABLE_SIZE (DUMP_TEST_SRC_MEM_SIZE +   \
    DUMP_TEST_DST_MEM_SIZE + DUMP_TEST_RESULTS_MEM_SIZE)


    #define DUMP_TEST_TABLE_END (DUMP_TEST_TABLE_START + DUMP_TEST_TABLE_SIZE)

    // In addition to the dump table locations we have scratch data area that is
    // used to put the SRC data that the MDST will point to.

    // This is the size of all the Data used for Dump testing
    #define DUMP_TEST_ALL_SIZE  (DUMP_TEST_TABLE_SIZE + (2*MEGABYTE))

    // This is the ending address of test Data area
    #define DUMP_TEST_ALL_END  (DUMP_TEST_TABLE_START + DUMP_TEST_ALL_SIZE)


    //These structures are defined in the HDAT spec
    //The MDST and MDDT have this format.
    struct dumpEntry
    {
        uint64_t dataAddr;
        uint16_t data_type;    // Used by payload
        uint16_t reserved;
        uint32_t dataSize;
    } PACKED;

    //The MDRT has this format.
    struct resultsEntry
    {
        uint64_t srcAddr;
        uint64_t destAddr;
        uint64_t dataSize;
        uint64_t reserved;
    } PACKED;


    // Processor Dump Area table format
    struct procDumpAreaEntry
    {
        uint32_t threadRegSize;        // Architected reg data size per thread
        uint8_t  threadRegVersion;     // Data format version
        uint8_t  reserved1[11];        // Reserved
        uint64_t dstArrayAddr;         // Hypervisor passed destination addresss
        uint8_t  reserved2[4];         // Reserved
        uint32_t dstArraySize;         // Hypervisor passed destination size
        uint64_t capArrayAddr;         // Actual destination address (filled by HB)
        uint8_t  reserved3[4];         // Reserved
        uint32_t capArraySize;         // Actual destination size (filled by HB)
    } PACKED;

    // Host formatted architected register data content (as per HDAT spec)
    struct hostArchRegDataHdr
    {
        uint32_t pir;
        uint8_t  coreState;
        uint8_t  reserved[3];
        HDAT::hdatHDIFDataArray_t iv_regArrayHdr;
    } PACKED;

    #define DUMP_ARCH_REG_TYPE_GPR	0x01
    #define DUMP_ARCH_REG_TYPE_SPR	0x02

    // Architected register data content entries
    struct hostArchRegDataEntry
    {
        uint32_t regType;
        uint32_t regNum;
        uint64_t regVal;
    } PACKED;

    // Structure version used to share SPR/GPR register data between
    // SBE and HB
    #define REG_DUMP_SBE_HB_STRUCT_VER 0x1

    // Structure version used to share SPR/GPR register data between
    // HB and OPAL
    #define REG_DUMP_HDAT_STRUCT_VER 0x1

    /* Processor architected dump header. This header is per processor*/
    struct sbeArchRegDumpProcHdr_t
    {
        uint8_t  ownerId;        /* FSP or SBE */
        uint8_t  version;        /* Interface version number*/
        uint16_t core_cnt;       /* Actual number of core whose register  data will be obtained */
        uint16_t thread_cnt;     /* Total number of thread whose register data will be obtained */
        uint16_t reg_cnt;        /* Max number of registers per thread */
    } PACKED;   //8Bytes

    // SBE formatted architected registers data
    // (Common structure between SBE and Hostboot)
    struct sbeArchRegDumpThreadHdr_t
    {
        uint32_t  pir;         // PIR value of thread corresponding to register
        uint32_t  coreState:8; // State of core in which this thread is present
        uint32_t  reserved:24;
    } PACKED;

    /**
     *  @brief Defines the structure for storing the SPR/GPR register data
     *
     *  @var isRegDataValid   :'1'- Variable regVal will contain valid register 
     *                         '0'- Variable regVal will contain fapiRC value
     *
     *  @var isLastReg        :'1' - Data is collected for the last SPR/GPR register
     *                         '0' - otherwise.
     *
     *  @var isFfdcPresent    :'1' - Failing FAPI FFDC is shared
     *                         '0' - Failing FFDC is not present
     *
     *  @var reserved0        :Reserved for future use and padding
     *
     *  @var regType          :Indicates type of register(SPR/GPR)
     *
     *  @var reserved1        :Reserved for future use and padding
     *
     *  @var regNum           :Address of the SPR/GPR register
     *
     *  @var regVal           :if isRegDataValid is '0'  - Valid Register value
     *                            isRegDataValid is '!=0'- fapiRC value.
     */
    struct sbeArchRegDumpEntries_t
    {
        uint64_t isRegDataValid:1;
        uint64_t isLastReg:1;
        uint64_t isFfdcPresent:1;
        uint64_t reseverd0:5;
        uint64_t regType:8;
        uint64_t reserved1:16;
        uint64_t regNum:32;
        uint64_t regVal;
    } PACKED;

    /**
    * @brief This function copies the architected register data content
    * from SBE reserved memory to hypervisor allocated memory
    *
    * @param[in]   void
    *
    * @return  errlHndl_t
    */
    errlHndl_t copyArchitectedRegs(void);

    /**
     * @brief This function is a wrapper function that calls
     *   getHostDataPtrs to get the MDDT, MDST, MDRT pointers
     *   and then passes those values to the copySrcToDest
     *   routine that performs the copy
     *
     * @param[in]   void
     *
     * @return  errlHndl_t
     */
     errlHndl_t doDumpCollect(void);

     /**
      * @brief This function copies the data and sizes retrieved from the
      * MDST(source table) to the addresses indicated by the MDDT(destination
      * table).   Each write is then logged in the MDRT (results table) with
      * source addr, destination addr and size
      *
      * @param[in]   srcTableEntry     Ptr to the first MDST entry
      * @param[in]   srcTableSize      Size of the entire MDST
      *
      * @param[in]   destTableAddr     Ptr to the first MDDT entry
      * @param[in]   destTableSize     Size of the entire MDDT
      *
      * @param[in]   resultsTableAddr  Ptr to the first MDRT entry
      * @param[in]   resultsTableSize  Size of the entire MDRT
      *
      * @return  errlHndl_t
      */
     errlHndl_t copySrcToDest(dumpEntry *srcTableEntry, uint64_t srcTableSize,
                              dumpEntry *destTableEntry, uint64_t destTableSize,
                              resultsEntry *resultsTableEntry,
                              uint64_t resultsTableSize);

    /**
     * @brief This function handles sending the mailbox message to the Fsp to
     *      notify of Dump Status.  Start, error or complete.  If Error or
     *      complete types are requested, the dump results table is passed
     *      to the FSP.
     *
     * @param[in] i_type - The type of DUMP msg being written.
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the error
     *      log.
     */
    errlHndl_t sendMboxMsg (DUMP_MSG_TYPE i_type);



} // end of namespace


#endif
