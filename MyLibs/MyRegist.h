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

// PINMODE -- DDR -> 0-вход  1-выход
// digitalWrite -- PORT  -> Если пин настроен на выход то 0- низкий сигналб 1- высокий; если на вход то 1- вкл подтягивающий резистор
// digitalRead -- PIN
//
// |PORTS|        PINS             |    HEX     |  Command
// |  D  | 7 6 5 4 3 2 1 0         |  B00000000 |DDRD PORTD PIND
// |  B  | x x 13 12 11 10 9 8     |  B00000000 |DDRB PORTB PINB
// |  C  | RESET A5 A4 A3 A2 A1 A0 |  B0000000  |DDRC PORTC PINC
//       ^
//       |
// HEX B76543210
//------------------------------------------------------------------
// 0 1 2 3 4 5 6 7 | 8 9 10 11 12 13 x x | A0 A1 A2 A3 A4 A5 |
//       PD        |          PB         |          PC       |
//------------------------------------------------------------------
//  DDRB = B00000001;  -->  PinMode(8,OUTPUT);
//  digitalRead :  if(PINB & B00100000)  -->  if(digitalRead(13) == 1)
//  digitalWrite : sbi(PORTB,PB5) - высокий уровень ; cbi(PORTB,PB5) - низкий уровень
//------------------------------------------------------------------
//  Пример:
//  void setup()
//  {
//    DDRD = B01000000;  --> установить PIN6 как выход
//  }
//  void loop()
//  {
//     sbi(PORTD, PB6);  --> выставление PIN6 в высокий уровень
//  }