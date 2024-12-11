/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:*
* Copyright 2024 RDK Management
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License atF
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
 
/**
* @file test_l1_cm_hal.c
* @page cm_hal Level 1 Tests
*
* ## Module's Role
* This module includes Level 1 functional tests (success and failure scenarios).
* This is to ensure that the cm_hal APIs meet the requirements across all vendors.
*
* **Pre-Conditions:**  None@n
* **Dependencies:** None@n
*
* Ref to API Definition specification documentation : [cm-hal_halSpec.md](../../docs/pages/cm-hal_halSpec.md)
*/
 
#include <ut.h>
#include <ut_log.h>
#include <ut_kvp_profile.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "cm_hal.h"

static int gTestGroup = 1;
static int gTestID = 1;
#define MAX_STRING_LENGTH 250

/**
* @brief This test verifies the successful initialization of the database by cm_hal_InitDB function
*
* In this test, the cm_hal_InitDB function is called and the return value is checked. The test is designed to ensure that the database initialization is successful and the function returns the expected value.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 001@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the cm_hal_InitDB function | No input data required for this function | The return value should be RETURN_OK | Should be successfull |
*/
void test_l1_cm_hal_positive1_cm_hal_InitDB(void)
{
    gTestID = 1 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = cm_hal_InitDB();

    UT_LOG_DEBUG("Invoking cm_hal_InitDB()");

    UT_ASSERT_EQUAL(ret, RETURN_OK);

    if (ret != RETURN_OK) {
        UT_LOG_ERROR("cm_hal_InitDB() failed");
    }
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the successful initialization of the Downstream (DS) in DOCSIS mode.
*
* In this test, the function docsis_InitDS() is invoked without any input parameters. The test checks if the function returns the expected value, indicating successful initialization of the DS in DOCSIS mode.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 002@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_InitDS with no input parameters | No input parameters | The return value should be RETURN_OK | Should be successful |
*/
void test_l1_cm_hal_positive1_docsis_InitDS(void)
{
    gTestID = 2 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret_val;

    UT_LOG_DEBUG("Invoking docsis_InitDS with no input parameters");
    ret_val = docsis_InitDS();

    UT_ASSERT_EQUAL(ret_val, RETURN_OK);

    if (ret_val != RETURN_OK) {
        UT_LOG_ERROR("docsis_InitDS failed with return value: %d\n", ret_val);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the successful initialization of the upstream channel in DOCSIS mode.
*
* In this test, the docsis_InitUS function is invoked without any input parameters. The test verifies that the function returns the expected status code, indicating successful initialization of the upstream channel in DOCSIS mode.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 003@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_InitUS with no input parameters | No input parameters | The function should return RETURN_OK | Should be successfull |
*/
void test_l1_cm_hal_positive1_docsis_InitUS(void)
{
    gTestID = 3 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int status;

    UT_LOG_DEBUG("Invoking docsis_InitUS with no input parameters");
    status = docsis_InitUS();

    UT_ASSERT_EQUAL(status, RETURN_OK);

    if (status != RETURN_OK) {
        UT_LOG_ERROR("docsis_InitUS failed with status: %d\n", status);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the docsis_getCMStatus API
*
* This test invokes the docsis_getCMStatus API with a valid cm_status buffer and checks if the return value is as expected.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 004@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_getCMStatus with valid cm_status buffer | cm_status = valid buffer | Return value should be RETURN_OK | Should be successful |
*/
void test_l1_cm_hal_positive1_docsis_getCMStatus(void)
{
    gTestID = 4 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR cm_status[40];
    int ret_val;

    UT_LOG_DEBUG("Invoking docsis_getCMStatus with valid cm_status buffer");
    ret_val = docsis_getCMStatus(cm_status);

    UT_LOG_DEBUG("docsis_getCMStatus returned %d, cm_status: %s", ret_val, cm_status);
    UT_ASSERT_EQUAL(ret_val, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the docsis_getCMStatus API when invoked with NULL cm_status buffer.
*
* In this test, the docsis_getCMStatus API is invoked with a NULL cm_status buffer and the return value is checked to be RETURN_ERR. This is to ensure that the API handles error scenarios correctly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 005@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_getCMStatus with NULL cm_status buffer | cm_status = NULL | The return value should be RETURN_ERR | The API should handle this error scenario correctly |
*/
void test_l1_cm_hal_negative1_docsis_getCMStatus(void)
{
    gTestID = 5 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR *cm_status = NULL;
    int ret_val;

    UT_LOG_DEBUG("Invoking docsis_getCMStatus with NULL cm_status buffer");
    ret_val = docsis_getCMStatus(cm_status);

    UT_LOG_DEBUG("docsis_getCMStatus returned %d", ret_val);
    UT_ASSERT_EQUAL(ret_val, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of the docsis_GetDSChannel API
*
* This test invokes the docsis_GetDSChannel API with a valid PCMMGMT_CM_DS_CHANNEL pointer and checks if the return value is as expected and the data in the structure is within the expected range.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 006@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetDSChannel with valid PCMMGMT_CM_DS_CHANNEL pointer | pinfo = valid pointer | Return value should be RETURN_OK | Should be successful |
* | 02 | Check if the ChannelID is greater than 0 | ChannelID = pinfo->ChannelID | ChannelID > 0 | Should be successful |
* | 03 | Check if the Frequency is within the range 54 to 1002 | Frequency = atoi(pinfo->Frequency) | 54 <= Frequency <= 1002 | Should be successful |
* | 04 | Check if the PowerLevel is within the range -15 to 15 | PowerLevel = atof(pinfo->PowerLevel) | -15 <= PowerLevel <= 15 | Should be successful |
* | 05 | Check if the SNRLevel is within the range 20 to 40 | SNRLevel = atoi(pinfo->SNRLevel) | 20 <= SNRLevel <= 40 | Should be successful |
* | 06 | Check if the Octets is greater than or equal to 0 | Octets = pinfo->Octets | Octets >= 0 | Should be successful |
* | 07 | Check if the Correcteds is greater than or equal to 0 | Correcteds = pinfo->Correcteds | Correcteds >= 0 | Should be successful |
* | 08 | Check if the Uncorrectables is greater than or equal to 0 | Uncorrectables = pinfo->Uncorrectables | Uncorrectables >= 0 | Should be successful |
* | 09 | Check if the LockStatus is either "Locked", "Unlocked" or "Not Available" | LockStatus = pinfo->LockStatus | LockStatus == "Locked" or "Unlocked" or "Not Available" | Should be successful |
*/
void test_l1_cm_hal_positive1_docsis_GetDSChannel(void)
{
    gTestID = 6;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PCMMGMT_CM_DS_CHANNEL pinfo = NULL;
    int ret = docsis_GetDSChannel(&pinfo);

    UT_LOG_DEBUG("Invoking docsis_GetDSChannel with valid PCMMGMT_CM_DS_CHANNEL pointer");

    UT_ASSERT_EQUAL(ret, RETURN_OK);    
    if (ret == RETURN_OK) {
        if (pinfo != NULL) {
            UT_LOG_DEBUG("docsis_GetDSChannel returned OK. Verifying the values in the structure pinfo");
            
            UT_LOG_DEBUG("pinfo->ChannelID is : %lu", pinfo->ChannelID);
            UT_LOG_DEBUG("pinfo->Frequency is : %s", pinfo->Frequency);
            UT_LOG_DEBUG("pinfo->PowerLevel is : %s", pinfo->PowerLevel);
            UT_LOG_DEBUG("pinfo->SNRLevel is : %s", pinfo->SNRLevel);
            UT_LOG_DEBUG("pinfo->Modulation is : %s", pinfo->Modulation);
            UT_LOG_DEBUG("pinfo->Octets is : %lu", pinfo->Octets);
            UT_LOG_DEBUG("pinfo->Correcteds is : %lu", pinfo->Correcteds);
            UT_LOG_DEBUG("pinfo->Uncorrectables is : %lu", pinfo->Uncorrectables);
            UT_LOG_DEBUG("pinfo->LockStatus is : %s", pinfo->LockStatus);

            if(pinfo->ChannelID > 0)
            {
                UT_LOG("Channel ID is %lu which is a valid value", pinfo->ChannelID);
                UT_PASS("Channel ID validation success");
            }
            else
            {
                UT_LOG("Channel ID is %lu which is an invalid value", pinfo->ChannelID);
                UT_FAIL("Channel ID validation failed");
            }
            
            if(pinfo->Frequency != NULL && atoi(pinfo->Frequency) >= 54 && atoi(pinfo->Frequency) <= 1002)
            {
                UT_LOG("Frequency is %s which is a valid value", pinfo->Frequency);
                UT_PASS("Frequency validation success");
            }
            else
            {
                UT_LOG("Frequency is %s which is an invalid value", pinfo->Frequency);
                UT_FAIL("Frequency validation failed");
            }
            
            if(pinfo->PowerLevel != NULL && atof(pinfo->PowerLevel) >= -15 && atof(pinfo->PowerLevel) <= 15)
            {
                UT_LOG("PowerLevel is %s which is a valid value", pinfo->PowerLevel);
                UT_PASS("PowerLevel validation success");
            }
            else
            {
                UT_LOG("PowerLevel is %s which is an invalid value", pinfo->PowerLevel);
                UT_FAIL("PowerLevel validation failed");
            }
            
            if(pinfo->SNRLevel != NULL && atoi(pinfo->SNRLevel) >= 20 && atoi(pinfo->SNRLevel) <= 40)
            {
                UT_LOG("SNRLevel is %s which is a valid value", pinfo->SNRLevel);
                UT_PASS("SNRLevel validation success");
            }
            else
            {
                UT_LOG("SNRLevel is %s which is an invalid value", pinfo->SNRLevel);
                UT_FAIL("SNRLevel validation failed");
            }
            
            if(pinfo->Octets >= 0)
            {
                UT_LOG("Octets is %lu which is a valid value", pinfo->Octets);
                UT_PASS("Octets validation success");
            }
            else
            {
                UT_LOG("Octets is %lu which is an invalid value", pinfo->Octets);
                UT_FAIL("Octets validation failed");
            }
            
            if(pinfo->Correcteds >= 0)
            {
                UT_LOG("Correcteds is %lu which is a valid value", pinfo->Correcteds);
                UT_PASS("Correcteds validation success");
            }
            else
            {
                UT_LOG("Correcteds is %lu which is an invalid value", pinfo->Correcteds);
                UT_FAIL("Correcteds validation failed");
            }
            
            if(pinfo->Uncorrectables >= 0)
            {
                UT_LOG("Uncorrectables is %lu which is a valid value", pinfo->Uncorrectables);
                UT_PASS("Uncorrectables validation success");
            }
            else
            {
                UT_LOG("Uncorrectables is %lu which is an invalid value", pinfo->Uncorrectables);
                UT_FAIL("Uncorrectables validation failed");
            }
            
            if(pinfo->LockStatus != NULL && 
               (strcmp(pinfo->LockStatus, "Locked") == 0 || 
                strcmp(pinfo->LockStatus, "Unlocked") == 0 || 
                strcmp(pinfo->LockStatus, "Not Available") == 0))
            {
                UT_LOG("LockStatus is %s which is a valid value", pinfo->LockStatus);
                UT_PASS("LockStatus validation success");
            }
            else
            {
                UT_LOG("LockStatus is %s which is an invalid value", pinfo->LockStatus);
                UT_FAIL("LockStatus validation failed");
            }
            
            free(pinfo);  // Free memory only if pinfo is not NULL
        } else {
            UT_LOG_ERROR("docsis_GetDSChannel returned NULL pointer");
            UT_FAIL("NULL pointer returned from docsis_GetDSChannel");
        }
    } else {
        UT_LOG_ERROR("docsis_GetDSChannel returned error");
    }    
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the docsis_GetDSChannel API when invoked with NULL PCMMGMT_CM_DS_CHANNEL pointer.
*
* In this test, the docsis_GetDSChannel API is invoked with a NULL PCMMGMT_CM_DS_CHANNEL pointer. The API is expected to return an error. This test is important to ensure the robustness of the API against invalid inputs.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 007@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetDSChannel API with NULL PCMMGMT_CM_DS_CHANNEL pointer | pinfo = NULL | The API should return an error | The API is expected to handle invalid inputs gracefully |
*/
void test_l1_cm_hal_negative1_docsis_GetDSChannel(void)
{
    gTestID = 7 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = docsis_GetDSChannel(NULL);

    UT_LOG_DEBUG("Invoking docsis_GetDSChannel with NULL PCMMGMT_CM_DS_CHANNEL pointer");
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    if (ret != RETURN_ERR) {
        UT_LOG_ERROR("docsis_GetDSChannel should have failed but returned with status %d\n", ret);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of the docsis_GetUsStatus API
*
* This test invokes the docsis_GetUsStatus API with valid parameters and checks if the return value is as expected and the output structure is filled correctly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 008@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetUsStatus with valid parameters | index = 1, pinfo = &info | The return value should be RETURN_OK | Should be successful |
* | 02 | Check the values in the output structure | info.Frequency, info.PowerLevel, info.LockStatus | The values should be within the expected range or match the expected values | Should be successful |
*/
void test_l1_cm_hal_positive1_docsis_GetUsStatus(void) 
{
    gTestID = 8;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PCMMGMT_CM_US_CHANNEL pinfo;
    UT_LOG_DEBUG("Invoking docsis_GetUsStatus with valid index and valid pinfo buffer");
    int ret = docsis_GetUsStatus(1, pinfo);

    UT_ASSERT_EQUAL(ret, RETURN_OK);

    if (ret == RETURN_OK) {
        // Add NULL check before dereferencing
        if (pinfo != NULL) {
            UT_LOG_DEBUG("docsis_GetUsStatus returned OK. Verifying the values in the structure pinfo");
            
            UT_LOG_DEBUG("ChannelID is : %lu", pinfo->ChannelID);
            
            // Add NULL checks for string members before access
            if (pinfo->Frequency != NULL) {
                UT_LOG_DEBUG("Frequency is : %s", pinfo->Frequency);
                int frequency = atoi(pinfo->Frequency);
                if(frequency >= 5 && frequency <= 204) {
                    UT_LOG("Frequency is %d which is a valid value", frequency);
                    UT_PASS("Frequency validation success");
                } else {
                    UT_LOG("Frequency is %d which is an invalid value", frequency);
                    UT_FAIL("Frequency validation failed");
                }
            } else {
                UT_LOG_ERROR("Frequency is NULL");
                UT_FAIL("Frequency validation failed - NULL value");
            }

            if (pinfo->PowerLevel != NULL) {
                UT_LOG_DEBUG("PowerLevel is : %s", pinfo->PowerLevel);
                int powerLevel = atoi(pinfo->PowerLevel);
                if(powerLevel >= 45 && powerLevel <= 61) {
                    UT_LOG("powerLevel is %d which is a valid value", powerLevel);
                    UT_PASS("powerLevel validation success");
                } else {
                    UT_LOG("powerLevel is %d which is an invalid value", powerLevel);
                    UT_FAIL("powerLevel validation failed");
                }
            } else {
                UT_LOG_ERROR("PowerLevel is NULL");
                UT_FAIL("PowerLevel validation failed - NULL value");
            }

            if (pinfo->ChannelType != NULL) {
                UT_LOG_DEBUG("ChannelType is : %s", pinfo->ChannelType);
            } else {
                UT_LOG_ERROR("ChannelType is NULL");
            }

            if (pinfo->SymbolRate != NULL) {
                UT_LOG_DEBUG("SymbolRate is : %s", pinfo->SymbolRate);
            } else {
                UT_LOG_ERROR("SymbolRate is NULL");
            }

            if (pinfo->Modulation != NULL) {
                UT_LOG_DEBUG("Modulation is : %s", pinfo->Modulation);
            } else {
                UT_LOG_ERROR("Modulation is NULL");
            }

            if (pinfo->LockStatus != NULL) {
                UT_LOG_DEBUG("LockStatus is : %s", pinfo->LockStatus);
                if(strcmp(pinfo->LockStatus, "Locked") == 0 || 
                   strcmp(pinfo->LockStatus, "Unlocked") == 0 || 
                   strcmp(pinfo->LockStatus, "Not Available") == 0) {
                    UT_LOG("LockStatus is %s which is a valid value", pinfo->LockStatus);
                    UT_PASS("LockStatus validation success");
                } else {
                    UT_LOG("LockStatus is %s which is an invalid value", pinfo->LockStatus);
                    UT_FAIL("LockStatus validation failed");
                }
            } else {
                UT_LOG_ERROR("LockStatus is NULL");
                UT_FAIL("LockStatus validation failed - NULL value");
            }
        } else {
            UT_LOG_ERROR("pinfo pointer is NULL after successful API return");
            UT_FAIL("NULL pointer validation failed");
        }
    } else {
        UT_LOG_ERROR("docsis_GetUsStatus returned error");
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the error handling of the docsis_GetUsStatus function
*
* This test invokes the docsis_GetUsStatus function with a NULL pinfo buffer to test its error handling capability. The function is expected to return an error in this case.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 009@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetUsStatus with NULL pinfo buffer | channel = 1, pinfo = NULL | The function should return an error | The function should handle NULL pointers correctly |
*/
void test_l1_cm_hal_negative1_docsis_GetUsStatus(void)
{
    gTestID = 9 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = docsis_GetUsStatus(1, NULL);

    UT_LOG_DEBUG("Invoking docsis_GetUsStatus with NULL pinfo buffer");
    UT_LOG_DEBUG("Return value of docsis_GetUsStatus : %d" , ret);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    if (ret != RETURN_ERR) {
        UT_LOG_ERROR("docsis_GetUsStatus did not return error as expected");
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the functionality of the docsis_GetUSChannel API
*
* This test is designed to verify the correct operation of the docsis_GetUSChannel API when provided with valid input. The API is expected to return the correct upstream channel information.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 010@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Allocate memory for PCMMGMT_CM_US_CHANNEL and Invoke docsis_GetUSChannel API with valid input | pinfo = allocated memory | docsis_GetUSChannel should return RETURN_OK | Should be successful |
* | 02 | Check the returned values of Frequency, PowerLevel and LockStatus | Frequency = pinfo->Frequency, PowerLevel = pinfo->PowerLevel, LockStatus = pinfo->LockStatus | Frequency should be between 5 and 204, PowerLevel should be between 45 and 61, LockStatus should be either "Locked", "Unlocked" or "Not Available" | Should be successful |
*/
void test_l1_cm_hal_positive1_docsis_GetUSChannel(void)
{
    gTestID = 10;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PCMMGMT_CM_US_CHANNEL pinfo = NULL;

    UT_LOG_DEBUG("Invoking docsis_GetUSChannel with valid pointer");
    int ret = docsis_GetUSChannel(&pinfo);

    UT_ASSERT_EQUAL(ret, RETURN_OK);

    if (ret == RETURN_OK) {
        if (pinfo != NULL) {
            UT_LOG_DEBUG("docsis_GetUSChannel returned OK. Checking returned values...");
            
            UT_LOG_DEBUG("pinfo->ChannelID is : %lu", pinfo->ChannelID);
            UT_LOG_DEBUG("pinfo->Frequency is : %s", pinfo->Frequency);
            UT_LOG_DEBUG("pinfo->PowerLevel is : %s", pinfo->PowerLevel);
            UT_LOG_DEBUG("pinfo->ChannelType is : %s", pinfo->ChannelType);
            UT_LOG_DEBUG("pinfo->SymbolRate is : %s", pinfo->SymbolRate);
            UT_LOG_DEBUG("pinfo->Modulation is : %s", pinfo->Modulation);
            UT_LOG_DEBUG("pinfo->LockStatus is : %s", pinfo->LockStatus);

            if (pinfo->Frequency != NULL) {
                int freq = atoi(pinfo->Frequency);
                if(freq >= 5 && freq <= 204)
                {
                    UT_LOG("Frequency is %d which is a valid value", freq);
                    UT_PASS("Frequency validation success");
                }
                else
                {
                    UT_LOG("Frequency is %d which is an invalid value", freq);
                    UT_FAIL("Frequency validation failed");
                }
            } else {
                UT_LOG_ERROR("Frequency is NULL");
                UT_FAIL("Frequency validation failed - NULL value");
            }

            if (pinfo->PowerLevel != NULL) {
                int power = atoi(pinfo->PowerLevel);
                if(power >= 45 && power <= 61)
                {
                    UT_LOG("powerLevel is %d which is a valid value", power);
                    UT_PASS("powerLevel validation success");
                }
                else
                {
                    UT_LOG("powerLevel is %d which is an invalid value", power);
                    UT_FAIL("powerLevel validation failed");
                }
            } else {
                UT_LOG_ERROR("PowerLevel is NULL");
                UT_FAIL("PowerLevel validation failed - NULL value");
            }

            if (pinfo->LockStatus != NULL) {
                if(strcmp(pinfo->LockStatus, "Locked") == 0 || 
                   strcmp(pinfo->LockStatus, "Unlocked") == 0 || 
                   strcmp(pinfo->LockStatus, "Not Available") == 0)
                {
                    UT_LOG("LockStatus is %s which is a valid value", pinfo->LockStatus);
                    UT_PASS("LockStatus validation success");
                }
                else
                {
                    UT_LOG("LockStatus is %s which is an invalid value", pinfo->LockStatus);
                    UT_FAIL("LockStatus validation failed");
                }
            } else {
                UT_LOG_ERROR("LockStatus is NULL");
                UT_FAIL("LockStatus validation failed - NULL value");
            }

            free(pinfo);  // Free memory only if pinfo is not NULL
        } else {
            UT_LOG_ERROR("docsis_GetUSChannel returned NULL pointer");
            UT_FAIL("NULL pointer returned from docsis_GetUSChannel");
        }
    } else {
        UT_LOG_ERROR("docsis_GetUSChannel returned error");
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the error handling of the docsis_GetUSChannel function when passed a NULL pointer.
*
* In this test, the docsis_GetUSChannel function is invoked with a NULL pointer to test its robustness and error handling capabilities.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 011@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetUSChannel with NULL pointer | docsis_GetUSChannel(NULL) | The function should return an error | The function should handle NULL pointers gracefully |
*/
void test_l1_cm_hal_negative1_docsis_GetUSChannel(void)
{
    gTestID = 11 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    UT_LOG_DEBUG("Invoking docsis_GetUSChannel with NULL pointer");
    int ret = docsis_GetUSChannel(NULL);

    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    if (ret != RETURN_ERR) {
        UT_LOG_ERROR("docsis_GetUSChannel did not return error for NULL pointer");
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the function docsis_GetDOCSISInfo
*
* This test invokes the function docsis_GetDOCSISInfo with a valid CMMGMT_CM_DOCSIS_INFO structure and checks if the return value is RETURN_OK. If the return value is RETURN_OK, it further validates the values in the structure.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 012@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the function docsis_GetDOCSISInfo with a valid CMMGMT_CM_DOCSIS_INFO structure | info = valid CMMGMT_CM_DOCSIS_INFO structure | The return value should be RETURN_OK | Should be successful |
* | 02 | Validate the values in the structure | info.DOCSISDownstreamScanning = "NotStarted", info.DOCSISDownstreamRanging = "NotStarted", info.DOCSISUpstreamScanning = "NotStarted", info.DOCSISUpstreamRanging = "NotStarted", info.DOCSISTftpStatus = "NotStarted", info.DOCSISDataRegComplete = "InProgress", info.ToDStatus = "NotStarted", info.BPIState = TRUE, info.NetworkAccess = TRUE, info.MaxCpeAllowed >= 1 and info.MaxCpeAllowed <= 255 | All assertions should pass | Should be successful |
*/
void test_l1_cm_hal_positive1_docsis_GetDOCSISInfo(void)
{
    gTestID = 12;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PCMMGMT_CM_DOCSIS_INFO pinfo = (PCMMGMT_CM_DOCSIS_INFO)malloc(sizeof(CMMGMT_CM_DOCSIS_INFO));
    UT_ASSERT_PTR_NOT_NULL(pinfo);
    memset(pinfo, 0, sizeof(CMMGMT_CM_DOCSIS_INFO));

    int ret = docsis_GetDOCSISInfo(pinfo);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    if (ret == RETURN_OK) {
        // Log DOCSIS Version
        UT_LOG_DEBUG("DOCSISVersion: %s\n", pinfo->DOCSISVersion);
        UT_ASSERT_TRUE(strlen(pinfo->DOCSISVersion) > 0);
        UT_ASSERT_TRUE(strstr(pinfo->DOCSISVersion, "3.0") != NULL || 
                      strstr(pinfo->DOCSISVersion, "3.1") != NULL);

        // Log scanning and ranging status fields
        UT_LOG_DEBUG("DOCSISDownstreamScanning: %s\n", pinfo->DOCSISDownstreamScanning);
        UT_LOG_DEBUG("DOCSISDownstreamRanging: %s\n", pinfo->DOCSISDownstreamRanging);
        UT_LOG_DEBUG("DOCSISUpstreamScanning: %s\n", pinfo->DOCSISUpstreamScanning);
        UT_LOG_DEBUG("DOCSISUpstreamRanging: %s\n", pinfo->DOCSISUpstreamRanging);

        const char* validStatus[] = {"NotStarted", "InProgress", "Complete"};
        UT_ASSERT_TRUE(
            strcmp(pinfo->DOCSISDownstreamScanning, validStatus[0]) == 0 ||
            strcmp(pinfo->DOCSISDownstreamScanning, validStatus[1]) == 0 ||
            strcmp(pinfo->DOCSISDownstreamScanning, validStatus[2]) == 0
        );
        UT_ASSERT_TRUE(
            strcmp(pinfo->DOCSISDownstreamRanging, validStatus[0]) == 0 ||
            strcmp(pinfo->DOCSISDownstreamRanging, validStatus[1]) == 0 ||
            strcmp(pinfo->DOCSISDownstreamRanging, validStatus[2]) == 0
        );
        UT_ASSERT_TRUE(
            strcmp(pinfo->DOCSISUpstreamScanning, validStatus[0]) == 0 ||
            strcmp(pinfo->DOCSISUpstreamScanning, validStatus[1]) == 0 ||
            strcmp(pinfo->DOCSISUpstreamScanning, validStatus[2]) == 0
        );
        UT_ASSERT_TRUE(
            strcmp(pinfo->DOCSISUpstreamRanging, validStatus[0]) == 0 ||
            strcmp(pinfo->DOCSISUpstreamRanging, validStatus[1]) == 0 ||
            strcmp(pinfo->DOCSISUpstreamRanging, validStatus[2]) == 0
        );

        // Log and validate TFTP status
        UT_LOG_DEBUG("DOCSISTftpStatus: %s\n", pinfo->DOCSISTftpStatus);
        const char* validTftpStatus[] = {"NotStarted", "InProgress", "DownloadComplete"};
        UT_ASSERT_TRUE(
            strcmp(pinfo->DOCSISTftpStatus, validTftpStatus[0]) == 0 ||
            strcmp(pinfo->DOCSISTftpStatus, validTftpStatus[1]) == 0 ||
            strcmp(pinfo->DOCSISTftpStatus, validTftpStatus[2]) == 0
        );

        // Log and validate Data Registration status
        UT_LOG_DEBUG("DOCSISDataRegComplete: %s\n", pinfo->DOCSISDataRegComplete);
        const char* validRegStatus[] = {"InProgress", "RegistrationComplete"};
        UT_ASSERT_TRUE(
            strcmp(pinfo->DOCSISDataRegComplete, validRegStatus[0]) == 0 ||
            strcmp(pinfo->DOCSISDataRegComplete, validRegStatus[1]) == 0
        );

        // Log and validate DHCP and TFTP attempts
        UT_LOG_DEBUG("DOCSISDHCPAttempts: %d\n", pinfo->DOCSISDHCPAttempts);
        UT_LOG_DEBUG("DOCSISTftpAttempts: %d\n", pinfo->DOCSISTftpAttempts);
        UT_ASSERT_TRUE(pinfo->DOCSISDHCPAttempts >= 0);
        UT_ASSERT_TRUE(pinfo->DOCSISTftpAttempts >= 0);

        // Log and validate Config filename
        UT_LOG_DEBUG("DOCSISConfigFileName: %s\n", pinfo->DOCSISConfigFileName);
        if (strlen(pinfo->DOCSISConfigFileName) > 0) {
            UT_ASSERT_TRUE(strlen(pinfo->DOCSISConfigFileName) < 64);
        }

        // Log and validate ToD Status
        UT_LOG_DEBUG("ToDStatus: %s\n", pinfo->ToDStatus);
        const char* validToDStatus[] = {"NotStarted", "Complete"};
        UT_ASSERT_TRUE(
            strcmp(pinfo->ToDStatus, validToDStatus[0]) == 0 ||
            strcmp(pinfo->ToDStatus, validToDStatus[1]) == 0
        );

        // Log and validate boolean fields
        UT_LOG_DEBUG("BPIState: %d\n", pinfo->BPIState);
        UT_LOG_DEBUG("NetworkAccess: %d\n", pinfo->NetworkAccess);
        UT_ASSERT_TRUE(pinfo->BPIState == TRUE || pinfo->BPIState == FALSE);
        UT_ASSERT_TRUE(pinfo->NetworkAccess == TRUE || pinfo->NetworkAccess == FALSE);

        // Log and validate Upgrade Server IP
        UT_LOG_DEBUG("UpgradeServerIP Value: %u\n", pinfo->UpgradeServerIP.Value);
        UT_ASSERT_TRUE(pinfo->UpgradeServerIP.Value != 0);

        // Log and validate MaxCpeAllowed
        UT_LOG_DEBUG("MaxCpeAllowed: %d\n", pinfo->MaxCpeAllowed);
        UT_ASSERT_TRUE(pinfo->MaxCpeAllowed >= 1 && pinfo->MaxCpeAllowed <= 255);

        // Log and validate Service Flow Parameters
        UT_LOG_DEBUG("UpstreamServiceFlowParams: %s\n", pinfo->UpstreamServiceFlowParams);
        UT_LOG_DEBUG("DownstreamServiceFlowParams: %s\n", pinfo->DownstreamServiceFlowParams);
        if (strlen(pinfo->UpstreamServiceFlowParams) > 0) {
            UT_ASSERT_TRUE(strlen(pinfo->UpstreamServiceFlowParams) < 64);
        }
        if (strlen(pinfo->DownstreamServiceFlowParams) > 0) {
            UT_ASSERT_TRUE(strlen(pinfo->DownstreamServiceFlowParams) < 64);
        }

        // Log and validate Data Rates
        UT_LOG_DEBUG("DOCSISDownstreamDataRate: %s\n", pinfo->DOCSISDownstreamDataRate);
        UT_LOG_DEBUG("DOCSISUpstreamDataRate: %s\n", pinfo->DOCSISUpstreamDataRate);
        if (strlen(pinfo->DOCSISDownstreamDataRate) > 0) {
            UT_ASSERT_TRUE(strlen(pinfo->DOCSISDownstreamDataRate) < 64);
            for (int i = 0; pinfo->DOCSISDownstreamDataRate[i] != '\0'; i++) {
                UT_ASSERT_TRUE(isdigit((unsigned char)pinfo->DOCSISDownstreamDataRate[i]));
            }
        }
        if (strlen(pinfo->DOCSISUpstreamDataRate) > 0) {
            UT_ASSERT_TRUE(strlen(pinfo->DOCSISUpstreamDataRate) < 64);
            for (int i = 0; pinfo->DOCSISUpstreamDataRate[i] != '\0'; i++) {
                UT_ASSERT_TRUE(isdigit((unsigned char)pinfo->DOCSISUpstreamDataRate[i]));
            }
        }

        // Log and validate Core Version
        UT_LOG_DEBUG("CoreVersion: %s\n", pinfo->CoreVersion);
        if (strlen(pinfo->CoreVersion) > 0) {
            UT_ASSERT_TRUE(strlen(pinfo->CoreVersion) < 64);
        }
    } else {
        UT_LOG_ERROR("docsis_GetDOCSISInfo failed with return status %d\n", ret);
    }

    free(pinfo);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the docsis_GetDOCSISInfo API when invoked with NULL PCMMGMT_CM_DOCSIS_INFO structure.
*
* In this test, the docsis_GetDOCSISInfo API is invoked with NULL PCMMGMT_CM_DOCSIS_INFO structure. The test is designed to ensure that the API handles this error condition correctly and returns the appropriate error code.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 013@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetDOCSISInfo API with NULL PCMMGMT_CM_DOCSIS_INFO structure | PCMMGMT_CM_DOCSIS_INFO = NULL | The API should return RETURN_ERR | The API should handle this error condition correctly |
*/
void test_l1_cm_hal_negative1_docsis_GetDOCSISInfo(void)
{
    gTestID = 13 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = docsis_GetDOCSISInfo(NULL);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    if (ret == RETURN_ERR) {
        UT_LOG_DEBUG("Invoking docsis_GetDOCSISInfo with NULL PCMMGMT_CM_DOCSIS_INFO structure\n");
    } else {
        UT_LOG_ERROR("docsis_GetDOCSISInfo did not fail as expected with NULL PCMMGMT_CM_DOCSIS_INFO structure\n");
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the function docsis_GetNumOfActiveTxChannels
*
* This test invokes the function docsis_GetNumOfActiveTxChannels with a valid pointer and checks if the function returns the correct number of active channels and the return status is OK.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 014@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetNumOfActiveTxChannels with valid pointer | activeChannels = 0 | Return status should be OK and activeChannels should be greater than or equal to 0 | Should be successful |
*/
void test_l1_cm_hal_positive1_docsis_GetNumOfActiveTxChannels(void)
{
    gTestID = 14 ;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG activeChannels = 0;
    int retStatus = 0;

    UT_LOG_DEBUG("Invoking docsis_GetNumOfActiveTxChannels with valid pointer");
    retStatus = docsis_GetNumOfActiveTxChannels(&activeChannels);

    UT_LOG_DEBUG("Returned status: %d, Active Channels: %lu", retStatus, activeChannels);
    UT_ASSERT_EQUAL(retStatus, RETURN_OK);
    UT_ASSERT(activeChannels >= 0);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the behavior of the docsis_GetNumOfActiveTxChannels API when invoked with NULL pointer.
*
* This test is important to ensure that the API handles invalid input gracefully and returns the appropriate error code. This is a negative test case where the API is deliberately invoked with invalid input to test its robustness.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 015@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetNumOfActiveTxChannels with NULL pointer | NULL | The function should return RETURN_ERR | The API should handle invalid input gracefully |
*/
void test_l1_cm_hal_negative1_docsis_GetNumOfActiveTxChannels(void)
{
    gTestID = 15;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int retStatus = 0;

    UT_LOG_DEBUG("Invoking docsis_GetNumOfActiveTxChannels with NULL pointer");
    retStatus = docsis_GetNumOfActiveTxChannels(NULL);

    UT_LOG_DEBUG("Returned status: %d", retStatus);
    UT_ASSERT_EQUAL(retStatus, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the function docsis_GetNumOfActiveRxChannels
*
* This test invokes the function docsis_GetNumOfActiveRxChannels with a valid cnt pointer and checks if the function returns the correct number of active Rx channels.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 016@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetNumOfActiveRxChannels with valid cnt pointer | cnt pointer = valid | The function should return with status RETURN_OK and cnt should be greater than or equal to 0 | Should be successful |
*/
void test_l1_cm_hal_positive1_docsis_GetNumOfActiveRxChannels(void)
{
    gTestID = 16;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG cnt;
    int ret;

    UT_LOG_DEBUG("Invoking docsis_GetNumOfActiveRxChannels with valid cnt pointer");
    ret = docsis_GetNumOfActiveRxChannels(&cnt);

    if (ret == RETURN_OK) {
        UT_LOG_INFO("docsis_GetNumOfActiveRxChannels returned with status RETURN_OK and cnt: %lu", cnt);
        UT_ASSERT_TRUE(cnt >= 0);
    } else {
        UT_LOG_ERROR("docsis_GetNumOfActiveRxChannels failed with status: %d", ret);
    }

    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the behavior of the docsis_GetNumOfActiveRxChannels API when invoked with NULL cnt pointer.
*
* In this test, the docsis_GetNumOfActiveRxChannels API is invoked with NULL cnt pointer. The expected behavior is that the API should return with status RETURN_ERR. This test is important to ensure the robustness of the API in handling invalid inputs.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 017@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetNumOfActiveRxChannels with NULL cnt pointer | cnt = NULL | The return value should be RETURN_ERR | The API should handle invalid inputs gracefully |
*/
void test_l1_cm_hal_negative1_docsis_GetNumOfActiveRxChannels(void)
{
    gTestID = 17;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret;

    UT_LOG_DEBUG("Invoking docsis_GetNumOfActiveRxChannels with NULL cnt pointer");
    ret = docsis_GetNumOfActiveRxChannels(NULL);

    if (ret == RETURN_ERR) {
        UT_LOG_INFO("docsis_GetNumOfActiveRxChannels returned with status RETURN_ERR as expected");
    } else {
        UT_LOG_ERROR("docsis_GetNumOfActiveRxChannels did not return expected status. Actual status: %d", ret);
    }

    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the function docsis_GetErrorCodewords
*
* This test invokes the function docsis_GetErrorCodewords with a valid CMMGMT_CM_ERROR_CODEWORDS structure and checks if the return value is RETURN_OK and if the values of UnerroredCodewords, CorrectableCodewords, and UncorrectableCodewords are greater than or equal to 0.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 018@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetErrorCodewords with valid CMMGMT_CM_ERROR_CODEWORDS structure | pinfo = valid CMMGMT_CM_ERROR_CODEWORDS structure | Return value should be RETURN_OK and values of UnerroredCodewords, CorrectableCodewords, and UncorrectableCodewords should be greater than or equal to 0 | Should be successful |
* | 02 | Validate the values in the structure |  | All assertions should pass | Should be successfull |
*/
void test_l1_cm_hal_positive1_docsis_GetErrorCodewords(void)
{
    gTestID = 18;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PCMMGMT_CM_ERROR_CODEWORDS pinfo = (PCMMGMT_CM_ERROR_CODEWORDS)malloc(sizeof(CMMGMT_CM_ERROR_CODEWORDS));
    int ret;

    /* Check if memory allocation was successful */
    if (pinfo == NULL) 
    {
        UT_LOG_ERROR("Memory allocation failed for pinfo");
        UT_FAIL("Memory allocation failed");
        return;
    }
    UT_LOG_DEBUG("Invoking docsis_GetErrorCodewords with valid PCMMGMT_CM_ERROR_CODEWORDS structure");
    ret = docsis_GetErrorCodewords(&pinfo);

    /* First check API return status */
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    
    if (ret == RETURN_OK)
    {
        /* Only access pinfo members if API succeeded and pinfo is valid */
        if (pinfo != NULL)
        {
            UT_LOG_DEBUG("pinfo->UnerroredCodewords is : %lu", pinfo->UnerroredCodewords);
            UT_LOG_DEBUG("pinfo->CorrectableCodewords is : %lu", pinfo->CorrectableCodewords);
            UT_LOG_DEBUG("pinfo->UncorrectableCodewords is : %lu", pinfo->UncorrectableCodewords);

            if(pinfo->UnerroredCodewords >= 0)
            {
                UT_LOG("UnerroredCodewords is %lu which is a valid value", pinfo->UnerroredCodewords);
                UT_PASS("UnerroredCodewords validation success");
            }
            else
            {
                UT_LOG("UnerroredCodewords is %lu which is an invalid value", pinfo->UnerroredCodewords);
                UT_FAIL("UnerroredCodewords validation failed");
            }

            if(pinfo->CorrectableCodewords >= 0)
            {
                UT_LOG("CorrectableCodewords is %lu which is a valid value", pinfo->CorrectableCodewords);
                UT_PASS("CorrectableCodewords validation success");
            }
            else
            {
                UT_LOG("CorrectableCodewords is %lu which is an invalid value", pinfo->CorrectableCodewords);
                UT_FAIL("CorrectableCodewords validation failed");
            }

            if(pinfo->UncorrectableCodewords >= 0)
            {
                UT_LOG("UncorrectableCodewords is %lu which is a valid value", pinfo->UncorrectableCodewords);
                UT_PASS("UncorrectableCodewords validation success");
            }
            else
            {
                UT_LOG("UncorrectableCodewords is %lu which is an invalid value", pinfo->UncorrectableCodewords);
                UT_FAIL("UncorrectableCodewords validation failed");
            }
        }
        else 
        {
            UT_LOG_ERROR("pinfo is NULL after API call");
            UT_FAIL("NULL pointer after API call");
        }
    }
    else 
    {
        UT_LOG_ERROR("docsis_GetErrorCodewords failed with status %d\n", ret);
    }
    /* Free allocated memory */
    if (pinfo != NULL)
    {
        free(pinfo);
        pinfo = NULL;
    }
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the error handling of the docsis_GetErrorCodewords API
*
* This test is designed to verify the error handling of the docsis_GetErrorCodewords API when it is invoked with a NULL pointer. The API is expected to return an error code.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 019@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetErrorCodewords API with NULL pointer | docsis_GetErrorCodewords(NULL) | The API should return an error code | The API is expected to handle the error gracefully |
*/
void test_l1_cm_hal_negative1_docsis_GetErrorCodewords(void)
{
    gTestID = 19;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret;

    ret = docsis_GetErrorCodewords(NULL);

    UT_LOG_DEBUG("Invoking docsis_GetErrorCodewords with NULL pointer");
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    if (ret != RETURN_ERR) {
        UT_LOG_ERROR("docsis_GetErrorCodewords should have failed but returned with status %d\n", ret);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the function docsis_GetMddIpModeOverride
*
* This test invokes the function docsis_GetMddIpModeOverride with a valid buffer and checks if the return value is as expected.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 020@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetMddIpModeOverride with valid buffer | pValue = valid buffer | Return value should be RETURN_OK | Should be successful |
*/
void test_l1_cm_hal_positive1_docsis_GetMddIpModeOverride(void)
{
    gTestID = 20;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR pValue[64];
    int ret;

    UT_LOG_DEBUG("Invoking docsis_GetMddIpModeOverride with valid buffer");
    ret = docsis_GetMddIpModeOverride(pValue);

    UT_LOG_DEBUG("Returned status: %d, Output value: %s", ret, pValue);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the docsis_GetMddIpModeOverride API when invoked with NULL buffer.
*
* In this test, the docsis_GetMddIpModeOverride API is invoked with NULL buffer and the return value is checked. The test is designed to ensure that the API handles the error condition correctly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 021@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetMddIpModeOverride API with NULL buffer | pValue = NULL | The return value should be RETURN_ERR | The API should handle the error condition correctly |
*/
void test_l1_cm_hal_negative1_docsis_GetMddIpModeOverride(void)
{
    gTestID = 21;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR *pValue = NULL;
    int ret;

    UT_LOG_DEBUG("Invoking docsis_GetMddIpModeOverride with NULL buffer");
    ret = docsis_GetMddIpModeOverride(pValue);

    UT_LOG_DEBUG("Returned status: %d", ret);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the docsis_GetMddIpModeOverride API for a valid buffer of size more than 64
*
* In this test, the docsis_GetMddIpModeOverride API is invoked with a valid buffer of size more than 64. The test verifies if the API is able to handle this scenario and return the expected output.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 022@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetMddIpModeOverride with valid buffer of size more than 64 | pValue = valid buffer of size more than 64 | The return value should be RETURN_OK | Should be successful |
*/
void test_l1_cm_hal_positive2_docsis_GetMddIpModeOverride(void)
{
    gTestID = 22;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR pValue[128];
    int ret;

    UT_LOG_DEBUG("Invoking docsis_GetMddIpModeOverride with valid buffer of size more than 64");
    ret = docsis_GetMddIpModeOverride(pValue);

    UT_LOG_DEBUG("Returned status: %d, Output value: %s", ret, pValue);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the function docsis_SetMddIpModeOverride with "ipv4Only" as input
*
* This test case is designed to verify if the function docsis_SetMddIpModeOverride is able to set the MddIpMode to "ipv4Only" successfully.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 023@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_SetMddIpModeOverride with "ipv4Only" | docsis_SetMddIpModeOverride("ipv4Only") | The return value should be RETURN_OK | Should be successfull |
*/
void test_l1_cm_hal_positive1_docsis_SetMddIpModeOverride(void)
{
    gTestID = 23;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    int ret = docsis_SetMddIpModeOverride("ipv4Only");
    UT_LOG_DEBUG("Invoking docsis_SetMddIpModeOverride with ipv4Only");
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of the docsis_SetMddIpModeOverride API when invoked with "ipv6Only" as input.
*
* The test is designed to validate the correct operation of the docsis_SetMddIpModeOverride API when it is invoked with a valid input. The API is expected to return a success status code.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 024@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the docsis_SetMddIpModeOverride API with "ipv6Only" as input | docsis_SetMddIpModeOverride("ipv6Only") | The API should return RETURN_OK | Should be successfull |
*/
void test_l1_cm_hal_positive2_docsis_SetMddIpModeOverride(void)
{
    gTestID = 24;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    int ret = docsis_SetMddIpModeOverride("ipv6Only");
    UT_LOG_DEBUG("Invoking docsis_SetMddIpModeOverride with ipv6Only");
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of the docsis_SetMddIpModeOverride API when provided with valid input.
*
* In this test, the docsis_SetMddIpModeOverride API is invoked with a valid argument "honorMdd". The test verifies that the API returns the expected result when invoked with valid input.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 025@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the docsis_SetMddIpModeOverride API with the argument "honorMdd" | docsis_SetMddIpModeOverride argument = "honorMdd" | The return value should be RETURN_OK | The test should pass if the API returns the expected result |
*/
void test_l1_cm_hal_positive3_docsis_SetMddIpModeOverride(void)
{
    gTestID = 25;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    int ret = docsis_SetMddIpModeOverride("honorMdd");
    UT_LOG_DEBUG("Invoking docsis_SetMddIpModeOverride with honorMdd");
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the docsis_SetMddIpModeOverride function with an empty string as input
*
* This test case is designed to verify the behavior of the docsis_SetMddIpModeOverride function when it is invoked with an empty string. The function is expected to handle this scenario gracefully and return a success status.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 026@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_SetMddIpModeOverride with an empty string |  | The function should return RETURN_OK | The function should handle the empty string input gracefully |
*/
void test_l1_cm_hal_positive4_docsis_SetMddIpModeOverride(void)
{
    gTestID = 26;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    CHAR *emptyStr = "";
    int ret = docsis_SetMddIpModeOverride(emptyStr);
    UT_LOG_DEBUG("Invoking docsis_SetMddIpModeOverride with empty string");
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the docsis_SetMddIpModeOverride function for negative scenario
*
* This test case is designed to test the negative scenario of the docsis_SetMddIpModeOverride function. The function is invoked with an invalid argument to check if it returns the appropriate error code.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 027@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_SetMddIpModeOverride function with invalid argument |  | The function should return error code | The API should handle the invalid input gracefully and return an error |
*/
void test_l1_cm_hal_negative1_docsis_SetMddIpModeOverride(void)
{
    gTestID = 27;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    CHAR *apmStr = "APM";
    int ret = docsis_SetMddIpModeOverride(apmStr);
    UT_LOG_DEBUG("Invoking docsis_SetMddIpModeOverride with APM");
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the docsis_SetMddIpModeOverride function for negative scenarios
*
* This test invokes the docsis_SetMddIpModeOverride function with an invalid argument and expects it to return an error. This is to ensure that the function handles invalid inputs correctly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 028@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_SetMddIpModeOverride with invalid argument "DualStack" | docsis_SetMddIpModeOverride argument = "DualStack" | The function should return an error | The function should handle invalid inputs correctly |
*/
void test_l1_cm_hal_negative2_docsis_SetMddIpModeOverride(void)
{
    gTestID = 28;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    CHAR *dualStr = "DualStack";
    int ret = docsis_SetMddIpModeOverride(dualStr);
    UT_LOG_DEBUG("Invoking docsis_SetMddIpModeOverride with DualStack");
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the behavior of the docsis_SetMddIpModeOverride function when passed a NULL argument
*
* This test is designed to verify the robustness of the docsis_SetMddIpModeOverride function. It tests the function's ability to handle NULL input, which is an edge case that the function should be able to handle gracefully.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 029@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_SetMddIpModeOverride with NULL argument | input = NULL | The function should return RETURN_ERR | The function should handle NULL input gracefully |
*/
void test_l1_cm_hal_negative3_docsis_SetMddIpModeOverride(void)
{
    gTestID = 29;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    int ret = docsis_SetMddIpModeOverride(NULL);
    UT_LOG_DEBUG("Invoking docsis_SetMddIpModeOverride with NULL");
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the behavior of the docsis_SetMddIpModeOverride function when provided with invalid input.
*
* In this test, the docsis_SetMddIpModeOverride function is invoked with an invalid string to test its error handling capabilities.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 030@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_SetMddIpModeOverride with an invalid string | docsis_SetMddIpModeOverride("invalid") | The function should return an error | The function should handle invalid input gracefully |
*/
void test_l1_cm_hal_negative4_docsis_SetMddIpModeOverride(void)
{
    gTestID = 30;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    int ret = docsis_SetMddIpModeOverride("invalid");
    UT_LOG_DEBUG("Invoking docsis_SetMddIpModeOverride with invalid string");
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the behavior of the docsis_SetMddIpModeOverride function when provided with special characters as input.
*
* In this test, the docsis_SetMddIpModeOverride function is invoked with a string of special characters. The objective is to ensure that the function handles such input correctly and returns an error.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 031@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_SetMddIpModeOverride with a string of special characters | input = "@#%" | The function should return an error | The function should handle special characters correctly and return an error |
*/
void test_l1_cm_hal_negative5_docsis_SetMddIpModeOverride(void)
{
    gTestID = 31;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    int ret = docsis_SetMddIpModeOverride("@#%");
    UT_LOG_DEBUG("Invoking docsis_SetMddIpModeOverride with special characters");
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the docsis_SetMddIpModeOverride function with invalid input
*
* In this test, the docsis_SetMddIpModeOverride function is invoked with a string of numbers as input. The function is expected to return an error, as the input is not valid.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 032@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_SetMddIpModeOverride with a string of numbers | docsis_SetMddIpModeOverride("1234") | The function should return an error | The API should handle invalid input gracefully |
*/
void test_l1_cm_hal_negative6_docsis_SetMddIpModeOverride(void)
{
    gTestID = 32;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    int ret = docsis_SetMddIpModeOverride("1234");
    UT_LOG_DEBUG("Invoking docsis_SetMddIpModeOverride with numbers");
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the function docsis_GetUSChannelId
*
* This test invokes the function docsis_GetUSChannelId and checks if the returned channelId is within the valid range (0-255). This is important to ensure that the function is working as expected and returning valid channel IDs.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 033@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the function docsis_GetUSChannelId | No input data required for this function | The returned channelId should be within the range 0-255 | Should be successful |
*/
void test_l1_cm_hal_positive1_docsis_GetUSChannelId(void)
{
    gTestID = 33;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    unsigned char channelId;

    UT_LOG_DEBUG("Invoking docsis_GetUSChannelId()");
    channelId = docsis_GetUSChannelId();

    UT_LOG_DEBUG("docsis_GetUSChannelId() returned channelId: %d", channelId);

    UT_ASSERT_TRUE(channelId >= 0 && channelId <= 255);

    if(!(channelId >= 0 && channelId <= 255))
    {
        UT_LOG_ERROR("docsis_GetUSChannelId() returned invalid channelId: %d", channelId);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to check the behavior of the docsis_SetUSChannelId function when invoked with a negative index.
*
* In this test, we are invoking the docsis_SetUSChannelId function with a negative index. The objective is to ensure that the function does not crash when invoked with such an input.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 034@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_SetUSChannelId with a negative index | index = -1 | The function should not crash | The function should handle the negative index gracefully |
*/
void test_l1_cm_hal_negative1_docsis_SetUSChannelId(void)
{
    gTestID = 34;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    INT index = -1; // Negative index value

    UT_LOG_DEBUG("Invoking docsis_SetUSChannelId with index: %d\n", index);
    docsis_SetUSChannelId(index);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the positive scenario of the function docsis_SetUSChannelId
*
* This test case is designed to test the function docsis_SetUSChannelId. The function is invoked with a positive index value. The test is to ensure that the function does not crash when invoked with a valid index.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 035@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_SetUSChannelId with a positive index value | index = 1 | The function should not crash | Should be successful |
*/
void test_l1_cm_hal_positive1_docsis_SetUSChannelId(void)
{
    gTestID = 35;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    INT index = 1; // Positive index value

    UT_LOG_DEBUG("Invoking docsis_SetUSChannelId with index: %d\n", index);
    docsis_SetUSChannelId(index);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks if the function docsis_GetDownFreq() returns a frequency value that is greater than or equal to 0
*
* In this test, the function docsis_GetDownFreq() is invoked and the returned frequency value is checked. The test passes if the frequency is greater than or equal to 0, otherwise it fails.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 036@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the function docsis_GetDownFreq() | No input data required for this function | The returned frequency value should be greater than or equal to 0 | If the frequency is less than 0, the test fails |
*/
void test_l1_cm_hal_positive1_docsis_GetDownFreq(void)
{
    gTestID = 36;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    unsigned long frequency = docsis_GetDownFreq();

    UT_LOG_DEBUG("Invoking docsis_GetDownFreq()");

    UT_ASSERT_TRUE(frequency >= 0);

    if(frequency < 0)
    {
        UT_LOG_ERROR("Test failed. Frequency is less than 0");
    }
    else
    {
        UT_LOG_INFO("Test passed. Frequency is greater than or equal to 0");
    }
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of the docsis_SetStartFreq API when provided with a frequency of 0
*
* In this test, the docsis_SetStartFreq API is invoked with a frequency of 0. The objective is to ensure that the API can handle this edge case correctly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 037@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_SetStartFreq with a frequency of 0 | frequency = 0 | The API should handle this edge case correctly | Should be successful |
*/
void test_l1_cm_hal_positive1_docsis_SetStartFreq(void)
{
    gTestID = 37;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    
    ULONG frequency = 0;

    UT_LOG_DEBUG("Invoking docsis_SetStartFreq with frequency: %lu", frequency);
    docsis_SetStartFreq(frequency);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of the docsis_SetStartFreq API when provided with a minimum possible frequency greater than 0Hz
*
* In this test, the docsis_SetStartFreq API is invoked with a frequency of 1Hz. The objective is to ensure that the API can handle and correctly process the minimum possible frequency value.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 038@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_SetStartFreq API with a frequency of 1Hz | frequency = 1 | The API should successfully set the start frequency to 1Hz | Should be successful |
*/
void test_l1_cm_hal_positive2_docsis_SetStartFreq(void)
{
    gTestID = 38;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG frequency = 1; // Assuming 1Hz is the minimum possible frequency greater than 0Hz

    UT_LOG_DEBUG("Invoking docsis_SetStartFreq with frequency: %lu", frequency);
    docsis_SetStartFreq(frequency);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the function docsis_GetDocsisEventLogItems
*
* This test is designed to validate the docsis_GetDocsisEventLogItems API. The API is invoked with valid parameters and the returned values are checked for correctness.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 039@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetDocsisEventLogItems with valid entryArray and len=10 | entryArray = valid array, len = 10 | The function should return the number of entries filled in the array and each entry should have valid values | Should be successful |
* | 02 | Validate the values in the structure |  | All assertions should pass | Should be successfull |
*/
void test_l1_cm_hal_positive1_docsis_GetDocsisEventLogItems(void)
{
    gTestID = 39;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CMMGMT_CM_EventLogEntry_t entryArray[10];
    INT len = 10;
    int ret;

    UT_LOG_DEBUG("Invoking docsis_GetDocsisEventLogItems with valid entryArray and len=%d", len);
    ret = docsis_GetDocsisEventLogItems(entryArray, len);

    for(int i=0; i<ret; i++)
    {
        UT_LOG_DEBUG("entryArray[i].docsDevEvIndex is : %u",entryArray[i].docsDevEvIndex);
        UT_LOG_DEBUG("entryArray[i].docsDevEvCounts is : %u",entryArray[i].docsDevEvCounts);
        UT_LOG_DEBUG("entryArray[i].docsDevEvLevel is : %u",entryArray[i].docsDevEvLevel);
        UT_LOG_DEBUG("entryArray[i].docsDevEvId is : %u",entryArray[i].docsDevEvId);
        UT_LOG_DEBUG("entryArray[i].docsDevEvText is : %u",entryArray[i].docsDevEvText);

        if(entryArray[i].docsDevEvIndex >= 0 && entryArray[i].docsDevEvIndex <= UINT_MAX)
        {
            UT_LOG("docsDevEvIndex is %u which is a valid value", entryArray[i].docsDevEvIndex);
            UT_PASS("docsDevEvIndex validation success");
        }
        else
        {
            UT_LOG("docsDevEvIndex is %u which is an invalid value", entryArray[i].docsDevEvIndex);
            UT_FAIL("docsDevEvIndex validation failed");
        }
        if(entryArray[i].docsDevEvCounts >= 0 && entryArray[i].docsDevEvCounts <= UINT_MAX)
        {
            UT_LOG("docsDevEvCounts is %u which is a valid value", entryArray[i].docsDevEvCounts);
            UT_PASS("docsDevEvCounts validation success");
        }
        else
        {
            UT_LOG("docsDevEvCounts is %u which is an invalid value", entryArray[i].docsDevEvCounts);
            UT_FAIL("docsDevEvCounts validation failed");
        }
        if(entryArray[i].docsDevEvLevel >= 0 && entryArray[i].docsDevEvLevel <= 255)
        {
            UT_LOG("docsDevEvLevel is %u which is a valid value", entryArray[i].docsDevEvLevel);
            UT_PASS("docsDevEvLevel validation success");
        }
        else
        {
            UT_LOG("docsDevEvLevel is %u which is an invalid value", entryArray[i].docsDevEvLevel);
            UT_FAIL("docsDevEvLevel validation failed");
        }
        if(entryArray[i].docsDevEvId >= 0 && entryArray[i].docsDevEvId <= UINT_MAX)
        {
            UT_LOG("docsDevEvId is %u which is a valid value", entryArray[i].docsDevEvId);
            UT_PASS("docsDevEvId validation success");
        }
        else
        {
            UT_LOG("docsDevEvId is %u which is an invalid value", entryArray[i].docsDevEvId);
            UT_FAIL("docsDevEvId validation failed");
        }
    }
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the function docsis_GetDocsisEventLogItems
*
* In this test, the function docsis_GetDocsisEventLogItems is invoked with a valid entryArray and len. The function is expected to return 0, indicating success.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 040@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetDocsisEventLogItems with valid entryArray and len | entryArray = valid array, len = 0 | The function should return 0 | Should be successful |
*/
void test_l1_cm_hal_positive2_docsis_GetDocsisEventLogItems(void)
{
    gTestID = 40;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CMMGMT_CM_EventLogEntry_t entryArray[10];
    INT len = 0;
    int ret;

    UT_LOG_DEBUG("Invoking docsis_GetDocsisEventLogItems with valid entryArray and len=%d", len);
    ret = docsis_GetDocsisEventLogItems(entryArray, len);

    UT_ASSERT_EQUAL(ret, 0);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the function docsis_GetDocsisEventLogItems.
*
* In this test, we are checking the return value of the function docsis_GetDocsisEventLogItems when it is invoked with a NULL entryArray and a length of 10.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 041@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetDocsisEventLogItems with NULL entryArray and len=10 | entryArray = NULL, len = 10 | The return value should be RETURN_ERR | The function should handle NULL entryArray gracefully |
*/
void test_l1_cm_hal_negative1_docsis_GetDocsisEventLogItems(void)
{
    gTestID = 41;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CMMGMT_CM_EventLogEntry_t *entryArray = NULL;
    INT len = 10;
    int ret;

    UT_LOG_DEBUG("Invoking docsis_GetDocsisEventLogItems with NULL entryArray and len=%d", len);
    ret = docsis_GetDocsisEventLogItems(entryArray, len);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the behavior of the docsis_GetDocsisEventLogItems API when invoked with a negative length.
*
* The test is designed to ensure that the API can handle erroneous input gracefully and return the expected error code. This is important to ensure the robustness of the API.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 042@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetDocsisEventLogItems with valid entryArray and negative len | entryArray = valid, len = -10 | The return value should be RETURN_ERR | The API should handle the erroneous input gracefully |
*/
void test_l1_cm_hal_negative2_docsis_GetDocsisEventLogItems(void)
{
    gTestID = 42;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CMMGMT_CM_EventLogEntry_t entryArray[10];
    INT len = -10;
    int ret;

    UT_LOG_DEBUG("Invoking docsis_GetDocsisEventLogItems with valid entryArray and len=%d", len);
    ret = docsis_GetDocsisEventLogItems(entryArray, len);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of the docsis_ClearDocsisEventLog API
*
* This test invokes the docsis_ClearDocsisEventLog API and checks if it returns the expected value. The purpose of this test is to ensure that the API is working as expected and is able to clear the DOCSIS event log successfully.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 043@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the docsis_ClearDocsisEventLog API | No input data required for this API | The return value should be RETURN_OK | If the return value is not RETURN_OK, the test fails |
*/
void test_l1_cm_hal_positive1_docsis_ClearDocsisEventLog(void)
{
    gTestID = 43;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    int returnValue;
    UT_LOG_DEBUG("Invoking docsis_ClearDocsisEventLog");
    returnValue = docsis_ClearDocsisEventLog();
    UT_ASSERT_EQUAL(returnValue, RETURN_OK);
    if (returnValue != RETURN_OK) {
        UT_LOG_ERROR("docsis_ClearDocsisEventLog failed with return value: %d", returnValue);
    }
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the cm_hal_GetDHCPInfo API
*
* This test case is designed to validate the cm_hal_GetDHCPInfo API. The API is tested for its ability to fetch DHCP information and validate the MAC address format.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 044@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Allocate memory for DHCP info structure | pInfo = malloc(sizeof(CMMGMT_CM_DHCP_INFO)) | Memory allocation should be successful | If memory allocation fails, test should return ERROR log |
* | 02 | Invoke cm_hal_GetDHCPInfo API with valid buffer | pInfo | API should return RETURN_OK | If API returns other than RETURN_OK, test should fail |
* | 03 | Validate MAC address format | pInfo->MACAddress | MAC address format should be valid | If MAC address format is invalid, test should fail |
*/
void test_l1_cm_hal_positive1_GetDHCPInfo(void)
{
    gTestID = 44;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PCMMGMT_CM_DHCP_INFO pInfo = (PCMMGMT_CM_DHCP_INFO) malloc(sizeof(CMMGMT_CM_DHCP_INFO));
    if (pInfo == NULL) {
        UT_LOG_ERROR("Memory allocation failed\n");
        return;
    }

    int ret = cm_hal_GetDHCPInfo(pInfo);
    UT_LOG_DEBUG("Invoking cm_hal_GetDHCPInfo with valid buffer\n");

    UT_LOG_DEBUG("pInfo->IPAddress is : %u",pInfo->IPAddress.Value);
    UT_LOG_DEBUG("pInfo->BootFileName is : %s",pInfo->BootFileName);
    UT_LOG_DEBUG("pInfo->SubnetMask is : %u",pInfo->SubnetMask.Value);
    UT_LOG_DEBUG("pInfo->Gateway is : %u",pInfo->Gateway.Value);
    UT_LOG_DEBUG("pInfo->TFTPServer is : %u",pInfo->TFTPServer.Value);
    UT_LOG_DEBUG("pInfo->TimeServer is : %s",pInfo->TimeServer);
    UT_LOG_DEBUG("pInfo->TimeOffset is : %d",pInfo->TimeOffset);
    UT_LOG_DEBUG("pInfo->LeaseTimeRemaining is : %lu",pInfo->LeaseTimeRemaining);
    UT_LOG_DEBUG("pInfo->RebindTimeRemaining is : %s",pInfo->RebindTimeRemaining);
    UT_LOG_DEBUG("pInfo->RenewTimeRemaining is : %s",pInfo->RenewTimeRemaining);
    UT_LOG_DEBUG("pInfo->MACAddress is : %s",pInfo->MACAddress);
    UT_LOG_DEBUG("pInfo->DOCSISDHCPStatus is : %s",pInfo->DOCSISDHCPStatus);

    UT_ASSERT_EQUAL(ret, RETURN_OK);

    if (ret == RETURN_OK) {
        // Validate MACAddress format
        int isMACValid = (strlen(pInfo->MACAddress) == 17) && (pInfo->MACAddress[2] == ':' && pInfo->MACAddress[5] == ':' && pInfo->MACAddress[8] == ':' && pInfo->MACAddress[11] == ':' && pInfo->MACAddress[14] == ':');
        UT_ASSERT_EQUAL(isMACValid, 1);
    }
    free(pInfo);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to check the behavior of the cm_hal_GetDHCPInfo API when invoked with NULL buffer
*
* In this test, we are testing the negative scenario where the cm_hal_GetDHCPInfo API is invoked with NULL buffer. The API is expected to return an error in this case.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 045@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_GetDHCPInfo API with NULL buffer | buffer = NULL | The API should return an error | The API is expected to handle NULL buffer and return an error |
*/
void test_l1_cm_hal_negative1_GetDHCPInfo(void)
{
    gTestID = 45;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = cm_hal_GetDHCPInfo(NULL);
    UT_LOG_DEBUG("Invoking cm_hal_GetDHCPInfo with NULL buffer\n");

    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of the cm_hal_GetIPv6DHCPInfo API
*
* This test invokes the cm_hal_GetIPv6DHCPInfo API with a valid pInfo parameter and checks if the return value is RETURN_OK. The test is designed to validate the positive scenario where the API is expected to succeed.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 046@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_GetIPv6DHCPInfo with valid pInfo | pInfo = &info | The return value should be RETURN_OK | The test should pass |
*/
void test_l1_cm_hal_positive1_GetIPv6DHCPInfo(void)
{
    gTestID = 46;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PCMMGMT_CM_IPV6DHCP_INFO info = (PCMMGMT_CM_IPV6DHCP_INFO)malloc(sizeof(CMMGMT_CM_IPV6DHCP_INFO));
    if (info == NULL) {
        UT_LOG_ERROR("Memory allocation failed\n");
        return;
    }
    memset(info, 0, sizeof(CMMGMT_CM_IPV6DHCP_INFO));

    UT_LOG_DEBUG("Invoking cm_hal_GetIPv6DHCPInfo with valid pInfo");
    int ret = cm_hal_GetIPv6DHCPInfo(info);
    UT_LOG_DEBUG("info->IPv6Address is : %s",info->IPv6Address);
    UT_LOG_DEBUG("info->IPv6BootFileName is : %s",info->IPv6BootFileName);
    UT_LOG_DEBUG("info->IPv6Prefix is : %s",info->IPv6Prefix);
    UT_LOG_DEBUG("info->IPv6Router is : %s",info->IPv6Router);
    UT_LOG_DEBUG("info->IPv6TFTPServer is : %s",info->IPv6TFTPServer);
    UT_LOG_DEBUG("info->IPv6TimeServer is : %s",info->IPv6TimeServer);
    UT_LOG_DEBUG("info->IPv6LeaseTimeRemaining is : %lu",info->IPv6LeaseTimeRemaining);
    UT_LOG_DEBUG("info->IPv6RebindTimeRemaining is : %lu",info->IPv6RebindTimeRemaining);
    UT_LOG_DEBUG("info->IPv6RenewTimeRemaining is : %lu",info->IPv6RenewTimeRemaining);

    if (ret != RETURN_OK) {
        UT_LOG_ERROR("cm_hal_GetIPv6DHCPInfo failed with return status %d", ret);
    }

    UT_ASSERT_EQUAL(ret, RETURN_OK);
    free(info);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the cm_hal_GetIPv6DHCPInfo API when invoked with NULL pInfo.
*
* In this test, the cm_hal_GetIPv6DHCPInfo API is invoked with NULL pInfo to verify that the API handles this error condition correctly and returns the expected error code.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 047@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_GetIPv6DHCPInfo with NULL pInfo | pInfo = NULL | The return value should be RETURN_ERR | The API should handle this error condition correctly |
*/
void test_l1_cm_hal_negative1_GetIPv6DHCPInfo(void)
{
    gTestID = 47;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    UT_LOG_DEBUG("Invoking cm_hal_GetIPv6DHCPInfo with NULL pInfo");
    int ret = cm_hal_GetIPv6DHCPInfo(NULL);

    if (ret != RETURN_ERR) {
        UT_LOG_ERROR("cm_hal_GetIPv6DHCPInfo should have failed but returned status %d", ret);
    }

    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the cm_hal_GetCPEList API
*
* This test case is designed to verify the positive scenario of the cm_hal_GetCPEList API. The API is expected to return a list of CPEs in the given LAN mode.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 048@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Allocate memory for CPE list | ppCPEList = malloc(sizeof(PCMMGMT_DML_CPE_LIST)) | Memory should be allocated successfully | Should be successful |
* | 02 | Invoke cm_hal_GetCPEList API with allocated memory and router mode | ppCPEList, &InstanceNum, LanMode = "router" | API should return RETURN_OK | Should be successful |
* | 03 | Assert the return value of the API | ret | ret should be equal to RETURN_OK | Should be successful |
* | 04 | Free the allocated memory | ppCPEList | Memory should be freed successfully | Should be successful |
*/
void test_l1_cm_hal_positive1_GetCPEList(void)
{
    gTestID = 48;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG InstanceNum = 0;
    CHAR LanMode[] = "router";
    PCMMGMT_DML_CPE_LIST ppCPEList = NULL;  // Initialize to NULL

    int ret = cm_hal_GetCPEList(&ppCPEList, &InstanceNum, LanMode);

    UT_ASSERT_EQUAL(ret, RETURN_OK);

    if (ret == RETURN_OK) {
        if (ppCPEList != NULL) {
            if (InstanceNum > 0) {
                UT_LOG_DEBUG("Number of CPE instances: %lu", InstanceNum);
                
                // Loop through all CPE instances
                for (ULONG i = 0; i < InstanceNum; i++) {
                    if (ppCPEList[i].IPAddress != NULL && ppCPEList[i].MACAddress != NULL) {
                        UT_LOG_DEBUG("CPE[%lu] IPAddress: %s", i, ppCPEList[i].IPAddress);
                        UT_LOG_DEBUG("CPE[%lu] MACAddress: %s", i, ppCPEList[i].MACAddress);
                        
                        // Add validation for IP Address format if needed
                        if (strlen(ppCPEList[i].IPAddress) > 0) {
                            UT_LOG("CPE[%lu] has valid IP Address format", i);
                            UT_PASS("IP Address validation success for CPE");
                        } else {
                            UT_LOG("CPE[%lu] has invalid IP Address", i);
                            UT_FAIL("IP Address validation failed for CPE");
                        }

                        // Add validation for MAC Address format if needed
                        if (strlen(ppCPEList[i].MACAddress) > 0) {
                            UT_LOG("CPE[%lu] has valid MAC Address format", i);
                            UT_PASS("MAC Address validation success for CPE");
                        } else {
                            UT_LOG("CPE[%lu] has invalid MAC Address", i);
                            UT_FAIL("MAC Address validation failed for CPE");
                        }
                    } else {
                        UT_LOG_ERROR("CPE[%lu] has NULL IP Address or MAC Address", i);
                        UT_FAIL("NULL pointer found in CPE list entry");
                    }
                }
            } else {
                UT_LOG_DEBUG("No CPE instances found (InstanceNum = 0)");
                UT_PASS("Successfully retrieved empty CPE list");
            }
            
            // Free the allocated memory
            free(ppCPEList);
        } else {
            UT_LOG_ERROR("cm_hal_GetCPEList returned NULL pointer for ppCPEList");
            UT_FAIL("NULL pointer returned from cm_hal_GetCPEList");
        }
    } else {
        UT_LOG_ERROR("cm_hal_GetCPEList returned error");
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the cm_hal_GetCPEList API
*
* This test case is designed to verify the cm_hal_GetCPEList API. The API is tested for its functionality and its return value.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 049@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Allocate memory for PCMMGMT_DML_CPE_LIST and Invoke cm_hal_GetCPEList API | ppCPEList = allocated memory, InstanceNum = uninitialized, LanMode = "bridge" | The return value should be RETURN_OK | The test should pass |
*/
void test_l1_cm_hal_positive2_GetCPEList(void)
{
    gTestID = 49;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG InstanceNum;
    CHAR LanMode[] = "bridge";

    PCMMGMT_DML_CPE_LIST ppCPEList = (PCMMGMT_DML_CPE_LIST) malloc(sizeof(CMMGMT_DML_CPE_LIST));

    int ret = cm_hal_GetCPEList(&ppCPEList, &InstanceNum, LanMode);
    UT_LOG_DEBUG("ppCPEList->IPAddress is : %s",ppCPEList->IPAddress);
    UT_LOG_DEBUG("ppCPEList->MACAddress is : %s",ppCPEList->MACAddress);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    free(ppCPEList);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the cm_hal_GetCPEList API when the first parameter is NULL.
*
* In this test, the cm_hal_GetCPEList API is invoked with the first parameter as NULL and the return value is checked to be RETURN_ERR. This is to ensure that the API handles the error scenario correctly when it is invoked with invalid parameters.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 050@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_GetCPEList API with first parameter as NULL | First parameter = NULL, InstanceNum = address of InstanceNum variable, LanMode = "router" | The return value should be RETURN_ERR | The API should handle the error scenario correctly |
*/
void test_l1_cm_hal_negative1_GetCPEList(void)
{
    gTestID = 50;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG InstanceNum;
    CHAR LanMode[] = "router";

    int ret = cm_hal_GetCPEList(NULL, &InstanceNum, LanMode);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the cm_hal_GetCPEList API when the second parameter is NULL.
*
* In this test, the cm_hal_GetCPEList API is invoked with the second parameter as NULL. The API is expected to return an error. This test is important to ensure the robustness of the API in handling invalid inputs.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 051@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_GetCPEList API with second parameter as NULL | ppCPEList = allocated memory, second parameter = NULL, LanMode = "router" | The return value should be RETURN_ERR | The API should handle the invalid input gracefully |
*/
void test_l1_cm_hal_negative2_GetCPEList(void)
{
    gTestID = 51;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PCMMGMT_DML_CPE_LIST *ppCPEList;
    CHAR LanMode[] = "router";

    ppCPEList = (PCMMGMT_DML_CPE_LIST*) malloc(sizeof(PCMMGMT_DML_CPE_LIST));

    int ret = cm_hal_GetCPEList(ppCPEList, NULL, LanMode);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    
    free(ppCPEList);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the cm_hal_GetCPEList API.
*
* In this test, we are trying to invoke the cm_hal_GetCPEList API with invalid parameters and expect it to return an error. This is to ensure that the API handles error conditions correctly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 052@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_GetCPEList API with third parameter as NULL | ppCPEList = allocated memory, InstanceNum = address of InstanceNum, NULL | The return value should be RETURN_ERR | The API should handle error conditions correctly |
*/
void test_l1_cm_hal_negative3_GetCPEList(void)
{
    gTestID = 52;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PCMMGMT_DML_CPE_LIST *ppCPEList;
    ULONG InstanceNum;

    ppCPEList = (PCMMGMT_DML_CPE_LIST*) malloc(sizeof(PCMMGMT_DML_CPE_LIST));

    int ret = cm_hal_GetCPEList(ppCPEList, &InstanceNum, NULL);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    free(ppCPEList);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the cm_hal_GetCPEList API.
*
* In this test, the cm_hal_GetCPEList API is invoked with an empty LanMode string and the return value is checked against RETURN_ERR to validate the error handling of the API.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 053@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_GetCPEList API with empty LanMode string | ppCPEList = allocated memory, InstanceNum = uninitialized, LanMode = "" | The return value should be RETURN_ERR | The API should handle the error scenario correctly |
*/
void test_l1_cm_hal_negative4_GetCPEList(void)
{
    gTestID = 53;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PCMMGMT_DML_CPE_LIST *ppCPEList;
    ULONG InstanceNum;
    CHAR LanMode[] = "";

    ppCPEList = (PCMMGMT_DML_CPE_LIST*) malloc(sizeof(PCMMGMT_DML_CPE_LIST));

    int ret = cm_hal_GetCPEList(ppCPEList, &InstanceNum, LanMode);
    UT_LOG_DEBUG("Return value from cm_hal_GetCPEList: %d\n", ret);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    free(ppCPEList);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the behavior of the cm_hal_GetCPEList function when provided with invalid LanMode.
*
* This test is designed to verify the robustness of the cm_hal_GetCPEList function. It tests the function's ability to handle invalid input parameters, specifically an invalid LanMode.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 054@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Allocate memory for PCMMGMT_DML_CPE_LIST and Invoke cm_hal_GetCPEList with invalid LanMode | ppCPEList = malloc(sizeof(PCMMGMT_DML_CPE_LIST)), InstanceNum = undefined, LanMode = "invalid" | The return value should be RETURN_ERR | The function should handle invalid input gracefully |
*/
void test_l1_cm_hal_negative5_GetCPEList(void)
{
    gTestID = 54;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PCMMGMT_DML_CPE_LIST *ppCPEList;
    ULONG InstanceNum;
    CHAR LanMode[] = "invalid";

    ppCPEList = (PCMMGMT_DML_CPE_LIST*) malloc(sizeof(PCMMGMT_DML_CPE_LIST));

    int ret = cm_hal_GetCPEList(ppCPEList, &InstanceNum, LanMode);
    UT_LOG_DEBUG("Return value from cm_hal_GetCPEList: %d\n", ret);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    free(ppCPEList);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the functionality of the cm_hal_GetMarket API when invoked with a valid buffer.
*
* In this test, the cm_hal_GetMarket API is invoked with a valid buffer of size 100. The test verifies that the API returns the expected return status and does not fail.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 055@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_GetMarket with a valid buffer of size 100 | market[100] | The return status should be RETURN_OK | The test should be successful |
*/
void test_l1_cm_hal_positive1_GetMarket(void)
{
    gTestID = 55;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR market[100];
    int ret = cm_hal_GetMarket(market);

    UT_LOG_DEBUG("Invoking cm_hal_GetMarket with valid buffer of size 100\n");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    if (ret != RETURN_OK) {
        UT_LOG_ERROR("cm_hal_GetMarket failed with return status %d\n", ret);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the cm_hal_GetMarket API when invoked with NULL buffer.
*
* In this test, the cm_hal_GetMarket API is invoked with NULL buffer and the return value is checked against the expected return value. This test is important to ensure that the API handles error conditions gracefully.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 056@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_GetMarket API with NULL buffer | buffer = NULL | The return value should be RETURN_ERR | The API should handle this error condition gracefully |
*/
void test_l1_cm_hal_negative1_GetMarket(void)
{
    gTestID = 56;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = cm_hal_GetMarket(NULL);

    UT_LOG_DEBUG("Invoking cm_hal_GetMarket with NULL buffer\n");
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    if (ret != RETURN_ERR) {
        UT_LOG_ERROR("cm_hal_GetMarket failed with return status %d\n", ret);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the cm_hal_GetMarket API when invoked with a valid buffer of size more than 100.
*
* In this test, the cm_hal_GetMarket API is invoked with a valid buffer of size more than 100. The objective is to ensure that the API can handle valid inputs and return the expected results.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 057@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_GetMarket with valid buffer of size more than 100 | market[200] | Should return RETURN_OK | Should be successful |
*/
void test_l1_cm_hal_positive2_GetMarket(void)
{
    gTestID = 57;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR market[200];
    int ret = cm_hal_GetMarket(market);

    UT_LOG_DEBUG("Invoking cm_hal_GetMarket with valid buffer of size more than 100\n");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    if (ret != RETURN_OK) {
        UT_LOG_ERROR("cm_hal_GetMarket failed with return status %d\n", ret);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the cm_hal_Set_HTTP_Download_Url function with valid URL and filename
*
* In this test, the cm_hal_Set_HTTP_Download_Url function is invoked with a valid URL and filename. The function is expected to return RETURN_OK, indicating successful execution.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 058@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Set_HTTP_Download_Url with valid URL and filename | pHttpUrl , pfilename | The function should return RETURN_OK | Should be successful |
*/
void test_l1_cm_hal_positive1_Set_HTTP_Download_Url(void)
{
    gTestID = 58;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char HttpUrl[MAX_STRING_LENGTH] = {0};  
    char filename[MAX_STRING_LENGTH] = {0};
    char retrievedString[MAX_STRING_LENGTH] = {0};
    
    UT_KVP_PROFILE_GET_STRING("cm.config.HttpUrl", retrievedString);
    strncpy(HttpUrl, retrievedString, sizeof(HttpUrl));
    UT_KVP_PROFILE_GET_STRING("cm.config.filename", retrievedString);
    strncpy(filename, retrievedString, sizeof(filename));

    char *pHttpUrl = HttpUrl;
    char *pfilename = filename;

    UT_LOG_DEBUG("Invoking cm_hal_Set_HTTP_Download_Url with valid URL and filename");
    int ret = cm_hal_Set_HTTP_Download_Url(pHttpUrl, pfilename);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the cm_hal_Set_HTTP_Download_Url function when provided with a valid URL and a null filename.
*
* This test case is designed to validate the negative scenario where the cm_hal_Set_HTTP_Download_Url function is invoked with a valid URL and a null filename. The function is expected to return an error in this case.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 059@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Set_HTTP_Download_Url with valid URL and null filename | pHttpUrl , pfilename = NULL | The function should return an error | The function is expected to handle null filename and return an error |
*/
void test_l1_cm_hal_negative1_Set_HTTP_Download_Url(void)
{
    gTestID = 59;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char HttpUrl[MAX_STRING_LENGTH] = {0};  
    char retrievedString[MAX_STRING_LENGTH] = {0};

    UT_KVP_PROFILE_GET_STRING("cm.config.HttpUrl", retrievedString);
    strncpy(HttpUrl, retrievedString, sizeof(HttpUrl));

    char *pHttpUrl = HttpUrl;
    char *pfilename = NULL;

    UT_LOG_DEBUG("Invoking cm_hal_Set_HTTP_Download_Url with valid URL and null filename");
    int ret = cm_hal_Set_HTTP_Download_Url(pHttpUrl, pfilename);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the behavior of the cm_hal_Set_HTTP_Download_Url function when provided with a null URL and a valid filename.
*
* This test is important to ensure that the function handles invalid input correctly and returns the appropriate error code.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 060@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Set_HTTP_Download_Url with null URL and valid filename | pHttpUrl = NULL, pfilename | The function should return RETURN_ERR | The function should handle invalid input correctly |
*/
void test_l1_cm_hal_negative2_Set_HTTP_Download_Url(void)
{
    gTestID = 60;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char filename[MAX_STRING_LENGTH] = {0};  
    char retrievedString[MAX_STRING_LENGTH] = {0};

    UT_KVP_PROFILE_GET_STRING("cm.config.filename", retrievedString);
    strncpy(filename, retrievedString, sizeof(filename));

    char *pHttpUrl = NULL;
    char *pfilename = filename;

    UT_LOG_DEBUG("Invoking cm_hal_Set_HTTP_Download_Url with null URL and valid filename");
    int ret = cm_hal_Set_HTTP_Download_Url(pHttpUrl, pfilename);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the cm_hal_Set_HTTP_Download_Url function for negative scenario
*
* This test case is designed to test the cm_hal_Set_HTTP_Download_Url function when an empty URL is provided. The function is expected to return an error in this case.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 061@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Set_HTTP_Download_Url with empty URL and valid filename | pHttpUrl = "", pfilename | The function should return an error | The function should handle invalid inputs gracefully |
*/
void test_l1_cm_hal_negative3_Set_HTTP_Download_Url(void)
{
    gTestID = 61;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char filename[MAX_STRING_LENGTH] = {0};
    char retrievedString[MAX_STRING_LENGTH] = {0};

    UT_KVP_PROFILE_GET_STRING("cm.config.filename", retrievedString);
    strncpy(filename, retrievedString, sizeof(filename));

    char *pHttpUrl = "";
    char *pfilename = filename;

    UT_LOG_DEBUG("Invoking cm_hal_Set_HTTP_Download_Url with empty URL and valid filename");
    int ret = cm_hal_Set_HTTP_Download_Url(pHttpUrl, pfilename);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the behavior of the cm_hal_Set_HTTP_Download_Url function when provided with a valid URL and an empty filename.
*
* This test is designed to verify that the cm_hal_Set_HTTP_Download_Url function returns an error when the filename is empty. This is important to ensure that the function behaves as expected in edge cases.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 062@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Set_HTTP_Download_Url with valid URL and empty filename | pHttpUrl , pfilename = "" | The return value should be RETURN_ERR | The function should return an error because the filename is empty |
*/
void test_l1_cm_hal_negative4_Set_HTTP_Download_Url(void)
{
    gTestID = 62;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char retrievedString[MAX_STRING_LENGTH] = {0};
    char HttpUrl[MAX_STRING_LENGTH] = {0};

    UT_KVP_PROFILE_GET_STRING("cm.config.HttpUrl", retrievedString);
    strncpy(HttpUrl, retrievedString, sizeof(HttpUrl));

    char *pHttpUrl = HttpUrl;
    char *pfilename = "";

    UT_LOG_DEBUG("Invoking cm_hal_Set_HTTP_Download_Url with valid URL and empty filename");
    int ret = cm_hal_Set_HTTP_Download_Url(pHttpUrl, pfilename);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the cm_hal_Set_HTTP_Download_Url function with valid URL and filename with special characters
*
* This test is designed to verify the cm_hal_Set_HTTP_Download_Url function. The function is tested with a valid URL and a filename containing special characters to ensure that it can handle such inputs correctly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 063@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Set_HTTP_Download_Url with valid URL and filename with special characters | pHttpUrl , pfilename | The return value should be RETURN_ERR | The function should handle special characters in the filename correctly |
*/
void test_l1_cm_hal_negative5_Set_HTTP_Download_Url(void)
{
    gTestID = 63;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char HttpUrl[MAX_STRING_LENGTH] = {0};  
    char retrievedString[MAX_STRING_LENGTH] = {0};
    
    UT_KVP_PROFILE_GET_STRING("cm.config.HttpUrl", retrievedString);
    strncpy(HttpUrl, retrievedString, sizeof(HttpUrl));   

    char *pHttpUrl = HttpUrl;
    char *pfilename = "Invalid Image@#";

    UT_LOG_DEBUG("Invoking cm_hal_Set_HTTP_Download_Url with valid URL and filename with special characters");
    int ret = cm_hal_Set_HTTP_Download_Url(pHttpUrl, pfilename);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the cm_hal_Set_HTTP_Download_Url function with valid URL and filename with special characters
*
* This test is designed to verify the cm_hal_Set_HTTP_Download_Url function. The function is tested with a valid URL and a filename containing special characters to ensure that it can handle such inputs correctly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 064@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Set_HTTP_Download_Url with Invalid URL with special characters and valid filename | pHttpUrl , pfilename | The return value should be RETURN_ERR | The function should handle special characters in the filename correctly |
*/
void test_l1_cm_hal_negative6_Set_HTTP_Download_Url(void)
{
    gTestID = 64;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char filename[MAX_STRING_LENGTH] = {0};
    char retrievedString[MAX_STRING_LENGTH] = {0};

    UT_KVP_PROFILE_GET_STRING("cm.config.filename", retrievedString);
    strncpy(filename, retrievedString, sizeof(filename));

    char *pHttpUrl = "Invalid URL@#";
    char *pfilename = filename;

    UT_LOG_DEBUG("Invoking cm_hal_Set_HTTP_Download_Url with invalid URL with special characters and valid filename");
    int ret = cm_hal_Set_HTTP_Download_Url(pHttpUrl, pfilename);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the cm_hal_Get_HTTP_Download_Url function
*
* This test case is designed to test the cm_hal_Get_HTTP_Download_Url function. It checks whether the function returns the correct HTTP download URL and filename when provided with valid buffers.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 065@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Get_HTTP_Download_Url with valid buffers | pHttpUrl = valid buffer, pfilename = valid buffer | The function should return RETURN_OK and the buffers should not be empty | Should be successful |
*/
void test_l1_cm_hal_positive1_Get_HTTP_Download_Url(void)
{
    gTestID = 65;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char pHttpUrl[200];
    char pfilename[200];

    UT_LOG_DEBUG("Invoking cm_hal_Get_HTTP_Download_Url with valid buffers");
    int ret = cm_hal_Get_HTTP_Download_Url(pHttpUrl, pfilename);

    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_ASSERT_STRING_NOT_EQUAL(pHttpUrl, "");
    UT_ASSERT_STRING_NOT_EQUAL(pfilename, "");

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the cm_hal_Get_HTTP_Download_Url API when invoked with NULL pHttpUrl buffer.
*
* In this test, the cm_hal_Get_HTTP_Download_Url API is invoked with NULL pHttpUrl buffer and the return value is checked to be RETURN_ERR. This is to ensure that the API handles the error scenario correctly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 066@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Get_HTTP_Download_Url with NULL pHttpUrl buffer | pHttpUrl = NULL, pfilename = pfilename | The return value should be RETURN_ERR | The API should handle the error scenario correctly |
*/
void test_l1_cm_hal_negative1_Get_HTTP_Download_Url(void)
{
    gTestID = 66;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char pfilename[200];

    UT_LOG_DEBUG("Invoking cm_hal_Get_HTTP_Download_Url with NULL pHttpUrl buffer");
    int ret = cm_hal_Get_HTTP_Download_Url(NULL, pfilename);

    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the cm_hal_Get_HTTP_Download_Url API when passed NULL for pfilename buffer.
*
* In this test, the cm_hal_Get_HTTP_Download_Url API is invoked with NULL for pfilename buffer. The API is expected to return an error in this scenario.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 067@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Get_HTTP_Download_Url with NULL pfilename buffer | pHttpUrl = empty buffer, pfilename = NULL | The return value should be RETURN_ERR | The API should handle NULL input gracefully |
*/
void test_l1_cm_hal_negative2_Get_HTTP_Download_Url(void)
{
    gTestID = 67;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char pHttpUrl[200];

    UT_LOG_DEBUG("Invoking cm_hal_Get_HTTP_Download_Url with NULL pfilename buffer");
    int ret = cm_hal_Get_HTTP_Download_Url(pHttpUrl, NULL);

    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the functionality of the cm_hal_Get_HTTP_Download_Url API when invoked with larger buffers.
*
* This test is designed to verify the correct operation of the cm_hal_Get_HTTP_Download_Url API. The API is invoked with larger buffers for the HTTP URL and filename. The test checks if the API returns the correct status and if the buffers are filled correctly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 068@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Get_HTTP_Download_Url with larger buffers for HTTP URL and filename | pHttpUrl = large buffer, pfilename = large buffer | The return value should be RETURN_OK and the buffers should not be empty | Should be successful |
*/
void test_l1_cm_hal_positive2_Get_HTTP_Download_Url(void)
{
    gTestID = 68;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char pHttpUrl[300];
    char pfilename[300];

    UT_LOG_DEBUG("Invoking cm_hal_Get_HTTP_Download_Url with larger buffers");
    int ret = cm_hal_Get_HTTP_Download_Url(pHttpUrl, pfilename);

    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_ASSERT_STRING_NOT_EQUAL(pHttpUrl, "");
    UT_ASSERT_STRING_NOT_EQUAL(pfilename, "");

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of the cm_hal_Set_HTTP_Download_Interface API when provided with valid input.
*
* This test invokes the cm_hal_Set_HTTP_Download_Interface API with a valid interface value and checks if the API returns the expected result. This is done to ensure that the API behaves as expected when provided with valid input.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 069@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Set_HTTP_Download_Interface with a valid interface value | interface = 0 | The return value should be RETURN_OK | The test should pass |
*/
void test_l1_cm_hal_positive1_Set_HTTP_Download_Interface(void)
{
    gTestID = 69;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    unsigned int interface = 0;
    int ret;

    UT_LOG_DEBUG("Invoking cm_hal_Set_HTTP_Download_Interface with interface value: %u", interface);
    ret = cm_hal_Set_HTTP_Download_Interface(interface);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    if (ret != RETURN_OK) {
        UT_LOG_ERROR("cm_hal_Set_HTTP_Download_Interface failed with return value: %d", ret);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of the cm_hal_Set_HTTP_Download_Interface API when a valid interface value is provided.
*
* In this test, the cm_hal_Set_HTTP_Download_Interface API is invoked with a valid interface value. The test verifies that the API returns the expected return value and does not produce any errors.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 070@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Set_HTTP_Download_Interface API with a valid interface value | interface = 1 | The return value should be RETURN_OK | The test should pass without any errors |
*/
void test_l1_cm_hal_positive2_Set_HTTP_Download_Interface(void)
{
    gTestID = 70;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    unsigned int interface = 1;
    int ret;

    UT_LOG_DEBUG("Invoking cm_hal_Set_HTTP_Download_Interface with interface value: %u", interface);
    ret = cm_hal_Set_HTTP_Download_Interface(interface);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    if (ret != RETURN_OK) {
        UT_LOG_ERROR("cm_hal_Set_HTTP_Download_Interface failed with return value: %d", ret);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the cm_hal_Set_HTTP_Download_Interface API for invalid interface value
*
* This test invokes the cm_hal_Set_HTTP_Download_Interface API with an invalid interface value and expects it to return an error. This is to ensure that the API correctly handles invalid inputs.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 071@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Set_HTTP_Download_Interface with invalid interface value | interface = 2 | The return value should be RETURN_ERR | The API should handle invalid inputs correctly |
*/
void test_l1_cm_hal_negative1_Set_HTTP_Download_Interface(void)
{
    gTestID = 71;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    unsigned int interface = 2;
    int ret;

    UT_LOG_DEBUG("Invoking cm_hal_Set_HTTP_Download_Interface with invalid interface value: %u", interface);
    ret = cm_hal_Set_HTTP_Download_Interface(interface);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    if (ret != RETURN_ERR) {
        UT_LOG_ERROR("cm_hal_Set_HTTP_Download_Interface did not fail as expected with return value: %d", ret);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the cm_hal_Get_HTTP_Download_Interface API
*
* This test invokes the cm_hal_Get_HTTP_Download_Interface API with a valid pointer and checks if the return value is as expected and the interface value is either 0 or 1.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 072@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Get_HTTP_Download_Interface with valid pointer | interface = valid pointer | Return value should be RETURN_OK and interface value should be either 0 or 1 | Should be successful |
*/
void test_l1_cm_hal_positive1_Get_HTTP_Download_Interface(void)
{
    gTestID = 72;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    unsigned int interface;
    int ret;

    UT_LOG_DEBUG("Invoking cm_hal_Get_HTTP_Download_Interface with valid pointer");
    ret = cm_hal_Get_HTTP_Download_Interface(&interface);

    UT_LOG_DEBUG("cm_hal_Get_HTTP_Download_Interface returned %d, interface: %u", ret, interface);
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_ASSERT_TRUE(interface == 0 || interface == 1);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the cm_hal_Get_HTTP_Download_Interface API when invoked with NULL pointer
*
* In this test, the cm_hal_Get_HTTP_Download_Interface API is invoked with NULL pointer to test the robustness of the API. The API should handle this scenario gracefully and return an error.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 073@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Get_HTTP_Download_Interface API with NULL pointer | NULL | The API should return an error | The API should handle this scenario gracefully and return an error |
*/
void test_l1_cm_hal_negative1_Get_HTTP_Download_Interface(void)
{
    gTestID = 73;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret;

    UT_LOG_DEBUG("Invoking cm_hal_Get_HTTP_Download_Interface with NULL pointer");
    ret = cm_hal_Get_HTTP_Download_Interface(NULL);

    UT_LOG_DEBUG("cm_hal_Get_HTTP_Download_Interface returned %d", ret);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the HTTP download status
*
* This test invokes the cm_hal_Get_HTTP_Download_Status API and checks if the status returned is 0. This is done to ensure that the HTTP download is functioning correctly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 074@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Get_HTTP_Download_Status API | No input data required for this API | The status returned should be 0 | If the status is not 0, the test case fails |
*/
void test_l1_cm_hal_positive1_Get_HTTP_Download_Status(void)
{
    gTestID = 74;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int status = cm_hal_Get_HTTP_Download_Status();
    UT_LOG_DEBUG("Status returned from cm_hal_Get_HTTP_Download_Status: %d", status);
    UT_LOG_DEBUG("Invoking cm_hal_Get_HTTP_Download_Status");
    UT_ASSERT_EQUAL(status, 0);

    if (status != 0) {
        UT_LOG_ERROR("Test case failed. Expected 0, got %d\n", status);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks if the cm_hal_Reboot_Ready function works as expected
*
* This test invokes the cm_hal_Reboot_Ready function with a valid ULONG pointer and checks if the return value and status are as expected.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 075@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Reboot_Ready with valid ULONG pointer | status = uninitialized ULONG variable | The return value should be RETURN_OK and status should be either 1 or 2 | Should be successful |
*/
void test_l1_cm_hal_positive1_Reboot_Ready(void)
{
    gTestID = 75;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG status;
    int ret = cm_hal_Reboot_Ready(&status);

    UT_LOG_DEBUG("Invoking cm_hal_Reboot_Ready with valid ULONG pointer");
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_ASSERT(status == 1 || status == 2);

    if (ret != RETURN_OK || (status != 1 && status != 2)) {
        UT_LOG_ERROR("Test failed: cm_hal_Reboot_Ready returned %d, status: %lu\n", ret, status);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the behavior of the cm_hal_Reboot_Ready function when passed a NULL pointer
*
* This test is designed to verify the robustness of the cm_hal_Reboot_Ready function. It tests the function's ability to handle invalid input, specifically a NULL pointer.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 076@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Reboot_Ready with NULL pointer | NULL | The function should return RETURN_ERR | The function should handle invalid input gracefully |
*/
void test_l1_cm_hal_negative1_Reboot_Ready(void)
{
    gTestID = 76;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = cm_hal_Reboot_Ready(NULL);

    UT_LOG_DEBUG("Invoking cm_hal_Reboot_Ready with NULL pointer");
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    if (ret != RETURN_ERR) {
        UT_LOG_ERROR("Test failed: cm_hal_Reboot_Ready returned %d, expected: %d\n", ret, RETURN_ERR);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of the cm_hal_HTTP_Download_Reboot_Now API
*
* This test invokes the cm_hal_HTTP_Download_Reboot_Now API and checks if the return value is as expected. The API is expected to initiate a HTTP download and reboot the system immediately.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 077@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the cm_hal_HTTP_Download_Reboot_Now API | No input data required for this API | The return value should be RETURN_OK | If the return value is not RETURN_OK, the test fails |
*/
void test_l1_cm_hal_positive1_HTTP_Download_Reboot_Now(void)
{
    gTestID = 77;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = cm_hal_HTTP_Download_Reboot_Now();

    UT_LOG_DEBUG("Invoking cm_hal_HTTP_Download_Reboot_Now");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    if (ret != RETURN_OK) {
        UT_LOG_ERROR("cm_hal_HTTP_Download_Reboot_Now failed with return status %d\n", ret);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the cm_hal_FWupdateAndFactoryReset function with invalid image name
*
* In this test, the cm_hal_FWupdateAndFactoryReset function is invoked with an invalid image name to ensure that the function handles error conditions correctly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 078@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_FWupdateAndFactoryReset function with invalid image name | pUrl , pImagename = "Invalid#Image@Name" | The function should return an error | The function should handle invalid inputs correctly |
*/
void test_l1_cm_hal_negative1_FWupdateAndFactoryReset(void)
{
    gTestID = 78;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char HttpUrl[MAX_STRING_LENGTH] = {0};  
    char retrievedString[MAX_STRING_LENGTH] = {0};
    
    UT_KVP_PROFILE_GET_STRING("cm.config.HttpUrl", retrievedString);
    strncpy(HttpUrl, retrievedString, sizeof(HttpUrl));

    char *pUrl = HttpUrl;
    char *pImagename = "Invalid#Image@Name";
    int ret = cm_hal_FWupdateAndFactoryReset(pUrl, pImagename);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the cm_hal_FWupdateAndFactoryReset API when provided with a NULL URL.
*
* In this test, the cm_hal_FWupdateAndFactoryReset API is invoked with a NULL URL and a valid image name. The test verifies that the API handles the error condition correctly and returns an error code.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 079@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the cm_hal_FWupdateAndFactoryReset API with a NULL URL and a valid image name | pUrl = NULL, pImagename | The API should return an error code | The API should handle the error condition correctly |
*/
void test_l1_cm_hal_negative2_FWupdateAndFactoryReset(void)
{
    gTestID = 79;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
 
    char filename[MAX_STRING_LENGTH] = {0};
    char retrievedString[MAX_STRING_LENGTH] = {0};
    
    UT_KVP_PROFILE_GET_STRING("cm.config.filename", retrievedString);
    strncpy(filename, retrievedString, sizeof(filename));

    char *pUrl = NULL;
    char *pImagename = filename;
    int ret = cm_hal_FWupdateAndFactoryReset(pUrl, pImagename);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the cm_hal_FWupdateAndFactoryReset API when the image name is NULL.
*
* In this test, the cm_hal_FWupdateAndFactoryReset API is invoked with a valid URL and NULL image name. The test verifies that the API returns an error in this scenario.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 080@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the cm_hal_FWupdateAndFactoryReset API with a valid URL and NULL image name | pUrl , pImagename = NULL | The API should return an error | The API is expected to handle the NULL image name and return an error |
*/
void test_l1_cm_hal_negative3_FWupdateAndFactoryReset(void)
{
    gTestID = 80;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char HttpUrl[MAX_STRING_LENGTH] = {0};  
    char retrievedString[MAX_STRING_LENGTH] = {0};
    
    UT_KVP_PROFILE_GET_STRING("cm.config.HttpUrl", retrievedString);
    strncpy(HttpUrl, retrievedString, sizeof(HttpUrl));

    char *pUrl = HttpUrl;
    char *pImagename = NULL;

    int ret = cm_hal_FWupdateAndFactoryReset(pUrl, pImagename);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the cm_hal_FWupdateAndFactoryReset API
*
* In this test, the cm_hal_FWupdateAndFactoryReset API is invoked with an empty URL and a valid image name. The API is expected to return an error as the URL is invalid.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 081@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_FWupdateAndFactoryReset API with empty URL and valid image name | pUrl = "", pImagename | The API should return an error | The test is expected to fail due to invalid URL |
*/
void test_l1_cm_hal_negative4_FWupdateAndFactoryReset(void)
{
    gTestID = 81;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
 
    char filename[MAX_STRING_LENGTH] = {0};
    char retrievedString[MAX_STRING_LENGTH] = {0};
    
    UT_KVP_PROFILE_GET_STRING("cm.config.filename", retrievedString);
    strncpy(filename, retrievedString, sizeof(filename));

    char *pUrl = "";
    char *pImagename = filename;
    int ret = cm_hal_FWupdateAndFactoryReset(pUrl, pImagename);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the cm_hal_FWupdateAndFactoryReset API
*
* In this test, the cm_hal_FWupdateAndFactoryReset API is invoked with an empty image name. The API is expected to return an error in this scenario.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 082@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_FWupdateAndFactoryReset API with empty image name | pUrl , pImagename = "" | The API should return an error | The function should handle invalid inputs gracefully |
*/
void test_l1_cm_hal_negative5_FWupdateAndFactoryReset(void)
{
    gTestID = 82;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char HttpUrl[MAX_STRING_LENGTH] = {0};  
    char retrievedString[MAX_STRING_LENGTH] = {0};
    
    UT_KVP_PROFILE_GET_STRING("cm.config.HttpUrl", retrievedString);
    strncpy(HttpUrl, retrievedString, sizeof(HttpUrl));

    char *pUrl = HttpUrl;
    char *pImagename = "";
    int ret = cm_hal_FWupdateAndFactoryReset(pUrl, pImagename);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the behavior of the cm_hal_FWupdateAndFactoryReset API when provided with invalid inputs.
*
* In this test, we are checking if the cm_hal_FWupdateAndFactoryReset API returns an error when provided with an invalid URL and a valid image name. This is important to ensure that the API has proper error handling mechanisms in place.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 083@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_FWupdateAndFactoryReset API with invalid URL and valid image name | pUrl = "invalid_url", pImagename | The return value should be RETURN_ERR | The API should handle invalid inputs gracefully |
*/
void test_l1_cm_hal_negative6_FWupdateAndFactoryReset(void)
{
    gTestID = 83;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
 
    char filename[MAX_STRING_LENGTH] = {0};
    char retrievedString[MAX_STRING_LENGTH] = {0};

    UT_KVP_PROFILE_GET_STRING("cm.config.filename", retrievedString);
    strncpy(filename, retrievedString, sizeof(filename));

    char *pUrl = "invalid_url";
    char *pImagename = filename;
    int ret = cm_hal_FWupdateAndFactoryReset(pUrl, pImagename);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the behavior of the cm_hal_FWupdateAndFactoryReset API when provided with an invalid image name.
*
* In this test, the cm_hal_FWupdateAndFactoryReset API is invoked with an invalid image name to ensure that the API handles such scenarios correctly and returns an error.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 084@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the cm_hal_FWupdateAndFactoryReset API with an invalid image name | pUrl , pImagename = "InvalidImageName" | The return value should be RETURN_ERR | The API should handle invalid inputs gracefully |
*/
void test_l1_cm_hal_negative7_FWupdateAndFactoryReset(void)
{
    gTestID = 84;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    char HttpUrl[MAX_STRING_LENGTH] = {0};  
    char retrievedString[MAX_STRING_LENGTH] = {0};
    
    UT_KVP_PROFILE_GET_STRING("cm.config.HttpUrl", retrievedString);
    strncpy(HttpUrl, retrievedString, sizeof(HttpUrl));

    char *pUrl = HttpUrl;
    char *pImagename = "InvalidImageName";
    int ret = cm_hal_FWupdateAndFactoryReset(pUrl, pImagename);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the successful reinitialization of the MAC address
*
* In this test, the cm_hal_ReinitMac function is invoked and the return value is checked to ensure the MAC address is successfully reinitialized.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 085@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the cm_hal_ReinitMac function | No input data required for this function | The return value should be RETURN_OK | If the return value is not RETURN_OK, the test fails |
*/
void test_l1_cm_hal_positive1_ReinitMac(void)
{
    gTestID = 85;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = cm_hal_ReinitMac();

    UT_LOG_DEBUG("Invoking cm_hal_ReinitMac");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    if (ret != RETURN_OK) {
        UT_LOG_ERROR("cm_hal_ReinitMac failed with return status %d", ret);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the docsis_GetProvIpType API
*
* This test invokes the docsis_GetProvIpType API with a valid buffer and checks if the return value is as expected.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 086@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetProvIpType with valid buffer | ipType = valid buffer | Return value should be RETURN_OK | Should be successful |
*/
void test_l1_cm_hal_positive1_docsis_GetProvIpType(void)
{
    gTestID = 86;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR ipType[10];
    int ret;

    UT_LOG_DEBUG("Invoking docsis_GetProvIpType with valid buffer");
    ret = docsis_GetProvIpType(ipType);

    if (ret == RETURN_OK) {
        UT_LOG_INFO("docsis_GetProvIpType returned %d, IP Type: %s\n", ret, ipType);
    } else {
        UT_LOG_ERROR("docsis_GetProvIpType returned %d, expected RETURN_OK\n", ret);
    }

    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the docsis_GetProvIpType API when invoked with NULL buffer.
*
* In this test, the docsis_GetProvIpType API is invoked with NULL buffer and the return value is checked against the expected return value. This is to ensure that the API handles error conditions correctly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 087@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetProvIpType with NULL buffer | buffer = NULL | The return value should be RETURN_ERR | The API should handle the error condition correctly |
*/
void test_l1_cm_hal_negative1_docsis_GetProvIpType(void)
{
    gTestID = 87;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret;

    UT_LOG_DEBUG("Invoking docsis_GetProvIpType with NULL buffer");
    ret = docsis_GetProvIpType(NULL);

    if (ret == RETURN_ERR) {
        UT_LOG_INFO("docsis_GetProvIpType returned %d, expected RETURN_ERR\n", ret);
    } else {
        UT_LOG_ERROR("docsis_GetProvIpType returned %d, expected RETURN_ERR\n", ret);
    }

    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of the docsis_GetCert API when invoked with a valid buffer.
*
* In this test, the docsis_GetCert API is invoked with a valid buffer. The test verifies that the API returns the expected result and that the certificate path is correctly retrieved.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 088@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetCert with valid buffer | certPath = valid buffer | The return value should be RETURN_OK and the certificate path should be correctly retrieved | Should be successful |
*/
void test_l1_cm_hal_positive1_docsis_GetCert(void)
{
    gTestID = 88;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CHAR certPath[256];
    int ret;

    UT_LOG_DEBUG("Invoking docsis_GetCert with valid buffer");
    ret = docsis_GetCert(certPath);
    UT_LOG_DEBUG("docsis_GetCert returned %d, certPath: %s", ret, certPath);
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the docsis_GetCert API when invoked with NULL buffer
*
* In this test, the docsis_GetCert API is invoked with NULL buffer to verify the negative scenario. The API is expected to return an error in this case. This test is important to ensure the robustness of the API in handling invalid inputs.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 089@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetCert API with NULL buffer | buffer = NULL | The API should return an error | The API is expected to handle invalid inputs gracefully |
*/
void test_l1_cm_hal_negative1_docsis_GetCert(void)
{
    gTestID = 89;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret;

    UT_LOG_DEBUG("Invoking docsis_GetCert with NULL buffer");
    ret = docsis_GetCert(NULL);

    UT_LOG_DEBUG("docsis_GetCert returned %d", ret);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the docsis_GetCertStatus API
*
* This test invokes the docsis_GetCertStatus API with a valid ULONG pointer and checks if the return value is as expected.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 090@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetCertStatus with valid ULONG pointer | certStatus = valid ULONG pointer | Return value should be RETURN_OK | Should be successful |
*/
void test_l1_cm_hal_positive1_docsis_GetCertStatus(void)
{
    gTestID = 90;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG certStatus;
    int ret;

    UT_LOG_DEBUG("Invoking docsis_GetCertStatus with valid ULONG pointer");
    ret = docsis_GetCertStatus(&certStatus);

    UT_LOG_DEBUG("docsis_GetCertStatus returned %d, certStatus: %lu", ret, certStatus);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the behavior of the docsis_GetCertStatus API when invoked with NULL pointer.
*
* In this test, the docsis_GetCertStatus API is invoked with NULL pointer to verify that it returns an error. This is important to ensure that the API handles invalid inputs gracefully.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 091@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetCertStatus API with NULL pointer | docsis_GetCertStatus(NULL) | The return value should be RETURN_ERR | The API should handle invalid inputs gracefully |
*/
void test_l1_cm_hal_negative1_docsis_GetCertStatus(void)
{
    gTestID = 91;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret;

    UT_LOG_DEBUG("Invoking docsis_GetCertStatus with NULL pointer");
    ret = docsis_GetCertStatus(NULL);

    UT_LOG_DEBUG("docsis_GetCertStatus returned %d", ret);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of the cm_hal_Get_CableModemResetCount API
*
* This test invokes the cm_hal_Get_CableModemResetCount API with a valid pointer and checks if the return value is as expected. The test is important to ensure the API is working as expected and is able to fetch the reset count correctly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 092@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Get_CableModemResetCount with valid pointer | resetcnt = 0 | The return value should be RETURN_OK | Should be successful |
*/
void test_l1_cm_hal_positive1_Get_CableModemResetCount(void)
{
    gTestID = 92;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG resetcnt = 0;
    int ret = cm_hal_Get_CableModemResetCount(&resetcnt);

    UT_LOG_DEBUG("Invoking cm_hal_Get_CableModemResetCount with valid pointer");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    if (ret == RETURN_OK) {
        UT_LOG_INFO("Reset count: %lu\n", resetcnt);
    } else {
        UT_LOG_ERROR("Failed to get reset count\n");
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the cm_hal_Get_CableModemResetCount API when invoked with NULL pointer.
*
* In this test, the cm_hal_Get_CableModemResetCount API is invoked with NULL pointer to ensure that the API handles the error condition correctly and returns an error.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 093@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Get_CableModemResetCount API with NULL pointer | NULL | The API should return an error | The API should handle the error condition correctly |
*/
void test_l1_cm_hal_negative1_Get_CableModemResetCount(void)
{
    gTestID = 93;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = cm_hal_Get_CableModemResetCount(NULL);

    UT_LOG_DEBUG("Invoking cm_hal_Get_CableModemResetCount with NULL pointer");
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    if (ret == RETURN_ERR) {
        UT_LOG_INFO("Correctly failed to get reset count with NULL pointer\n");
    } else {
        UT_LOG_ERROR("Unexpectedly succeeded in getting reset count with NULL pointer\n");
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of the cm_hal_Get_LocalResetCount API
*
* This test invokes the cm_hal_Get_LocalResetCount API with a valid pointer to ULONG and checks if the return value is RETURN_OK. The test is designed to ensure that the API is working as expected and is able to retrieve the local reset count successfully.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 094@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Get_LocalResetCount with valid pointer to ULONG | resetcnt = 0 | The return value should be RETURN_OK | The API should work as expected |
*/
void test_l1_cm_hal_positive1_Get_LocalResetCount(void)
{
    gTestID = 94;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG resetcnt = 0;
    int ret = cm_hal_Get_LocalResetCount(&resetcnt);

    UT_LOG_DEBUG("Invoking cm_hal_Get_LocalResetCount with valid pointer to ULONG");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    if (ret != RETURN_OK) {
        UT_LOG_ERROR("cm_hal_Get_LocalResetCount failed with status %d\n", ret);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the cm_hal_Get_LocalResetCount API
*
* In this test, we are trying to invoke the cm_hal_Get_LocalResetCount API with NULL pointer to check if it handles the error scenario gracefully.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 095@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Get_LocalResetCount API with NULL pointer | NULL | The return value should be RETURN_ERR | The API should handle the error scenario gracefully |
*/
void test_l1_cm_hal_negative1_Get_LocalResetCount(void)
{
    gTestID = 95;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = cm_hal_Get_LocalResetCount(NULL);

    UT_LOG_DEBUG("Invoking cm_hal_Get_LocalResetCount with NULL pointer");
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    if (ret != RETURN_ERR) {
        UT_LOG_ERROR("cm_hal_Get_LocalResetCount failed with status %d\n", ret);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of the cm_hal_Get_DocsisResetCount API
*
* This test invokes the cm_hal_Get_DocsisResetCount API with a valid pointer and checks if the return value is as expected. The purpose of this test is to ensure that the API is working as expected and is able to retrieve the reset count correctly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 096@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Get_DocsisResetCount with a valid pointer | resetcnt = 0 | The return value should be RETURN_OK | Should be successful |
*/
void test_l1_cm_hal_positive1_Get_DocsisResetCount(void)
{
    gTestID = 96;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG resetcnt = 0;
    int ret = cm_hal_Get_DocsisResetCount(&resetcnt);

    UT_LOG_DEBUG("Invoking cm_hal_Get_DocsisResetCount with valid pointer");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    if (ret != RETURN_OK) {
        UT_LOG_ERROR("cm_hal_Get_DocsisResetCount failed with status %d\n", ret);
    } else {
        UT_LOG_INFO("Reset count: %lu\n", resetcnt);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the behavior of the cm_hal_Get_DocsisResetCount API when invoked with a NULL pointer.
*
* This test is important to ensure that the API handles invalid input parameters gracefully and returns the appropriate error code. This is a basic level test.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 097@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Get_DocsisResetCount API with NULL pointer | NULL | The API should return RETURN_ERR | The API should handle invalid input parameters gracefully |
*/
void test_l1_cm_hal_negative1_Get_DocsisResetCount(void)
{
    gTestID = 97;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = cm_hal_Get_DocsisResetCount(NULL);

    UT_LOG_DEBUG("Invoking cm_hal_Get_DocsisResetCount with NULL pointer");
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    if (ret != RETURN_ERR) {
        UT_LOG_ERROR("cm_hal_Get_DocsisResetCount failed with status %d\n", ret);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of the cm_hal_Get_ErouterResetCount API
*
* This test case is designed to validate the positive scenario of the cm_hal_Get_ErouterResetCount API. It checks if the API is able to successfully retrieve the Erouter reset count when provided with a valid pointer.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 098@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the cm_hal_Get_ErouterResetCount API with a valid pointer | resetcnt = 0 | The return value should be RETURN_OK | Should be successfull |
*/
void test_l1_cm_hal_positive1_Get_ErouterResetCount(void)
{
    gTestID = 98;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG resetcnt = 0;
    int ret = cm_hal_Get_ErouterResetCount(&resetcnt);

    UT_LOG_DEBUG("Invoking cm_hal_Get_ErouterResetCount with valid pointer");
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    if (ret != RETURN_OK) {
        UT_LOG_ERROR("cm_hal_Get_ErouterResetCount failed with status %d\n", ret);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the behavior of the cm_hal_Get_ErouterResetCount API when invoked with a NULL pointer.
*
* This test is important to ensure that the API handles invalid input gracefully and returns the appropriate error code. This is a basic level test.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 099@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_Get_ErouterResetCount API with NULL pointer | input = NULL | The API should return RETURN_ERR | The API should handle invalid input gracefully |
*/
void test_l1_cm_hal_negative1_Get_ErouterResetCount(void)
{
    gTestID = 99;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret = cm_hal_Get_ErouterResetCount(NULL);

    UT_LOG_DEBUG("Invoking cm_hal_Get_ErouterResetCount with NULL pointer");
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    if (ret != RETURN_ERR) {
        UT_LOG_ERROR("cm_hal_Get_ErouterResetCount failed with status %d\n", ret);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the functionality of the cm_hal_HTTP_LED_Flash API when the LED flash is set to true.
*
* In this test, the cm_hal_HTTP_LED_Flash API is invoked with the LedFlash parameter set to true. The test verifies that the API returns the expected result when the LED flash is enabled.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 100@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_HTTP_LED_Flash with LedFlash set to true | LedFlash = true | The return value should be RETURN_OK | The test should pass if the API returns the expected result |
*/
void test_l1_cm_hal_positive1_HTTP_LED_Flash(void)
{
    gTestID = 100;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN LedFlash = TRUE;
    int ret;

    UT_LOG_DEBUG("Invoking cm_hal_HTTP_LED_Flash with LedFlash set to true");
    ret = cm_hal_HTTP_LED_Flash(LedFlash);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the functionality of the cm_hal_HTTP_LED_Flash API when the LedFlash is set to false.
*
* In this test, the cm_hal_HTTP_LED_Flash API is invoked with LedFlash set to false. The test verifies that the API returns the expected result when invoked with this specific set of input data.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 101@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_HTTP_LED_Flash API with LedFlash set to false | LedFlash = false | The return value should be RETURN_OK | The test should pass |
*/
void test_l1_cm_hal_positive2_HTTP_LED_Flash(void)
{
    gTestID = 101;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN LedFlash = FALSE;
    int ret;

    UT_LOG_DEBUG("Invoking cm_hal_HTTP_LED_Flash with LedFlash set to false");
    ret = cm_hal_HTTP_LED_Flash(LedFlash);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the cm_hal_HTTP_LED_Flash API when a non-boolean value is passed as an argument.
*
* In this test, the cm_hal_HTTP_LED_Flash API is invoked with a non-boolean value for the LedFlash parameter. The objective is to ensure that the API can handle such erroneous input gracefully and return the appropriate error code.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 102@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_HTTP_LED_Flash with LedFlash set to a non-boolean value | LedFlash = 2 | The return value should be RETURN_ERR | The API should handle the erroneous input gracefully and return the appropriate error code |
*/
void test_l1_cm_hal_negative1_HTTP_LED_Flash(void)
{
    gTestID = 102;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN LedFlash = 2; // non-boolean value
    int ret;

    UT_LOG_DEBUG("Invoking cm_hal_HTTP_LED_Flash with LedFlash set to a non-boolean value");
    ret = cm_hal_HTTP_LED_Flash(LedFlash);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the function docsis_GetDsOfdmChanTable
*
* This test invokes the function docsis_GetDsOfdmChanTable with valid pointers and checks if the return value is as expected and the output parameters are within the expected range.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 103@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetDsOfdmChanTable with valid pointers | ppinfo = valid pointer, output_NumberOfEntries = valid pointer | Return value should be RETURN_OK and output parameters should be within the expected range | Should be successful |
* | 02 | Validate the values in the structure |  | All assertions should pass | Should be successfull |
*/
void test_l1_cm_hal_positive1_docsis_GetDsOfdmChanTable(void)
{
    gTestID = 103;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PDOCSIF31_CM_DS_OFDM_CHAN ppinfo = (PDOCSIF31_CM_DS_OFDM_CHAN)malloc(sizeof(DOCSIF31_CM_DS_OFDM_CHAN));
    int output_NumberOfEntries;
    int ret;

    if (ppinfo == NULL) {
        UT_LOG_ERROR("Memory allocation failed for ppinfo");
        UT_FAIL("Memory allocation failed");
        return;
    }

    UT_LOG_DEBUG("Invoking docsis_GetDsOfdmChanTable with valid pointers");
    ret = docsis_GetDsOfdmChanTable(&ppinfo, &output_NumberOfEntries);

    UT_ASSERT_EQUAL(ret, RETURN_OK);
    
    if (ret == RETURN_OK) {
        // Check if ppinfo is still valid after API call
        if (ppinfo == NULL) {
            UT_LOG_ERROR("ppinfo is NULL after API call");
            UT_FAIL("ppinfo is NULL after API call");
            return;
        }
        // Debug logs after NULL check
        UT_LOG_DEBUG("ppinfo->ChannelId is : %u", ppinfo->ChannelId);
        UT_LOG_DEBUG("ppinfo->ChanIndicator is : %u", ppinfo->ChanIndicator);
        UT_LOG_DEBUG("ppinfo->SubcarrierZeroFreq is : %u", ppinfo->SubcarrierZeroFreq);
        UT_LOG_DEBUG("ppinfo->FirstActiveSubcarrierNum is : %u", ppinfo->FirstActiveSubcarrierNum);
        UT_LOG_DEBUG("ppinfo->LastActiveSubcarrierNum is : %u", ppinfo->LastActiveSubcarrierNum);
        UT_LOG_DEBUG("ppinfo->NumActiveSubcarriers is : %u", ppinfo->NumActiveSubcarriers);
        UT_LOG_DEBUG("ppinfo->SubcarrierSpacing is : %u", ppinfo->SubcarrierSpacing);
        UT_LOG_DEBUG("ppinfo->CyclicPrefix is : %u", ppinfo->CyclicPrefix);
        UT_LOG_DEBUG("ppinfo->RollOffPeriod is : %u", ppinfo->RollOffPeriod);
        UT_LOG_DEBUG("ppinfo->PlcFreq is : %u", ppinfo->PlcFreq);
        UT_LOG_DEBUG("ppinfo->NumPilots is : %u", ppinfo->NumPilots);
        UT_LOG_DEBUG("ppinfo->TimeInterleaverDepth is : %u", ppinfo->TimeInterleaverDepth);
        UT_LOG_DEBUG("ppinfo->averageSNR is : %s", ppinfo->averageSNR);
        UT_LOG_DEBUG("ppinfo->PowerLevel is : %s", ppinfo->PowerLevel);
        UT_LOG_DEBUG("ppinfo->PlcTotalCodewords is : %llu", ppinfo->PlcTotalCodewords);
        UT_LOG_DEBUG("ppinfo->PlcUnreliableCodewords is : %llu", ppinfo->PlcUnreliableCodewords);
        UT_LOG_DEBUG("ppinfo->NcpTotalFields is : %llu", ppinfo->NcpTotalFields);
        UT_LOG_DEBUG("ppinfo->NcpFieldCrcFailures is : %llu", ppinfo->NcpFieldCrcFailures);

        if(output_NumberOfEntries >= 0)
        {
            UT_LOG("output_NumberOfEntries is %d which is a valid value", output_NumberOfEntries);
            UT_PASS("output_NumberOfEntries validation success");
        }
        else
        {
            UT_LOG("output_NumberOfEntries is %d which is an invalid value", output_NumberOfEntries);
            UT_FAIL("output_NumberOfEntries validation failed");
        }

        if(ppinfo->ChanIndicator == 2 || ppinfo->ChanIndicator == 3 || ppinfo->ChanIndicator == 4)
        {
            UT_LOG("ChanIndicator is %u which is a valid value", ppinfo->ChanIndicator);
            UT_PASS("ChanIndicator validation success");
        }
        else
        {
            UT_LOG("ChanIndicator is %u which is an invalid value", ppinfo->ChanIndicator);
            UT_FAIL("ChanIndicator validation failed");
        }

        if(ppinfo->FirstActiveSubcarrierNum >= 148 && ppinfo->FirstActiveSubcarrierNum <= 7895)
        {
            UT_LOG("FirstActiveSubcarrierNum is %u which is a valid value", ppinfo->FirstActiveSubcarrierNum);
            UT_PASS("FirstActiveSubcarrierNum validation success");
        }
        else
        {
            UT_LOG("FirstActiveSubcarrierNum is %u which is an invalid value", ppinfo->FirstActiveSubcarrierNum);
            UT_FAIL("FirstActiveSubcarrierNum validation failed");
        }

        if(ppinfo->LastActiveSubcarrierNum >= 148 && ppinfo->LastActiveSubcarrierNum <= 7895)
        {
            UT_LOG("LastActiveSubcarrierNum is %u which is a valid value", ppinfo->LastActiveSubcarrierNum);
            UT_PASS("LastActiveSubcarrierNum validation success");
        }
        else
        {
            UT_LOG("LastActiveSubcarrierNum is %u which is an invalid value", ppinfo->LastActiveSubcarrierNum);
            UT_FAIL("LastActiveSubcarrierNum validation failed");
        }

        if(ppinfo->SubcarrierSpacing == 50 || ppinfo->SubcarrierSpacing == 25)
        {
            UT_LOG("SubcarrierSpacing is %u which is a valid value", ppinfo->SubcarrierSpacing);
            UT_PASS("SubcarrierSpacing validation success");
        }
        else
        {
            UT_LOG("SubcarrierSpacing is %u which is an invalid value", ppinfo->SubcarrierSpacing);
            UT_FAIL("SubcarrierSpacing validation failed");
        }

        if((ppinfo->CyclicPrefix * 64) % 20 == 0)
        {
            UT_LOG("CyclicPrefix is %u which is a valid value", ppinfo->CyclicPrefix);
            UT_PASS("CyclicPrefix validation success");
        }
        else
        {
            UT_LOG("CyclicPrefix is %u which is an invalid value", ppinfo->CyclicPrefix);
            UT_FAIL("CyclicPrefix validation failed");
        }
    }

    if (ppinfo != NULL) {
        free(ppinfo);
    }
    
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the behavior of the docsis_GetDsOfdmChanTable API when invoked with NULL ppinfo pointer.
*
* The test invokes the docsis_GetDsOfdmChanTable API with NULL ppinfo pointer and checks if the API returns the expected error code. This is to ensure that the API handles invalid input parameters correctly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 104@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetDsOfdmChanTable API with NULL ppinfo pointer | ppinfo = NULL, output_NumberOfEntries = address of an integer variable | The API should return an error code | The API should handle invalid input parameters correctly |
*/
void test_l1_cm_hal_negative1_docsis_GetDsOfdmChanTable(void)
{
    gTestID = 104;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int output_NumberOfEntries;
    int ret;

    UT_LOG_DEBUG("Invoking docsis_GetDsOfdmChanTable with NULL ppinfo pointer");
    ret = docsis_GetDsOfdmChanTable(NULL, &output_NumberOfEntries);

    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the docsis_GetDsOfdmChanTable API for negative scenario where output_NumberOfEntries pointer is NULL
*
* This test is designed to validate the behavior of the docsis_GetDsOfdmChanTable API when it is invoked with NULL output_NumberOfEntries pointer. The API is expected to return an error in this scenario.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 105@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetDsOfdmChanTable API with NULL output_NumberOfEntries pointer | ppinfo = NULL, output_NumberOfEntries = NULL | The return value should be RETURN_ERR | The API should handle the NULL pointer gracefully and return an error |
*/
void test_l1_cm_hal_negative2_docsis_GetDsOfdmChanTable(void)
{
    gTestID = 105;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PDOCSIF31_CM_DS_OFDM_CHAN ppinfo = NULL;
    int *output_NumberOfEntries = NULL;
    int ret;

    UT_LOG_DEBUG("Invoking docsis_GetDsOfdmChanTable with NULL output_NumberOfEntries pointer");
    ret = docsis_GetDsOfdmChanTable(&ppinfo, output_NumberOfEntries);

    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the function docsis_GetUsOfdmaChanTable
*
* This test invokes the function docsis_GetUsOfdmaChanTable with valid pointers and checks if the function returns the expected status and output. The test also verifies the values of the output parameters.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 106@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetUsOfdmaChanTable with valid pointers | ppinfo = valid pointer, output_NumberOfEntries = valid pointer | The function should return RETURN_OK and output_NumberOfEntries should be greater than or equal to 0. | Should be successful |
* | 02 | Validate the values in the structure |  | All assertions should pass | Should be successfull |
*/
void test_l1_cm_hal_positive1_docsis_GetUsOfdmaChanTable(void)
{
    gTestID = 106;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PDOCSIF31_CM_US_OFDMA_CHAN ppinfo = (PDOCSIF31_CM_US_OFDMA_CHAN)malloc(sizeof(DOCSIF31_CM_US_OFDMA_CHAN));
    int output_NumberOfEntries;
    int status;

    UT_LOG_DEBUG("Invoking docsis_GetUsOfdmaChanTable with valid pointers");
    status = docsis_GetUsOfdmaChanTable(&ppinfo, &output_NumberOfEntries);

    UT_ASSERT_EQUAL(status, RETURN_OK);
    if (status == RETURN_OK) {
        UT_ASSERT(output_NumberOfEntries >= 0);
        if(ppinfo->FirstActiveSubcarrierNum >= 74 && ppinfo->FirstActiveSubcarrierNum <= 3947)
        {
            UT_LOG("FirstActiveSubcarrierNum is %u which is a valid value", ppinfo->FirstActiveSubcarrierNum);
            UT_PASS("FirstActiveSubcarrierNum validation success");
        }
        else
        {
            UT_LOG("FirstActiveSubcarrierNum is %u which is an invalid value", ppinfo->FirstActiveSubcarrierNum);
            UT_FAIL("FirstActiveSubcarrierNum validation failed");
        }
        if(ppinfo->LastActiveSubcarrierNum >= 74 && ppinfo->LastActiveSubcarrierNum <= 3947)
        {
            UT_LOG("LastActiveSubcarrierNum is %u which is a valid value", ppinfo->LastActiveSubcarrierNum);
            UT_PASS("LastActiveSubcarrierNum validation success");
        }
        else
        {
            UT_LOG("LastActiveSubcarrierNum is %u which is an invalid value", ppinfo->LastActiveSubcarrierNum);
            UT_FAIL("LastActiveSubcarrierNum validation failed");
        }
        if(ppinfo->NumActiveSubcarriers >= 1 && ppinfo->NumActiveSubcarriers <= 3800)
        {
            UT_LOG("NumActiveSubcarriers is %u which is a valid value", ppinfo->NumActiveSubcarriers);
            UT_PASS("NumActiveSubcarriers validation success");
        }
        else
        {
            UT_LOG("NumActiveSubcarriers is %u which is an invalid value", ppinfo->NumActiveSubcarriers);
            UT_FAIL("NumActiveSubcarriers validation failed");
        }
        if(ppinfo->SubcarrierSpacing == 50 || ppinfo->SubcarrierSpacing == 25)
        {
            UT_LOG("SubcarrierSpacing is %u which is a valid value", ppinfo->SubcarrierSpacing);
            UT_PASS("SubcarrierSpacing validation success");
        }
        else
        {
            UT_LOG("SubcarrierSpacing is %u which is an invalid value", ppinfo->SubcarrierSpacing);
            UT_FAIL("SubcarrierSpacing validation failed");
        }      

    } else {
        UT_LOG_ERROR("docsis_GetUsOfdmaChanTable failed with status: %d\n", status);
    }
    free(ppinfo);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the docsis_GetUsOfdmaChanTable API when invoked with NULL ppinfo pointer.
*
* In this test, the docsis_GetUsOfdmaChanTable API is invoked with NULL ppinfo pointer and it is expected to return an error. This test is important to ensure the robustness of the API in handling invalid inputs.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 107@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetUsOfdmaChanTable API with NULL ppinfo pointer | ppinfo = NULL, output_NumberOfEntries = address of an integer variable | The return status should be RETURN_ERR | The API should handle the invalid input gracefully and return an error |
*/
void test_l1_cm_hal_negative1_docsis_GetUsOfdmaChanTable(void)
{
    gTestID = 107;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int output_NumberOfEntries;
    int status;

    UT_LOG_DEBUG("Invoking docsis_GetUsOfdmaChanTable with NULL ppinfo pointer");
    status = docsis_GetUsOfdmaChanTable(NULL, &output_NumberOfEntries);

    UT_ASSERT_EQUAL(status, RETURN_ERR);
    if (status != RETURN_ERR) {
        UT_LOG_ERROR("docsis_GetUsOfdmaChanTable did not fail as expected with NULL ppinfo pointer\n");
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the docsis_GetUsOfdmaChanTable API when invoked with NULL output_NumberOfEntries pointer.
*
* This test is important to ensure that the API handles error conditions correctly and returns the appropriate error code when invoked with invalid parameters.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 108@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetUsOfdmaChanTable API with NULL output_NumberOfEntries pointer | ppinfo = uninitialized, output_NumberOfEntries = NULL | The return status should be RETURN_ERR | The API should handle the error condition correctly |
*/
void test_l1_cm_hal_negative2_docsis_GetUsOfdmaChanTable(void)
{
    gTestID = 108;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PDOCSIF31_CM_US_OFDMA_CHAN ppinfo;
    int status;

    UT_LOG_DEBUG("Invoking docsis_GetUsOfdmaChanTable with NULL output_NumberOfEntries pointer");
    status = docsis_GetUsOfdmaChanTable(&ppinfo, NULL);

    UT_ASSERT_EQUAL(status, RETURN_ERR);
    if (status != RETURN_ERR) {
        UT_LOG_ERROR("docsis_GetUsOfdmaChanTable did not fail as expected with NULL output_NumberOfEntries pointer\n");
    }
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the correct functionality of the docsis_GetStatusOfdmaUsTable API
*
* This test invokes the docsis_GetStatusOfdmaUsTable API with valid pointers and checks if the return status is OK. It also checks if the output_NumberOfEntries is greater than or equal to 0 and if the RangingStatus of each entry in the table is between 1 and 6.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 109@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetStatusOfdmaUsTable with valid pointers | ppinfo = valid pointer, output_NumberOfEntries = valid pointer | The return status should be OK | Should be successful |
* | 02 | Check if output_NumberOfEntries is greater than or equal to 0 | output_NumberOfEntries = value returned by API | output_NumberOfEntries should be greater than or equal to 0 | Should be successful |
* | 03 | Check if the RangingStatus of each entry in the table is between 1 and 6 | ppinfo = value returned by API | RangingStatus of each entry should be between 1 and 6 | Should be successful |
*/
void test_l1_cm_hal_positive1_docsis_GetStatusOfdmaUsTable(void)
{
    gTestID = 109;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PDOCSIF31_CMSTATUSOFDMA_US ppinfo = NULL;  
    int output_NumberOfEntries = 0;
    int status;

    if (ppinfo == NULL)
    {
        UT_LOG_ERROR("Memory allocation failed for ppinfo");
        UT_FAIL("Memory allocation failed");
        return;
    }
    UT_LOG_DEBUG("Invoking docsis_GetStatusOfdmaUsTable with valid pointers");
    status = docsis_GetStatusOfdmaUsTable(&ppinfo, &output_NumberOfEntries);

    UT_ASSERT_EQUAL(status, RETURN_OK);
    
    if (status == RETURN_OK)
    {
        if (ppinfo != NULL)
        {
            UT_LOG_DEBUG("ppinfo->ChannelId is : %u", ppinfo->ChannelId);
            UT_LOG_DEBUG("ppinfo->T3Timeouts is : %u", ppinfo->T3Timeouts);
            UT_LOG_DEBUG("ppinfo->T4Timeouts is : %u", ppinfo->T4Timeouts);
            UT_LOG_DEBUG("ppinfo->RangingAborteds is : %u", ppinfo->RangingAborteds);
            UT_LOG_DEBUG("ppinfo->T3Exceededs is : %u", ppinfo->T3Exceededs);
            UT_LOG_DEBUG("ppinfo->IsMuted is : %s", ppinfo->IsMuted);
            UT_LOG_DEBUG("ppinfo->RangingStatus is : %u", ppinfo->RangingStatus);

            UT_ASSERT(output_NumberOfEntries >= 0);

            if (ppinfo->RangingStatus >= 1 && ppinfo->RangingStatus <= 6)
            {
                UT_LOG("RangingStatus is %u which is a valid value", ppinfo->RangingStatus);
                UT_PASS("RangingStatus validation success");
            }
            else
            {
                UT_LOG("RangingStatus is %u which is an invalid value", ppinfo->RangingStatus);
                UT_FAIL("RangingStatus validation failed");
            }
        }
        else
        {
            UT_LOG_ERROR("ppinfo is NULL after successful API call");
            UT_FAIL("NULL pointer after successful API call");
        }
    }
    else
    {
        UT_LOG_ERROR("docsis_GetStatusOfdmaUsTable failed with status %d", status);
    }

    if (ppinfo != NULL)
    {
        free(ppinfo);
        ppinfo = NULL;  // Set to NULL after freeing
    }
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the behavior of the docsis_GetStatusOfdmaUsTable API when invoked with NULL pointer for ppinfo
*
* This test is designed to validate the error handling mechanism of the docsis_GetStatusOfdmaUsTable API. The API is invoked with NULL pointer for ppinfo and the return status is checked. The API is expected to return an error in this scenario.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 110@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetStatusOfdmaUsTable with NULL pointer for ppinfo | ppinfo = NULL, output_NumberOfEntries = address of integer variable | The return status should be RETURN_ERR | The API should handle the NULL pointer gracefully and return an error |
*/
void test_l1_cm_hal_negative1_docsis_GetStatusOfdmaUsTable(void)
{
    gTestID = 110;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int output_NumberOfEntries;
    int status;

    UT_LOG_DEBUG("Invoking docsis_GetStatusOfdmaUsTable with NULL pointer for ppinfo");
    status = docsis_GetStatusOfdmaUsTable(NULL, &output_NumberOfEntries);

    UT_ASSERT_EQUAL(status, RETURN_ERR);
    if (status != RETURN_ERR) {
        UT_LOG_ERROR("docsis_GetStatusOfdmaUsTable did not return expected error\n");
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the error handling of the function docsis_GetStatusOfdmaUsTable when invoked with NULL pointer for output_NumberOfEntries.
*
* In this test, the function docsis_GetStatusOfdmaUsTable is invoked with a NULL pointer for the output_NumberOfEntries parameter. The test verifies that the function returns an error in this scenario.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 111@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_GetStatusOfdmaUsTable with NULL pointer for output_NumberOfEntries | ppinfo = &ppinfo, output_NumberOfEntries = NULL | The function should return an error | The function should handle the NULL pointer gracefully and return an error |
*/
void test_l1_cm_hal_negative2_docsis_GetStatusOfdmaUsTable(void)
{
    gTestID = 111;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    PDOCSIF31_CMSTATUSOFDMA_US ppinfo;
    int status;

    UT_LOG_DEBUG("Invoking docsis_GetStatusOfdmaUsTable with NULL pointer for output_NumberOfEntries");
    status = docsis_GetStatusOfdmaUsTable(&ppinfo, NULL);

    UT_ASSERT_EQUAL(status, RETURN_ERR);
    if (status != RETURN_ERR) {
        UT_LOG_ERROR("docsis_GetStatusOfdmaUsTable did not return expected error\n");
    }
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief Test to verify the functionality of docsis_LLDgetEnableStatus API
*
* This test case is designed to verify if the docsis_LLDgetEnableStatus API is able to correctly fetch the enable status of LLD from the bootfile.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 112@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke the docsis_LLDgetEnableStatus API | No input data required for this API | The API should return the enable status of LLD from the bootfile | The returned status should be either ENABLE, DISABLE or RETURN_ERR |
*/
void test_l1_cm_hal_positive1_docsis_LLDgetEnableStatus(void) 
{
    gTestID = 112;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);
    
    int status = docsis_LLDgetEnableStatus();
    UT_LOG_DEBUG("Invoking docsis_LLDgetEnableStatus()");
    
    if (status == ENABLE)
    {
        UT_LOG_DEBUG("LLD is enabled in the bootfile");
        UT_ASSERT_EQUAL(status, ENABLE);
    }
    else if (status == DISABLE)
    {
        UT_LOG_DEBUG("LLD is disabled or the entry is missing in the bootfile");
        UT_ASSERT_EQUAL(status, DISABLE);
    }
    else if (status == RETURN_ERR)
    {
        UT_LOG_ERROR("Error occurred while retrieving LLD status");
        UT_ASSERT_EQUAL(status, ENABLE); 
    }
    else 
    {
        UT_LOG_ERROR("Unexpected status value: %d", status);
        UT_ASSERT(FALSE);
    }   
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is to verify the functionality of the cm_hal_snmpv3_kickstart_initialize API
*
* This test case is designed to test the positive scenario of the cm_hal_snmpv3_kickstart_initialize API. The API is invoked with valid snmpv3_kickstart_table_t and the return value is checked against the expected return value.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 113@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_snmpv3_kickstart_initialize API with valid snmpv3_kickstart_table_t | cm_hal_snmpv3_kickstart_initialize(&kickstart_table) | The return value should be RETURN_OK | Should be successfull |
*/
void test_l1_cm_hal_positive1_cm_hal_snmpv3_kickstart_initialize(void)
{
    gTestID = 113;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    snmpv3_kickstart_table_t kickstart_table;
    snmp_kickstart_row_t row;

    row.security_name.length = 10;
    row.security_name.buffer = (unsigned char*)"Name1";
    row.security_number.length = 10;
    row.security_number.buffer = (unsigned char*)"0ABCDEFG";

    kickstart_table.n_rows = 1;
    kickstart_table.kickstart_values[0] = &row;

    UT_LOG_DEBUG("Invoking cm_hal_snmpv3_kickstart_initialize with valid snmpv3_kickstart_table_t");
    int ret = cm_hal_snmpv3_kickstart_initialize(&kickstart_table);
    UT_ASSERT_EQUAL(ret, RETURN_OK);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the behavior of the cm_hal_snmpv3_kickstart_initialize API when invoked with NULL pointer.
*
* In this test, the cm_hal_snmpv3_kickstart_initialize API is invoked with NULL pointer to check if the API handles the NULL pointer scenario correctly and returns the expected error code.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 114@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_snmpv3_kickstart_initialize API with NULL pointer | NULL | The API should return RETURN_ERR | The API should handle NULL pointer correctly |
*/
void test_l1_cm_hal_negative1_cm_hal_snmpv3_kickstart_initialize(void)
{
    gTestID = 114;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    UT_LOG_DEBUG("Invoking cm_hal_snmpv3_kickstart_initialize with NULL pointer");
    int ret = cm_hal_snmpv3_kickstart_initialize(NULL);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);
    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the negative scenario of the cm_hal_snmpv3_kickstart_initialize API
*
* This test case checks the behavior of the cm_hal_snmpv3_kickstart_initialize API when it is invoked with a NULL snmp_kickstart_row_t. The API is expected to return an error in this scenario.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 115@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_snmpv3_kickstart_initialize API with NULL snmp_kickstart_row_t | kickstart_table.n_rows = 1, kickstart_table.kickstart_values[0] = NULL | The API should return an error | The API is expected to handle NULL input gracefully |
*/
void test_l1_cm_hal_negative2_cm_hal_snmpv3_kickstart_initialize(void)
{
    gTestID = 115;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    snmpv3_kickstart_table_t kickstart_table;

    kickstart_table.n_rows = 1;
    kickstart_table.kickstart_values[0] = NULL;

    UT_LOG_DEBUG("Invoking cm_hal_snmpv3_kickstart_initialize with snmp_kickstart_row_t as NULL");
    int ret = cm_hal_snmpv3_kickstart_initialize(&kickstart_table);

    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the function docsis_IsEnergyDetected
*
* This test invokes the function docsis_IsEnergyDetected with a valid boolean pointer and checks if the function returns the expected value.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 116@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_IsEnergyDetected with valid boolean pointer | energyDetected = uninitialized boolean variable | The function should return RETURN_OK | Should be successfull |
*/
void test_l1_cm_hal_positive1_docsis_IsEnergyDetected(void)
{
    gTestID = 116;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    BOOLEAN energyDetected;
    int returnValue;

    UT_LOG_DEBUG("Invoking docsis_IsEnergyDetected with valid boolean pointer");
    returnValue = docsis_IsEnergyDetected(&energyDetected);

    UT_LOG_DEBUG("docsis_IsEnergyDetected returned %d, Energy Detected: %d", returnValue, energyDetected);
    UT_ASSERT_EQUAL(returnValue, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test checks the behavior of the docsis_IsEnergyDetected API when invoked with NULL pointer
*
* The test invokes the docsis_IsEnergyDetected API with NULL pointer and checks if the return value is RETURN_ERR. This is to ensure that the API handles invalid inputs gracefully.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 117@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke docsis_IsEnergyDetected with NULL pointer | NULL | RETURN_ERR | The function should handle NULL pointers correctly |
*/
void test_l1_cm_hal_negative1_docsis_IsEnergyDetected(void)
{
    gTestID = 117;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int returnValue;

    UT_LOG_DEBUG("Invoking docsis_IsEnergyDetected with NULL pointer");
    returnValue = docsis_IsEnergyDetected(NULL);

    UT_LOG_DEBUG("docsis_IsEnergyDetected returned %d", returnValue);
    UT_ASSERT_EQUAL(returnValue, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the functionality of the cm_hal_set_ReinitMacThreshold API when provided with a valid input.
*
* In this test, the cm_hal_set_ReinitMacThreshold API is invoked with a valid input value and the return value is checked to ensure that the API is functioning as expected.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 118@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_set_ReinitMacThreshold API with a valid input value | value = 10 | The return value should be RETURN_OK | The test should pass |
*/
void test_l1_cm_hal_positive1_set_ReinitMacThreshold(void)
{
    gTestID = 118;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG value = 10; // Assuming 10 is within the acceptable range
    int ret;

    UT_LOG_DEBUG("Invoking cm_hal_set_ReinitMacThreshold with value: %lu\n", value);
    ret = cm_hal_set_ReinitMacThreshold(value);

    UT_ASSERT_EQUAL(ret, RETURN_OK);

    if (ret != RETURN_OK) {
        UT_LOG_ERROR("cm_hal_set_ReinitMacThreshold failed with return value: %d\n", ret);
    }

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the cm_hal_get_ReinitMacThreshold API
*
* This test invokes the cm_hal_get_ReinitMacThreshold API with a valid pointer and checks if the return value is as expected.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 119@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_get_ReinitMacThreshold with valid pointer | threshold = valid pointer | Return value should be RETURN_OK | Should be successful |
*/
void test_l1_cm_hal_positive1_get_ReinitMacThreshold(void)
{
    gTestID = 119;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    ULONG threshold;
    int ret;

    UT_LOG_DEBUG("Invoking cm_hal_get_ReinitMacThreshold with valid pointer");
    ret = cm_hal_get_ReinitMacThreshold(&threshold);

    UT_LOG_DEBUG("cm_hal_get_ReinitMacThreshold returned %d, threshold: %lu", ret, threshold);
    UT_ASSERT_EQUAL(ret, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to check the behavior of the cm_hal_get_ReinitMacThreshold function when passed a NULL pointer.
*
* In this test, we are testing the robustness of the cm_hal_get_ReinitMacThreshold function. We want to ensure that the function can handle being passed a NULL pointer without crashing or behaving unexpectedly.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 120@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_get_ReinitMacThreshold with NULL pointer | NULL | The function should return RETURN_ERR | The function should handle NULL pointers gracefully |
*/
void test_l1_cm_hal_negative1_get_ReinitMacThreshold(void)
{
    gTestID = 120;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int ret;

    UT_LOG_DEBUG("Invoking cm_hal_get_ReinitMacThreshold with NULL pointer");
    ret = cm_hal_get_ReinitMacThreshold(NULL);

    UT_LOG_DEBUG("cm_hal_get_ReinitMacThreshold returned %d", ret);
    UT_ASSERT_EQUAL(ret, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test verifies the cm_hal_get_DiplexerSettings API
*
* This test invokes the cm_hal_get_DiplexerSettings API with a valid CM_DIPLEXER_SETTINGS pointer and checks if the return value is as expected.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 121@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_get_DiplexerSettings with valid CM_DIPLEXER_SETTINGS pointer | diplexerSettings = valid pointer | Return value should be RETURN_OK | Should be successful |
*/
void test_l1_cm_hal_positive1_cm_hal_get_DiplexerSettings(void)
{
    gTestID = 121;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    CM_DIPLEXER_SETTINGS diplexerSettings;
    int returnValue;

    UT_LOG_DEBUG("Invoking cm_hal_get_DiplexerSettings with valid CM_DIPLEXER_SETTINGS pointer");
    returnValue = cm_hal_get_DiplexerSettings(&diplexerSettings);

    UT_LOG_INFO("cm_hal_get_DiplexerSettings returned %d, usDiplexerSetting: %u, dsDiplexerSetting: %u\n", returnValue, diplexerSettings.usDiplexerSetting, diplexerSettings.dsDiplexerSetting);
    UT_ASSERT_EQUAL(returnValue, RETURN_OK);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

/**
* @brief This test is designed to verify the behavior of the cm_hal_get_DiplexerSettings API when invoked with NULL pointer.
*
* This test is important to ensure that the API handles invalid input gracefully and returns the appropriate error code.@n
*
* **Test Group ID:** Basic: 01@n
* **Test Case ID:** 122@n
* **Priority:** High@n
* @n
* **Pre-Conditions:** None@n
* **Dependencies:** None@n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
* @n
* **Test Procedure:**@n
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke cm_hal_get_DiplexerSettings with NULL pointer | NULL | The function should return RETURN_ERR | The function should handle invalid input gracefully |
*/
void test_l1_cm_hal_negative1_cm_hal_get_DiplexerSettings(void)
{
    gTestID = 122;
    UT_LOG_INFO("In %s [%02d%03d]\n", __FUNCTION__, gTestGroup, gTestID);

    int returnValue;

    UT_LOG_DEBUG("Invoking cm_hal_get_DiplexerSettings with NULL pointer");
    returnValue = cm_hal_get_DiplexerSettings(NULL);

    UT_LOG_INFO("cm_hal_get_DiplexerSettings returned %d\n", returnValue);
    UT_ASSERT_EQUAL(returnValue, RETURN_ERR);

    UT_LOG_INFO("Out %s\n", __FUNCTION__);
}

static UT_test_suite_t * pSuite = NULL;

/**
* @brief Register the main tests for this module
*
* @return int - 0 on success, otherwise failure
*/

int test_cm_hal_register(void)
{
    // Create the test suite
    pSuite = UT_add_suite("[L1 cm_hal]", NULL, NULL);
    if (pSuite == NULL) {
        return -1;
    }

    // Add tests to the suite

    UT_add_test( pSuite, "l1_cm_hal_positive1_cm_hal_InitDB", test_l1_cm_hal_positive1_cm_hal_InitDB);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_InitDS", test_l1_cm_hal_positive1_docsis_InitDS);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_InitUS", test_l1_cm_hal_positive1_docsis_InitUS);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_getCMStatus", test_l1_cm_hal_positive1_docsis_getCMStatus);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_getCMStatus", test_l1_cm_hal_negative1_docsis_getCMStatus);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_GetDSChannel", test_l1_cm_hal_positive1_docsis_GetDSChannel);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_GetDSChannel", test_l1_cm_hal_negative1_docsis_GetDSChannel);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_GetUsStatus", test_l1_cm_hal_positive1_docsis_GetUsStatus);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_GetUsStatus", test_l1_cm_hal_negative1_docsis_GetUsStatus);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_GetUSChannel", test_l1_cm_hal_positive1_docsis_GetUSChannel);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_GetUSChannel", test_l1_cm_hal_negative1_docsis_GetUSChannel);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_GetDOCSISInfo", test_l1_cm_hal_positive1_docsis_GetDOCSISInfo);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_GetDOCSISInfo", test_l1_cm_hal_negative1_docsis_GetDOCSISInfo);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_GetNumOfActiveTxChannels", test_l1_cm_hal_positive1_docsis_GetNumOfActiveTxChannels);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_GetNumOfActiveTxChannels", test_l1_cm_hal_negative1_docsis_GetNumOfActiveTxChannels);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_GetNumOfActiveRxChannels", test_l1_cm_hal_positive1_docsis_GetNumOfActiveRxChannels);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_GetNumOfActiveRxChannels", test_l1_cm_hal_negative1_docsis_GetNumOfActiveRxChannels);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_GetErrorCodewords", test_l1_cm_hal_positive1_docsis_GetErrorCodewords);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_GetErrorCodewords", test_l1_cm_hal_negative1_docsis_GetErrorCodewords);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_GetMddIpModeOverride", test_l1_cm_hal_positive1_docsis_GetMddIpModeOverride);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_GetMddIpModeOverride", test_l1_cm_hal_negative1_docsis_GetMddIpModeOverride);
    UT_add_test( pSuite, "l1_cm_hal_positive2_docsis_GetMddIpModeOverride", test_l1_cm_hal_positive2_docsis_GetMddIpModeOverride);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_SetMddIpModeOverride", test_l1_cm_hal_positive1_docsis_SetMddIpModeOverride);
    UT_add_test( pSuite, "l1_cm_hal_positive2_docsis_SetMddIpModeOverride", test_l1_cm_hal_positive2_docsis_SetMddIpModeOverride);
    UT_add_test( pSuite, "l1_cm_hal_positive3_docsis_SetMddIpModeOverride", test_l1_cm_hal_positive3_docsis_SetMddIpModeOverride);
    UT_add_test( pSuite, "l1_cm_hal_positive4_docsis_SetMddIpModeOverride", test_l1_cm_hal_positive4_docsis_SetMddIpModeOverride);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_SetMddIpModeOverride", test_l1_cm_hal_negative1_docsis_SetMddIpModeOverride);
    UT_add_test( pSuite, "l1_cm_hal_negative2_docsis_SetMddIpModeOverride", test_l1_cm_hal_negative2_docsis_SetMddIpModeOverride);
    UT_add_test( pSuite, "l1_cm_hal_negative3_docsis_SetMddIpModeOverride", test_l1_cm_hal_negative3_docsis_SetMddIpModeOverride);
    UT_add_test( pSuite, "l1_cm_hal_negative4_docsis_SetMddIpModeOverride", test_l1_cm_hal_negative4_docsis_SetMddIpModeOverride);
    UT_add_test( pSuite, "l1_cm_hal_negative5_docsis_SetMddIpModeOverride", test_l1_cm_hal_negative5_docsis_SetMddIpModeOverride);
    UT_add_test( pSuite, "l1_cm_hal_negative6_docsis_SetMddIpModeOverride", test_l1_cm_hal_negative6_docsis_SetMddIpModeOverride);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_GetUSChannelId", test_l1_cm_hal_positive1_docsis_GetUSChannelId);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_SetUSChannelId", test_l1_cm_hal_negative1_docsis_SetUSChannelId);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_SetUSChannelId", test_l1_cm_hal_positive1_docsis_SetUSChannelId);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_GetDownFreq", test_l1_cm_hal_positive1_docsis_GetDownFreq);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_SetStartFreq", test_l1_cm_hal_positive1_docsis_SetStartFreq);
    UT_add_test( pSuite, "l1_cm_hal_positive2_docsis_SetStartFreq", test_l1_cm_hal_positive2_docsis_SetStartFreq);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_GetDocsisEventLogItems", test_l1_cm_hal_positive1_docsis_GetDocsisEventLogItems);
    UT_add_test( pSuite, "l1_cm_hal_positive2_docsis_GetDocsisEventLogItems", test_l1_cm_hal_positive2_docsis_GetDocsisEventLogItems);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_GetDocsisEventLogItems", test_l1_cm_hal_negative1_docsis_GetDocsisEventLogItems);
    UT_add_test( pSuite, "l1_cm_hal_negative2_docsis_GetDocsisEventLogItems", test_l1_cm_hal_negative2_docsis_GetDocsisEventLogItems);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_ClearDocsisEventLog", test_l1_cm_hal_positive1_docsis_ClearDocsisEventLog);
    UT_add_test( pSuite, "l1_cm_hal_positive1_GetDHCPInfo", test_l1_cm_hal_positive1_GetDHCPInfo);
    UT_add_test( pSuite, "l1_cm_hal_negative1_GetDHCPInfo", test_l1_cm_hal_negative1_GetDHCPInfo);
    UT_add_test( pSuite, "l1_cm_hal_positive1_GetIPv6DHCPInfo", test_l1_cm_hal_positive1_GetIPv6DHCPInfo);
    UT_add_test( pSuite, "l1_cm_hal_negative1_GetIPv6DHCPInfo", test_l1_cm_hal_negative1_GetIPv6DHCPInfo);
    UT_add_test( pSuite, "l1_cm_hal_positive1_GetCPEList", test_l1_cm_hal_positive1_GetCPEList);
    UT_add_test( pSuite, "l1_cm_hal_positive2_GetCPEList", test_l1_cm_hal_positive2_GetCPEList);
    UT_add_test( pSuite, "l1_cm_hal_negative1_GetCPEList", test_l1_cm_hal_negative1_GetCPEList);
    UT_add_test( pSuite, "l1_cm_hal_negative2_GetCPEList", test_l1_cm_hal_negative2_GetCPEList);
    UT_add_test( pSuite, "l1_cm_hal_negative3_GetCPEList", test_l1_cm_hal_negative3_GetCPEList);
    UT_add_test( pSuite, "l1_cm_hal_negative4_GetCPEList", test_l1_cm_hal_negative4_GetCPEList);
    UT_add_test( pSuite, "l1_cm_hal_negative5_GetCPEList", test_l1_cm_hal_negative5_GetCPEList);
    UT_add_test( pSuite, "l1_cm_hal_positive1_GetMarket", test_l1_cm_hal_positive1_GetMarket);
    UT_add_test( pSuite, "l1_cm_hal_negative1_GetMarket", test_l1_cm_hal_negative1_GetMarket);
    UT_add_test( pSuite, "l1_cm_hal_positive2_GetMarket", test_l1_cm_hal_positive2_GetMarket);
    UT_add_test( pSuite, "l1_cm_hal_positive1_Set_HTTP_Download_Url", test_l1_cm_hal_positive1_Set_HTTP_Download_Url);
    UT_add_test( pSuite, "l1_cm_hal_negative1_Set_HTTP_Download_Url", test_l1_cm_hal_negative1_Set_HTTP_Download_Url);
    UT_add_test( pSuite, "l1_cm_hal_negative2_Set_HTTP_Download_Url", test_l1_cm_hal_negative2_Set_HTTP_Download_Url);
    UT_add_test( pSuite, "l1_cm_hal_negative3_Set_HTTP_Download_Url", test_l1_cm_hal_negative3_Set_HTTP_Download_Url);
    UT_add_test( pSuite, "l1_cm_hal_negative4_Set_HTTP_Download_Url", test_l1_cm_hal_negative4_Set_HTTP_Download_Url);
    UT_add_test( pSuite, "l1_cm_hal_negative5_Set_HTTP_Download_Url", test_l1_cm_hal_negative5_Set_HTTP_Download_Url);
    UT_add_test( pSuite, "l1_cm_hal_negative6_Set_HTTP_Download_Url", test_l1_cm_hal_negative6_Set_HTTP_Download_Url);
    UT_add_test( pSuite, "l1_cm_hal_positive1_Get_HTTP_Download_Url", test_l1_cm_hal_positive1_Get_HTTP_Download_Url);
    UT_add_test( pSuite, "l1_cm_hal_negative1_Get_HTTP_Download_Url", test_l1_cm_hal_negative1_Get_HTTP_Download_Url);
    UT_add_test( pSuite, "l1_cm_hal_negative2_Get_HTTP_Download_Url", test_l1_cm_hal_negative2_Get_HTTP_Download_Url);
    UT_add_test( pSuite, "l1_cm_hal_positive2_Get_HTTP_Download_Url", test_l1_cm_hal_positive2_Get_HTTP_Download_Url);
    UT_add_test( pSuite, "l1_cm_hal_positive1_Set_HTTP_Download_Interface", test_l1_cm_hal_positive1_Set_HTTP_Download_Interface);
    UT_add_test( pSuite, "l1_cm_hal_positive2_Set_HTTP_Download_Interface", test_l1_cm_hal_positive2_Set_HTTP_Download_Interface);
    UT_add_test( pSuite, "l1_cm_hal_negative1_Set_HTTP_Download_Interface", test_l1_cm_hal_negative1_Set_HTTP_Download_Interface);
    UT_add_test( pSuite, "l1_cm_hal_positive1_Get_HTTP_Download_Interface", test_l1_cm_hal_positive1_Get_HTTP_Download_Interface);
    UT_add_test( pSuite, "l1_cm_hal_negative1_Get_HTTP_Download_Interface", test_l1_cm_hal_negative1_Get_HTTP_Download_Interface);
    UT_add_test( pSuite, "l1_cm_hal_positive1_Get_HTTP_Download_Status", test_l1_cm_hal_positive1_Get_HTTP_Download_Status);
    UT_add_test( pSuite, "l1_cm_hal_positive1_Reboot_Ready", test_l1_cm_hal_positive1_Reboot_Ready);
    UT_add_test( pSuite, "l1_cm_hal_negative1_Reboot_Ready", test_l1_cm_hal_negative1_Reboot_Ready);
    UT_add_test( pSuite, "l1_cm_hal_positive1_HTTP_Download_Reboot_Now", test_l1_cm_hal_positive1_HTTP_Download_Reboot_Now);
    UT_add_test( pSuite, "l1_cm_hal_negative1_FWupdateAndFactoryReset", test_l1_cm_hal_negative1_FWupdateAndFactoryReset);
    UT_add_test( pSuite, "l1_cm_hal_negative2_FWupdateAndFactoryReset", test_l1_cm_hal_negative2_FWupdateAndFactoryReset);
    UT_add_test( pSuite, "l1_cm_hal_negative3_FWupdateAndFactoryReset", test_l1_cm_hal_negative3_FWupdateAndFactoryReset);
    UT_add_test( pSuite, "l1_cm_hal_negative4_FWupdateAndFactoryReset", test_l1_cm_hal_negative4_FWupdateAndFactoryReset);
    UT_add_test( pSuite, "l1_cm_hal_negative5_FWupdateAndFactoryReset", test_l1_cm_hal_negative5_FWupdateAndFactoryReset);
    UT_add_test( pSuite, "l1_cm_hal_negative6_FWupdateAndFactoryReset", test_l1_cm_hal_negative6_FWupdateAndFactoryReset);
    UT_add_test( pSuite, "l1_cm_hal_negative7_FWupdateAndFactoryReset", test_l1_cm_hal_negative7_FWupdateAndFactoryReset);
    UT_add_test( pSuite, "l1_cm_hal_positive1_ReinitMac", test_l1_cm_hal_positive1_ReinitMac);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_GetProvIpType", test_l1_cm_hal_positive1_docsis_GetProvIpType);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_GetProvIpType", test_l1_cm_hal_negative1_docsis_GetProvIpType);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_GetCert", test_l1_cm_hal_positive1_docsis_GetCert);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_GetCert", test_l1_cm_hal_negative1_docsis_GetCert);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_GetCertStatus", test_l1_cm_hal_positive1_docsis_GetCertStatus);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_GetCertStatus", test_l1_cm_hal_negative1_docsis_GetCertStatus);
    UT_add_test( pSuite, "l1_cm_hal_positive1_Get_CableModemResetCount", test_l1_cm_hal_positive1_Get_CableModemResetCount);
    UT_add_test( pSuite, "l1_cm_hal_negative1_Get_CableModemResetCount", test_l1_cm_hal_negative1_Get_CableModemResetCount);
    UT_add_test( pSuite, "l1_cm_hal_positive1_Get_LocalResetCount", test_l1_cm_hal_positive1_Get_LocalResetCount);
    UT_add_test( pSuite, "l1_cm_hal_negative1_Get_LocalResetCount", test_l1_cm_hal_negative1_Get_LocalResetCount);
    UT_add_test( pSuite, "l1_cm_hal_positive1_Get_DocsisResetCount", test_l1_cm_hal_positive1_Get_DocsisResetCount);
    UT_add_test( pSuite, "l1_cm_hal_negative1_Get_DocsisResetCount", test_l1_cm_hal_negative1_Get_DocsisResetCount);
    UT_add_test( pSuite, "l1_cm_hal_positive1_Get_ErouterResetCount", test_l1_cm_hal_positive1_Get_ErouterResetCount);
    UT_add_test( pSuite, "l1_cm_hal_negative1_Get_ErouterResetCount", test_l1_cm_hal_negative1_Get_ErouterResetCount);
    UT_add_test( pSuite, "l1_cm_hal_positive1_HTTP_LED_Flash", test_l1_cm_hal_positive1_HTTP_LED_Flash);
    UT_add_test( pSuite, "l1_cm_hal_positive2_HTTP_LED_Flash", test_l1_cm_hal_positive2_HTTP_LED_Flash);
    UT_add_test( pSuite, "l1_cm_hal_negative1_HTTP_LED_Flash", test_l1_cm_hal_negative1_HTTP_LED_Flash);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_GetDsOfdmChanTable", test_l1_cm_hal_positive1_docsis_GetDsOfdmChanTable);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_GetDsOfdmChanTable", test_l1_cm_hal_negative1_docsis_GetDsOfdmChanTable);
    UT_add_test( pSuite, "l1_cm_hal_negative2_docsis_GetDsOfdmChanTable", test_l1_cm_hal_negative2_docsis_GetDsOfdmChanTable);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_GetUsOfdmaChanTable", test_l1_cm_hal_positive1_docsis_GetUsOfdmaChanTable);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_GetUsOfdmaChanTable", test_l1_cm_hal_negative1_docsis_GetUsOfdmaChanTable);
    UT_add_test( pSuite, "l1_cm_hal_negative2_docsis_GetUsOfdmaChanTable", test_l1_cm_hal_negative2_docsis_GetUsOfdmaChanTable);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_GetStatusOfdmaUsTable", test_l1_cm_hal_positive1_docsis_GetStatusOfdmaUsTable);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_GetStatusOfdmaUsTable", test_l1_cm_hal_negative1_docsis_GetStatusOfdmaUsTable);
    UT_add_test( pSuite, "l1_cm_hal_negative2_docsis_GetStatusOfdmaUsTable", test_l1_cm_hal_negative2_docsis_GetStatusOfdmaUsTable);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_LLDgetEnableStatus", test_l1_cm_hal_positive1_docsis_LLDgetEnableStatus);
    UT_add_test( pSuite, "l1_cm_hal_positive1_cm_hal_snmpv3_kickstart_initialize", test_l1_cm_hal_positive1_cm_hal_snmpv3_kickstart_initialize);
    UT_add_test( pSuite, "l1_cm_hal_negative1_cm_hal_snmpv3_kickstart_initialize", test_l1_cm_hal_negative1_cm_hal_snmpv3_kickstart_initialize);
    UT_add_test( pSuite, "l1_cm_hal_negative2_cm_hal_snmpv3_kickstart_initialize", test_l1_cm_hal_negative2_cm_hal_snmpv3_kickstart_initialize);
    UT_add_test( pSuite, "l1_cm_hal_positive1_docsis_IsEnergyDetected", test_l1_cm_hal_positive1_docsis_IsEnergyDetected);
    UT_add_test( pSuite, "l1_cm_hal_negative1_docsis_IsEnergyDetected", test_l1_cm_hal_negative1_docsis_IsEnergyDetected);
    UT_add_test( pSuite, "l1_cm_hal_positive1_set_ReinitMacThreshold", test_l1_cm_hal_positive1_set_ReinitMacThreshold);
    UT_add_test( pSuite, "l1_cm_hal_positive1_get_ReinitMacThreshold", test_l1_cm_hal_positive1_get_ReinitMacThreshold);
    UT_add_test( pSuite, "l1_cm_hal_negative1_get_ReinitMacThreshold", test_l1_cm_hal_negative1_get_ReinitMacThreshold);
    UT_add_test( pSuite, "l1_cm_hal_positive1_cm_hal_get_DiplexerSettings", test_l1_cm_hal_positive1_cm_hal_get_DiplexerSettings);
    UT_add_test( pSuite, "l1_cm_hal_negative1_cm_hal_get_DiplexerSettings", test_l1_cm_hal_negative1_cm_hal_get_DiplexerSettings);
    return 0;
}
