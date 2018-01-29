/*******************************************************************************
* File Name: `$I2C_SLAVE_NAME`.c
* Version `$CY_MAJOR_VERSION`.`$CY_MINOR_VERSION`
*
* Description:
*  This file provides source code for the CharLCD_I2C component's API.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.

*******************************************************************************/
#include "project.h"
#include "CyLib.h"
#include "`$I2C_SLAVE_NAME`.h"

#if(CY_PSOC4)
	#include "`$I2C_MASTER_NAME`.h"
	#include "`$I2C_MASTER_NAME`_PVT.h"
#else
	#include "`$I2C_MASTER_NAME`.h"
	#include "`$I2C_MASTER_NAME`_PVT.h"
#endif /*PSOC4*/

/* Stores the state of conponent. Indicates wherewer component is 
* in enabled state or not.
*/
uint8 `$I2C_SLAVE_NAME`_enableState = 0u;

uint8 `$I2C_SLAVE_NAME`_initVar = 0u;

cystatus I2C_status;
_Bool FlgLCD_ERR;

void `$I2C_SLAVE_NAME`_Test()
{    
    I2C_status = `$I2C_MASTER_NAME`_MasterStatus();
	printf("%u", I2C_status);
    NewLine();
	if ((I2C_status != `$I2C_MASTER_NAME`_MSTAT_WR_CMPLT) && !FlgLCD_ERR)
    {
        FlgLCD_ERR = 1;
    }
	
	if (FlgLCD_ERR && (I2C_status == `$I2C_MASTER_NAME`_MSTAT_WR_CMPLT)) 
    {
        printf("%s","LCD not working");
        NewLine();
        CyDelay(250u);
    }
    else
    {
        printf("%s", "LCD is working");
        NewLine();
    }
	`$I2C_SLAVE_NAME`_Position(0u,1u);
    `$I2C_SLAVE_NAME`_PrintString("Cypress PSoC 4");
	//`$I2C_SLAVE_NAME`_Position(1u,2u);
	`$I2C_SLAVE_NAME`_PosPrintString(1u,2u,"Hello World");
	`$I2C_SLAVE_NAME`_PosPrintString(2u,0u,"CY8CKIT-042 20x4 LCD");
	`$I2C_SLAVE_NAME`_PosPrintString(3u,0u,"DEMO of CharLCD_PCF8574_I2C");
   	CyDelay(1u);    
}
/*******************************************************************************
* Function Name: `$I2C_SLAVE_NAME`_Init
********************************************************************************
*
* Summary:
*  Perform initialization required for components normal work.
*  This function initializes the LCD hardware module as follows:
*        Enable 4-bit interface
*        Clear the display
*        Enable auto cursor increment
*        Resets the cursor to start position
*  Also loads custom character set to LCD if it was defined in the customizer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void `$I2C_SLAVE_NAME`_Init(void) `=ReentrantKeil($I2C_SLAVE_NAME . "_Init")`
{
    /* INIT CODE */
    CyDelay(`$I2C_SLAVE_NAME`_INIT_DELAY);									/* Delay 20 ms */
    `$I2C_SLAVE_NAME`_WrtCntrlUpNib(`$I2C_SLAVE_NAME`_DISPLAY_8_BIT_INIT);   	/* Selects 8-bit mode */
    CyDelay(`$I2C_SLAVE_NAME`_INIT_UP_NIB_DELAY);								/* Delay 5 ms */
	`$I2C_SLAVE_NAME`_WrtCntrlUpNib(`$I2C_SLAVE_NAME`_DISPLAY_8_BIT_INIT);  	/* Selects 8-bit mode */
    CyDelay(`$I2C_SLAVE_NAME`_INIT_UP_NIB_DELAY);								/* Delay 5 ms */
	`$I2C_SLAVE_NAME`_WrtCntrlUpNib(`$I2C_SLAVE_NAME`_DISPLAY_8_BIT_INIT);  	/* Selects 8-bit mode */
	CyDelay(`$I2C_SLAVE_NAME`_INIT_UP_NIB_DELAY);								/* Delay 5 ms */
	`$I2C_SLAVE_NAME`_WrtCntrlUpNib(`$I2C_SLAVE_NAME`_DISPLAY_4_BIT_INIT);   	/* Selects 4-bit mode */
	CyDelay(`$I2C_SLAVE_NAME`_INIT_UP_NIB_DELAY);								/* Delay 5 ms */

	`$I2C_SLAVE_NAME`_WriteControl(`$I2C_SLAVE_NAME`_DISPLAY_4_BIT_INIT);		/* Write 4-bit Mode 2x16 or 4x20 Char */
	CyDelay(`$I2C_SLAVE_NAME`_INIT_CMD_DELAY);								/* Delay 5 ms */
    `$I2C_SLAVE_NAME`_WriteControl(`$I2C_SLAVE_NAME`_CLEAR_DISPLAY);			/* Clear LCD Screen */
	CyDelay(`$I2C_SLAVE_NAME`_INIT_CMD_DELAY);								/* Delay 5 ms */
    `$I2C_SLAVE_NAME`_WriteControl(`$I2C_SLAVE_NAME`_CURSOR_AUTO_INCR_ON);		/* Incr Cursor One Space to Right After Writes */
	CyDelay(`$I2C_SLAVE_NAME`_INIT_CMD_DELAY);								/* Delay 5 ms */
	`$I2C_SLAVE_NAME`_WriteControl(`$I2C_SLAVE_NAME`_DISPLAY_ON_CURSOR_OFF);	/* Display ON Cursor OFF */
 	CyDelay(`$I2C_SLAVE_NAME`_INIT_CMD_DELAY);								/* Delay 5 ms */  
	
	#if(`$I2C_SLAVE_NAME`_CUSTOM_CHAR_SET != `$I2C_SLAVE_NAME`_NONE)
        `$I2C_SLAVE_NAME`_LoadCustomFonts(`$I2C_SLAVE_NAME`_customFonts);
    #endif /* `$I2C_SLAVE_NAME`_CUSTOM_CHAR_SET != `$I2C_SLAVE_NAME`_NONE */
}


