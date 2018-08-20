#ifndef SNAKE_H
#define SNAKE_H
     
#include <Arduino.h>
#include <Position.h>
     
typedef uint8_t byte;

class Snake {
    private:
        unsigned int snakeSpeed;
        unsigned int snakeLength;
        Position snakePosition;
        void Spp();
        void Smm();
    public:
        Snake();
        ~Snake();
        void show();
        void actualizeDirecionAndSpeed();
};
     
#endif