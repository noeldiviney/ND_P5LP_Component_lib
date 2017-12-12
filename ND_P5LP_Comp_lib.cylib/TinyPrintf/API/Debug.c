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

/* Used to insert a carriage return and line feed */
#define NewLine() UART_dbg_PutChar(CR); UART_dbg_PutChar(LF);

void printMenu(void)
{
    // Print Menu.
	UART_dbg_PutString("**********************");
    UART_dbg_PutString("*  Menu");
	NewLine();
    UART_dbg_PutString("*  M - Print menu");
	NewLine();
    UART_dbg_PutString("*  0 - Reset counter");
	NewLine();
    UART_dbg_PutString("*  1 - Increment counter");
	NewLine();
    UART_dbg_PutString("*  3 - Stop continues counter");
	NewLine();
    UART_dbg_PutString("*  4 - Get switch and LED state");
	NewLine();
    UART_dbg_PutString("*  5 - Set LED on");
	NewLine();
    UART_dbg_PutString("*  6 - Set LED off");
	NewLine();	

}

void scopeTrig(uint8 val)
{
	Scope_Trig(val);
}