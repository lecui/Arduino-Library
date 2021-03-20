#ifndef MyRegist_h
#define MyRegist_h

#include "Arduino.h"

//PWM_Pins    timers
//OCR2B -- 3  -- TIMER2B
//OCR0B -- 5 --  TIMER0B
//OCR0A -- 6 -- TIMER0A
//OCR1A -- 9 -- TIMER1A
//OCR1B -- 10 -- TIMER1B
//OCR2A -- 11 -- TIMER2A

#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))

#define analogWritePin3(val) (sbi(TCCR2A, COM2B1), OCR2B = val)
#define analogWritePin5(val) (sbi(TCCR0A, COM0A1), OCR0B = val)
#define analogWritePin6(val) (sbi(TCCR0A, COM0A1), OCR0A = val)
#define analogWritePin9(val) (sbi(TCCR1A, COM1A1), OCR1A = val)
#define analogWritePin10(val) (sbi(TCCR1A, COM1B1), OCR1B = val)
#define analogWritePin11(val) (sbi(TCCR2A, COM2A1), OCR2A = val)

#endif
