/*	Author:  hsu019 Huapei Su
 *  Partner(s) Name: none
 *	Lab Section: 023
 *	Assignment: Lab #4  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


enum States { Start, Init, Wait, Increase, Decrease, Reset } State;
unsigned char count;
unsigned char stay;


void Tick()
{
	 switch(State) {
		 case Start:
			 State = Init;
			 break;
		 case Init:
			 State = Wait;
		 	 break;
		 case Increase:
			 State = Wait;
		 	 stay = 1;
			 break;
		 case Decrease:
			 State = Wait;
			 stay = 1;
			 break;
		 case Reset:
			 State = Wait;
		     stay = 1;
			 break;
		 case Wait:
			 if (PINA == 0x01 && !stay) {
			 	State = Increase;
			 }
			 else if (PINA == 0x02 && !stay) {
				State = Decrease;
			 }
			 else if (PINA == 0x03)
			 {
				 State = Reset;
			 }
			 else if (PINA == 0x00)
			 {
				 stay = 0;
				 State = Wait;
			 }
			 else {
				State = Wait;
			 }
			 break;
		 default:
			 State = Start;
			 break;
	}

	 switch(State) {
	 case Init:
		 count = 0x07;
	 	 PORTC = count;
		 break;
	 case Increase:
		 if (count < 0x09)
		 {
		 	count++;
	 		PORTC = count;
		 }
		 else {
			PORTC = count;
		 }
	 	 break;
	 case Decrease:
		 if (count > 0x00)
		 {
		 	count = count - 1;
	 		PORTC = count;
		 }
		 else {
			PORTC = count;
		 }
	     break;
	 case Reset:
		 count = 0x00;
	 	 PORTC = count;
	     break;
	 case Wait:
	 	 PORTC = count;
	     break;
	 default:
		 break;
	 }
	}



int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00;PORTA = 0xFF;
    DDRC = 0xFF;PORTC = 0x00;
	State = Start; 
    while(1){
        Tick();
    }
    return 0;
}
