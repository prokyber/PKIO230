#include "PKIO230.h"

PKIO230 pkio230(0x20);

void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("PCF8574_LIB_VERSION:\t");
  Serial.println(PCF8574_LIB_VERSION);

  Wire.begin();

  pkio230.begin();
  Serial.println(pkio230.isConnected());

}


void loop()
{
  //  night rider
  for (int i = 0; i < 4; i++)
  {
    pkio230.relaySet(i,HIGH);
    delay(100);
  }
  for (int i = 4; i >= 0; i--)
  {
    pkio230.relaySet(i,LOW);
    delay(100);
  }
  for (int i = 0; i < 4; i++)
  {
    Serial.println(pkio230.inputRead(i));
    delay(100);
  }

}
