#include <Arduino.h>
#include <U8g2lib.h>
#include <InterpretIRData.h>
#include <Snake.h>

#define SPEAKER_PIN 9

InterpretIRData dataInterpreter;
U8G2_SSD1306_128X64_NONAME_1_HW_I2C OLEDScreen = U8G2_SSD1306_128X64_NONAME_1_HW_I2C(U8G2_R0, U8X8_PIN_NONE);

Snake mySnake = Snake(&OLEDScreen);

String toScreen;
String gotFromPilot;


void displayPrepare(void) {
  OLEDScreen.setFont(u8g2_font_6x10_tf);
  OLEDScreen.setFontRefHeightExtendedText();
  OLEDScreen.setDrawColor(1);
  OLEDScreen.setFontPosTop();
  OLEDScreen.setFontDirection(0);
}

void displayString(String toDraw) {
  OLEDScreen.drawStr( 0, 0, toDraw.c_str());
}

void draw(void) {
  displayPrepare();
  displayString(dataInterpreter.interpretSignal(gotFromPilot));
}

void setup(void) {  
  OLEDScreen.begin();
  OLEDScreen.setFlipMode(1);

  pinMode(SPEAKER_PIN, HIGH);
}
 
void loop(void) {
  
  digitalWrite(SPEAKER_PIN, LOW);
  gotFromPilot = dataInterpreter.checkIRSignal();

  OLEDScreen.firstPage();  
  do {
    draw();
    mySnake.show();
  } while( OLEDScreen.nextPage() );
}
