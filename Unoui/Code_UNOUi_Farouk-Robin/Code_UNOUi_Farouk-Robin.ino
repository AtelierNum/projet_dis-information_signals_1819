const int numReadings = 50;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = 0;

#include <FastLED.h>
#define NUM_LEDS 6 // définir le nombre de leds

CRGBArray<NUM_LEDS> leds; // définir un tableau de données chaque entrée du tableau représentera une led.
float  inc = 0; // un variable que l'on va utiliser pour créer une animation.

void setup() {
  FastLED.addLeds<NEOPIXEL, 9>(leds, NUM_LEDS); //Ici on défini le nombre de led
  Serial.begin(9600); // ouvrir la connexion série
  pinMode(8, OUTPUT);
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {


  int value = analogRead(0); // lire la valeur sur la pin A0 et la stocker dans une variable entière
  int  v = abs(constrain(value, 0, 1024));

  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = v;
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average: Cela nous permet d'effectur une "moyenne" des valeurs
  average = total / numReadings;
  average = constrain(average, 0, 1024);
  // send it to the computer as ASCII digits
  Serial.println(average);
  delay(1);        // delay in between reads for stability


  //analogRead(0)=constrain(value,100,1000);

  if (average > 150) {// Valeur a partir de laquelle l'enceinte et les lampes s'active
    tone(8, average * 10);
    int n=map(average,150,160,2,6);
    inc +=  0.05; // on augmente la valeur de inc
    // on calcule en fonction de inc un valeur qui va osciller entre 0 et 244.
    int green = (sin(inc) + 1) * 122; // cette valeur est stocké dans une variable nommée "green"

    // Pour i allant de 0 à 5, on va éxecuter le code entre accolades,
    // à chaque fois on augmente la valeur de i de 1
    for (int i = 0; i < n; i++) {
      // on change la valeur de la led 'i' du tableau nommé 'leds" en lui donnant une nouvelle valeur RGB
      leds[i] = CRGB(255 - green, green, 0);

    }
  } else { //Boucle permettant de couper le son et la lumièré
    noTone(8);
     for (int i = 0; i < NUM_LEDS; i++) {
      // on change la valeur de la led 'i' du tableau nommé 'leds" en lui donnant une nouvelle valeur RGB
      leds[i] = CRGB(0,0,0);

    }
  }


  FastLED.show(); // on actualise le ruban de led
}
