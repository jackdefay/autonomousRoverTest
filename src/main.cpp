#include <Arduino.h>

#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;

void setup() {
    pinMode(A0, OUTPUT);

    dac.begin(0x62);   
}

void loop() {
    //ramps up speed
    for(int i = 175; i>60; i--){
      analogWrite(A0, i);
      dac.setVoltage(i*20, false);
      delay(20);
    }

    // analogWrite(A0, 100);  //top speed
    // analogWrite(10, 160);  //a half turn to the left to form a circle

    analogWrite(A0, 175);
    dac.setVoltage(2047, false);
    delay(1000);
}
