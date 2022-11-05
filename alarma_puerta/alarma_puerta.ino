#define LED 8//the led attach to
#define BOLA 2
#define ALARMA 5
void setup()
{ 
  pinMode(LED,OUTPUT);
  pinMode(ALARMA,OUTPUT);
  pinMode(BOLA,INPUT);
  digitalWrite(BOLA, HIGH);
} 

void loop() 
{ 
  int digitalVal = digitalRead(BOLA); 
  if(LOW == digitalVal)
  {
    digitalWrite(LED,LOW);
  }
  else
  {
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
}
