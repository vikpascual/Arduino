#include "IRremote.h"
#include "IR.h"
#include <LiquidCrystal.h>
IRrecv irrecv(RECEIVER);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("LECTOR INFRAROJOS");
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn();
}

void loop()
{
  int tmpValue;
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    for (int i = 0; i < 23; i++)
    {
      if ((keyValue[i] == results.value) && (i<KEY_NUM))
      {
        lcd.clear();
        lcd.print("LECTOR INFRAROJOS");
        lcd.setCursor(0, 1);
        lcd.print(keyBuf[i]);
        tmpValue = results.value;
      }
      else if(REPEAT==i)
      {
        Serial.println( "0x"+String(results.value, HEX));
        results.value = tmpValue;
      }
    }
    irrecv.resume(); // receive the next value
  }
   //lcd.print(millis() / 1000);

//The implementation effect of the above program is 
//the same as that of the following, but it is more concise
/*
   switch(results.value)
  {
  case 0xFFA25D: Serial.println("POWER"); break;
  case 0xFFE21D: Serial.println("FUNC/STOP"); break;
  case 0xFF629D: Serial.println("VOL+"); break;
  case 0xFF22DD: Serial.println("FAST BACK");    break;
  case 0xFF02FD: Serial.println("PAUSE");    break;
  case 0xFFC23D: Serial.println("FAST FORWARD");   break;
  case 0xFFE01F: Serial.println("DOWN");    break;
  case 0xFFA857: Serial.println("VOL-");    break;
  case 0xFF906F: Serial.println("UP");    break;
  case 0xFF9867: Serial.println("EQ");    break;
  case 0xFFB04F: Serial.println("ST/REPT");    break;
  case 0xFF6897: Serial.println("0");    break;
  case 0xFF30CF: Serial.println("1");    break;
  case 0xFF18E7: Serial.println("2");    break;
  case 0xFF7A85: Serial.println("3");    break;
  case 0xFF10EF: Serial.println("4");    break;
  case 0xFF38C7: Serial.println("5");    break;
  case 0xFF5AA5: Serial.println("6");    break;
  case 0xFF42BD: Serial.println("7");    break;
  case 0xFF4AB5: Serial.println("8");    break;
  case 0xFF52AD: Serial.println("9");    break;
  case 0xFFFFFFFF: Serial.println(" REPEAT");break;  
  default: 
    int i = 0;
  }
  */
}
