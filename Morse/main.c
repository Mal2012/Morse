#include "msp430fr5739.h"
#include "uart.h"
//#include "uart2.h"
#include "debounce.h"
#include "led.h"


/*
 * main.c
 */
int main(void) {
	uartInit();
	//uart_init();
		// Stop WDT
		WDTCTL = WDTPW + WDTHOLD;

		// both ports as inputs
		P4DIR=0x00;

		// enable interrupts for S1 and S2 buttons
		P4IE |= (S1+S2);

		// Button S1 and S2 are in active-low configuration -> enable pull-ups on respective ports
		// Very imortant - else many different distortion levels !!!
		P4REN=(S1+S2);

		// the other end of the resistor has to be pulled high
		P4OUT=(S1+S2);

		// clear interrupt flag
		P4IFG&=~(S1+S2);

		LEDInit();

		_enable_interrupt();

		// do nothing, interrupt routine will take charge
		for (;;){
		}
}
// Port 4 interrupt service routine
#pragma vector=PORT4_VECTOR
__interrupt void Port_4(void){

	debounce();
    if(P4IFG&S1){
    	//check if S1 was pressed
    	debounce();
    	output('.');
    	//uart_putc('.');
    	// uart_puts("Hello World!");
    	// clear the interrupt flag
        P4IFG &= ~S1;
        // set LEDs on both ports
        PJOUT |= (LED1 + LED2 + LED3 + LED4);
        P3OUT |= (LED5 + LED6 + LED7 + LED8);
    }
    //check if S2 was pressed
    if(P4IFG&S2) {
    	debounce();
    	output('-');
    	//uart_putc('-');
    	// clear the interrupt flag
        P4IFG &= ~S2;
        // reset LEDs on both ports
        PJOUT &= ~(LED1 + LED2 + LED3 + LED4);
        P3OUT &= ~(LED5 + LED6 + LED7 + LED8);
    }
 }


