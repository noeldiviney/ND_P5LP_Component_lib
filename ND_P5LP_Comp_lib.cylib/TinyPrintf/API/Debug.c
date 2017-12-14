/* ========================================
 *
 * File Debug.c
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
#define NewLine() `$UART_NAME`_PutChar(CR); `$UART_NAME`_PutChar(LF);

/* Variable to store UART Received Char */
uint8						ch;
 /* Transmit Buffer */
 char transmitBuffer[XMIT_BFR_SIZE];
 uint8		outputCounter8  =  0;
 uint16		outputCounter16 =  0;
 uint32		outputCounter32 =  0;
 uint8		flagPrint		=  FALSE;
 uint8		flagContCntr	=  FALSE;
 
 const char* strOn			=  "ON";
 const char* strOff			=  "OFF";

 cystatus I2C_status;
_Bool FlgLCD_ERR;


void `$INSTANCE_NAME`_printMenu(void)
{
    // Print Menu.
	`$UART_NAME`_PutString("**********************");
    `$UART_NAME`_PutString("*  Menu");
	NewLine();
    `$UART_NAME`_PutString("*  M - Print menu");
	NewLine();
    `$UART_NAME`_PutString("*  0 - Reset counter");
	NewLine();
    `$UART_NAME`_PutString("*  1 - Increment counter");
	NewLine();
    `$UART_NAME`_PutString("*  3 - Stop continues counter");
	NewLine();
    `$UART_NAME`_PutString("*  4 - Get switch and LED state");
	NewLine();
    `$UART_NAME`_PutString("*  5 - Set LED on");
	NewLine();
    `$UART_NAME`_PutString("*  6 - Set LED off");
	NewLine();	

}


void `$INSTANCE_NAME`_init(void)
{

	/* Start SCB UART module */
	`$UART_NAME`_Start();
	/* initialize tinyprintf with PSoC putchar function */
	init_printf(NULL,putdata);
	`$UART_NAME`_PutString("USB_UART\n");
	NewLine();
	NewLine();

	/* printf examples */
	`$UART_NAME`_PutString("printf Examples");
	NewLine();
	NewLine();
    /* Run the TinyPrintf example */
    tpf_test();

}

/* End of File */