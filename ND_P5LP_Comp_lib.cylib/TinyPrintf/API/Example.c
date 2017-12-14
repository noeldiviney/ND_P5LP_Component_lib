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

#define CR 0x0D
#define LF 0x0A

/* Used to insert a carriage return and line feed */
#define NewLine() `$UART_NAME`_PutChar(CR); `$UART_NAME`_PutChar(LF);

/* For use with tinyprintf function */
/* defines how the function will transmit data */
void putdata ( void* p, char c)
{
	`$UART_NAME`_PutChar(c);
}


void tpf_test()
{
	/* tinyprintf supports the following formats:
	
	'd' int as a signed decimal number
	'u' uint as a decimal number
	'c' character
	's' null terminated string
	'x' / 'X' hexadecimal with lower / upper case letters
	
	*/
	
	int8 d = -10;
	uint8 u = 127;
	char c = 'c';
	const char s[] = "Null String\n";
	char buffer[50];

	/* Place your application code here. */

	`$UART_NAME`_PutString("USB_UART\n");
	NewLine();
	NewLine();

	/* printf examples */

	`$UART_NAME`_PutString("printf Examples");
	NewLine();
	NewLine();

	/* print variables using printf */
	printf("%d", d);
	NewLine();
	printf("%u", u);
	NewLine();
	printf("%x", u);
	NewLine();
	printf("%X", u);
	NewLine();
	printf("%c", c);
	NewLine();
	printf("%s", s);
	NewLine();
	
	/* sprintf examples */
	
	`$UART_NAME`_PutString("sprintf Examples");
	NewLine();
	NewLine();
	
	sprintf(buffer, "signed decimal: %d",d);
	`$UART_NAME`_PutString(buffer);
	NewLine();
	
	sprintf(buffer, "unsigned decimal: %u",u);
	`$UART_NAME`_PutString(buffer);
	NewLine();
	
	sprintf(buffer, "lower case hex: %x",u);
	`$UART_NAME`_PutString(buffer);
	NewLine();
	
	sprintf(buffer, "uppper case hex: %X",u);
	`$UART_NAME`_PutString(buffer);
	NewLine();
	
	sprintf(buffer, "character: %c",c);
	`$UART_NAME`_PutString(buffer);
	NewLine();
	
	sprintf(buffer, "string: %s",s);
	`$UART_NAME`_PutString(buffer);
	
//    for(;;)
//    {

//    }
}


/* [] END OF FILE */
