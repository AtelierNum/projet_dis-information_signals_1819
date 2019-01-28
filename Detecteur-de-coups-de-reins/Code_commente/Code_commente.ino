
//moteur
#include <Servo.h>
Servo myservo; //creation d'un objet qu'on appelera myservo, que l'on pourra manipuler pour envoyer des informations au servo moteur



//led
#include <FastLED.h>
#define NUM_LEDS 16 // définir le nombre de leds

CRGBArray<NUM_LEDS> leds; // définir un tableau de données chaque entrée du tableau représentera une led.
float  inc = 0; // un variable que l'on va utiliser pour créer une animation.

//micro seuil
int seuil_micro = 600; // variable défini le seuil du micro


//orgasme
boolean orgasme = false; // creation d'une variable qui créer deux états: vrai ou faux.



void setup() {
 Serial.begin(9600); // ouvrir la connexion série

  //moteur
  pinMode(5, OUTPUT); // préciser que l'on veut utiliser la pin 5 comme une sortie
  myservo.attach(5);  // préciser à notre bibliothèque qu'un servo est connecté à la pin 5
  myservo.write(90);  //le moteru ne tourne pas


  //led
  FastLED.addLeds<NEOPIXEL, 9>(leds, NUM_LEDS); //le strip de led est connectée sur la pin 9

  //capteur IR
  pinMode(13, INPUT); //le capteur infrarouge est branché sur la pin 13, c'est une entrée

}

void loop() {

  //micro
  int micro = analogRead(3); // lire la valeur sur la pin A3 et la stocker dans une variable entière
  Serial.println(micro); // imprimmer le contenu de la variable dans le moniteur série


  //ir
  int ir3 = digitalRead(13); // lire la valeur sur la pin 13 et la stocker dans une variable entière




 if ( ir3 == 1)  {    // pas de sous-vêtements devant le capteur

    orgasme = false;

    myservo.write(90);                  // le moteur ne tourne pas

    inc +=  0.05;                       // on augmente la valeur de inc
                                      // on calcule en fonction de inc un valeur qui va osciller entre 0 et 244.


                                            // à chaque fois on augmente la valeur de i de 1
    for (int i = 0; i < NUM_LEDS; i++) {
                                          // on change la valeur de la led 'i' du tableau nommé 'leds" en lui donnant une nouvelle valeur RGB
    leds[i] = CRGB(0, 0, 0);              //éteind
    }


  }

  else if (ir3 == 0 )  { // sous vetement devant le capteur

    if (micro < seuil_micro) { // valeur micro inférieur à la limite definie précédement



      myservo.write(90); // le moteur ne tourne pas

      inc +=  0.05; // on augmente la valeur de inc

      // Pour i allant de 0 à 5, on va éxecuter le code entre accolades,
      // à chaque fois on augmente la valeur de i de 1
      for (int i = 0; i < NUM_LEDS; i++) {
        // on change la valeur de la led 'i' du tableau nommé 'leds" en lui donnant une nouvelle valeur RGB
        leds[i] = CRGB(255, 255, 255); //blanc

      }

    }



    if (micro > seuil_micro) {               // valeur micro supérieur à la limite definie précédement



      orgasme == true;

      myservo.write(100); // faire tourner le servo le sens des aiguilles

      int lightIntensity =  map(micro, 250, 1023, 100, 255); // (intensité du micro, valeur sonore minimum, valeur sonore max, intensité lum minimum, intensité lum maximum)

      for (int i = 0 ; i < NUM_LEDS ; i += 1) {  //tableau de valeurs pour le calcul de chaque leds
        leds[i] = CRGB(255,0,lightIntensity); // (rouge saturation (255 max),vert saturation (0 min), intensité lumineuse en fonction du son)
      }
    }



  FastLED.show(); // on actualise le ruban de led
  delay(5);
}
}
