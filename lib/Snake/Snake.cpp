#include "Snake.h"

/**
private:
        byte snakeSpeed;
        byte snakeLength;
        byte snakeDirection;
        Position snakePosition;

        void Spp();
        void Smm();
        void turnRight();
        void turnLeft();
    public:
        Snake();
        ~Snake();
        void show(U8G2_SSD1306_128X64_NONAME_1_HW_I2C *u8g2);
        void actualizeDirecionAndSpeed(); 
*/

Snake::Snake(U8G2_SSD1306_128X64_NONAME_1_HW_I2C *screenToDsplaySnake){
    snakePosition.setX(MAX_X_POSITION / 2);
    snakePosition.setY(MAX_Y_POSITION / 2);
    snakeSpeed = MIN_SPEED;
    snakeLength = INITIAL_LENGTH;
    snakeDirection = INITIAL_DIRECTION;
    screen = screenToDsplaySnake;
}

Snake::~Snake(){
    /* nothing to do here */
}

void Snake::show(){
    screen->drawCircle(10, 10, 10);
}

/**
 Obstacle
-public
--show()
--getPosition()
-private
--Position obstaclePosition
--bool exists
 */