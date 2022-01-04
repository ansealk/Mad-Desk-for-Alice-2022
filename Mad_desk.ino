
// Пины шаг, направление, энейбл
#define PUL 5
#define DIR 6
#define ENA 7

// Направление
#define CCW HIGH
#define CW  LOW

// Для теста - 4 минуты по 2 секунды в каждой
// Для реального поворота  - 15 минут по 60 сеукнд в каждой
#define MINUTES   5
#define SECONDS   60
#define MSEC_IN_SEC 1000

// Задержка между шагами при повороте в милисекундах
#define ROTATE_DELAY  1000

// Продолжительсность поворота в секундах
#define ROTATE_TIME 10
void setup() 
{
  pinMode (PUL, OUTPUT);
  pinMode (DIR, OUTPUT);
  pinMode (ENA, OUTPUT);
 
}

void loop() 
{
  bool waitFlag = true;
    
  for (int i=0; i<5000; i++)    // Вперед на 6400 шагов (угол в 90 градусов в)
  {
    // Движение на 90 градусов занимает 10 секунд при ROTATE_DELAY = 1000
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

  waitFlag=true;
  for (int min=0; min<MINUTES && waitFlag; min++)
  {
    for (int sec=0; sec<SECONDS && waitFlag; sec++) 
    {
      // Корректировка - завершаем цикл досрочно, если до конца времени осталось времени на поворот
      if (min==MINUTES-1 && sec>=SECONDS - ROTATE_TIME ) 
        waitFlag=false;
      else
        delay(MSEC_IN_SEC);
    }
  }
}
