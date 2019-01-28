

////////////////// JOYEUX NOËL

//////OUVRIR SAPIN

// bibliothèque servomoteurs
#include <Servo.h>
Servo myservo; // faire un objet pour utiliser un servomoteur

//////ALLUMER LEDS

// bibliothèque leds
#include <FastLED.h>
#define NUM_LEDS 5 // nombre de leds

CRGBArray<NUM_LEDS> leds; //créer un tableau pour adresser chaque led individuellement




void setup() {

//////OUVRIR SAPIN

  Serial.begin(9600); // ouvrir une connexion série

  pinMode(6, OUTPUT);// préciser que l'on va utiliser la pin 6 comme une sortie.
  myservo.attach(6);// attacher notre servomoteur à cette pin 6

//////ALLUMER LEDS

   FastLED.addLeds<NEOPIXEL, 4>(leds, NUM_LEDS); // initialiser le ruban sur la pin 4

} //fin setup

void loop() {

//////OUVRIR SAPIN

  int potValue = analogRead(0); // valeur sur l'entrée analogique 0
  Serial.println(potValue); // valeur potentiomètre dans le moniteur série

  // Pour ouvrir le sapin, on a besoin d'indiquer à notre servomoteur une position pour son bras movible, donc il faut lui donner une valeur qui dépend du potentiomètre
  int servoPos = map(potValue, 0, 1023, 0, 180); // on map la valeur de notre potentiomètre qui est comprise entre 0 et 1023, vers un intervalle compris entre 0 et 180?.
  myservo.write(servoPos); // écrire la position calculée sur le servomoteur

//////ALLUMER LEDS

   int fsrValue = analogRead(1); // valeur sur l'entrée analogique 1
 int hueValue = map(fsrValue, 1, 1023, 0, 200); // transformer notre valeur provenant du capteur en une valeur comprise entre 0 et 200.

 // on parcourt toutes les leds de notre rubant à l'aide d'une boucle fort
 for (int i = 0; i < NUM_LEDS; i++) {
   leds[i] = CHSV(hueValue, 255, 255); // on applique la teinte en utilisant le mode HSV
 }
 FastLED.show();// on actualise le ruban de led

} //fin loop

///////// N'OUBLIEZ PAS DE REFERMER LA TRAPE, ON NE VOUDRAIT PAS QUE TOUT LE MONDE VOIT SE QUI SE CACHE LA DEDANS
