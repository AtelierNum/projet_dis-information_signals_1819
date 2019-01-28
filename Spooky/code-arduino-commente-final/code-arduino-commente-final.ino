// inclure la bibliothèque servo
#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN            9 // permet de préciser au program que nous utilisons la pin 9 comme une entrée
#define NUMPIXELS      24 // indique le nombre de led que la carte arduino doit traiter

// créer un objet que l'on appelera myservo que l'on pourra manipuler pour envoyer des informations à notre servo moteur
Servo myservo;

//CRGBArray<NUM_LEDS> leds; // définir un tableau de données chaque entrée du tableau représentera une led.
float  inc = 0;
// ajouter variable my servo)
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() { // code qui ne sera exécuté qu'une seul fois au début de votre programme

  Serial.begin(9600); // ouvrir la connexion série
  pinMode(9, OUTPUT); // préciser que l'on veut utiliser la pin 9 comme une sortie
  pinMode(5, OUTPUT); // préciser que l'on veut utiliser la pin 5 comme une sortie
  myservo.attach(5);  // préciser à notre bibliothèque qu'un servo est connecté à la pin 5
  // on initialise notre strip de led sur la pin 9
  // FastLED.addLeds<NEOPIXEL, 9>(leds, NUM_LEDS);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() { // code qui sera exécuté en boucle une fois le programme démarré

  int value = analogRead(0); // lire la valeur sur la pin A0 et la stocker dans une variable entière
  int value1 = analogRead(0);
  delay(5); // attente avant de recommencer l'opération (ici elle est nulle)
  int newvalmoteur = constrain(map(value1, 500, 800, 90, 180), 90, 180); // notre valeur est comprise entre 0 et 1023, on veut une valeur entre 90 et 180
  delay(5); // attente avant de recommencer l'opération (ici elle est nulle)
  int newvalled = constrain(map(value, 320, 750, 0, 255), 0, 255); // notre valeur est comprise entre 0 et 1023, on veut une valeur entre 0 et 255

  Serial.println(value); // imprimmer le contenu de la variable dans le moniteur série
  myservo.write(newvalmoteur); // faire tourner le servo le plus vite possible dans le sens inverse des aiguilles d'une montre


  delay(50); // attente avant de recommencer l'opération (ici elle est nulle)

  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(newvalled, 0, 0)); // génère la couleur rouge en réagissant à la luminosité grace à la photorésistence

  }
  pixels.show(); // This sends the updated pixel color to the hardware.

  delay(10); // attente avant de recommencer l'opération (ici elle est nulle)


}
