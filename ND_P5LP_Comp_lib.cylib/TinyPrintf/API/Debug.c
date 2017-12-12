/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "`$INSTANCE_NAME`_API.h"
#include "`$INSTANCE_NAME`_Example.h"
#include "`$INSTANCE_NAME`_Debug.h"

void printMenu(void)
{
    // Print Menu.
    sprintf(transmitBuffer, "*****************\r\n");
    // Send out the data.
    UART_1_PutString(transmitBuffer);
    sprintf(transmitBuffer, "*  Menu:\r\n");
    UART_1_PutString(transmitBuffer);
    sprintf(transmitBuffer, "*  M - Print menu\r\n");
    UART_1_PutString(transmitBuffer);
    sprintf(transmitBuffer, "*  0 - Reset counter\r\n");
    UART_1_PutString(transmitBuffer);
    sprintf(transmitBuffer, "*  1 - Increment counter\r\n");
    UART_1_PutString(transmitBuffer);
    sprintf(transmitBuffer, "*  2 - Start continues counter\r\n");
    UART_1_PutString(transmitBuffer);
    sprintf(transmitBuffer, "*  3 - Stop continues counter\r\n");
    UART_1_PutString(transmitBuffer);
    sprintf(transmitBuffer, "*  4 - Get switch and LED state\r\n");
    UART_1_PutString(transmitBuffer);
    sprintf(transmitBuffer, "*  5 - Set LED on\r\n");
    UART_1_PutString(transmitBuffer);
    sprintf(transmitBuffer, "*  6 - Set LED off\r\n");
    UART_1_PutString(transmitBuffer);
}

void scopeTrig(uint8 val)
{
	Scope_Trig(val);
}