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

uint16_t address = 0;
uint16_t command = 0;

unsigned char x;

void setup() {
  Serial.begin(115200);
  IrSender.begin();
  pinMode(PIN_BUTTON_TURN_ON, INPUT_PULLUP);
  pinMode(PIN_BUTTON_SWING, INPUT_PULLUP);
  pinMode(PIN_BUTTON_STRONG, INPUT_PULLUP);
  pinMode(PIN_BUTTON_MEDIUM, INPUT_PULLUP);

  digitalWrite(32, LOW);

}

void loop() {
  if (Serial.available()){
    x = Serial.read();
    switch(x){
      case '1':
        IrSender.sendPronto(prontoDataTurnOn);
        Serial.println("fan ON");
        break;
      case '2':
        IrSender.sendPronto(prontoDataStrong);
        Serial.println("fan strong");
        break;
      case '3':
        IrSender.sendPronto(prontoDataMedium);
        break;
      case '4':
        IrSender.sendPronto(prontoDataSwing);
        break;
      case '5': //led on
        address = 0x80;
        command = 0x12;
        IrSender.sendNEC(address, command, 0);
        break;
      case '6': //led off
        address = 0x80;
        command = 0x1A;
        IrSender.sendNEC(address, command, 0);
        break;
      case '7': //led red
        address = 0x80;
        command = 0x4;
        IrSender.sendNEC(address, command, 0);
        break;
      case '8': //led green
        address = 0x80;
        command = 0x5;
        IrSender.sendNEC(address, command, 0);
        break;
      case '9': //led gradation
        address = 0x80;
        command = 0x1E;
        IrSender.sendNEC(address, command, 0);
        break;
      case 'a': //led white
        address = 0x80;
        command = 0x3;
        IrSender.sendNEC(address, command, 0);
        break;
      case 'b'://servo
        address = 0xDE80;
        command = 0x9;
        IrSender.sendNEC(address, command, 0);
        break;
      default:
        break;
    }
    
//    if(x == '1'){
//      IrSender.sendPronto(prontoDataTurnOn);
//    } else if(x == '2'){
//      IrSender.sendPronto(prontoDataStrong);
//    } else if(x == '3'){
//      IrSender.sendPronto(prontoDataMedium);
//    } else if(x == '4'){
//      IrSender.sendPronto(prontoDataSwing);
//    } else if(x == '5'){ //led on
//      address = 0x80;
//      command = 0x12;
//      IrSender.sendNEC(address, command, 0);
//    } else if(x == '6'){ //led off
//      address = 0x80;
//      command = 0x1A;
//      IrSender.sendNEC(address, command, 0);
//    } else if(x == '7'){ //led red
//      address = 0x80;
//      command = 0x4;
//      IrSender.sendNEC(address, command, 0);
//    } else if(x == '8'){ //led green
//      address = 0x80;
//      command = 0x5;
//      IrSender.sendNEC(address, command, 0);
//    }
  }
  //リモコン
  if (digitalRead(PIN_BUTTON_TURN_ON) == LOW) {
//    IrSender.sendPronto(prontoDataTurnOn);
//    Serial.println("send trun on at " + String(millis()));
//    digitalWrite(PIN_BUTTON_TURN_ON, HIGH);
    address = 0x80;
    command = 0x12;
    IrSender.sendNEC(address, command, 0);
  } else if (digitalRead(PIN_BUTTON_SWING) == LOW) {
//    IrSender.sendPronto(prontoDataSwing);
//    Serial.println("send trun off at " + String(millis()));
    address = 0x80;
    command = 0x1A;
    IrSender.sendNEC(address, command, 0);
  } else if (digitalRead(PIN_BUTTON_STRONG) == LOW) {
//    IrSender.sendPronto(prontoDataStrong);
//    Serial.println("send trun off at " + String(millis()));
    address = 0x80;
    command = 0x3;
    IrSender.sendNEC(address, command, 0);
  } else if (digitalRead(PIN_BUTTON_MEDIUM) == LOW) {
//    IrSender.sendPronto(prontoDataMedium);
//    Serial.println("send trun off at " + String(millis()));
    address = 0x80;
    command = 0x1E;
    IrSender.sendNEC(address, command, 0);
    
  }
  delay(200);

  

}
