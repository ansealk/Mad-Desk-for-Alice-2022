
// Пины шаг, направление, энейбл
#define PUL 5
#define DIR 6
#define ENA 7

// Направление
#define CCW HIGH
#define CW  LOW

// Для теста - 4 минуты по 2 секунды в каждой
// Для реального поворота  - 15 минут по 60 сеукнд в каждой
#define MINUTES   1
#define SECONDS   2
#define MSEC_IN_SEC 1000

// Задержка между шагами при повороте
#define ROTATE_DELAY  1
void setup() 
{
  pinMode (PUL, OUTPUT);
  pinMode (DIR, OUTPUT);
  pinMode (ENA, OUTPUT);
 
}

void loop() 
{
  for (int i=0; i<5000; i++)    // Вперед на 6400 шагов (угол в 90 градусов в)
  {
    digitalWrite(DIR,CCW);            // Задаем направление
    digitalWrite(ENA,HIGH);           // Включаем передачу
    digitalWrite(PUL,HIGH);           // Даем один импульс
    delayMicroseconds(ROTATE_DELAY);  // Ожидание
    digitalWrite(PUL,LOW);            // Гасим импульс
    delayMicroseconds(ROTATE_DELAY);  // Ожидание
  }
  // Ожидание MINUTES минут.
  // Почему два цикла? 
  // Тупая ардуина переполняется на одном счетчике (минуты * секунды * милисекунды)
  // Потому сделал ожидание в цикле минут и секунд
  for (int min=0; min<MINUTES; min++)
    for (int sec=0; sec<SECONDS; sec++) 
      delay(MSEC_IN_SEC);
  
}
