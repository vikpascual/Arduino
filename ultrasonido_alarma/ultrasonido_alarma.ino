#include "SR04.h"

#define TRIG_PIN 12
#define ECHO_PIN 11 
#define LED 7
#define ALARMA 4

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
long distancia_previa = 0;
void setup() {
   Serial.begin(9600);//Initialization of Serial Port
   delay(1000);
   pinMode(LED, OUTPUT);
   pinMode(ALARMA, OUTPUT);
}

void loop() {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   if(a - distancia_previa > 30 || a - distancia_previa < -30){
    for(int i=0;i<50;i++)
      {
        digitalWrite(LED,HIGH);
        digitalWrite(ALARMA,HIGH);
        delay(50);
        digitalWrite(ALARMA,LOW);
        digitalWrite(LED,LOW);
        delay(50);
      }
    
   }
    distancia_previa = a; 
   
   delay(500);
}
