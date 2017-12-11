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
#if !defined(TFP_TEST_H)
#define TFP_TEST_H    

#define CR 0x0D
#define LF 0x0A
    /* Used to insert a carriage return and line feed */
#define NewLine() UART_dbg_PutChar(CR); UART_dbg_PutChar(LF);

    
void putdata ( void* p, char c);
void tpf_test();

#endif  /* TFP_TEST_H */
/* [] END OF FILE */
