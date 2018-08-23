#ifndef SNAKEPART_H
#define SNAKEPART_H
     
#include <Arduino.h>
#include <Position.h>
#include <U8g2lib.h>

#define PART_SIZE 4
#define MAP_SIZE_X 32
#define MAP_SIZE_Y 16

#define EXISTS true
#define NOT_EXISTS false

typedef uint8_t byte;

class SnakePart {
    private:
        Position position;
        boolean exists;
        U8G2_SSD1306_128X64_NONAME_1_HW_I2C *screen;
    public:
        SnakePart();
        ~SnakePart();

        void show();
        void hide(); 

        void setScreen(U8G2_SSD1306_128X64_NONAME_1_HW_I2C*);

        Position getPosition();
        void setPosition(Position);

        bool getState();
        void setState(bool);
};
     
#endif