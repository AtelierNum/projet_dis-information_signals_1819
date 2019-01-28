
// inclure la bibliothèque dédiée à l'afficheur 4 digit
#include "TM1637.h"
// définir les pins de connexion pour la clock et la donnée
#define CLK 8
#define DIO 9
TM1637 tm1637(CLK, DIO); // attacher de manière effective nos pin et notre écran

// inclure la bibliothèque fast-led
#include <FastLED.h>
#define NUM_LEDS 7 // définir le nombre de leds
int compteur = false ;
int valuedetector = 0 ;

CRGBArray<NUM_LEDS> leds; // définir un tableau de données chaque entrée du tableau représentera une led.
float  inc = 0; // un variable que l'on va utiliser pour créer une animation.


// définir les caractères disponnibles
int8_t NumTab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; //0~9,A,b,C,d,E,F
// définir une variable que l'on va augmenter petit à petit pour calculer en temps
int num = 1000;

// inclure la bibliothèque servo
#include <Servo.h>

// créer un objet que l'on appelera myservo que l'on pourra manipuler pour envoyer
// des informations à notre servo moteur
Servo myservo;

void setup() {

  Serial.begin(9600); // ouvrir la connexion série
  pinMode(7, INPUT); // préciser que la pin 7 va être utilisée comme une entrée

  //int valuedetector = digitalRead(7); // lire la valeur sur la pin 7 et la stocker dans une variable entière
  valuedetector = 0 ;

  // initialiser notre écran et spécifier sa luminosité
  tm1637.init();
  tm1637.set(BRIGHTEST);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;

  FastLED.addLeds<NEOPIXEL, 6>(leds, NUM_LEDS);

  pinMode(5, OUTPUT); // préciser que l'on veut utiliser la pin 5 comme une sortie
  myservo.attach(5);  // préciser à notre bibliothèque qu'un servo est connecté à la pin 5
  myservo.write(360);

}

void loop() {

  valuedetector = digitalRead(7); // lire la valeur sur la pin 7 et la stocker dans une variable entière
  Serial.println(valuedetector); // imprimer le contenu de la variable dans le moniteur série

  if (valuedetector == 1 && compteur == false ) {
    compteur = true;
    delay(100);
  }

  else if (valuedetector == 1 && compteur == true) {
    compteur = false;
    num = 1000;
    myservo.write(360);
    delay(100);
  }

  if (compteur == true) {
    if (num > 0) {
      num += -1 ; // dimimue la valeur de num de 1

    }
    else {
      inc +=  0.05; // on augmente la valeur de inc
      // on calcule en fonction de inc un valeur qui va osciller entre 0 et 244.
      int green = (sin(inc) + 1) * 122; // cette valeur est stocké dans une variable nommée "green"

      // Pour i allant de 0 à 3, on va éxecuter le code entre accolades,
      // à chaque fois on augmente la valeur de i de 1
      for (int i = 0; i < NUM_LEDS; i++) {
        // on change la valeur de la led 'i' du tableau nommé 'leds" en lui donnant une nouvelle valeur RGB
        leds[i] = CRGB(255 - green, green, 0);
      }
      FastLED.show(); // on actualise le ruban de led

      myservo.write(90);


    }



  }




  // calculer le chiffre à afficher pour chaque colone du tableau de numération
  // car même si notre chiffre à moins de 4 valeurs (0 pour les milliers, centaines et dizaines)
  // on veut afficher les zéros précédent notre valeur.
  int milles = int((num / 1000) % 10);
  int cents = int ((num / 100) % 10);
  int dizaines = int((num / 10) % 10);
  int unites = int(num % 10);

  tm1637.display(0, NumTab[milles]); // afficher le chiffre des milliers sur l'ensemble de segment le plus à gauche
  tm1637.display(1, NumTab[cents]);
  tm1637.display(2, NumTab[dizaines]);
  tm1637.display(3, NumTab[unites]); // afficher le chiffre des unités sur l'ensemble de segment le plus à droite

  delay(10); // attendre un peu

// les leds s'éteignent
  leds[0] = CRGB(0, 0, 0);
      leds[1] = CRGB(0, 0, 0);
      leds[2] = CRGB(0, 0, 0);
      leds[3] = CRGB(0, 0, 0);
      leds[4] = CRGB(0, 0, 0);
      leds[5] = CRGB(0, 0, 0);
      leds[6] = CRGB(0, 0, 0);

      FastLED.show(); // on actualise le ruban de led







}
