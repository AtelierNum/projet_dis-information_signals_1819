#include <Servo.h> // On inclut la bibliothêque du servomoteur.

int pinMic = A0; // On associe le micro au pin analogique 0.

Servo myservo1; // On appelle le servomoteur linéaire 1 myservo1.
int pinServo1 = 2; // On associe le pin du servomoteur linéaire 1 au pin digital 2.

Servo myservo2; // On appelle le servomoteur linéaire 2 myservo2.
int pinServo2 = 4; // On associe le pin du servomoteur linéaire 2 au pin digital 4.


void setup() {
  Serial.begin(9600); // On lance les servomoteurs linéaires.
  myservo1.attach(pinServo1); // On attache le servomoteur linéaire 1 à son pin.
  myservo2.attach(pinServo2); // On attache le servomoteur linéaire 2 à son pin.
  myservo1.write(90); // Le servomoteur linéaire 1 est immobile.
  myservo2.write(90); // Le servomoteur linéaire 2 est immobile.
}


void loop() {
  int value = analogRead(pinMic); // On crée la variable value qui prendra la valeur lue sur le micro.

  if (value<700) { // Si la valeur lue par le micro est supérieure à 700, soit le seuil où on considérera le volume comme fort:
    myservo1.write(179); // Le servomoteur linéaire 1 se déplace à son point maximum.
    myservo2.write(179); // Le servomoteur linéaire 2 se déplace à son point maximum.
  }

  else { // Si la valeur lue par le micro est inférieure à 700, soit le seuil où on considérera le volume comme faible:
    myservo1.write(1); // Le servomoteur linéaire 1 se déplace à son point minimum.
    myservo2.write(1); // Le servomoteur linéaire 2 se déplace à son point minimum.
    delay(5000); // Les servomoteurs linéaires attendent 2 secondes.
  }

}
