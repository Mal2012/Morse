/*
 * led.c
 *
 *  Created on: 20.10.2013
 *      Author: win_user
 */

#include "led.h"

void LEDInit(void){

	//initialize direction of first four bits to OUTPUT, because of OR(x, 1) = 1
	PJDIR |= LED1+LED2+LED3+LED4;

	//LEDs Off, as default constellation : AND(x, 0) = 0
	PJOUT &= ~(LED1+LED2+LED3+LED4);

	//initialize direction of last four bits to OUTPUT, because of OR(x, 1) = 1
	P3DIR |= LED5+LED6+LED7+LED8;

	//LEDs Off, as default constellation : AND(x, 0) = 0
	P3OUT &= ~(LED5+LED6+LED7+LED8);
}

//array of led pins
const unsigned char leds[]={LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};

// Turn the chosen LEDs on by using array as reference : PJOUT |= BITn -> 1
void LEDOn(unsigned char LEDn){

	if ((LEDn>0)&&(LEDn<=4)){

		PJOUT |= leds[--LEDn];
	}
    if ((LEDn>4)&&(LEDn<=8)){
    	P3OUT |= leds[--LEDn];
    }
}

// Turn the chosen LEDs off by using array as reference : PJOUT &= ~BITn -> 0
void LEDOff(unsigned char LEDn){

	if ((LEDn>0)&&(LEDn<=4)){
		PJOUT &= ~leds[--LEDn];
	}
	else if ((LEDn>4)&&(LEDn<=8)){
    	P3OUT &= ~leds[--LEDn];
    }
}

// Turn the chosen LEDs on/off by using array as reference : PJOUT ^= BITn -> 1/0
void LEDToggle(unsigned char LEDn){

	if ((LEDn>0)&&(LEDn<=4)){
		PJOUT ^= leds[--LEDn];
	}
	else if ((LEDn>4)&&(LEDn<=8)){
		P3OUT ^= leds[--LEDn];
	}
}
