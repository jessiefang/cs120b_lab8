/*	Author: Yunjie Fang
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: 
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1<< ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
   // DDRD = 0xFF; PORTD = 0x00;
    ADC_init();

    /* Insert your solution below */
    while (1) {

	unsigned long  MAX = 767;
	unsigned long x = 0x00;
	unsigned long  oneled = MAX/8;
    	    x = ADC;
        unsigned long tmpB = (long)x; 
	if(tmpB <= oneled){
		PORTB = 0x01;
	}else if(tmpB <= oneled * 2){
	       PORTB = 0x03;
	}else if(tmpB <= oneled * 3){
               PORTB = 0x07;
        }else if(tmpB <= oneled * 4){
               PORTB = 0x0F;
        }else if(tmpB <= oneled * 5){
               PORTB = 0x1F;
        }else if(tmpB <= oneled * 6){
               PORTB = 0x3F;
        }else if(tmpB <= oneled * 7){
               PORTB = 0x7F;
        }else if(tmpB <= oneled * 8){
               PORTB = 0xFF;
        }
    }
    return 1;
}
