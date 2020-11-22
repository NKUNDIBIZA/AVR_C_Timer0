/*
 * AVR_C_Timer0.c
 *
 * Created: 11/22/2020 2:20:06 AM
 * Author : NKUNDIBIZA ALLY
 */ 
#define OC0		0x03


#include <avr/io.h>
#include <avr/interrupt.h>


int main(void)
{

	DDRB = (1 << OC0);	// Set 0C0 pin as OUTPUT
    TCCR0 =  (1 << COM00) | (5 << CS00);  // Normal mode toggle OC0 pin on MAX 

}


