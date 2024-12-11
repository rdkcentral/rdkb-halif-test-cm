/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:*
* Copyright 2023 RDK Management
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cm_hal.h"


INT cm_hal_InitDB(void)
{
  /*TODO: Implement Me!*/
  return (INT)0;
}

INT docsis_InitDS(void)
{
  /*TODO: Implement Me!*/
  return (INT)0;
}

INT docsis_InitUS(void)
{
  /*TODO: Implement Me!*/
  return (INT)0;
}

INT docsis_getCMStatus(CHAR* cm_status)
{
  /*TODO: Implement Me!*/
  (void)cm_status;
  return (INT)0;
}

INT docsis_GetDSChannel(PCMMGMT_CM_DS_CHANNEL* ppinfo)
{
  /*TODO: Implement Me!*/
  (void)ppinfo;
  return (INT)0;
}

INT docsis_GetUsStatus(USHORT i, PCMMGMT_CM_US_CHANNEL pinfo)
{
  /*TODO: Implement Me!*/
  (void)i;
  (void)pinfo;
  return (INT)0;
}

INT docsis_GetUSChannel(PCMMGMT_CM_US_CHANNEL* ppinfo)
{
  /*TODO: Implement Me!*/
  (void)ppinfo;
  return (INT)0;
}

INT docsis_GetDOCSISInfo(PCMMGMT_CM_DOCSIS_INFO pinfo)
{
  /*TODO: Implement Me!*/
  (void)pinfo;
  return (INT)0;
}

INT docsis_GetNumOfActiveTxChannels(ULONG* cnt)
{
  /*TODO: Implement Me!*/
  (void)cnt;
  return (INT)0;
}

INT docsis_GetNumOfActiveRxChannels(ULONG* cnt)
{
  /*TODO: Implement Me!*/
  (void)cnt;
  return (INT)0;
}

INT docsis_GetErrorCodewords(PCMMGMT_CM_ERROR_CODEWORDS* ppinfo)
{
  /*TODO: Implement Me!*/
  (void)ppinfo;
  return (INT)0;
}

INT docsis_GetMddIpModeOverride(CHAR* pValue)
{
  /*TODO: Implement Me!*/
  (void)pValue;
  return (INT)0;
}

INT docsis_SetMddIpModeOverride(CHAR* pValue)
{
  /*TODO: Implement Me!*/
  (void)pValue;
  return (INT)0;
}

UINT8 docsis_GetUSChannelId(void)
{
  /*TODO: Implement Me!*/
  return (UINT8)0;
}

void docsis_SetUSChannelId(INT index)
{
  /*TODO: Implement Me!*/
  (void)index;
}

ULONG docsis_GetDownFreq(void)
{
  /*TODO: Implement Me!*/
  return (ULONG)0;
}

void docsis_SetStartFreq(ULONG value)
{
  /*TODO: Implement Me!*/
  (void)value;
}

INT docsis_GetDocsisEventLogItems(CMMGMT_CM_EventLogEntry_t* entryArray, INT len)
{
  /*TODO: Implement Me!*/
  (void)entryArray;
  (void)len;
  return (INT)0;
}

INT docsis_ClearDocsisEventLog(void)
{
  /*TODO: Implement Me!*/
  return (INT)0;
}

INT cm_hal_GetDHCPInfo(PCMMGMT_CM_DHCP_INFO pInfo)
{
  /*TODO: Implement Me!*/
  (void)pInfo;
  return (INT)0;
}

INT cm_hal_GetIPv6DHCPInfo(PCMMGMT_CM_IPV6DHCP_INFO pInfo)
{
  /*TODO: Implement Me!*/
  (void)pInfo;
  return (INT)0;
}

INT cm_hal_GetCPEList(PCMMGMT_DML_CPE_LIST* ppCPEList, ULONG* InstanceNum, CHAR* LanMode)
{
  /*TODO: Implement Me!*/
  (void)ppCPEList;
  (void)InstanceNum;
  (void)LanMode;
  return (INT)0;
}

INT cm_hal_GetMarket(CHAR* market)
{
  /*TODO: Implement Me!*/
  (void)market;
  return (INT)0;
}

INT cm_hal_Set_HTTP_Download_Url(char* pHttpUrl, char* pfilename)
{
  /*TODO: Implement Me!*/
  (void)pHttpUrl;
  (void)pfilename;
  return (INT)0;
}

INT cm_hal_Get_HTTP_Download_Url(char* pHttpUrl, char* pfilename)
{
  /*TODO: Implement Me!*/
  (void)pHttpUrl;
  (void)pfilename;
  return (INT)0;
}

