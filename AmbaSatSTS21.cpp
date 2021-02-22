/*******************************************************************************
* AmbaSat-1 
* Filename: AmbaSatSHT31.c
*
* This library is designed specifically for AmbaSat-1 and the 
* STS21 Digital Temperature and Humidity Sensor
* 
* Copyright (c) 2021 AmbaSat Ltd
* https://ambasat.com
*
* licensed under Creative Commons Attribution-ShareAlike 3.0
* ******************************************************************************/

#include "AmbaSatSTS21.h"

// ======================================================================================

AmbaSatSTS21::AmbaSatSTS21() 
{
    temperature = NAN;

    if (!i2cInitialised) 
    {
        PRINTLN_DEBUG(F("Starting I2C interface."));
        Wire.begin(); 
        delay(300); // Wait for sensor to start
        
        // Global I2C reset
        PRINTLN_DEBUG(F("Global I2C reset"));
        Wire.beginTransmission(0x00); // global i2c reset address
        Wire.write(0x06);
        Wire.endTransmission(); 
        
        delay(50); // wait for everything to reboot
        PRINTLN_DEBUG(F("I2C Wire has been set up."));
        i2cInitialised = true;
    }
}

// ======================================================================================

bool AmbaSatSTS21::getSensorReading(float *temp) 
{
    unsigned int data[2];

    // Start I2C Transmission
    Wire.beginTransmission(AMBASAT_STS21_ADDR);

    // Select no hold master
    Wire.write(0xF3);

    // End I2C Transmission
    Wire.endTransmission();
    delay(50);

    // Request 2 bytes of data
    Wire.requestFrom(AMBASAT_STS21_ADDR, 2);

    // Read 2 bytes of data
    if (Wire.available() == 2)
    {
      data[0] = Wire.read();
      data[1] = Wire.read();
    }
    else
    {
        PRINTLN_DEBUG(F("ERROR: Failed to read data"));
        return false;
    }

    // Convert the data
    int rawtmp = data[0] * 256 + data[1];
    int value = rawtmp & 0xFFFC;
    temperature = -46.85 + (175.72 * (value / 65536.0));
    *temp = temperature;
    return true;
}