/*******************************************************************************
* Function Name: `$I2C_SLAVE_NAME`_Enable									   *
********************************************************************************
*
* Summary:
*  Turns on the display.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
* Theory:
*  This finction has no effect when it called first time as
*  `$I2C_SLAVE_NAME`_Init() turns on the LCD.
*
*******************************************************************************/
void `$I2C_SLAVE_NAME`_Enable(void) `=ReentrantKeil($I2C_SLAVE_NAME . "_Enable")`
{
    `$I2C_SLAVE_NAME`_DisplayOn();
    `$I2C_SLAVE_NAME`_enableState = 1u;
}


/*******************************************************************************
* Function Name: `$I2C_SLAVE_NAME`_Start
********************************************************************************
*
* Summary:
*  Perform initialization required for components normal work.
*  This function initializes the LCD hardware module as follows:
*        Enable 4-bit interface
*        Clear the display
*        Enable auto cursor increment
*        Resets the cursor to start position
*  Also loads custom character set to LCD if it was defined in the customizer.
*  If it was not the first call in this project then it just turns on the
*  display
*
*
* Parameters:
*  `$I2C_SLAVE_NAME`_initVar - global variable.
*
* Return:
*  `$I2C_SLAVE_NAME`_initVar - global variable.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void `$I2C_SLAVE_NAME`_Start(void) `=ReentrantKeil($I2C_SLAVE_NAME . "_Start")`
{
    /* If not initialized then perform initialization */
    if(`$I2C_SLAVE_NAME`_initVar == 0u)
    {
        `$I2C_SLAVE_NAME`_Init();
        `$I2C_SLAVE_NAME`_initVar = 1u;
    }

    /* Turn on the LCD */
    `$I2C_SLAVE_NAME`_Enable();
    `$I2C_SLAVE_NAME`_Test();
}


