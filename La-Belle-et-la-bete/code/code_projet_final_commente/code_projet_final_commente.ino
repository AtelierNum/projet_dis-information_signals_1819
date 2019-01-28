#include <Servo.h> // inclure la bibliothèque Servo
#include <FastLED.h> // inclure la bibliothèque FastLED
#define NUM_LEDS 3 // le nombre de leds sur la première bande de led sera 3
#define NUM_LEDS2 3 // le nombre de leds sur la deuxième bande de led sera 3 aussi

CRGBArray<NUM_LEDS> leds; // ce tableau de données représente la première led.
CRGBArray<NUM_LEDS2> leds2; // ce tableau de données représente la deuxième led.

Servo myservo; // on crée un objet 'myservo' pour pouvoir envoyer des informations au moteur

void setup() {
  pinMode(3, OUTPUT); // on utilise la pin 3 comme sortie
  myservo.attach(3);  // le servo est connecté à la pin 3
  Serial.begin(9600); // on ouvre la connexion série

  FastLED.addLeds<NEOPIXEL, 9>(leds, NUM_LEDS); // on initialise la première led sur la pin 9
  myservo.write(0); // le moteur doit se placer à 0 par default

  for (int i = 0; i < NUM_LEDS; i++) { // la première led doit être allumée par default
    leds[i] = CRGB(225, 255, 255); // on donne à la valeur 'i' du tableau 'leds' une valeur RGB qui se présentera comme un blanc
  }

  FastLED.addLeds<NEOPIXEL, 7>(leds2, NUM_LEDS2); // on initialise la deuxième led sur la pin 7
  for (int i = 0; i < NUM_LEDS2; i++) { // la deuxième led ne doit pas être allumée au départ
    leds2[i] = CRGB(0, 0, 0); // on donne à la valeur 'i' du tableau 'leds' une valeur RGB qui sera noir, donc la led ne sera pas allumée
  }
  FastLED.show(); // on actualise les rubans de leds
} // fin du setup

void loop() {

  int value = analogRead(3); // lire la valeur sur la pin A3 et la stocker dans une variable entière
  Serial.println(value); // on imprime le contenu de la variable dans le moniteur série


  if (value > 400) { // si la valeur du capteur est supérieur à 400, les actions suivantes vont être accomplis:

    for (int i = 0; i < NUM_LEDS; i++) { // on change la couleur de la première led
      leds[i] = CRGB(255, 0, 0); // on donne à la valeur 'i' du tableau 'leds' une nouvelle valeur RGB qui se présentera comme un rouge
    }

    for (int i = 0; i < NUM_LEDS2; i++) { // on change la couleur de la deuxième led
      leds2[i] = CRGB(225, 0, 0); // on donne à la valeur 'i' du tableau 'leds' une nouvelle valeur RGB qui se présentera comme un rouge
    }
    FastLED.show(); // on actualise le ruban de led
    myservo.write(0); // le moteur doit être placé à l'extrémité
    delay(1000); // on applique un delai de 1 seconde
    myservo.write(180); // on dit au moteur de se placé à l'autre extrémité
    delay(5000); // on applique un delai de 5 secondes
    myservo.write(0); // le moteur doit revenir au point de départ
    delay(2500); // on applique un delai de 2 secondes et demi

    for (int i = 0; i < NUM_LEDS; i++) { // on change la couleur de la première led
      leds[i] = CRGB(255, 255, 255); // on donne à la valeur 'i' du tableau 'leds' une nouvelle valeur RGB qui se présentera comme un blanc
    }
    for (int i = 0; i < NUM_LEDS2; i++) { // on change la couleur de la deuxième led
      // on donne à la valeur 'i' du tableau 'leds' une nouvelle valeur RGB qui se présentera comme un blanc
      leds2[i] = CRGB(0, 0, 0);
    }
    FastLED.show(); // on actualise le ruban de led
  }

} // fin du loop
