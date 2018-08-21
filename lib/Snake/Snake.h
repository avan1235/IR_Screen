#ifndef SNAKE_H
#define SNAKE_H
     
#include <Arduino.h>
#include <Position.h>
#include <U8g2lib.h>

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

#define MIN_SPEED 1
#define MAX_SPEED 3
#define INITIAL_LENGTH 3
#define MAX_LENGTH 9
#define INITIAL_DIRECTION UP
     
typedef uint8_t byte;

class Snake {
    private:
        byte snakeSpeed;
        byte snakeLength;
        byte snakeDirection;
        Position snakePosition;
        U8G2_SSD1306_128X64_NONAME_1_HW_I2C *screen;

        void Spp();
        void Smm();
        void turnRight();
        void turnLeft();
    public:
        Snake(U8G2_SSD1306_128X64_NONAME_1_HW_I2C *screenToDsplaySnake);
        ~Snake();
        void show();
        void actualizeDirecionAndSpeed();      
};
     
#endif