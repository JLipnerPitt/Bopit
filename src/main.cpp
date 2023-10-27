#include "BopIt.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "SPI.h"

int main() {
  init();
  delay(500);
  Wire.begin(); // starts I2C transmission
  Wire.beginTransmission(0x27); // starts sending to address of LCD
  BopIt game;
  //Wire.endTransmission();
}