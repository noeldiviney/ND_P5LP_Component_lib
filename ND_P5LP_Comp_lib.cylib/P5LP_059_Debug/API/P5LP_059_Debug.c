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


/*
 *     Initialization code to be called from "main.c"
 *
 */
void `$INSTANCE_NAME`_Start(void)
{
    UART_dbg_Start();

   I2C_M_FF_Start();
   PCF8574_LCD_Start();
    
   TinyPrintf_Start();
   
   printf("%s", "Hello World");
   NewLine();
   TriggerScope();
   PCF8574_LCD_Test();
}

/* [] END OF FILE */
