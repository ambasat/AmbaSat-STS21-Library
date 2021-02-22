/*******************************************************************************
* AmbaSat-1 
* Filename: main.cpp
*
* Example program to test the AmbaSat-1 library for the 
* STS21 Digital Temperature Sensor
* 
* Copyright (c) 2021 AmbaSat Ltd
* https://ambasat.com
*
* licensed under Creative Commons Attribution-ShareAlike 3.0
* ******************************************************************************/

#include <AmbaSatSTS21.h>
#include <Debugging.h>

AmbaSatSTS21 *ambasatSTS21;

// =============================================================================

void setup()
{
    Serial.begin(9600);

    while (!Serial)
	{
        delay(10);    
	}
		
    ambasatSTS21 = new AmbaSatSTS21();

    PRINTLN_DEBUG("Setup complete");  		
}

// =============================================================================

void loop()
{
  float temperature;
 
  if (ambasatSTS21->getSensorReading(&temperature)) 
  {  
      PRINT_DEBUG(F("temperature: "));
      PRINTLN_DEBUG(temperature);   
  } 
  else 
  { 
      PRINTLN_DEBUG("Error: Failed to read sensor");
  }  

  delay(1000);
}