/*******************************************************************************
* Function Name: `$I2C_SLAVE_NAME`_Stop
********************************************************************************
*
* Summary:
*  Turns off the display of the LCD screen.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void `$I2C_SLAVE_NAME`_Stop(void) `=ReentrantKeil($I2C_SLAVE_NAME . "_Stop")`
{
    /* Calls LCD Off Macro */
    `$I2C_SLAVE_NAME`_DisplayOff();
    `$I2C_SLAVE_NAME`_enableState = 0u;
}


/*******************************************************************************
*  Function Name: `$I2C_SLAVE_NAME`_Position
********************************************************************************
*
* Summary:
*  Moves active cursor location to a point specified by the input arguments
*
* Parameters:
*  row:     Specific row of LCD module to be written
*  column:  Column of LCD module to be written
*
* Return:
*  None.
*
* Note:
*  This only applies for LCD displays which use the 2X40 address mode.
*  This results in Row 2 offset from row one by 0x28.
*  When there are more than 2 rows, each row must be fewer than 20 characters.
*
*******************************************************************************/
void `$I2C_SLAVE_NAME`_Position(uint8 row, uint8 column) `=ReentrantKeil($I2C_SLAVE_NAME . "_Position")`
{
    switch (row)
    {
        case (uint8)0:
            `$I2C_SLAVE_NAME`_WriteControl(`$I2C_SLAVE_NAME`_ROW_0_START + column);
            break;
        case (uint8) 1:
            `$I2C_SLAVE_NAME`_WriteControl(`$I2C_SLAVE_NAME`_ROW_1_START + column);
            break;
        case (uint8) 2:
            `$I2C_SLAVE_NAME`_WriteControl(`$I2C_SLAVE_NAME`_ROW_2_START + column);
            break;
        case (uint8) 3:
            `$I2C_SLAVE_NAME`_WriteControl(`$I2C_SLAVE_NAME`_ROW_3_START + column);
            break;
        default:
            /* if default case is hit, invalid row argument was passed.*/
            break;
    }
}


/*******************************************************************************
* Function Name: `$I2C_SLAVE_NAME`_PrintString
********************************************************************************
*
* Summary:
*  Writes a zero terminated string to the LCD.
*
* Parameters:
*  string:  pointer to head of char8 array to be written to the LCD module
*
* Return:
*  None.
*
*******************************************************************************/
void `$I2C_SLAVE_NAME`_PrintString(char8 const string[]) `=ReentrantKeil($I2C_SLAVE_NAME . "_PrintString")`
{
    uint8 indexU8 = 1u;
    char8 current = *string;

    /* Until null is reached, print next character */
    while((char8) '\0' != current)
    {
        `$I2C_SLAVE_NAME`_WriteData((uint8)current);
        current = string[indexU8];
        indexU8++;
    }
}


/*******************************************************************************
*  Function Name: `$I2C_SLAVE_NAME`_PutChar
********************************************************************************
*
* Summary:
*  Writes a single character to the current cursor position of the LCD module.
*  Custom character names (`$INTANCE_NAME`_CUSTOM_0 through
*  `$INTANCE_NAME`_CUSTOM_7) are acceptable as inputs.
*
* Parameters:
*  character:  character to be written to the LCD
*
* Return:
*  None.
*
*******************************************************************************/
void `$I2C_SLAVE_NAME`_PutChar(char8 character) `=ReentrantKeil($I2C_SLAVE_NAME . "_PutChar")`
{
    `$I2C_SLAVE_NAME`_WriteData((uint8)character);
}


/*******************************************************************************
*  Function Name: `$I2C_SLAVE_NAME`_WriteData
********************************************************************************
*
* Summary:
*   Writes a DATA Command to the LCD by sending the Upper Nibble and
*   the Lower Nibble twice, once with the E input High and once with the 
*	E input Low with the the RS input held High and the RW input held Low 
*	while the K input or Back Light (BL) input is held High.
*
*******************************************************************************/	

void `$I2C_SLAVE_NAME`_WriteData(uint8 dByte) `=ReentrantKeil($I2C_SLAVE_NAME . "_WriteData")`

