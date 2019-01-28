// on inclut la bibliothèque servo
#include <Servo.h>

// on créé un objet nommé 'myservo' à qui on pourra envoyer des informations pour le mettre en mouvement
Servo myservo;

// on créé une variable correspondant à la fréquence de départ du son émis par le buzzer
int freq = 440;

void setup() {

  Serial.begin(9600); // on ouvre la connexion série entre l'ordinateur et la carte arduino
  pinMode(7, INPUT); // on utilise la pin 7 comme entrée (le bouton y est branché)
  pinMode(8, OUTPUT); // on utilise la pin 8 comme une sortie (le buzzer y est branché)
  pinMode(12, OUTPUT); // on utilise la pin 12 comme une sortie (le servomoteur y est branché)
  myservo.attach(12); // on attache le servomoteur à la pin 12

}

void loop() {

  Serial.println(digitalRead(7)); // on imprimme la valeur lue par la pin 7 (c'est-à-dire si oui ou non le bouton est actionné) dans le moniteur série

  if (digitalRead(7)) { // si on appuie sur le bouton :
    freq += 2; // on ajoute 2 à la la variable freq à chaque fois que le code est lu (donc la fréquence augmente et le son est plus aigu)
    tone(8, freq); // le buzzer connecté à la pin 8 émet un son de fréquence égale à la variable freq
    myservo.write(180); // le servomoteur avance à sa position maximale
  }
  else {
    freq = 440; // si on n'appuie pas sur le bouton :
    myservo.write(0); // le servomoteur reste/revient à sa position initiale
    noTone(8); // le buzzer n'émet pas de son
  }
}
