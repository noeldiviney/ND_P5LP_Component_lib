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
#if !defined(TINYPRINTF_EXAMPLE_H)
#define TINYPRINTF_EXAMPLE_H    

#define CR 0x0D
#define LF 0x0A
    /* Used to insert a carriage return and line feed */
#define NewLine() `$UART_NAME`_PutChar(CR); `$UART_NAME`_PutChar(LF);

    
void putdata ( void* p, char c);
void tpf_test();

#endif  /* TINYPRINTF_EXAMPLE_H */
/* [] END OF FILE */