{
    uint8 buffer[`$I2C_SLAVE_NAME`_BUFFER_SIZE], UPPER_NIB, LOWER_NIB;
	uint8 BLH_EH_RWL_RSH, BLH_EL_RWL_RSH;
	
	UPPER_NIB = dByte & `$I2C_SLAVE_NAME`_UPPER_NIB_MASK;
   	LOWER_NIB = (dByte & `$I2C_SLAVE_NAME`_LOWER_NIB_MASK) << `$I2C_SLAVE_NAME`_LOWER_NIB_SHIFT;
	
	BLH_EH_RWL_RSH = `$I2C_SLAVE_NAME`_BLH + `$I2C_SLAVE_NAME`_EH + `$I2C_SLAVE_NAME`_RSH;
	BLH_EL_RWL_RSH = `$I2C_SLAVE_NAME`_BLH + `$I2C_SLAVE_NAME`_RSH;
	
	/* Initialize buffer with packet */
   
	buffer[`$I2C_SLAVE_NAME`_PACKET_0_POS] = UPPER_NIB | BLH_EH_RWL_RSH;
    buffer[`$I2C_SLAVE_NAME`_PACKET_1_POS] = UPPER_NIB | BLH_EL_RWL_RSH;
    buffer[`$I2C_SLAVE_NAME`_PACKET_2_POS] = LOWER_NIB | BLH_EH_RWL_RSH;
    buffer[`$I2C_SLAVE_NAME`_PACKET_3_POS] = LOWER_NIB | BLH_EL_RWL_RSH;
    
#if(CY_PSOC4)
	
	(void) I2C_`$I2C_SLAVE_NAME`_I2CMasterWriteBuf(`$I2C_SLAVE_NAME`_I2C_SLAVE_ADDR, buffer, `$I2C_SLAVE_NAME`_PACKET_SIZE, \
                                  I2C_`$I2C_SLAVE_NAME`_I2C_MODE_COMPLETE_XFER);

#else    
   	
	(void) `$I2C_MASTER_NAME`_MasterWriteBuf(`$I2C_SLAVE_NAME`_SLAVE_ADDR, buffer, `$I2C_SLAVE_NAME`_PACKET_SIZE, \
                                  `$I2C_MASTER_NAME`_MODE_COMPLETE_XFER);

#endif /*PSOC4*/ 

	CyDelayUs(`$I2C_SLAVE_NAME`_DATA_DELAY_US);
}

/*******************************************************************************
*  Function Name: `$I2C_SLAVE_NAME`_WriteControl
********************************************************************************
*
* Summary:
*   Writes a CONTROL Command to the LCD by sending the Upper Nibble and
*   the Lower Nibble twice, once with the E input High and once with the 
*	E input Low with the the RS and the RW input held Low while the
*	K input or Back Light (BL) input is held High.
*
*******************************************************************************/	