INT cm_hal_Set_HTTP_Download_Interface(unsigned int interface)
{
  /*TODO: Implement Me!*/
  (void)interface;
  return (INT)0;
}

INT cm_hal_Get_HTTP_Download_Interface(unsigned int* pinterface)
{
  /*TODO: Implement Me!*/
  (void)pinterface;
  return (INT)0;
}

INT cm_hal_HTTP_Download(void)
{
  /*TODO: Implement Me!*/
  return (INT)0;
}

INT cm_hal_Get_HTTP_Download_Status(void)
{
  /*TODO: Implement Me!*/
  return (INT)0;
}

INT cm_hal_Reboot_Ready(ULONG* pValue)
{
  /*TODO: Implement Me!*/
  (void)pValue;
  return (INT)0;
}

INT cm_hal_HTTP_Download_Reboot_Now(void)
{
  /*TODO: Implement Me!*/
  return (INT)0;
}

INT cm_hal_FWupdateAndFactoryReset(char* pUrl, char* pImagename)
{
  /*TODO: Implement Me!*/
  (void)pUrl;
  (void)pImagename;
  return (INT)0;
}

INT cm_hal_ReinitMac(void)
{
  /*TODO: Implement Me!*/
  return (INT)0;
}

INT docsis_GetProvIpType(CHAR* pValue)
{
  /*TODO: Implement Me!*/
  (void)pValue;
  return (INT)0;
}

INT docsis_GetCert(CHAR* pCert)
{
  /*TODO: Implement Me!*/
  (void)pCert;
  return (INT)0;
}

INT docsis_GetCertStatus(ULONG* pVal)
{
  /*TODO: Implement Me!*/
  (void)pVal;
  return (INT)0;
}

INT cm_hal_Get_CableModemResetCount(ULONG* resetcnt)
{
  /*TODO: Implement Me!*/
  (void)resetcnt;
  return (INT)0;
}

INT cm_hal_Get_LocalResetCount(ULONG* resetcnt)
{
  /*TODO: Implement Me!*/
  (void)resetcnt;
  return (INT)0;
}

INT cm_hal_Get_DocsisResetCount(ULONG* resetcnt)
{
  /*TODO: Implement Me!*/
  (void)resetcnt;
  return (INT)0;
}

INT cm_hal_Get_ErouterResetCount(ULONG* resetcnt)
{
  /*TODO: Implement Me!*/
  (void)resetcnt;
  return (INT)0;
}

INT cm_hal_HTTP_LED_Flash(BOOLEAN LedFlash)
{
  /*TODO: Implement Me!*/
  (void)LedFlash;
  return (INT)0;
}

INT docsis_GetDsOfdmChanTable(PDOCSIF31_CM_DS_OFDM_CHAN* ppinfo, int* output_NumberOfEntries)
{
  /*TODO: Implement Me!*/
  (void)ppinfo;
  (void)output_NumberOfEntries;
  return (INT)0;
}

INT docsis_GetUsOfdmaChanTable(PDOCSIF31_CM_US_OFDMA_CHAN* ppinfo, int* output_NumberOfEntries)
{
  /*TODO: Implement Me!*/
  (void)ppinfo;
  (void)output_NumberOfEntries;
  return (INT)0;
}

INT docsis_GetStatusOfdmaUsTable(PDOCSIF31_CMSTATUSOFDMA_US* ppinfo, int* output_NumberOfEntries)
{
  /*TODO: Implement Me!*/
  (void)ppinfo;
  (void)output_NumberOfEntries;
  return (INT)0;
}

INT docsis_LLDgetEnableStatus(void)
{
  /*TODO: Implement Me!*/
  return (INT)0;
}

INT cm_hal_snmpv3_kickstart_initialize(snmpv3_kickstart_table_t* pKickstart_Table)
{
  /*TODO: Implement Me!*/
  (void)pKickstart_Table;
  return (INT)0;
}

INT docsis_IsEnergyDetected(BOOLEAN* pEnergyDetected)
{
  /*TODO: Implement Me!*/
  (void)pEnergyDetected;
  return (INT)0;
}

INT cm_hal_set_ReinitMacThreshold(ULONG value)
{
  /*TODO: Implement Me!*/
  (void)value;
  return (INT)0;
}

INT cm_hal_get_ReinitMacThreshold(ULONG* pValue)
{
  /*TODO: Implement Me!*/
  (void)pValue;
  return (INT)0;
}

INT cm_hal_get_DiplexerSettings(CM_DIPLEXER_SETTINGS* pValue)
{
  /*TODO: Implement Me!*/
  (void)pValue;
  return (INT)0;
}


