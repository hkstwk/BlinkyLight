/*
 * main.h
 *
 *  Created on: 27 dec. 2014
 *      Author: harm
 */

#ifndef MAIN_H_
#define MAIN_H_

void ioinit();
ISR(TIMER1_COMPA_vect);

static const int DELAY = 100;

#endif /* MAIN_H_ */
