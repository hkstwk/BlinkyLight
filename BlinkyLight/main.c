// this code sets up counter1 A output at 25% and B output at 75%
// using ICR1 as top (16bit), Fast PWM.


//#include <avr/io.h>
//
//
//int main(void)
//{
//    DDRB |= (1 << DDB1)|(1 << DDB2);
//    // PB1 and PB2 is now an output
//
//    OCR1A = 0xFFFF;
//    OCR1B = 0xFFFF;
//    // set TOP to 16bit
//
//    OCR1A = 0x3FFF;
//    // set PWM for 25% duty cycle @ 16bit
//
//    OCR1B = 0xBFFF;
//    // set PWM for 75% duty cycle @ 16bit
//
//    TCCR1A |= (1 << COM1A1)|(1 << COM1B1);
//    // set none-inverting mode
//
//    TCCR1A |= (1 << WGM11);
//    TCCR1B |= (1 << WGM12)|(1 << WGM13);
//    // set Fast PWM mode using ICR1 as TOP
//
//    TCCR1B |= (1 << CS10);
//    // START the timer with no prescaler
//
//
//
//    while (1);
//    {
//        // we have a working Fast PWM
//    }
//}

// this code sets up counter0 for an 8kHz Fast PWM wave @ 16Mhz Clock


#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRD |= (1 << DDD6);
    // PD6 is now an output

    OCR0A = 128;
    // set PWM for 50% duty cycle


    TCCR0A |= (1 << COM0A1);
    // set none-inverting mode

    TCCR0A |= (1 << WGM01) | (1 << WGM00);
    // set fast PWM Mode

    TCCR0B |= (1 << CS01);
    // set prescaler to 8 and starts PWM


    while (1);
    {
        // we have a working Fast PWM
    	if (OCR0A > 0) {
    		OCR0A--;
    	}
    	else {
    		OCR0A = 255;
    	}
    	_delay_ms(100);
    }
}
