#include "InterpretIRData.h"

#include <IRremote.h>

const String UP = "e0e006f9";
const String DOWN = "e0e08679";
const String RIGHT = "e0e046b9";
const String LEFT = "e0e0a659";
const String CENTER = "e0e016e9";
const String EXIT = "e0e0b44b";
const String MUTE = "e0e0f00f";
const String MENU = "e0e058a7";

InterpretIRData::InterpretIRData(){
    irrecv.enableIRIn(); // Start the receiver
    previousMillisIR = millis();
    currentMillisIR = millis();
}

InterpretIRData::~InterpretIRData(){
    /**
     * nothing to destruct
     */
}

String InterpretIRData::checkIRSignal(){
    String IRdata = "";

    currentMillisIR = millis();

    if (currentMillisIR - previousMillisIR >= IR_INTERVAL) {
        previousMillisIR = currentMillisIR;
        if (irrecv.decode(&results)) {
            IRdata =  String(results.value, HEX);
            irrecv.resume(); // Receive the next value
        }
    }

    return IRdata;
}

String InterpretIRData::interpretSignal(String data){
    String interpretedString = "";

    if (data == UP){
        interpretedString = "UP";
    }
    else if (data == DOWN){
        interpretedString = "DOWN";
    }
    else if (data == RIGHT){
        interpretedString = "RIGHT";
    }
    else if (data == LEFT){
        interpretedString = "LEFT";
    }
    else if (data == CENTER){
        interpretedString = "CENTER";
    }
    else if (data == MUTE){
        interpretedString = "MUTE";
    }
    else if (data == MENU){
        interpretedString = "MENU";
    }
    else if (data == EXIT){
        interpretedString = "EXIT";
    }
    else{
        interpretedString = "__ERROR__";
    }

    return interpretedString;
}