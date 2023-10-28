#include "BopIt.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// analog pins
int coin_scanner_pin = A0;
int lever_pin = A1;
int joystick_x_pin = A2;
int joystick_y_pin = A3;
int roulette_pin = A4;

int main() {
  init();
  delay(500); // delay for seed
  // setting up pins
  pinMode(coin_scanner_pin, INPUT);
  pinMode(lever_pin, INPUT);
  pinMode(joystick_x_pin, INPUT);
  pinMode(joystick_y_pin, INPUT);
  pinMode(roulette_pin, INPUT);
  
  Wire.begin(); // starts I2C transmission
  Wire.beginTransmission(0x27); // starts sending to address of LCD
  BopIt game;
  game.set_state(awaiting_coin);

  while (game.get_curr_state() == awaiting_coin) {
    if (analogRead(coin_scanner_pin) < 500) {
      game.set_state(start);
    }
  }

  while (game.get_curr_state() == start) {
    BopItState choice = game.action();
    switch(choice) {
       case slots:
          game.slots_game();
       case pachinko:
          game.pachinko_game();
       case roulette:
          game.roulette_game();
    }
  }

  //Wire.endTransmission();
}