void `$I2C_SLAVE_NAME`_WriteControl(uint8 cByte) `=ReentrantKeil($I2C_SLAVE_NAME . "_WriteControl")`
{
    uint8 buffer[`$I2C_SLAVE_NAME`_BUFFER_SIZE], UPPER_NIB, LOWER_NIB;
	uint8 BLH_EH_RWL_RSL, BLH_EL_RWL_RSL;
	
	UPPER_NIB = cByte & `$I2C_SLAVE_NAME`_UPPER_NIB_MASK;
   	LOWER_NIB = (cByte & `$I2C_SLAVE_NAME`_LOWER_NIB_MASK) << `$I2C_SLAVE_NAME`_LOWER_NIB_SHIFT;
	
	BLH_EH_RWL_RSL = `$I2C_SLAVE_NAME`_BLH + `$I2C_SLAVE_NAME`_EH;
	BLH_EL_RWL_RSL = `$I2C_SLAVE_NAME`_BLH;
	
	/* Initialize buffer with packet */
   
	buffer[`$I2C_SLAVE_NAME`_PACKET_0_POS] = UPPER_NIB | BLH_EH_RWL_RSL;
    buffer[`$I2C_SLAVE_NAME`_PACKET_1_POS] = UPPER_NIB | BLH_EL_RWL_RSL;
    buffer[`$I2C_SLAVE_NAME`_PACKET_2_POS] = LOWER_NIB | BLH_EH_RWL_RSL;
    buffer[`$I2C_SLAVE_NAME`_PACKET_3_POS] = LOWER_NIB | BLH_EL_RWL_RSL;
     
#if(CY_PSOC4)
	
	(void) `$I2C_SLAVE_NAME`_I2CMasterWriteBuf(`$I2C_SLAVE_NAME`_I2C_SLAVE_ADDR, buffer, `$I2C_SLAVE_NAME`_PACKET_SIZE, \
                                  I2C_`$I2C_SLAVE_NAME`_I2C_MODE_COMPLETE_XFER);
#else    
   	
	(void) `$I2C_MASTER_NAME`_MasterWriteBuf(`$I2C_SLAVE_NAME`_SLAVE_ADDR, buffer, `$I2C_SLAVE_NAME`_PACKET_SIZE, \
                                  `$I2C_MASTER_NAME`_MODE_COMPLETE_XFER);

#endif /*PSOC4*/ 

	CyDelayUs(`$I2C_SLAVE_NAME`_CMD_DELAY_US);
}

/*******************************************************************************
*  Function Name: `$I2C_SLAVE_NAME`_WrtCntrlUpNib
********************************************************************************
*
* Summary:
*   Writes a CONTROL Command to the LCD by sending only the UPPER NIBBLE twice,
*	once with the E input High and once with the E input Low with the RS input 
*	and RW input held Low while the K input or Back Light (BL) input is held High.
*
*******************************************************************************/
void `$I2C_SLAVE_NAME`_WrtCntrlUpNib(uint8 cByte) `=ReentrantKeil($I2C_SLAVE_NAME . "_WrtCntrlUpNib")`
{
    uint8 buffer[`$I2C_SLAVE_NAME`_UPPER_NIB_BUFFER_SIZE], UPPER_NIB;
	uint8 BLH_EH_RWL_RSL, BLH_EL_RWL_RSL;
	
	UPPER_NIB = cByte & `$I2C_SLAVE_NAME`_UPPER_NIB_MASK;
	
	BLH_EH_RWL_RSL = `$I2C_SLAVE_NAME`_BLH + `$I2C_SLAVE_NAME`_EH;
	BLH_EL_RWL_RSL = `$I2C_SLAVE_NAME`_BLH;
	
	/* Initialize buffer with packet */
   
	buffer[`$I2C_SLAVE_NAME`_PACKET_0_POS] = UPPER_NIB | BLH_EH_RWL_RSL;
    buffer[`$I2C_SLAVE_NAME`_PACKET_1_POS] = UPPER_NIB | BLH_EL_RWL_RSL;
     
#if(CY_PSOC4)
	
	(void) I2C_`$I2C_SLAVE_NAME`_I2CMasterWriteBuf(`$I2C_SLAVE_NAME`_I2C_SLAVE_ADDR, buffer, `$I2C_SLAVE_NAME`_UPPER_NIB_PACKET_SIZE, \
                                  I2C_`$I2C_SLAVE_NAME`_I2C_MODE_COMPLETE_XFER);
	
#else    
   	
	(void) `$I2C_MASTER_NAME`_MasterWriteBuf(`$I2C_SLAVE_NAME`_SLAVE_ADDR, buffer, `$I2C_SLAVE_NAME`_UPPER_NIB_PACKET_SIZE, \
                                  `$I2C_MASTER_NAME`_MODE_COMPLETE_XFER);

#endif /*PSOC4*/ 
	
	CyDelayUs(`$I2C_SLAVE_NAME`_CMD_DELAY_US);

}
/*******************************************************************************
* Function Name: `$I2C_SLAVE_NAME`_IsReady
********************************************************************************
*
* Summary:
*  Polls LCD until the ready bit is set.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  Changes pins to High-Z.
*
*******************************************************************************/
void `$I2C_SLAVE_NAME`_IsReady(void) `=ReentrantKeil($I2C_SLAVE_NAME . "_IsReady")`
{
   
	CyDelay(1u);
	
}

