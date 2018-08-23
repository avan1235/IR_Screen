#ifndef POSITION_H
#define POSITION_H
     
#include <Arduino.h>

#define MAX_X_POSITION 32
#define MAX_Y_POSITION 16

typedef uint8_t byte;

class Position {
    private:
        byte xPosition;
        byte yPosition;
    public:
        Position();
        ~Position();
        void setX(byte);
        void setY(byte);
        byte getX();
        byte getY();
        void Xpp();
        void Xmm();
        void Ypp();
        void Ymm();
};
     
#endif
