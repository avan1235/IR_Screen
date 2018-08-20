#include <Arduino.h>
#include <U8g2lib.h>
#include <InterpretIRData.h>

#define SPEAKER_PIN 9

InterpretIRData dataInterpreter;

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
  toScreen = dataInterpreter.interpretSignal(gotFromPilot);
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

  
}

void loop(void) {
  
  digitalWrite(SPEAKER_PIN, LOW);
  gotFromPilot = dataInterpreter.checkIRSignal();

  u8g2.firstPage();  
  do {
    draw();
  } while( u8g2.nextPage() );
}
