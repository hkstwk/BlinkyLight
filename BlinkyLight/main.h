/*
 * main.h
 *
 *  Created on: 27 dec. 2014
 *      Author: harm
 */

#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdbool.h>


void ioinit();
ISR(TIMER1_COMPA_vect);

static const int DELAY = 5000;

#endif /* MAIN_H_ */
