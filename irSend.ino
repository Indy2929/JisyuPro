#include <Arduino.h>

#define PIN_SEND 4
#define PIN_BUTTON_TURN_ON 0
#define PIN_BUTTON_SWING 18
#define PIN_BUTTON_STRONG 17
#define PIN_BUTTON_MEDIUM 22

#define IR_SEND_PIN PIN_SEND
#include <IRremote.hpp>

char prontoDataTurnOn[] ="0000 006D 0022 0000 0159 00A8 0018 0014 0018 0014 0018 0012 001A 0012 0018 0014 0018 0014 0018 0012 0018 003F 0018 0014 0016 0041 0018 003F 0016 0041 0018 003F 0016 0016 0016 0041 0016 0041 0016 0016 0016 0014 0018 0014 0016 0016 0016 0016 0016 0014 0016 0016 0016 0016 0016 0041 0016 0041 0016 0041 0016 0041 0016 0041 0016 0041 0016 0041 0016 0041 0016 06C3 ";
char prontoDataStrong[] ="0000 006D 0022 0000 015B 00A8 001A 0012 0018 0014 0018 0012 001A 0012 0018 0014 0018 0014 0018 0012 001A 003D 001A 0012 0018 003F 0018 003F 001A 003D 001A 003D 001A 0012 0018 003F 001A 003D 001A 0012 0018 0014 0018 0014 0018 003F 0018 0012 001A 0012 0018 0014 0018 0014 0018 003F 0018 003F 0018 003F 0018 0014 0018 003F 0018 003F 0018 003F 0018 003F 0018 06C3 ";
char prontoDataMedium[] ="0000 006D 0022 0000 0159 00AA 0018 0012 001A 0012 0018 0014 0018 0012 001A 0012 0018 0014 0018 0012 001A 003D 001A 0012 0018 003F 0018 003F 001A 003D 001A 003D 001A 0012 0018 003F 001A 003D 001A 0012 0018 0014 0018 003F 0018 003F 0018 0014 0018 0012 001A 0012 0018 0014 0018 003F 0018 003F 0018 0014 0018 0012 0018 003F 001A 003D 001A 003D 001A 003F 0018 06C3 ";
char prontoDataSwing[] = "0000 006D 0022 0000 015B 00A8 001A 0012 0018 0012 001A 0012 001A 0012 0018 0014 0018 0012 001A 0012 0018 003F 001A 0012 0018 003F 0018 003F 0018 003F 0018 003F 001A 0012 0018 003F 0018 003F 0018 003F 001A 0012 0018 003F 0018 0014 0018 003F 0018 0012 001A 0012 001A 0012 0018 0014 0018 003F 0018 0012 001A 003D 001A 0012 001A 003D 001A 003D 001A 003D 001A 06C3 ";


void setup() {
  Serial.begin(115200);
  IrSender.begin();
  pinMode(PIN_BUTTON_TURN_ON, INPUT_PULLUP);
  pinMode(PIN_BUTTON_SWING, INPUT_PULLUP);
  pinMode(PIN_BUTTON_STRONG, INPUT_PULLUP);
  pinMode(PIN_BUTTON_MEDIUM, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(PIN_BUTTON_TURN_ON) == LOW) {
    IrSender.sendPronto(prontoDataTurnOn);
    Serial.println("send trun on at " + String(millis()));
  } else if (digitalRead(PIN_BUTTON_SWING) == LOW) {
    IrSender.sendPronto(prontoDataSwing);
    Serial.println("send trun off at " + String(millis()));
  } else if (digitalRead(PIN_BUTTON_STRONG) == LOW) {
    IrSender.sendPronto(prontoDataStrong);
    Serial.println("send trun off at " + String(millis()));
  } else if (digitalRead(PIN_BUTTON_MEDIUM) == LOW) {
    IrSender.sendPronto(prontoDataMedium);
    Serial.println("send trun off at " + String(millis()));
  }
  delay(200);
}
