/*
 * main.c
 *
 *  Created on: 24 dec. 2014
 *      Author: harm
 */


#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#include "main.h"

int
main (void)
{
	// This function initiates IO ports, timers and interrupts
	ioinit();

	// Do awesome effects. Loop forever.
    while(1)
    {
        PORTB ^= (1 << PB1);
		_delay_ms(DELAY);
		PORTB = 0;
		PORTB ^= (1 << PB3);
		_delay_ms(DELAY);
		PORTB = 0;
		PORTB ^= (1 << PB2);
		_delay_ms(DELAY);
		PORTB = 0;
    }
}

void ioinit()
{
	// Set all ports to output and pull all pins low.
	DDRB = 0xff;
	DDRC = 0xff;
	DDRD = 0xff;
	PORTB = 0xff; // all pins high

	// Set timer 1 at 1.3kHz as frame buffer interrupt
	// using 256 prescaler and arduino clock frequency of 1.6MHz
	TCCR1A = 0; // set entire TCCR1A register to 0
	TCCR1B = 0;
	TCNT1 = 0;  // initialize counter to 0
	//OCR1A = 48; // compare match register = ((16*10^6) / (256*1300)) - 1 (must be <65536)
	OCR1A = 1024; // somewhat slower, so you can see the effect. Uncomment this one, and comment the line above.

	// Turn on CTC mode
	TCCR1B |= (1 << WGM12);

	// Set CS12 bit for 256 prescaler
	TCCR1B |= (1 << CS12);

	// enable timer compare interrupt
	TIMSK1 |= (1 << OCIE1A);

	//
	sei();
}

ISR(TIMER1_COMPA_vect)
{
	// Toggle port PB4 LOW to HIGH
	// Not really necessary, but helps to show POV when
	PORTB ^= (1 << 4);
}
