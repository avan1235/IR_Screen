#include "SnakePart.h"

SnakePart::SnakePart(U8G2_SSD1306_128X64_NONAME_1_HW_I2C *screenToDsplayPart){
    screen = screenToDsplayPart;
    exists = false;
}

SnakePart::~SnakePart(){
    /* nothing to do here */
}

void SnakePart::show(){
    screen->drawDisc(position.getX(), position.getY(), PART_SIZE / 2);
}

void SnakePart::hide(){
    
}