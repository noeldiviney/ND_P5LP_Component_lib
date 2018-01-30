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
   `$UART_NAME`_Start();

   `$PRINTF_NAME`_Start();
   
   printf("%s", "Hello World");
   NewLine();
   TriggerScope();
    
    
   `$I2C_MASTER_NAME`_Start();
   `$I2C_SLAVE_NAME`_Start();
    
   `$I2C_SLAVE_NAME`_Test();
}

/* [] END OF FILE */
