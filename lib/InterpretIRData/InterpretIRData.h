#ifndef INTERPRETIRDATA_H
#define INTERPRETIRDATA_H
     
#include <Arduino.h>
#include <IRremote.h>

#define RECV_PIN 0
#define IR_INTERVAL 100

class InterpretIRData {
    public:
        IRrecv irrecv = IRrecv(RECV_PIN);
        decode_results results = decode_results();
        unsigned long previousMillisIR;
        unsigned long currentMillisIR;
        InterpretIRData();
        ~InterpretIRData();
        String checkIRSignal();
        String interpretSignal(String data);
};
     
#endif
