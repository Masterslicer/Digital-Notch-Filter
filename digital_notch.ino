#include "MCP4261.h"

MCP4261 digitalPot(10, 9850.0, 90.0, 9850.0, 90.0);
MCP4261 digitalPot_100k(9, 100000.0, 90.0, 100000.0, 90.0);

#define buttonPin_1 2
bool potNum1 = 1;
bool potNum0 = 0;

uint16_t pos_notch, data, pos1,pos2,pos_Q_Factor, pos3, pos4;
float calcRes, calcPos;


void setup()
{
    Serial.begin(9600);
    
    digitalPot.begin();
    digitalPot_100k.begin();
    digitalPot.DigitalPotReadTconRegister();
    digitalPot_100k.DigitalPotReadTconRegister();
    //digitalPot.DigitalPotTerminalAConnect(potNum1);
    //digitalPot_100k.DigitalPotTerminalBDisconnect(potNum1);
    //digitalPot_100k.DigitalPotTerminalBDisconnect(potNum0);
    pinMode(buttonPin_1, INPUT_PULLUP);
   
}

void loop()
{
//CHange these Variables to set the resistance of Potentiometers
pos_notch = 256 - 180;    // Please don't change '256', change the digit after '-' sign. It represent the distance from Potentiometer
pos_Q_Factor = 256 - 250;  // terminal. Higher the number after '-' sign, larger the resistance

pos1 = digitalPot_100k.DigitalPotReadWiperPosition( potNum0);
pos3 = digitalPot.DigitalPotReadWiperPosition( potNum0);
delay(10);
digitalPot.DigitalPotSetWiperPosition(potNum0, pos_notch);
delay(1000);
digitalPot.DigitalPotSetWiperPosition(potNum1, pos_notch);
delay(1000);
digitalPot_100k.DigitalPotSetWiperPosition(potNum0, pos_Q_Factor);
delay(1000);
digitalPot_100k.DigitalPotSetWiperPosition(potNum1, pos_Q_Factor);
delay(1000);
pos2 = digitalPot_100k.DigitalPotReadWiperPosition( potNum0);
pos4 = digitalPot.DigitalPotReadWiperPosition( potNum0);

Serial.print("Position = ");
Serial.println(pos1);
Serial.print("updated Position = ");
Serial.println(pos2);
Serial.print("5K pre Position = ");
Serial.println(pos3);
Serial.print("Updated position for 5k = ");
Serial.println(pos4);



while(1)
{}

}
