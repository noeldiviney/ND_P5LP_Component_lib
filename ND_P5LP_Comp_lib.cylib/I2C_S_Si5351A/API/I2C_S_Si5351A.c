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
#include "CyLib.h"
#include "`$I2C_SLAVE_NAME`.h"

#include "`$I2C_MASTER_NAME`.h"
#include "`$I2C_MASTER_NAME`_PVT.h"





#if 0
#define I2C_WRITE 0b11000000		// I2C address for writing to the Si5351A
#define I2C_READ  0b11000001		// I2C address for reading to the Si5351A

uint8_t i2cSendRegister(uint8_t reg, uint8_t data)
{
	uint8_t stts;

	i2c_start_wait(I2C_WRITE);

	stts = i2c_write(reg);
	if (stts) return 3;

	stts = i2c_write(data);
	if (stts) return 4;

	i2c_stop();	

	return 0;
}

uint8_t i2cReadRegister(uint8_t reg, uint8_t *data)
{
	uint8_t stts;

	i2c_start_wait(I2C_WRITE);

	stts = i2c_write(reg);
	if (stts) return 3;

	stts = i2c_rep_start(I2C_READ);
	if (stts) return 4;

	*data = i2c_readNak();

	i2c_stop();	

	return 0;
}

//
// Set up specified PLL with mult, num and denom
// mult is 15..90
// num is 0..1,048,575 (0xFFFFF)
// denom is 0..1,048,575 (0xFFFFF)
//
void setupPLL(uint8_t pll, uint8_t mult, uint32_t num, uint32_t denom)
{
	uint32_t P1;					// PLL config register P1
	uint32_t P2;					// PLL config register P2
	uint32_t P3;					// PLL config register P3

	P1 = (uint32_t)(128 * ((float)num / (float)denom));
	P1 = (uint32_t)(128 * (uint32_t)(mult) + P1 - 512);
	P2 = (uint32_t)(128 * ((float)num / (float)denom));
	P2 = (uint32_t)(128 * num - denom * P2);
	P3 = denom;

	i2cSendRegister(pll + 0, (P3 & 0x0000FF00) >> 8);
	i2cSendRegister(pll + 1, (P3 & 0x000000FF));
	i2cSendRegister(pll + 2, (P1 & 0x00030000) >> 16);
	i2cSendRegister(pll + 3, (P1 & 0x0000FF00) >> 8);
	i2cSendRegister(pll + 4, (P1 & 0x000000FF));
	i2cSendRegister(pll + 5, ((P3 & 0x000F0000) >> 12) | ((P2 & 0x000F0000) >> 16));
	i2cSendRegister(pll + 6, (P2 & 0x0000FF00) >> 8);
	i2cSendRegister(pll + 7, (P2 & 0x000000FF));
}

//
// Set up MultiSynth with integer divider and R divider
// R divider is the bit value which is OR'ed onto the appropriate register, it is a #define in si5351a.h
//
void setupMultisynth(uint8_t synth, uint32_t divider, uint8_t rDiv)
{
	uint32_t P1;					// Synth config register P1
	uint32_t P2;					// Synth config register P2
	uint32_t P3;					// Synth config register P3

	P1 = 128 * divider - 512;
	P2 = 0;							// P2 = 0, P3 = 1 forces an integer value for the divider
	P3 = 1;

	i2cSendRegister(synth + 0,   (P3 & 0x0000FF00) >> 8);
	i2cSendRegister(synth + 1,   (P3 & 0x000000FF));
	i2cSendRegister(synth + 2,   ((P1 & 0x00030000) >> 16) | rDiv);
	i2cSendRegister(synth + 3,   (P1 & 0x0000FF00) >> 8);
	i2cSendRegister(synth + 4,   (P1 & 0x000000FF));
	i2cSendRegister(synth + 5,   ((P3 & 0x000F0000) >> 12) | ((P2 & 0x000F0000) >> 16));
	i2cSendRegister(synth + 6,   (P2 & 0x0000FF00) >> 8);
	i2cSendRegister(synth + 7,   (P2 & 0x000000FF));
}

//
// Switches off Si5351a output
// Example: si5351aOutputOff(SI_CLK0_CONTROL);
// will switch off output CLK0
//
void `$INSTANCE_NAME`_OutputOff(uint8_t clk)
{
	i2c_init();
	
	i2cSendRegister(clk, 0x80);		// Refer to SiLabs AN619 to see bit values - 0x80 turns off the output stage

	i2c_exit();
}

// 
// Set CLK0 output ON and to the specified frequency
// Frequency is in the range 1MHz to 150MHz
// Example: si5351aSetFrequency(10000000);
// will set output CLK0 to 10MHz
//
// This example sets up PLL A
// and MultiSynth 0
// and produces the output on CLK0
//
void `$INSTANCE_NAME`_SetFrequency(uint32_t frequency)
{
	uint32_t pllFreq;
	uint32_t xtalFreq = XTAL_FREQ;
	uint32_t l;
	float f;
	uint8_t mult;
	uint32_t num;
	uint32_t denom;
	uint32_t divider;

	i2c_init();						// Initialise the I2C

	divider = 900000000 / frequency;// Calculate the division ratio. 900,000,000 is the maximum internal 
									// PLL frequency: 900MHz
	if (divider % 2) divider--;		// Ensure an even integer division ratio

	pllFreq = divider * frequency;	// Calculate the pllFrequency: the divider * desired output frequency

	mult = pllFreq / xtalFreq;		// Determine the multiplier to get to the required pllFrequency
	l = pllFreq % xtalFreq;			// It has three parts:
	f = l;							// mult is an integer that must be in the range 15..90
	f *= 1048575;					// num and denom are the fractional parts, the numerator and denominator
	f /= xtalFreq;					// each is 20 bits (range 0..1048575)
	num = f;						// the actual multiplier is  mult + num / denom
	denom = 1048575;				// For simplicity we set the denominator to the maximum 1048575

									// Set up PLL A with the calculated multiplication ratio
	setupPLL(SI_SYNTH_PLL_A, mult, num, denom);
									// Set up MultiSynth divider 0, with the calculated divider. 
									// The final R division stage can divide by a power of two, from 1..128. 
									// reprented by constants SI_R_DIV1 to SI_R_DIV128 (see si5351a.h header file)
									// If you want to output frequencies below 1MHz, you have to use the 
									// final R division stage
	setupMultisynth(SI_SYNTH_MS_0, divider, SI_R_DIV_1);
									// Reset the PLL. This causes a glitch in the output. For small changes to 
									// the parameters, you don't need to reset the PLL, and there is no glitch
	i2cSendRegister(SI_PLL_RESET, 0xA0);	
									// Finally switch on the CLK0 output (0x4F)
									// and set the MultiSynth0 input to be PLL A
	i2cSendRegister(SI_CLK0_CONTROL, 0x4F | SI_CLK_SRC_PLL_A);

	i2c_exit();						// Exit I2C
}
#endif  /* #if 0  */


/* [] END OF FILE */
