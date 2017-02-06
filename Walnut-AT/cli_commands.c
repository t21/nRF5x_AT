#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "cli_commands.h"
#include "app_uart.h"
#include "wble.h"

#define NRF_LOG_MODULE_NAME "CLI_CMD"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"

#define RESP_SIZE 100
static uint8_t resp_str[RESP_SIZE];
static uint8_t resp_str_len;


void uart_put_string(uint8_t *str, uint8_t len)
{
    for (int i = 0; i < len; i++) {
        app_uart_put(str[i]);
    }
}


void execute_cli_command(char *str, int str_len)
{
    NRF_LOG_DEBUG("cmd=");
    for (int i = 0; i < str_len; i++) {
        NRF_LOG_RAW_INFO("%c", str[i]);
    }
    NRF_LOG_RAW_INFO("\r\n");
    
    if (strncmp(str, "AT", str_len) == 0) {
        // Attention command that determines the presence of a Data Communication Equipment (DCE)
        NRF_LOG_DEBUG("AT\r\n");
        uart_put_string("OK\r\n", strlen("OK\r\n"));
        
    } else if (strncmp(str, "AT+CGMI", str_len) == 0) {
        NRF_LOG_DEBUG("AT+CGMI\r\n");
    } else if (strncmp(str, "AT+CGMM", str_len) == 0) {
        NRF_LOG_DEBUG("AT+CGMM\r\n");
    } else if (strncmp(str, "AT+CGMR", str_len) == 0) {
        NRF_LOG_DEBUG("AT+CGMR\r\n");
    } else if (strncmp(str, "AT+CGSN", str_len) == 0) {
        NRF_LOG_DEBUG("AT+CGSN\r\n");
    } else if (strncmp(str, "AT+GMi", str_len) == 0) {
        NRF_LOG_DEBUG("AT+GMi\r\n");
    } else if (strncmp(str, "AT+GMM", str_len) == 0) {
        NRF_LOG_DEBUG("AT+GMM\r\n");
    } else if (strncmp(str, "AT+GMR", str_len) == 0) {
        NRF_LOG_DEBUG("AT+GMR\r\n");
    } else if (strncmp(str, "AT+GSN", str_len) == 0) {
        NRF_LOG_DEBUG("AT+GSN\r\n");
    } else if (strncmp(str, "ATI", str_len) == 0) {
        NRF_LOG_DEBUG("ATI\r\n");
    } else if (strncmp(str, "AT+CSGT", str_len) == 0) {
        NRF_LOG_DEBUG("AT+CSGT\r\n");
    } else if (strncmp(str, "AT&W", str_len) == 0) {
        NRF_LOG_DEBUG("AT&W\r\n");
    } else if (strncmp(str, "ATZ", str_len) == 0) {
        NRF_LOG_DEBUG("ATZ\r\n");
    } else if (strncmp(str, "ATE", str_len) == 0) {
        NRF_LOG_DEBUG("ATE\r\n");
    } else if (strncmp(str, "AT+UFWUPD", str_len) == 0) {
        NRF_LOG_DEBUG("AT+UFWUPD\r\n");
    } else if (strncmp(str, "AT+CPWROFF", str_len) == 0) {
        NRF_LOG_DEBUG("AT+CPWROFF\r\n");
    } else if (strncmp(str, "AT+UMSTAT", str_len) == 0) {
        NRF_LOG_DEBUG("AT+UMSTAT\r\n");
    } else if (strncmp(str, "AT+UMRS", str_len) == 0) {
        NRF_LOG_DEBUG("AT+UMRS\r\n");
    } else if (strncmp(str, "ATO", str_len) == 0) {
        NRF_LOG_DEBUG("ATO\r\n");
    } else if (strncmp(str, "AT+UDCP", str_len) == 0) {
        NRF_LOG_DEBUG("AT+UDCP\r\n");
    } else if (strncmp(str, "AT+UDCPC", str_len) == 0) {
        NRF_LOG_DEBUG("AT+UDCPC\r\n");
    } else if (strncmp(str, "AT+UDDRP", str_len) == 0) {
        NRF_LOG_DEBUG("AT+UDDRP\r\n");
    } else if (strncmp(str, "AT+UDSC", str_len) == 0) {
        NRF_LOG_DEBUG("AT+UDSC\r\n");
    } else if (strncmp(str, "AT+UDSF", str_len) == 0) {
        NRF_LOG_DEBUG("AT+UDSF\r\n");
    } else if (strncmp(str, "AT+UDWS", str_len) == 0) {
        NRF_LOG_DEBUG("AT+UDWS\r\n");
    } else if (strncmp(str, "AT+UDCFG", str_len) == 0) {
        NRF_LOG_DEBUG("AT+UDCFG\r\n");


    } else if (strncmp(str, "AT+UBTDM?", str_len) == 0) {
        // Reads the GAP discoverability mode
        NRF_LOG_DEBUG("AT+UBTDM?\r\n");
        
    } else if (strncmp(str, "AT+UBTDM=", str_len) == 0) {
        // Writes the GAP discoverability mode
        NRF_LOG_DEBUG("AT+UBTDM=\r\n");
        
    } else if (strncmp(str, "AT+UBTCM?", str_len) == 0) {
        // Reads the GAP connectability mode
        NRF_LOG_DEBUG("AT+UBTCM?\r\n");
        
    } else if (strncmp(str, "AT+UBTCM=", str_len) == 0) {
        // Writes the GAP connectability mode
        NRF_LOG_DEBUG("AT+UBTCM=\r\n");
        
    } else if (strncmp(str, "AT+UBTPM?", str_len) == 0) {
        // Reads the pairing mode
        NRF_LOG_DEBUG("AT+UBTPM?\r\n");
        
    } else if (strncmp(str, "AT+UBTPM=", str_len) == 0) {
        // Writes the pairing mode
        NRF_LOG_DEBUG("AT+UBTPM=\r\n");
        
    } else if (strncmp(str, "AT+UBTSM?", str_len) == 0) {
        // Reads the security mode
        NRF_LOG_DEBUG("AT+UBTSM?\r\n");
    } else if (strncmp(str, "AT+UBTSM=", str_len) == 0) {
        // Writes the security mode
        NRF_LOG_DEBUG("AT+UBTSM=\r\n");
        
    } else if (strncmp(str, "AT+UBTUC=", str_len) == 0) {
        // Write user confirmation
        NRF_LOG_DEBUG("AT+UBTUC=\r\n");
        
    } else if (strncmp(str, "AT+UBTUPE=", str_len) == 0) {
        // User passkey entry
        NRF_LOG_DEBUG("AT+UBTUPE=\r\n");
        
    } else if (strncmp(str, "AT+UBTD=", str_len) == 0) {
        // Performs an inquiry procedure to find any discoverable devices in the vicinity
        NRF_LOG_DEBUG("AT+UBTD=\r\n");
        
    } else if (strncmp(str, "AT+UBTB=", str_len) == 0) {
        // Performs a GAP bond procedure with another Bluetooth device
        NRF_LOG_DEBUG("AT+UBTB=\r\n");
        
    } else if (strncmp(str, "AT+UBTUB=", str_len) == 0) {
        // This command unbonds a previously bonded device
        NRF_LOG_DEBUG("AT+UBTUB=\r\n");
        
    } else if (strncmp(str, "AT+UBTBD", str_len) == 0) {
        // Read the bonded devices
        NRF_LOG_DEBUG("AT+UBTBD\r\n");
        
    } else if (strncmp(str, "AT+UBTRSS=", str_len) == 0) {
        // This request returns the current received signal strength, RSSI, for the connection between the module and the remote device identified by the 'bd_addr' parameter
        NRF_LOG_DEBUG("AT+UBTRSS=\r\n");
        
    } else if (strncmp(str, "AT+UBTLE?", str_len) == 0) {
        // Reads the configuration status
        NRF_LOG_DEBUG("AT+UBTLE?\r\n");
        
    } else if (strncmp(str, "AT+UBTLE=", str_len) == 0) {
        // Writes the configuration status
        NRF_LOG_DEBUG("AT+UBTLE=\r\n");
        
//    } else if (strncmp(str, "AT+UBTAD?", str_len) == 0) {
//        // Read custom advertising data
//        NRF_LOG_DEBUG("AT+UBTAD?\r\n");
//        
//    } else if (strncmp(str, "AT+UBTLE=", str_len) == 0) {
//        // Write custom advertising data
//        NRF_LOG_DEBUG("AT+UBTLE=\r\n");
//        
//    } else if (strncmp(str, "AT+UBTSD?", str_len) == 0) {
//        // Read scan response data
//        NRF_LOG_DEBUG("AT+UBTSD?\r\n");
//        
//    } else if (strncmp(str, "AT+UBTSD=", str_len) == 0) {
//        // Write scan response data
//        NRF_LOG_DEBUG("AT+UBTSD=\r\n");
        
//    } else if (strncmp(str, "AT+UBTLECFG=", str_len) == 0) {
//        // Read Bluetooth LE configuration
//        NRF_LOG_DEBUG("AT+UBTLECFG=\r\n");
        
    } else if (strncmp(str, "AT+UBTLECFG", strlen("AT+UBTLECFG")) == 0) {
        // Bluetooth LE configuration
        //NRF_LOG_DEBUG("AT+UBTLECFG\r\n");
        uint32_t param_tag, param_value;
        if (sscanf(str, "AT+UBTLECFG=%d,%d", &param_tag, &param_value) == 2) {
            // Write Bluetooth LE configuration
            NRF_LOG_DEBUG("tag=%d, val=%d\r\n", param_tag, param_value);
            if (wble_set_cfg(param_tag, param_value)) {
                uart_put_string("OK\r\n", strlen("OK\r\n"));
            } else {
                // Error, most likely trying to set a parameter value outside of allowed limits
                uart_put_string("ERROR\r\n", strlen("ERROR\r\n"));
            }
        } else if (sscanf(str, "AT+UBTLECFG=%d", &param_tag) == 1) {
            // Read Bluetooth LE configuration
            
            memset(resp_str, 0, sizeof(resp_str));
            
            if (wble_get_cfg(param_tag, resp_str, &resp_str_len)) {
                uart_put_string(resp_str, resp_str_len);
                uart_put_string("OK\r\n", strlen("OK\r\n"));
            } else {
                // Error, most likely request for a parameter that is not supported
                uart_put_string("ERROR\r\n", strlen("ERROR\r\n"));
            }
            
        } else {
            // Error parsing input string
            uart_put_string("ERROR\r\n", strlen("ERROR\r\n"));
        } 
        
        
    } else if (strncmp(str, "AT+UBTGDP=", str_len) == 0) {
        // Discovers all primary services on the remote device
        NRF_LOG_DEBUG("AT+UBTGDP=\r\n");
        
    } else if (strncmp(str, "AT+UBTGDPU=", str_len) == 0) {
        // Discovers all primary services by UUID on the remote device
        NRF_LOG_DEBUG("AT+UBTGDPU=\r\n");
        
    } else if (strncmp(str, "AT+UBTGFI=", str_len) == 0) {
        // Find all included services on the remote device between start handle and end handle
        NRF_LOG_DEBUG("AT+UBTGFI=\r\n");
        
    } else if (strncmp(str, "AT+UBTGDCS=", str_len) == 0) {
        // Discovers all characteristics of a service
        NRF_LOG_DEBUG("AT+UBTGDCS=\r\n");
        
    } else if (strncmp(str, "AT+UBTGDCD=", str_len) == 0) {
        // Discovers all descriptors of a characteristic
        NRF_LOG_DEBUG("AT+UBTGDCD=\r\n");
        
    } else if (strncmp(str, "AT+UBTGR=", str_len) == 0) {
        // Reads the characteristic; all bytes included
        NRF_LOG_DEBUG("AT+UBTGR=\r\n");
        
    } else if (strncmp(str, "AT+UBTGRU=", str_len) == 0) {
        // Reads all characteristics by UUID. It will read all the bytes in each characteristic
        NRF_LOG_DEBUG("AT+UBTGRU=\r\n");
        
    } else if (strncmp(str, "AT+UBTGRM=", str_len) == 0) {
        // Reads all characteristics in the attrHandleList
        NRF_LOG_DEBUG("AT+UBTGRM=\r\n");
        
    } else if (strncmp(str, "AT+UBTGW=", str_len) == 0) {
        // Write characteristic. Used for data transfers less than 20 bytes. For large writes, use +UBTGWL
        NRF_LOG_DEBUG("AT+UBTGW=\r\n");
        
    } else if (strncmp(str, "AT+UBTGWC=", str_len) == 0) {
        // Write client characteristic configuration
        NRF_LOG_DEBUG("AT+UBTGWC=\r\n");
        
    } else if (strncmp(str, "AT+UBTGWN=", str_len) == 0) {
        // Write characteristic with no notification from the remote side
        NRF_LOG_DEBUG("AT+UBTGWN=\r\n");
        
    } else if (strncmp(str, "AT+UBTGWL=", str_len) == 0) {
        // Write long characteristic. This is used to write a characteristic longer than 20 bytes or whenever a reliable write is required
        NRF_LOG_DEBUG("AT+UBTGWL=\r\n");
         
    }
    
}
