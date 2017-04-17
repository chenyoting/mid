
#include "SevSeg.h"
SevSeg sevseg;

void setup() 
{
  Serial.begin(9600);
  Serial.println("22");
 Serial.println("04050432 04050785");
 byte numDigits = 4;
 byte digitPins[] = {A0,A1, A2, A3};
 byte segmentPins[] = { 2, 3, 4, 5, 6, 7, 8, 9};
 sevseg.begin(COMMON_CATHODE, numDigits, digitPins,segmentPins);


}

void loop()
{
  int val;
    if(Serial.available())
    {
      val = Serial.parseInt();
      Serial.println(val);    
      if(val>=0 && val<10000)
      {
        sevseg.setNumber(val);
          sevseg.refreshDisplay();
        }
      else
        Serial.println("range error");  
      
      
    }
    else
            sevseg.refreshDisplay();

    
}
