#ifndef SNAKEPART_H
#define SNAKEPART_H
     
#include <Arduino.h>
#include <Position.h>
#include <U8g2lib.h>

#define PART_SIZE 4

class SnakePart {
    private:
        Position position;
        boolean exists;
        U8G2_SSD1306_128X64_NONAME_1_HW_I2C *screen;
    public:
        SnakePart(U8G2_SSD1306_128X64_NONAME_1_HW_I2C*);
        ~SnakePart();

        void show();
        void hide(); 

        Position getPosition();
        void setPosition(Position);

        bool getState();
        void setState(bool);
};
     
#endif