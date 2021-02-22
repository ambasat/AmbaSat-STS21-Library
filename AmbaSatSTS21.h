/*******************************************************************************
* AmbaSat-1 
* Filename: AmbaSatSTS21.h
*
* This library is designed specifically for AmbaSat-1 and the 
* STS21 Digital Temperature Sensor
* 
* Copyright (c) 2021 AmbaSat Ltd
* https://ambasat.com
*
* licensed under Creative Commons Attribution-ShareAlike 3.0
* ******************************************************************************/

#ifndef __AmbaSatSTS21Sensor__
#define __AmbaSatSTS21Sensor__

#define AMBASAT_STS21_ADDR 0x4A // AmbaSat Sensor Address 

#include <Arduino.h>
#include <Wire.h>
#include <Debugging.h>

class AmbaSatSTS21 
{
    public:
        AmbaSatSTS21(void);    
        bool getSensorReading(float *temp);
    private:
        float temperature;
        bool i2cInitialised = false;
};

#endif // __AmbaSatSTS21Sensor__

