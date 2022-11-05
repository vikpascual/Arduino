/*
DO NOTE_C5
RE NOTE_D5
MI NOTE_E5
FA NOTE_F5
SOL NOTE_G5
LA NOTE_A5
SI NOTE_B5
DO NOTE_C6
*/
#include "pitches.h"
int melody[] = {NOTE_G5, NOTE_G5, NOTE_D5, NOTE_D5, NOTE_B5, NOTE_B5, NOTE_G5, NOTE_D6, NOTE_C6, NOTE_B5, NOTE_A5,
NOTE_G5, NOTE_G5, 739.99, NOTE_E5, NOTE_D5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_B5, NOTE_B5, NOTE_D6,
NOTE_C6, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_D6, NOTE_D6 ,NOTE_D6, NOTE_B5, NOTE_D6, NOTE_C6, NOTE_C6,
NOTE_A5, NOTE_C6, NOTE_B5, NOTE_B5, NOTE_G5, NOTE_B5, NOTE_A5, NOTE_D5, NOTE_E5, 739.99, NOTE_G5, NOTE_G5,
NOTE_A5, NOTE_A5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_A5,
NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_D6, NOTE_D6, NOTE_B5, NOTE_D6, NOTE_C6, NOTE_C6, NOTE_A5,
NOTE_C6, NOTE_B5, NOTE_B5, NOTE_G5, NOTE_B5, NOTE_A5, NOTE_D5, NOTE_E5, 739.99, NOTE_G5, NOTE_G5, NOTE_A5,
NOTE_A5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_C6, NOTE_C6, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_A5, NOTE_G5,
NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5
};
int duration_negra = 1000;
int duration_blanca = 2000;
int duration_corchea = 500;
void setup() {
  // put your setup code here, to run once:
  for (int thisNote = 0; thisNote < sizeof(melody); thisNote++) {
    // pin8 output the voice, every scale is 0.5 sencond
      tone(8, melody[thisNote], duration_negra);
      delay(500);
  } 
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
