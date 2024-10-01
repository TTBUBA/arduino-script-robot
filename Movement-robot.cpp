#include <Servo.h>  // libreria Servo che serve per controllare i motori

// Dichiarazione degli oggetti Servo per i sei motori
Servo motore1, motore2, motore3, motore4, motore5, motore6;

void setup() 
{
  // ogni motore ha un pin specifico
  motore1.attach(8);
  motore2.attach(9);
  motore3.attach(5);
  motore4.attach(4);
  motore5.attach(7);
  motore6.attach(3);

  // avvia la comunicazione seriale a 9600 bit
  Serial.begin(9600);
}

void loop() 
{
  // chiama la funzione che gestisce il movimento del robot tramite la tastiera
  MovementRobotKeyBoard();
}

// Funzione per il controllo del movimento del robot tramite la tastiera
void MovementRobotKeyBoard()
{
  // Se c'è un dato disponibile sulla porta seriale ovvero un comando da tastiera
  if(Serial.available() > 0)
  {
    // legge il carattere inviato dalla tastiera
    char comandoTastiera = Serial.read();

    // switch che verifica quale tasto è stato premuto
    switch (comandoTastiera) 
    {
      // Se il tasto è "w", muove il motore1 ad un angolo di 90 gradi
      case 'w':
        motore1.write(90);
        break;

      case 's':
        motore2.write(0); 
        break;

      case 'd':
        motore4.write(10);
        break;

      case 'a':
        motore6.write(45);  
        break;
    }
  }
}
