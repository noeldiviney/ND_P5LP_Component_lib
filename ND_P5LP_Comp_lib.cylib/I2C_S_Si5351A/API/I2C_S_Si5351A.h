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

#ifndef `$INSTANCE_NAME`_H
#define `$INSTANCE_NAME`_H

/*#include <inttypes.h>*/

#define SI_CLK0_CONTROL         16 // Register definitions
#define SI_CLK1_CONTROL	        17
#define SI_CLK2_CONTROL	        18
#define SI_SYNTH_PLL_A	        26
#define SI_SYNTH_PLL_B	        34
#define SI_SYNTH_MS_0	        42
#define SI_SYNTH_MS_1           50
#define SI_SYNTH_MS_2           58
#define SI_PLL_RESET            177

#define SI_R_DIV_1              0b00000000 // R-division ratio definitions
#define SI_R_DIV_2              0b00010000
#define SI_R_DIV_4              0b00100000
#define SI_R_DIV_8              0b00110000
#define SI_R_DIV_16             0b01000000
#define SI_R_DIV_32             0b01010000
#define SI_R_DIV_64             0b01100000
#define SI_R_DIV_128            0b01110000

#define SI_CLK_SRC_PLL_A        0b00000000
#define SI_CLK_SRC_PLL_B        0b00100000

#define XTAL_FREQ	27000000			// Crystal frequency

void `$INSTANCE_NAME`_OutputOff(uint8_t clk);
void `$INSTANCE_NAME`_SetFrequency(uint32_t frequency);

#endif //`$INSTANCE_NAME`_H


/* [] END OF FILE */
