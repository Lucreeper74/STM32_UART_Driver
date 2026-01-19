#ifndef __STM32_UART_RX_H__
#define __STM32_UART_RX_H__

#include "stm32_uart_utils.h"

#define UART_RX_BUFFER_SIZE 64  /* !< Size of the UART RX buffer */
#define UART_CMD_FIELDS_SIZE (UART_RX_BUFFER_SIZE / 2)  /* !< Size of the UART parameter buffer */

/*
*   Definition of UART Command structure
*/
typedef struct {
    char    command[UART_CMD_FIELDS_SIZE]; /* !< Command type */
    char    param[UART_CMD_FIELDS_SIZE];   /* !< Command parameter */
    bool    has_param;     /* !< Flag indicating if parameter is present */
} UART_Command;

/*
*   Definition of UART Receiver handle structure
*/
typedef struct {
    UART_HandleTypeDef* UART_Handle;    /* !< Associated UART Handle */
    volatile uint8_t    rx_char;        /* !< Received character (volatile for ITR access)  */
    volatile uint8_t    rx_buffer[UART_RX_BUFFER_SIZE];  /* !< Reception buffer (volatile for ITR access) */
    volatile uint8_t    rx_index;       /* !< Reception buffer index (volatile for ITR access) */
    volatile uint8_t    cmd_ready;      /* !< Command ready flag (volatile for ITR access) */
} UART_RX_Handle;

extern UART_RX_Handle huart_rx; // Global UART Receiver handle

/*
*   Function to initialize the UART Receiver handle
*/
void UART_RX_Init(UART_HandleTypeDef* huart);

/*
*   Function to parse the UART RX command
*/
UART_Command UART_RX_ParseCmd(UART_RX_Handle* huart_rx);

/*
*   Function to handle the UART RX callback
*/
void UART_RX_Callback(UART_HandleTypeDef* huart);

#endif // __STM32_UART_RX_H__