#if(`$I2C_SLAVE_NAME`_CONVERSION_ROUTINES == 1u)

    /*******************************************************************************
    *  Function Name: `$I2C_SLAVE_NAME`_PrintInt8
    ********************************************************************************
    *
    * Summary:
    *  Print a byte as two ASCII characters.
    *
    * Parameters:
    *  value:  The byte to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void `$I2C_SLAVE_NAME`_PrintInt8(uint8 value) `=ReentrantKeil($I2C_SLAVE_NAME . "_PrintInt8")`
    {
        static char8 const CYCODE `$I2C_SLAVE_NAME`_hex[16u] = "0123456789ABCDEF";
        
        `$I2C_SLAVE_NAME`_PutChar((char8) `$I2C_SLAVE_NAME`_hex[value >> `$I2C_SLAVE_NAME`_BYTE_UPPER_NIBBLE_SHIFT]);
        `$I2C_SLAVE_NAME`_PutChar((char8) `$I2C_SLAVE_NAME`_hex[value & `$I2C_SLAVE_NAME`_BYTE_LOWER_NIBBLE_MASK]);
    }


    /*******************************************************************************
    *  Function Name: `$I2C_SLAVE_NAME`_PrintInt16
    ********************************************************************************
    *
    * Summary:
    *  Print a uint16 as four ASCII characters.
    *
    * Parameters:
    *  value:   The uint16 to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void `$I2C_SLAVE_NAME`_PrintInt16(uint16 value) `=ReentrantKeil($I2C_SLAVE_NAME . "_PrintInt16")`
    {
        `$I2C_SLAVE_NAME`_PrintInt8((uint8)(value >> `$I2C_SLAVE_NAME`_U16_UPPER_BYTE_SHIFT));
        `$I2C_SLAVE_NAME`_PrintInt8((uint8)(value & `$I2C_SLAVE_NAME`_U16_LOWER_BYTE_MASK));
    }


    /*******************************************************************************
    *  Function Name: `$I2C_SLAVE_NAME`_PrintNumber
    ********************************************************************************
    *
    * Summary:
    *  Print an uint32 value as a left-justified decimal value.
    *
    * Parameters:
    *  value:  The byte to be printed out as ASCII characters.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void `$I2C_SLAVE_NAME`_PrintNumber(uint16 value) `=ReentrantKeil($I2C_SLAVE_NAME . "_PrintNumber")`
    {

        char8 number[`$I2C_SLAVE_NAME`_NUMBER_OF_REMAINDERS];
        char8 temp[`$I2C_SLAVE_NAME`_NUMBER_OF_REMAINDERS];

        uint8 digIndex = 0u;
        uint8 numDigits;

        /* Load these in reverse order */
        while(value >= `$I2C_SLAVE_NAME`_TEN)
        {
            temp[digIndex] = (value % `$I2C_SLAVE_NAME`_TEN) + '0';
            value /= `$I2C_SLAVE_NAME`_TEN;
            digIndex++;
        }

        temp[digIndex] = (value % `$I2C_SLAVE_NAME`_TEN) + '0';
        numDigits = digIndex;

        /* While index is greater than or equal to zero copy number
        * from temporary array to number[].
        */
        while (digIndex != 0u)
        {
            number[numDigits - digIndex] = temp[digIndex];
            digIndex--;
        }
        
        /* Copy last digit */
        number[numDigits] = temp[0u];

        /* Null Termination */
        number[numDigits + 1u] = (char8) '\0';

        /* Print out number */
        `$I2C_SLAVE_NAME`_PrintString(&number[0u]);
    }

#endif /* `$I2C_SLAVE_NAME`_CONVERSION_ROUTINES == 1u */


/* [] END OF FILE */
