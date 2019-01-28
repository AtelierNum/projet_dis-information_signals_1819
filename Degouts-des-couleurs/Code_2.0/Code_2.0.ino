#include <FastLED.h>
#define NUM_LEDS 12 // définir le nombre de leds


#include <Servo.h>
Servo myservo;
// créer un objet que l'on appelera myservo que l'on pourra manipuler pour envoyer des informations à notre servo moteur.


CRGBArray<NUM_LEDS> leds; // définir un tableau de données chaque entrée du tableau représentera une led.
float  inc = 0; // une variable que l'on va utiliser pour créer une animation.



void setup() {
  Serial.begin(9600); // ouvrir la connexion série

  FastLED.addLeds<NEOPIXEL, 9>(leds, NUM_LEDS); // on initialise notre strip de led sur la pin 9
   pinMode(13, INPUT); // préciser que la pin 13 va être utilisée comme une entrée

  pinMode(6, OUTPUT); // préciser que l'on veut utiliser la pin 6 comme une sortie
  myservo.attach(6);  // préciser à notre bibliothèque qu'un servo est connecté à la pin 6

  Serial.begin(9600); // ouvrir la connexion série

}

void loop() {

  int value = analogRead(0); // lire la valeur sur la pin A0 (infrarouge)
  //Serial.println(value); // imprimmer le contenu de la variable dans le moniteur série



  int value2 = digitalRead(13); // lire la valeur sur la pin 13 et la stocker dans une variable entière
  Serial.println(value2); // imprimmer le contenu de la variable dans le moniteur série

  if (value > 400) {
    myservo.write(180); // mettre le servo en buté à droite (rotation de 180°)
  }
  else{

     myservo.write(0); // mettre le servo en position de repos
  }

  if (value2 == 0) {

    leds[0] = CRGB(0, 255, 0); // Led verte
    leds[1] = CRGB(0, 255, 0); // Led verte
    leds[2] = CRGB(0, 255, 0); // Led verte
    leds[3] = CRGB(0, 255, 0); // Led verte
    leds[4] = CRGB(0, 255, 0); // Led verte
    leds[5] = CRGB(0, 255, 0); // Led verte
    leds[6] = CRGB(0, 0, 0); // Led inactive
    leds[7] = CRGB(0, 0, 0); // Led inactive
    leds[8] = CRGB(0, 0, 0); // Led inactive
    leds[9] = CRGB(0, 0, 255); // Led bleue
    leds[10] = CRGB(0, 0, 255); // Led bleue
    leds[11] = CRGB(0, 0, 255); // Led bleue

  }

  //if (value2 == 1)
  else{

    leds[0] = CRGB(0, 255, 0); // Led verte
    leds[1] = CRGB(0, 255, 0); // Led verte
    leds[2] = CRGB(0, 255, 0); // Led verte
    leds[3] = CRGB(0, 255, 0); // Led verte
    leds[4] = CRGB(0, 255, 0); // Led verte
    leds[5] = CRGB(0, 255, 0); // Led verte
    leds[6] = CRGB(255, 0, 0); // Led rouge
    leds[7] = CRGB(255, 0, 0); // Led rouge
    leds[8] = CRGB(255, 0, 0); // Led rouge
    leds[9] = CRGB(0, 0, 0); // Led inactive
    leds[10] = CRGB(0, 0, 0); // Led inactive
    leds[11] = CRGB(0, 0, 0); // Led inactive

  }

  FastLED.show(); // on actualise le ruban de led

}




