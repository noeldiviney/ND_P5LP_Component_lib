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
#if !defined(DEBUG_H)
#define DEBUG_H

#define <cytypes.h>
#define FALSE				0
#define TRUE 				1
#define OFF					0
#define ON					1
#define XMIT_BFR_SIZE		256

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
 
 void printMenu();
 void TrigggerScope(uint8 val);
 #endif		/* DEBUG_H */
 
 /* [] END OF FILE */