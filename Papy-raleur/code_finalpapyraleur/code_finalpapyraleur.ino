#include <Servo.h>

// créer un objet que l'on appelera myservo que l'on pourra manipuler pour envoyer
// des informations à notre servo moteur
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
const int L1 = 2; // initialisation de la lampe


void setup() {

  pinMode(6, OUTPUT); // branchement à la borne 6 pour le moteur du bras
  pinMode(9, OUTPUT); // branchement à la borne 9 pour le moteur pied
  pinMode(10, OUTPUT); // branchement à la borne 10 pour le deuxième moteur pied
  pinMode(11, OUTPUT); // branchement à la borne 11 pour le moteur de la bulle
  pinMode(L1, OUTPUT); //L1 est une broche de sortie
  myservo1.attach(9); // le moteur pied est attaché à la borne 9
  myservo2.attach(10); // le moteur pied est attaché à la borne 10
  myservo3.attach(6);// le moteur bras lié à la borne 6
  myservo4.attach(11); // moteur de la bulle attaché à la borne 11
  Serial.begin(9600); // ouvrir la connexion série
}

void loop() {
  int value = analogRead(0);
  Serial.println(value); // lire les valeurs du reçue par le micro et les enregistrer

  if (value < 350) { // si la valeur reçue par le micro est inférieur à 450 ne rien faire

  }

  else if (value > 350) { // // sinon executer l'action
    myservo1.write(81); // activation moteur 1 (pieds)
    myservo2.write(110);
    delay(1500);
    myservo1.write(90); // arrêter la course du veille homme
    myservo2.write(90);


    myservo4.write(0); // lever bulle à 180
    delay (500);


    myservo3.write(0); // lever bras à 180 degrés
    delay(600);

    digitalWrite(L1, HIGH); //allumer la lampe
    delay(450); // attendre 1 seconde
    digitalWrite(L1, LOW); // eteindre la lampe
    delay(280); // attendre 2 seconde
    digitalWrite(L1, HIGH); //allumer la lampe
    delay(450); // attendre 1 seconde
    digitalWrite(L1, LOW); // Eteindre la lampe
    delay(280); // attendre 2 seconde
    digitalWrite(L1, HIGH); //allumer la lampe
    delay(450); // attendre 1 seconde
    digitalWrite(L1, LOW); // Eteindrela lampe
    delay(280); // attendre 2 seconde


    myservo3.write(140);   // baisser le brass (bras)
    delay(250);

    myservo4.write(140);  // baisser la bulle
    delay(500);


  }

}

