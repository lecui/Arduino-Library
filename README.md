## Управление пинами через 3 ключевых слова:
DDR   -> Установить пин как: 0-вход  1-выход
PORT  -> Если пин настроен на выход то 0- низкий сигналб 1- высокий; если на вход то 1- вкл подтягивающий резистор
PIN   -> Считать текущее состояние пина



## Нумерация пинов с интерпритацией в двоичной системе. Нумерация пинов начинается сконца и начинается с нуля

| PORTS |        PINS              |    HEX     |  Command       |
| ----- | ------------------------ | ---------- | -------------- |
|   D   |    7 6 5 4 3 2 1 0       |  B00000000 |DDRD PORTD PIND |
|   B   |  x x 13 12 11 10 9 8     |  B00000000 |DDRB PORTB PINB |
|   C   |  RESET A5 A4 A3 A2 A1 A0 |  B0000000  |DDRC PORTC PINC |

## Таблица соответствия пинов к портам:

|  0 1 2 3 4 5 6 7 | 8 9 10 11 12 13 x x | A0 A1 A2 A3 A4 A5 |
| ---------------- | ------------------- | ----------------- |
|       PD         |          PB         |          PC       |


## Соотношение стандартных функций к обращениям через регистры:

  DDRB = B00000001;  -->  PinMode(8,OUTPUT);
  if(PINB & B00100000)  -->  if(digitalRead(13) == 1)
  sbi(PORTB,PB5) - высокий уровень ; cbi(PORTB,PB5) - низкий уровень  -->  digitalWrite(5,HIGH)
------------------------------------------------------------------

## Пример:

void setup()
{
 DDRD = B01000000;  --> установить PIN6 как выход
}
void loop()
{
     sbi(PORTD, PB6);  --> выставление PIN6 в высокий уровень
}
  
  ------------------------------------------------------------------
 void setup()
{
  DDRD = B01000000;
}

void loop()
{
      /*
      if (PINB & B00010000) //проверка нажатия кнопки
          sbi(PORTB, PB5);    //включение диода
        else
          cbi(PORTB, PB5);    //выключение
      */
  for (int i = 0; i < 255; i += 10)
  {
    analogWritePin6(i);
    delay(50);
  }
}
