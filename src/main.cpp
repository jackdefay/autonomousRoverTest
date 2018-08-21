#include <Arduino.h>

//libraries for external DAC
#include <Wire.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;  //initialize DAC

void setup() {
    //set pins
    pinMode(A0, OUTPUT);
    dac.begin(0x62);
}

void loop() {
    //cycles through range of motion and speed
    for(int i = 175; i>60; i--){
      analogWrite(A0, i);
      dac.setVoltage(i*20, false);
      delay(20);
    }

    //centers and stops the wheels
    analogWrite(A0, 175);
    dac.setVoltage(2047, false);
    delay(1000);
}
