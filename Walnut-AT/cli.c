#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "boards.h"
#include "cli.h"
#include "app_uart.h"
#include "cli_commands.h"

#define NRF_LOG_MODULE_NAME "CLI"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"

#define UART_TX_BUF_SIZE 256                         /**< UART TX buffer size. */
#define UART_RX_BUF_SIZE 256                         /**< UART RX buffer size. */
#define BUF_SIZE         100

static char m_buffer[BUF_SIZE];
static int m_buffer_idx;


void cli_put_string(uint8_t *str, uint8_t len)
{
    for (int i = 0; i < len; i++) {
        app_uart_put(str[i]);
    }
}


void cli_get_data(void)
{
    uint8_t c;

    //NRF_LOG_RAW_INFO("%d\r\n", m_buffer_idx);
    app_uart_get(&c);
    
    if (c != '\n') {
        if (c >= '!' && c <= 'z') {
            //NRF_LOG_RAW_INFO("Char:%c\r\n", c);
            if ((c>= 'a') && (c <= 'z')) {
                // to upper
                c -= 32;
            }
            
            m_buffer[m_buffer_idx] = c;
            m_buffer_idx++;
            m_buffer_idx %= BUF_SIZE;
        }
    } else {
        execute_cli_command(m_buffer, m_buffer_idx);
//        //NRF_LOG_RAW_INFO("Word:");
//        cli_put_string("Word:", strlen("Word:"));
//        for (int i = 0; i < m_buffer_idx; i++) {
//            //NRF_LOG_RAW_INFO("%c", m_buffer[i]);
//            app_uart_put(m_buffer[i]);
//        }
//        //NRF_LOG_RAW_INFO("\r\n");
//        cli_put_string("\r\n", strlen("\r\n"));
        memset(m_buffer, 0, BUF_SIZE);
        m_buffer_idx = 0;
    }
}


void cli_event_handler(app_uart_evt_t * p_event)
{
    switch (p_event->evt_type) {
    case APP_UART_DATA_READY:
        /**< An event indicating that UART data has been received. The data is available in the FIFO and can be fetched using @ref app_uart_get. */
        cli_get_data();
        break;

    case APP_UART_FIFO_ERROR:
        /**< An error in the FIFO module used by the app_uart module has occured. The FIFO error code is stored in app_uart_evt_t.data.error_code field. */
        APP_ERROR_HANDLER(p_event->data.error_code);
        break;

    case APP_UART_COMMUNICATION_ERROR:
        /**< An communication error has occured during reception. The error is stored in app_uart_evt_t.data.error_communication field. */
        APP_ERROR_HANDLER(p_event->data.error_communication);
        break;

    case APP_UART_TX_EMPTY:
        /**< An event indicating that UART has completed transmission of all available data in the TX FIFO. */
        break;

    case APP_UART_DATA:
        /**< An event indicating that UART data has been received, and data is present in data field. This event is only used when no FIFO is configured. */
        break;
    }
}



bool cli_init(void)
{
    uint32_t err_code;

    memset(m_buffer, 0, BUF_SIZE);
    m_buffer_idx = 0;

    const app_uart_comm_params_t comm_params =
    {
        RX_PIN_NUMBER,
        TX_PIN_NUMBER,
        RTS_PIN_NUMBER,
        CTS_PIN_NUMBER,
        APP_UART_FLOW_CONTROL_ENABLED,
        false,
//        UART_BAUDRATE_BAUDRATE_Baud115200
        UART_BAUDRATE_BAUDRATE_Baud230400
//        UART_BAUDRATE_BAUDRATE_Baud921600
    };

    APP_UART_FIFO_INIT(&comm_params,
                         UART_RX_BUF_SIZE,
                         UART_TX_BUF_SIZE,
                         cli_event_handler,
                         APP_IRQ_PRIORITY_LOWEST,
                         err_code);

    APP_ERROR_CHECK(err_code);
}
