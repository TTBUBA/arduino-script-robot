#include <servo.h>

Servo motore1 , motore2 , motore3 , motore4 , motore5 , motore6;
void setup() 
{
  motore1.attach(8);
  motore2.attach(8);
  motore2.attach(8);
  motore3.attach(8);
  motore4.attach(8);
  motore5.attach(8);
  motore6.attach(8);

  Serial.begin(9600);
}

void loop() 
{
  MovementRobotKeyBoard();
}

void MovementRobotKeyBoard()
{
  if(Serial.available() > 0)
  {
    char comandoTastiera = Serial.read();

    switch (comandoTastiera) 
    {
      case "w":
        motore1.write(90);
        break;

      case "d":
        motore2.write(90);
              
      case "s":
        motore2.write(90);
        break;

      case "a":
        motore2.write(90);
        break;
    }
  }
}
