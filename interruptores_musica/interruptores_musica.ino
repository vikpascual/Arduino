#include <pitches.h>

/*
DO NOTE_C5
RE NOTE_D5
MI NOTE_E5
FA NOTE_F5
SOL NOTE_G5
LA NOTE_A5
SI NOTE_B5
DO NOTE_C6
739.99 FA SOSTENIDO
*/
#include "pitches.h"
#define MUSICA1 5
#define MUSICA2 6
#define LED1 3
#define LED2 4
int melody1[] = {NOTE_G5, NOTE_G5, NOTE_D5, NOTE_D5, NOTE_B5, NOTE_B5, NOTE_G5, NOTE_D6, NOTE_C6, NOTE_B5, NOTE_A5,
NOTE_G5, NOTE_G5, 739.99, NOTE_E5, NOTE_D5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_B5, NOTE_B5, NOTE_D6,
NOTE_C6, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_D6, NOTE_D6 ,NOTE_D6, NOTE_B5, NOTE_D6, NOTE_C6, NOTE_C6,
NOTE_A5, NOTE_C6, NOTE_B5, NOTE_B5, NOTE_G5, NOTE_B5, NOTE_A5, NOTE_D5, NOTE_E5, 739.99, NOTE_G5, NOTE_G5,
NOTE_A5, NOTE_A5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_A5,
NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_D6, NOTE_D6, NOTE_B5, NOTE_D6, NOTE_C6, NOTE_C6, NOTE_A5,
NOTE_C6, NOTE_B5, NOTE_B5, NOTE_G5, NOTE_B5, NOTE_A5, NOTE_D5, NOTE_E5, 739.99, NOTE_G5, NOTE_G5, NOTE_A5,
NOTE_A5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_C6, NOTE_C6, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_A5, NOTE_G5,
NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5
};
int melody2[] = {NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_E5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_E5, 
NOTE_E5, NOTE_D6, NOTE_D6, NOTE_D6, 0,NOTE_D6, NOTE_B5, NOTE_B5, NOTE_B5,40, NOTE_C6, NOTE_C6, NOTE_C6, 0, NOTE_C6,
NOTE_G5, NOTE_G5, NOTE_G5, 0, NOTE_A5, NOTE_A5, NOTE_A5, 0, NOTE_A5, NOTE_C6, NOTE_C6, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_A5, 
NOTE_G5, NOTE_E5
};
int duration = 500; //SE PUEDE USAR UNA DURACION PARA LAS NEGRAS DE 1000 Y PARA LAS BLANCAS 2000 PERO MI ZUMBADOR SOLO ADMITE DURACIONES DE 500
void setup() {
  // put your setup code here, to run once:
  pinMode(MUSICA1,INPUT_PULLUP);
  pinMode(MUSICA2,INPUT_PULLUP);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(MUSICA1) == LOW){
    digitalWrite(LED1,HIGH);
    for (int thisNote = 0; thisNote < sizeof(melody1); thisNote++) {
    // pin8 output the voice, every scale is 0.5 sencond
      tone(4, melody1[thisNote], duration);
      delay(500);
    } 
    digitalWrite(LED1,LOW);
  }
  if(digitalRead(MUSICA2) == LOW){
    digitalWrite(LED2,HIGH);
    for (int thisNote = 0; thisNote < sizeof(melody2); thisNote++) {
    // pin8 output the voice, every scale is 0.5 sencond
      tone(4, melody2[thisNote], duration);
      delay(400);
    } 
    digitalWrite(LED2,LOW);
  }
}
