#include <Wire.h>
#include "paj7620.h"
#include <Servo.h>

// une variable qui représente notre capteur, nous utilisons 3 servo moteurs donc nous introduisons 3 variables
// nous avons nommé nos moteurs en fonction de la pin de sortie pour nous faciliter la lecture
uint8_t gesture = 0;
Servo myservo2;
Servo myservo6;
Servo myservo9;

void setup() {

  pinMode(2, OUTPUT); // préciser que l'on veut utiliser la pin 2 comme une sortie
  myservo2.attach(2);  // préciser à notre bibliothèque qu'un servo est connecté à la pin 2, ici le moteur2
    myservo2.write(0); // le moteur au repos ne bouge pas il est donc à 0°

  pinMode(6, OUTPUT); // utiliser la pin 6 comme une sortie
  myservo6.attach(6); // servo correspond au moteur6
  myservo6.write(90); // le moteur au repos est positionné à 90°

  pinMode(9, OUTPUT); // utiliser la pin 9 comme une sortie
  myservo9.attach(9); // servo correspond au moteur9
  myservo9.write(90); // le moteur au repos est positionné à 90°

  Serial.begin(9600);

  gesture = paj7620Init(); // introduire le capteur de mouvement
  Serial.println("Please input your gestures:\n");
}

void loop() {

  uint8_t data = 0, data1 = 0;
  gesture = paj7620ReadReg(0x43, 1, &data); // lire les valeur du capteur

  switch (data) {
    case GES_RIGHT_FLAG: // si data correspond à un gesture vers la droite
      Serial.println("Right"); // OUVRE LES PORTES
      myservo6.write(180); // lorsque l'on effectue un mouvement vers la droite les moteurs s'activent, les hélices des 2 moteurs exerce une rotation de 90° dans un sens opposé
      myservo9.write(0);

      break;
    case GES_LEFT_FLAG: // si data correspond à un gesture vers la gauche
      Serial.println("Left"); // FERME LES PORTES
      // myservo.write(90); // 2x MOTEUR 1 HELICE
      myservo6.write(90);
      myservo9.write(90);

       break;
    case GES_CLOCKWISE_FLAG: // si data correspond à un gesture tourner dans le sens des aiguilles d'une montre
      Serial.println("Clockwise"); // FAIT TOURNER LE SABLIER
      myservo2.write(180); // le moteur à double hélice va exercer une rotation de 180°


      break;
    case GES_COUNT_CLOCKWISE_FLAG: // si data correspond à un gesture tourner dans le sens inverse des aiguilles d'une montre
      Serial.println("anti-clockwise");
      myservo2.write(0); // le moteur à double hélice va exercer une rotation de 180° dans le sens inverse

//  autres mouvements possibles de la bibliothèque que nous n'utilisons pas :

      break;
    case GES_UP_FLAG: // si data correspond à un gesture vers le haut
      Serial.println("Up");

      break;
    case GES_DOWN_FLAG: // si data correspond à un gesture vers le bas
      Serial.println("Down"); //

      break;
    case GES_FORWARD_FLAG: // si data correspond à un gesture vers l'avant
      Serial.println("Forward");

      break;
    case GES_BACKWARD_FLAG: // si data correspond à un gesture vers l'arrière
      Serial.println("Backward");

      break;
    default:
      paj7620ReadReg(0x44, 1, &data1);
      if (data1 == GES_WAVE_FLAG) {
        Serial.println("wave");

      }
      break;



  }
}
