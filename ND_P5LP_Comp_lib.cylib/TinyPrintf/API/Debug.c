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
#define NewLine() UART_dbg_PutChar(CR); UART_dbg_PutChar(LF);

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

void TriggerScope(void)
{
	Scope_Trig_Write(0u);
	Scope_Trig_Write(1u);
}

void P5LP_059_Dbg_init(void)
{
	CyGlobalIntEnable; /* Enable global interrupts. */

	/* Start SCB UART module */
	UART_dbg_Start();
	/* initialize tinyprintf with PSoC putchar function */
	init_printf(NULL,putdata);
	UART_dbg_PutString("USB_UART\n");
	NewLine();
	NewLine();

	/* printf examples */
	UART_dbg_PutString("printf Examples");
	NewLine();
	NewLine();
    /* Run the TinyPrintf example */
//    tpf_test();

		
    
	I2C_M_FF_Start();
	CharLCD_PCF8574_I2C_Start();

	printf("%u", I2C_status);
	NewLine();    

//TrigggerScope();    
    I2C_status = I2C_M_FF_MasterStatus();
	printf("%u", I2C_status);
	if ((I2C_status != I2C_M_FF_MSTAT_WR_CMPLT) && !FlgLCD_ERR)
    {
        FlgLCD_ERR = 1;
    }
	
	if (FlgLCD_ERR && (I2C_status == I2C_M_FF_MSTAT_WR_CMPLT)) 
    {
UART_dbg_PutString("LCD OK\n");
            CyDelay(250u);
    }
		CharLCD_PCF8574_I2C_PrintString("Cypress PSoC 4");
		//CharLCD_PCF8574_I2C_Position(1u,2u);
		CharLCD_PCF8574_I2C_PosPrintString(1u,2u,"Hello World");
		CharLCD_PCF8574_I2C_PosPrintString(2u,0u,"CY8CKIT-042 20x4 LCD");
		CharLCD_PCF8574_I2C_PosPrintString(3u,0u,"DEMO of CharLCD_PCF8574_I2C");
   		CyDelay(1u);    
    /* Scope trigger*/
}

/* End of File */