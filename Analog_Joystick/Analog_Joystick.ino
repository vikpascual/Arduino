const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
const int x_rojo = 530;
const int y_rojo = 0;
const int x_azul = 0;
const int y_azul = 1024;
const int x_verde = 1024;
const int y_verde = 1024;
#define BLUE 3
#define GREEN 5
#define RED 6
void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}
int redValue;
int greenValue;
int blueValue;
int x;
int y;
void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  x = analogRead(X_pin);
  Serial.print(x);
  Serial.print("\n");
  Serial.print("Y-axis: ");
  y = analogRead(Y_pin);
  Serial.println(y);
  Serial.print("\n\n");
  redValue = 255 - sqrt(pow(max(x_rojo,x)-min(x_rojo,x),2)+pow(max(y_rojo,y)-min(y_rojo,y),2))/4;
  Serial.print("ROJO: ");
  Serial.println(redValue);
  greenValue = 255 - sqrt(pow(max(x_verde,x)-min(x_verde,x),2)+pow(max(y_verde,y)-min(y_verde,y),2))/4;
  Serial.print("VERDE: ");
  Serial.println(greenValue);
  blueValue = 255 - sqrt(pow(max(x_azul,x)-min(x_azul,x),2)+pow(max(y_azul,y)-min(y_azul,y),2))/4;
  Serial.print("AZUL: ");
  Serial.println(blueValue);
  if(blueValue < 0){
    blueValue = 0;  
  }
  if(redValue < 0){
    redValue = 0;  
  }
  if(greenValue < 0){
    greenValue = 0;  
  }
  analogWrite(BLUE, blueValue);
  analogWrite(GREEN, greenValue);
  analogWrite(RED, redValue);
  delay(100);

  /*
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  delay(1000);
  */
}
