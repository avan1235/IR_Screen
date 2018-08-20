#include <Arduino.h>
#include <U8g2lib.h>
#include <IRremote.h>


#define INTERVAL 100
#define SPEAKER_PIN 9

int RECV_PIN = 0;
IRrecv irrecv(RECV_PIN);
decode_results results;

String toScreen;
String gotFromPilot;

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void u8g2_prepare(void) {
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setFontRefHeightExtendedText();
  u8g2.setDrawColor(1);
  u8g2.setFontPosTop();
  u8g2.setFontDirection(0);
}

void u8g2_ascii() {
    if(gotFromPilot == "e0e006f9"){
      toScreen = "UP";
    }
    else if(gotFromPilot == "e0e08679"){
      toScreen = "DOWN";
    }
    else if(gotFromPilot == "e0e046b9"){
      toScreen = "RIGHT";
    }
    else if(gotFromPilot == "e0e0a659"){
      toScreen = "LEFT";
    }
    else if(gotFromPilot == "e0e016e9"){
      toScreen = "CENTER";
    }
    else if(gotFromPilot == "e0e0b44b"){
      toScreen = "EXIT";
    }
    else if(gotFromPilot == "e0e0f00f"){
      toScreen = "MUTE";
    }
    else if(gotFromPilot == "e0e058a7"){
      toScreen = "MENU";
    }
    else{
      toScreen = "No match!?!";
    }
  u8g2.drawStr( 0, 0, toScreen.c_str());
}

void draw(void) {
  u8g2_prepare();
  u8g2_ascii();
}

void setup(void) {  
  u8g2.begin();
  u8g2.setFlipMode(1);

  pinMode(SPEAKER_PIN, HIGH);

  irrecv.enableIRIn(); // Start the receiver
}

/**
 * up - e0e006f9
 * down - e0e08679
 * right - e0e046b9
 * left - e0e0a659
 * center - e0e016e9
 * exit - e0e0b44b
 * mute - e0e0f00f
 * menu - e0e058a7
 */

unsigned long previousMillis;
unsigned long currentMillis;

void loop(void) {
  currentMillis = millis();
  digitalWrite(SPEAKER_PIN, LOW);

  if (currentMillis - previousMillis >= INTERVAL) {
    previousMillis = currentMillis;
    if (irrecv.decode(&results)) {
      gotFromPilot =  String(results.value, HEX);
      irrecv.resume(); // Receive the next value
    }
    else{
      toScreen = "No signal";
    }
  }

  u8g2.firstPage();  
  do {
    draw();
  } while( u8g2.nextPage() );
}
