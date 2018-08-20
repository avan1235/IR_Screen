#include "Position.h"

Position::Position(byte x, byte y){
    xPosition = x;
    yPosition = y;
}

Position::~Position(){
    /**
     * nothing to do here
     */
}

void Position::setX(byte x){
    xPosition = x % MAX_X_POSITION;
}

void Position::setY(byte y){
    yPosition = y % MAX_Y_POSITION;
}

byte Position::getX(){
    return xPosition;
}

byte Position::getY(){
    return yPosition;
}

void Position::Xpp(){
    xPosition = (xPosition + 1) % MAX_X_POSITION;
}

void Position::Xmm(){
    xPosition = (xPosition - 1) % MAX_X_POSITION;
}

void Position::Ypp(){
    yPosition = (yPosition + 1) % MAX_Y_POSITION;
}

void Position::Ymm(){
    yPosition = (yPosition - 1) % MAX_Y_POSITION;
}