/*	Author:  hsu019 Huapei Su
 *  Partner(s) Name: none
 *	Lab Section: 023
 *	Assignment: Lab #2  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as outputs, initialize to 0s
	DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as inputs
	DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs, initialize to 0s
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpD = 0x00;
	unsigned char total = 0x00;
while(1) {
		tmpA = PINA;
		tmpB = PINB;
		tmpC = PINC;

		total = tmpA + tmpB + tmpC;

		if (total > 140) {
			tmpD = (tmpD & 0xFE) | 0x01;
		}

		//PORTD = tmpD;
		
		if (tmpA > tmpC)
		{
			if((tmpA - tmpC) > 80){
				tmpD = (tmpD & 0xFD) | 0x02;
			}
		}
		else{
			if((tmpC - tmpA) > 80){
				tmpD = (tmpD & 0xFD) | 0x02;
			}
		}

		tmpD = (tmpD & 0x03) | (total & 0xFC);

		PORTD = tmpD;
	}
    return 1;
}
