#include "Snake.h"

/**
 * private:
        byte snakeSpeed;
        byte snakeDirection;
        Position snakePosition;
        SnakePart parts[MAX_LENGTH];
        U8G2_SSD1306_128X64_NONAME_1_HW_I2C *screen;

        void Spp();
        void Smm();
        void turnRight();
        void turnLeft();
    public:
        Snake(U8G2_SSD1306_128X64_NONAME_1_HW_I2C*);
        ~Snake();
        void show();
        void actualizeDirecionAndSpeed();   
*/

Snake::Snake(U8G2_SSD1306_128X64_NONAME_1_HW_I2C *screenToDsplaySnake){
    snakePosition.setX(MAX_X_POSITION / 2);
    snakePosition.setY(MAX_Y_POSITION / 2);

    snakeSpeed = MIN_SPEED;
    snakeDirection = INITIAL_DIRECTION;
    screen = screenToDsplaySnake;

    currentMillis = millis();
    lastMillis = millis();

    for(byte i = 0; i < INITIAL_LENGTH; i++){
        parts[i].setScreen(screenToDsplaySnake);

        Position tempPosition;
        tempPosition.setX(snakePosition.getX() - i);
        tempPosition.setY(snakePosition.getY());
        parts[i].setPosition(tempPosition);

        parts[i].setState(EXISTS);
    }
    for(byte i = INITIAL_LENGTH; i < MAX_LENGTH; i++){
        parts[i].setScreen(screenToDsplaySnake);
    }
    
}

Snake::~Snake(){
    /* nothing to do here */
}


byte Snake::indexLastPart(){
    byte lastIndex = 0;
    while(parts[lastIndex].getState() == EXISTS){
         lastIndex++;
    }
    return lastIndex-1;
}

void Snake::Smm(){
    byte lastIndex = indexLastPart();
    // here we have the index af the last part in Snake
    parts[lastIndex].setState(NOT_EXISTS);
}

void Snake::Spp(){  //TODO
    byte newIndex = indexLastPart() + 1;
    if(newIndex < MAX_LENGTH && newIndex > 1){
        parts[newIndex].setState(EXISTS);
        byte oneBeforeIndex = newIndex - 1;
        byte twoBeforeIndex = newIndex - 2;

        if(parts[oneBeforeIndex].getPosition().getX() == parts[twoBeforeIndex].getPosition().getX()){
            
        }
    }
    else if(newIndex < MAX_LENGTH){

    }
}

void Snake::show(){
    for(byte i = 0; i < MAX_LENGTH; i++){
        if(parts[i].getState() == EXISTS){
            parts[i].show();
        }
    }
}

void Snake::turnRight(){
    if(snakeDirection == UP){
        snakeDirection = RIGHT;
    }
    else if(snakeDirection == RIGHT){
        snakeDirection = DOWN;
    }
    else if(snakeDirection == DOWN){
        snakeDirection = LEFT;
    }
    else{
        snakeDirection = UP;
    }
}

void Snake::turnLeft(){
    if(snakeDirection == UP){
        snakeDirection = LEFT;
    }
    else if(snakeDirection == LEFT){
        snakeDirection = DOWN;
    }
    else if(snakeDirection == DOWN){
        snakeDirection = RIGHT;
    }
    else{
        snakeDirection = UP;
    }
}

void Snake::actualizeScreen(){
    currentMillis = millis();
    if(currentMillis - lastMillis >= MOVE_INTERWAL){
        lastMillis = currentMillis;
        if(snakeDirection == UP){
            snakePosition.setY(snakePosition.getY()-1);            
        }
        else if(snakeDirection == DOWN){
            snakePosition.setY(snakePosition.getY()+1);
        }
        else if(snakeDirection == RIGHT){
            snakePosition.setX(snakePosition.getX()+1);
        }
        else if(snakeDirection == LEFT){
            snakePosition.setX(snakePosition.getX()-1);
        }

        byte lastIndex = indexLastPart();
        while(lastIndex > 0){
            parts[lastIndex].setPosition(parts[lastIndex-1].getPosition());
            lastIndex--;
        }

        parts[0].setPosition(snakePosition);
        parts[0].show();
        parts[indexLastPart()].hide();
    }
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