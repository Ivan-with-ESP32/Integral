//-----------------КНОПКА---------------------
#define BTN_1 5
#define BTN_2 6
#include "GyverButton.h"
GButton butt1(BTN_1);
GButton butt2(BTN_2);
//-----------------OLED-----------------------
#include <GyverOLED.h>
GyverOLED<SSD1306_128x32, OLED_NO_BUFFER> oled;

//---------------ENCODER----------------------
#include "GyverEncoder.h"
Encoder enc1;

#define SW        2
#define DT        3
#define CLK       4

//-----------------ЗМІННІ---------------------
int a;
int b;
int k = 1;;
int n;
int d;
float F_1;
float F_2;
float F_x;
byte num;
byte form;
boolean flag = 0;
boolean flag_1 = 0;
const uint8_t bitmap_128x32_one[] PROGMEM = {
  0x00,0x00,0x80,0xE0,0xF0,0xF0,0x38,0x18,0x18,0x0C,0x0C,0x0C,0x1C,0x1C,0x78,0xF8,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0x90,0x10,0xB0,0xE0,0x00,0x00,0x80,0xC0,0xE0,0x70,0x30,0x30,0x30,0x70,0xE0,0xC0,0x00,0x02,0x02,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x01,0x01,0x01,0x3E,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFE,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x07,0x1F,0x3F,0x7F,0x7C,0xF0,0xF0,0xE0,0xE0,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x80,0xC0,0xE0,0x30,0x1A,0x1E,0x0E,0x06,0x02,0x02,0x02,0x00,0x00,0x00,0x0E,0x06,0x0E,0x1E,0x3E,0x7E,0xF6,0xE0,0x80,0xC0,0xE0,0x36,0x1E,0x0E,0x06,0x06,0x0E,0x00,0x00,0x00,0xF0,0xF8,0xF8,0x1C,0x0E,0x0E,0x06,0x06,0x06,0x06,0x06,0x06,0x0C,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x0E,0x06,0x0E,0x1E,0x3E,0x7E,0xF6,0xE0,0x80,0xC0,0xE0,0x36,0x1E,0x0E,0x06,0x06,0x0E,0x00,
  0x00,0x00,0x80,0xC0,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x03,0x07,0x0F,0xFF,0xFE,0xFC,0x00,0x00,0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x03,0x07,0x0F,0x3E,0x7C,0xF8,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x80,0x00,0x80,0xC0,0xE0,0x70,0x38,0x0C,0x0F,0x0F,0x1F,0x7C,0xF8,0xF0,0xE0,0x80,0x00,0x00,0x80,0x00,0x00,0x1F,0x7F,0xFF,0xF0,0xC0,0x80,0x80,0x80,0x80,0x80,0xC0,0xE0,0x70,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x80,0x00,0x80,0xC0,0xE0,0x70,0x38,0x0C,0x0F,0x0F,0x1F,0x7C,0xF8,0xF0,0xE0,0x80,0x00,0x00,0x80,
  0x00,0x00,0x0F,0x0F,0x0F,0x0E,0x1C,0x18,0x18,0x18,0x18,0x1C,0x0C,0x0E,0x0F,0x07,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x06,0x06,0x06,0x07,0x03,0x01,0x00,0x71,0x99,0x88,0x88,0x49,0xFF,0x00,0x00,0x02,0x02,0x03,0x03,0x03,0x03,0x02,0x02,0x00,0x00,0x02,0x03,0x03,0x03,0x03,0x03,0x02,0x02,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x03,0x03,0x03,0x01,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
};
const uint8_t bitmap_128x32_two[] PROGMEM = {
  0x00,0x00,0x80,0xE0,0xF0,0xF0,0x38,0x18,0x18,0x0C,0x0C,0x0C,0x1C,0x1C,0x78,0xF8,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0x90,0x10,0xB0,0xE0,0x00,0x00,0x80,0xC0,0xE0,0x70,0x30,0x30,0x30,0x70,0xE0,0xC0,0x00,0x02,0x02,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x02,0x02,0x02,0x7C,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xF0,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x07,0x1F,0x3F,0x7F,0x7C,0xF0,0xF0,0xE0,0xE0,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x80,0xC0,0xE0,0x30,0x1A,0x1E,0x0E,0x06,0x02,0x02,0x02,0x00,0x00,0x00,0x0E,0x06,0x0E,0x1E,0x3E,0x7E,0xF6,0xE0,0x80,0xC0,0xE0,0x36,0x1E,0x0E,0x06,0x06,0x0E,0x00,0x00,0x00,0x00,0xF0,0xF0,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0x70,0x30,0x30,0x30,0x30,0x60,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x80,0xC0,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x03,0x07,0x0F,0xFF,0xFE,0xFC,0x00,0x00,0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x03,0x07,0x0F,0x3E,0x7C,0xF8,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x80,0x00,0x80,0xC0,0xE0,0x70,0x38,0x0C,0x0F,0x0F,0x1F,0x7C,0xF8,0xF0,0xE0,0x80,0x00,0x00,0x83,0x03,0x03,0x03,0x3F,0x3F,0x03,0x03,0x03,0x03,0x00,0x3F,0xFF,0xE0,0x80,0x00,0x00,0x00,0x80,0xC0,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x0F,0x0F,0x0F,0x0E,0x1C,0x18,0x18,0x18,0x18,0x1C,0x0C,0x0E,0x0F,0x07,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x06,0x06,0x06,0x07,0x03,0x01,0x00,0x71,0x99,0x88,0x88,0x49,0xFF,0x00,0x00,0x02,0x02,0x03,0x03,0x03,0x03,0x02,0x02,0x00,0x00,0x02,0x03,0x03,0x03,0x03,0x03,0x02,0x02,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x03,0x03,0x01,0x00,0x03,0x03,0x03,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
void setup() {
  oled.init();              // инициализация
  oled.clear();
  oled.setScale(4);
  enc1.setType(TYPE2);
  pinMode(SW, INPUT_PULLUP);
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(13, OUTPUT);
  oled.print("Hello");
  delay(1000);

}
void loop() {
  butt1.tick();
  butt2.tick();
  enc1.tick(digitalRead(CLK), digitalRead(DT), !digitalRead(SW));
  
  if(flag_1 == 0){
    oled.setScale(3);
    oled.home();
    oled.print("Формула:");
    oled.setCursorXY(110, 3);
    oled.print(form);
    if(enc1.isLeft()) form --;
    if(enc1.isRight()) form ++;
    if(enc1.isClick()) flag_1 = 1;
    }
  if (butt1.isDouble()) {
    flag_1 = 0;
    form = 0;
  }
//----------------ФОРМУЛА 1------------------- 
  if(form == 1 && flag_1 == 1){
  oled.drawBitmap(0, 0, bitmap_128x32_one, 128, 32);
  if (enc1.isHolded()){
    flag = 1;
    digitalWrite(13, HIGH);
  }
  if(flag == 1){
    if(enc1.isLeft()){
      num--;
      digitalWrite(13, LOW);
    }
    if(enc1.isRight()){
      num++;
      digitalWrite(13, LOW);
    }
    if(enc1.isClick()) flag = 0;
  }
  if(num > 4) num = 4;
  if(num < 0) num = 0;
  switch(num){
    case 2:{
      oled.setScale(1);
      oled.setCursorXY(118, 1);
      oled.print("b");
      if (enc1.isRight()){
        b++;
        oled.drawBitmap(0, 0, bitmap_128x32_one, 128, 32);
        oled.setCursorXY(30, 1);
        oled.print(b);
      }
      if (enc1.isLeft()){
        b--;
        oled.drawBitmap(0, 0, bitmap_128x32_one, 128, 32);
        if(a < 0) oled.setCursorXY(24, 1);
        else{oled.setCursorXY(30, 1);}
        oled.print(b);
      }
      }
    break;
    case 1:{
      oled.setScale(1);
      oled.setCursorXY(118, 1);
      oled.print("a");
      if (enc1.isRight()){
        a++;
        oled.drawBitmap(0, 0, bitmap_128x32_one, 128, 32);
        oled.setCursorXY(40, 22);
        oled.print(a);
      }
      if (enc1.isLeft()){
        a--;
        oled.drawBitmap(0, 0, bitmap_128x32_one, 128, 32);
        oled.setCursorXY(40, 22);
        oled.print(a);
      }
      }
    break;
    case 3:{
      oled.setScale(1);
      oled.setCursorXY(118, 1);
      oled.print("n");
      if (enc1.isRight()){
        n++;
        oled.drawBitmap(0, 0, bitmap_128x32_one, 128, 32);
        oled.setCursorXY(85, 1);
        oled.print(n);
      }
      if (enc1.isLeft()){
        n--;
        oled.drawBitmap(0, 0, bitmap_128x32_one, 128, 32);
        oled.setCursorXY(85, 1);
        oled.print(n);
      }
      }
    break;
    case 4:{
      oled.setScale(1);
      oled.setCursorXY(118, 1);
      oled.print("k");
      if (enc1.isRight()){
        k++;
        oled.drawBitmap(0, 0, bitmap_128x32_one, 128, 32);
        oled.setScale(3);
        oled.setCursorXY(48, 3);
        oled.print(k);
      }
      if (enc1.isLeft()){
        k--;
        oled.drawBitmap(0, 0, bitmap_128x32_one, 128, 32);
        oled.setScale(3);
        oled.setCursorXY(48, 3);
        oled.print(k);
      }
      }
      }
  if (enc1.isDouble()){
    
    oled.drawBitmap(0, 0, bitmap_128x32_one, 128, 32);
    oled.setScale(3);
    oled.setCursorXY(48, 3);
    oled.print(k);
    oled.setScale(1);
    oled.setCursorXY(30, 1);
    oled.print(b);
    oled.setCursorXY(40, 22);
    oled.print(a);
    oled.setCursorXY(85, 1);
    oled.print(n);
    
      }

  if(butt1.isClick()){
    oled.clear();
    oled.home();
    oled.setScale(2);
    oled.print("Продовжити?");
  }
    
  if(butt2.isClick()){
    n++;
    F_1 = k * pow(b, n) / n;
    F_2 = k * pow(a, n) / n;
    F_x = F_1 -= F_2;
    oled.clear();
    oled.home();
    oled.setScale(4);
    oled.print(F_x);
    }
  }
  if(form == 2 && flag_1 == 1){
    oled.drawBitmap(0, 0, bitmap_128x32_two, 128, 32);
  }
}
