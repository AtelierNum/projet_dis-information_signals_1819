// PROJET FINAL
// branchement monteur
// inclure la bibliothèque servo
#include <Servo.h>

// créer un objet que l'on appelera myservo que l'on pourra manipuler pour envoyer
// des informations à notre servo moteur
Servo myservo;

void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT); // préciser que l'on veut utiliser la pin 6 comme une sortie
  myservo.attach(6);  // préciser à notre bibliothèque qu'un servo est connecté à la pin 6
}

void loop() {
  int val = analogRead(0); // lire une valeur sur A0 - celle ci sera comprise entre 0 et 1023
  Serial.println(val);
  int newval = map(val, 200, 700, 90, 0); // notre valeur est comprise entre 0 et 1023, on veut une valeur entre 0 et 180
  newval = constrain(newval, 0, 90);
  myservo.write(newval);

}
