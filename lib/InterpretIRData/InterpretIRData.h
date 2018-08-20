#ifndef INTERPRETIRDATA_H
#define INTERPRETIRDATA_H
     
#include <Arduino.h>
     
class InterpretIRData {
    public:
        InterpretIRData();
        ~InterpretIRData();
        String checkIRSignal();
        String interpretSignal(String data);
};
     
#endif
