#include "SnakePart.h"

SnakePart::SnakePart(){
    exists = false;
}

SnakePart::~SnakePart(){
    /* nothing to do here */
}

void SnakePart::setScreen(U8G2_SSD1306_128X64_NONAME_1_HW_I2C *toSet){
    screen = toSet;
}

void SnakePart::show(){
    screen->drawCircle(position.getX()*PART_SIZE-(PART_SIZE/2), position.getY()*PART_SIZE-(PART_SIZE/2), PART_SIZE / 2);
}

void SnakePart::hide(){
    screen->setDrawColor(0); 
    screen->drawCircle(position.getX()*PART_SIZE-(PART_SIZE/2), position.getY()*PART_SIZE-(PART_SIZE/2), PART_SIZE / 2);
    screen->setDrawColor(1);
}

Position SnakePart::getPosition(){
    return position;
}

void SnakePart::setPosition(Position toSet){
    position = toSet;
}

bool SnakePart::getState(){
    return exists;
}

void SnakePart::setState(bool state){
    exists = state;
}