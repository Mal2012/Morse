/*
 * led.h
 *
 *  Created on: 20.10.2013
 *      Author: win_user
 */

#ifndef LED_H_
#define LED_H_

#include "msp430fr5739.h"

#define LED1 BIT0 // LED on PJ.0
#define LED2 BIT1 // LED on PJ.1
#define LED3 BIT2 // LED on PJ.2
#define LED4 BIT3 // LED on PJ.3
#define LED5 BIT4 // LED on P3.4
#define LED6 BIT5 // LED on P3.5
#define LED7 BIT6 // LED on P3.6
#define LED8 BIT7 // LED on P3.7

#define S1	 BIT0 // Switch 1 on P4.0
#define S2	 BIT1 // Switch 2 on P4.1

// prototypes of the functions

// initialize LEDs
void LEDInit(void);

// Turn LEDs on
void LEDOn(unsigned char);

// Turn LEDs off
void LEDOff(unsigned char);

// Toggle LEDs by using XOR
void LEDToggle(unsigned char);

#endif /* LED_H_ */
