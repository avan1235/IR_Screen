#ifndef INTERPRETIRDATA_H
#define INTERPRETIRDATA_H
     
#include <Arduino.h>
#include <IRremote.h>

#define RECV_PIN 8
#define IR_INTERVAL 100

class InterpretIRData{
    public:
        InterpretIRData();
        ~InterpretIRData();
        void setupIR();
        String checkIRSignal();
        String interpretSignal(String);
    private:
        IRrecv irrecv;
        decode_results results;
        unsigned long previousMillisIR;
        unsigned long currentMillisIR;
};
     
#endif
