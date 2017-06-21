
#include"value.h"

int latchPin = 4;    //connected to pin 12 (ST_CP) of both shift register ic

int clockPin = 5;    //connected to pin 11 (SH_CP) of both shift register ic

int dataPin = 6;    //connected to pin 12 (DS) of first shift register ic

void setup()
{
  pinMode(latchPin, OUTPUT);  //seting direction of pins
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  
  //convertion relay status in array to bytes
  byte firstByte = 0;
  byte secondByte = 0;
  for(int i=0;i<8;i++)
  {
    firstByte = firstByte << i;
    firstByte = firstByte | (relay[i]&0x01);
  }
  
  for(int i=0;i<8;i++)
  {
    secondByte = secondByte << i;
    secondByte = secondByte | (relay[i+8]&0x01);
  }
  
  digitalWrite(latchPin, LOW);  //make the latch pin low. so that output will not change during shifting
  
  shiftOut(dataPin, clockPin, MSBFIRST, firstByte);   //shift out first byte(relay#1 to #8)
  shiftOut(dataPin, clockPin, MSBFIRST, secondByte);  //shift out second byte(relay#9 to #16)
  
  digitalWrite(latchPin, HIGH);  //make the latch pin high. so thate relay status will be writen on it
  
}

void loop()
{
  //do noting 
}

