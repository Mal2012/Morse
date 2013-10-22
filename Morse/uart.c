/*
 * uart.c
 *
 *  Created on: 22.10.2013
 *      Author: Malcolm
 */
#include "msp430fr5739.h"

void uartInit(){
	  // Configure UART pins P2.0 & P2.1
	  P2SEL1 |= BIT0 + BIT1;
	  P2SEL0 &= ~(BIT0 + BIT1);
	  UCA0CTL1 |= UCSWRST;
	   UCA0CTL1 = UCSSEL_2;                      // Set SMCLK as UCLk
	   UCA0BR0 = 52;                              // 9600 baud
	   // 8000000/(9600*16) - INT(8000000/(9600*16))=0.083
	   UCA0BR1 = 0;
	   UCA0MCTLW = 0x4911 ;
	   UCA0CTL1 &= ~UCSWRST;
}
void output(char outp){
	  // One time initialization of header and footer transmit package
	   // Configure UART 0
	   UCA0TXBUF = outp;

	   //while ( ( UCA0IFG & UCTXIFG ) == 0 );
	  //UCA0TXBUF = c;
}


