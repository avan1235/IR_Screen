#include <Arduino.h>
#include <U8g2lib.h>
#include <InterpretIRData.h>
#include <Snake.h>

#define SPEAKER_PIN 9


U8G2_SSD1306_128X64_NONAME_1_HW_I2C OLEDScreen = U8G2_SSD1306_128X64_NONAME_1_HW_I2C(U8G2_R0, U8X8_PIN_NONE);
InterpretIRData dataInterpreter = InterpretIRData();
Snake mySnake = Snake(&OLEDScreen);

String gotFromPilot = "";

void displayPrepare() {
  OLEDScreen.setFont(u8g2_font_6x10_tf);
  OLEDScreen.setFontRefHeightExtendedText();
  OLEDScreen.setDrawColor(1);
  OLEDScreen.setFontPosTop();
  OLEDScreen.setFontDirection(0);
}

void displayString(String toDraw) {
  OLEDScreen.drawStr( 0, 0, toDraw.c_str());
}

void draw(String s) {
  displayPrepare();
  String toScreen = dataInterpreter.interpretSignal(s);
  displayString(toScreen.c_str());
}

void setup() {  
  OLEDScreen.begin();
  OLEDScreen.setFlipMode(1);

  dataInterpreter.setupIR();

  pinMode(SPEAKER_PIN, HIGH);
}
 
void loop() {
  digitalWrite(SPEAKER_PIN, LOW);

  gotFromPilot = dataInterpreter.checkIRSignal();

  OLEDScreen.firstPage();  
  do {
    draw(gotFromPilot);
    mySnake.show();
  } while( OLEDScreen.nextPage() );
}
