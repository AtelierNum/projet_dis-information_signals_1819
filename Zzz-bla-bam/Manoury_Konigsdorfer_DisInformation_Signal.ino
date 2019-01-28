

#include <FastLED.h> //bibliothèque pour pouvoir activer des LEDs
#define NUM_LEDS 6 //le nombre LEDs utilisé

CRGBArray<NUM_LEDS> leds; //choisi le mode colorimétrique des LEDs

const int numReadings = 15; //pour pouvoir lisser les valeurs lues par le capteur, sur 15 valeurs le lissage se fait

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average






void setup() {
  // le code lu une fois, la mise en place des éléments de code
  Serial.begin(9600); //début du code, obligation de mettre cette ligne
  FastLED.addLeds<NEOPIXEL, 9> (leds, NUM_LEDS); //où on donne info aux LEDs, leur type

  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }

}

void loop() {
  // le code lu une fois, la mise en place des éléments de code

  int value = analogRead(0); //dit que variable nommée value se lit depuis le branchement analog O


  total = total - readings[readIndex]; //tout le code permettant de lire la valeur et la lisser et ainsi obtenir une moyenne average
  // read from the sensor:
  readings[readIndex] = value;
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;

  Serial.println(average); //inscrit la valeur moyenne dans le traceur série pour qu'on puisse voir sa valeur

  if (average < 80) { //condition que si average est inférieur à 80 alors les leds 0 et 1 s'allument un peu en vert

    leds[0] = CRGB (0, 250, 0);
    leds[1] = CRGB (0, 250, 0);
    leds[2] = CRGB (0, 0, 0);
    leds[3] = CRGB (0, 0, 0);
    leds[4] = CRGB (0, 0, 0);
    leds[5] = CRGB (0, 0, 0);

  } else if (average > 80 && average < 120) { //condition que si average est inférieur à 120 et supérieur à 80 alors les leds 2 et 3 s'allument un peu en vert
    leds[0] = CRGB (0, 0, 0);
    leds[1] = CRGB (0, 0, 0);
    leds[2] = CRGB (0, 250, 0);
    leds[3] = CRGB (0, 250, 0);
    leds[4] = CRGB (0, 0, 0);
    leds[5] = CRGB (0, 0, 0);

  } else if (average > 120 ) { //condition que si average est supérieur à 120 alors les leds 4 et 5 s'allument un peu en rouge
    leds[0] = CRGB (0, 0, 0);
    leds[1] = CRGB (0, 0, 0);
    leds[2] = CRGB (0, 0, 0);
    leds[3] = CRGB (00, 0, 0);
    leds[4] = CRGB (250, 0, 0);
    leds[5] = CRGB (250, 0, 0);
  }
  FastLED.show(); //permet au LEDs de s'allumer

}
