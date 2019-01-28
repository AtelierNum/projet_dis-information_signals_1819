// inclure la bibliothèque servo
#include <Servo.h>
Servo myservo;//objet que l’on pourra manipuler pour envoyer des informations au servo moteur
Servo myservo2; //objet que l’on pourra manipuler pour envoyer des informations au servo moteur

//Définir l’information
void setup()

Serial.begin(9600); // ouvrir la connexion serie
pinMode(9,OUTPUT); // Connecter servomoteur à la pin 9
pinMode(6,OUTPUT);// Connecter servomoteur à la pin 6
myservo.attach(9);// Connecter capteur au servomoteur 1
myservo2.attach(6);// Connecter capteur au servomoteur 2

}

void loop() {//Lire en boucle

int value = analogRead(5); // lire la valeur sur la pin A5 et la stocker dans une variable entière
Serial.println(value); // imprimmer le contenu de la variable dans le moniteur série
int servoPos = map(value,100,500,20,160)//Intervalle de rotation de 140°
myservo.write(servoPos);// Lire l’information de la valeur 1
int value2 = analogRead(0); // lire la valeur sur la pin A0 et la stocker dans une variable entière
//Serial.println(value2); // imprimmer le contenu de la variable dans le moniteur série
int servoPos2 = map(value2,100,500,0,180);//Intervalle de rotation de 180°
myservo2.write(servoPos2);// Lire l’information de la valeur 2
