// inclure la bibliothèque servo
#include <Servo.h>

// créer un objet que l'on appelera myservo que l'on pourra manipuler afin d'envoyer des informations à notre servo moteur
Servo myservo1; // on crée une variable servo moteur continu 1
Servo myservo2; //on crée une variable servo moteur continu 2

void setup() {
  pinMode(9, OUTPUT); // préciser que l'on veut utiliser la pin 9 comme une sortie pour le servo 1
  myservo1.attach(9);  // préciser à notre bibliothèque que le servo 1 est connecté à la pin 9
 // pinMode(6, OUTPUT); // préciser que l'on veut utiliser la pin 6 comme une sortie pour le servo 2
 // myservo2.attach(6); // préciser à notre bibliothèque que le servo 2 est connecté à la pin 6

  //photoresistance
  Serial.begin(9600); // ouvrir la connexion série
}

void loop() {
  /*
    myservo.write(90); // mettre le servo en position de repos
    delay(1500); // attendre 1.5 sec
    myservo.write(0); // faire tourner le servo le plus vite possible dans le sens des aiguilles d'une montre
    delay(1500);
    myservo.write(0);// mettre le servo en position de repos
    delay(1500);
  */

  //photoresistance
  int value = analogRead(0); // lire la valeur sur la pin A0 et la stocker dans une variable entière
  Serial.println(value); // imprimer le contenu de la variable dans le moniteur série

 // int servopos = map(value, 15, 600, 0, 180);
  //myservo1.write(servopos);

  if (value > 400) { // Si ma valeur de photorésistance est supérieure à 400
    myservo1.write(90); // alors servo 1 tourne
    //myservo2.write(90g); // alors servo 2 tourne
  }
  else {

    myservo1.write(100); // faire tourner le servo le plus vite possible dans le sens inverse des aiguilles d'une montre
   // myservo2.write(180); // faire tourner le servo le plus vite possible dans le sens inverse des aiguilles d'une montre

  }
}



