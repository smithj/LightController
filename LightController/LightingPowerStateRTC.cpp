/*
 * LightingPowerStateRTC.cpp
 *
 *  Created on: Aug 16, 2015
 *      Author: james
 *
 *
 *  Determines if lights should be on by comparing the current time, read from a RTC, against a static on/off time table.
 *
 *
 */

#include "LightingPowerStateRTC.h"
#include <Arduino.h>
#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

#define DS1307_ADDRESS 0x68
byte zero = 0x00; //workaround for issue #527

int lightsOnStartTime = 0;





LightingPowerStateRTC::LightingPowerStateRTC(int lightsOnStartHour) {
	// TODO Auto-generated constructor stub

	lightsOnStartTime = lightsOnStartHour;

	Serial.print("lights on set to ");
	Serial.println(lightsOnStartTime);
}

LightingPowerStateRTC::LightingPowerStateRTC() {

	// default time for lights on is 8pm
	lightsOnStartTime = 20;
	Serial.print("lights on set to ");
	Serial.println(lightsOnStartTime);
}

LightingPowerStateRTC::~LightingPowerStateRTC() {
	// TODO Auto-generated destructor stub
}



void LightingPowerStateRTC::setup(){

	Wire.begin();

	setSyncProvider(RTC.get);   // the function to get the time from the RTC

	if(timeStatus()!= timeSet)
		Serial.println("Unable to sync with the RTC");
	else
		Serial.println("RTC has set the system time");

}

bool LightingPowerStateRTC::powerOn(){

	Serial.print(hour());
	printDigits(minute());
	printDigits(second());
	Serial.print(" ");
	Serial.print(day());
	Serial.print(" ");
	Serial.print(month());
	Serial.print(" ");
	Serial.print(year());
	Serial.println();

	if (hour() >= lightsOnStartTime)
		return true;
	else
		return false;

}


int LightingPowerStateRTC::hoursUntilLightsOn(){

	Serial.print("Start time: ");
	Serial.println(lightsOnStartTime);
	int hoursLeft = (lightsOnStartTime - hour() - 1);

	// sanity check in case this is called when the lights should be on.
	if (hoursLeft < 0)
		return 0;
	else
		return hoursLeft;

}


void LightingPowerStateRTC::printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
