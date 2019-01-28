// inclure la bibliothèque fast-led
#include <FastLED.h>    // intégrer la led
#define NUM_LEDS 64 // définir le nombre de leds

CRGBArray<NUM_LEDS> leds; // définir un tableau de données chaque entrée du tableau représentera une led.

int happyleds[64] = { 0, 0, 0, 0, 0, 0, 0, 0,      // Il s'agit ici de 8 rangées de 8 leds, chaque valeur équivaut à un état, (0: éteint), (1: allumé).
                      0, 1, 1, 0, 0, 1, 1, 0,      // Grâce aux 64 leds il est donc possible de dessiner en laissant certaines leds éteintes.
                      0, 1, 1, 0, 0, 1, 1, 0,      // happy led pour :)
                      0, 0, 0, 0, 0, 0, 0, 0,      // angry led pour :(
                      1, 1, 0, 0, 0, 0, 1, 1,      // medium led pour :l
                      1, 1, 0, 0, 0, 0, 1, 1,
                      0, 1, 1, 1, 1, 1, 1, 0,
                      0, 0, 1, 1, 1, 1, 0, 0
                    };
int angryleds[64] = { 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 1, 1, 0, 0, 1, 1, 0,
                      0, 1, 1, 0, 0, 1, 1, 0,
                      0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 1, 1, 1, 1, 0, 0,
                      0, 1, 1, 1, 1, 1, 1, 0,
                      1, 1, 0, 0, 0, 0, 1, 1,
                      1, 1, 0, 0, 0, 0, 1, 1
                    };
int mediumleds[64] = { 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 1, 1, 0, 0, 1, 1, 0,
                       0, 1, 1, 0, 0, 1, 1, 0,
                       0, 0, 0, 0, 0, 0, 0, 0,
                       1, 1, 1, 1, 1, 1, 1, 1,
                       1, 1, 1, 1, 1, 1, 1, 1,
                       0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0
                     };






void setup() {
  FastLED.addLeds<NEOPIXEL, 6>(leds, NUM_LEDS);
  Serial.begin(9600); // ouvrir la connexion série
}

void loop() {

  int value = analogRead(0);
  Serial.println(value);
  int hueval = map(value, 750, 0, 255, 700);


  //HAPPY//


  // int ambientBrightness = analogRead(250);         // ici on vient définir le dessin modéliser plus haut en fonction d'un interval de valeur collecter par le capteur de présence.
  if (value < 580 && value > 400) {
    hueval = 80;                                      // ici on définit la valeur de hueval pour associé la couleur verte l'orsque l'on se place dans l'interval de valeur voulu.
    // Pour i allant de 0 à 5, on va éxecuter le code entre accolades,
    // à chaque fois on augmente la valeur de i de 1
    for (int i = 0; i < NUM_LEDS; i++) {
      // on change la valeur de la led 'i' du tableau nommé "leds" en lui donnant une nouvelle valeur RGB
      leds[i] = CHSV(hueval , 255, 100 * happyleds[i]);
    }


    //ANGRY//

  }
  else  if (value < 1024 && value > 580) {
    hueval = 250;
    // Pour i allant de 0 à 5, on va éxecuter le code entre accolades,
    // à chaque fois on augmente la valeur de i de 1
    for (int i = 0; i < NUM_LEDS; i++) {
      // on change la valeur de la led 'i' du tableau nommé "leds" en lui donnant une nouvelle valeur RGB
      leds[i] = CHSV(hueval , 255, 100 * angryleds[i]);
    }


    //MEDIUM//

  }                                                               // la boucle if permet de faire varier la couleur en fonction de la présence éventuelle d'une voiture
  else  if (value < 400 && value > 100) {                         // si la valeur détectée par le capteur de présence est positive alors les leds s'allument, ensuite
    hueval = 45;                                                  // 3 intervalles sont déterminés pour chaque message délivrés par les leds.
    // Pour i allant de 0 à 5, on va éxecuter le code entre accolades,
    // à chaque fois on augmente la valeur de i de 1
    for (int i = 0; i < NUM_LEDS; i++) {
      // on change la valeur de la led 'i' du tableau nommé "leds" en lui donnant une nouvelle valeur RGB
      leds[i] = CHSV(hueval , 255, 100 * mediumleds[i]);
    }


    //ZERO// 5924 octets ///

  }
  else  if (value < 100 && value > 0) {
    // Pour i allant de 0 à 5, on va éxecuter le code entre accolades,
    // à chaque fois on augmente la valeur de i de 1
    for (int i = 0; i < NUM_LEDS; i++) {
      // on change la valeur de la led 'i' du tableau nommé "leds" en lui donnant une nouvelle valeur RGB
      leds[i] = CHSV(hueval , 255,0);
    }

  }
  Serial.println(value);
  FastLED.show();// on actualise le ruban de led
  delay(100);
}
