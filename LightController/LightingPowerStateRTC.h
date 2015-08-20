/*
 * LightingPowerStateRTC.h
 *
 *  Created on: Aug 16, 2015
 *      Author: james
 */

#ifndef LIGHTINGPOWERSTATERTC_H_
#define LIGHTINGPOWERSTATERTC_H_

#include "LightingPowerState.h"
#include <Arduino.h>

class LightingPowerStateRTC : public LightingPowerState {
public:
	LightingPowerStateRTC();
	LightingPowerStateRTC(int lightsOnStartHour);
	virtual ~LightingPowerStateRTC();


	virtual bool isOn(){
		return powerOn();
	};


	inline virtual void initialize(){
		//Serial.println("RTC init");
		setup();
	}

	virtual int hoursLeftOff(){
		return hoursUntilLightsOn();
	}

	void setup();
	bool powerOn();

private:
	void printDigits(int digits);

	int lightsOnStartTime;
	int hoursUntilLightsOn();


};

#endif /* LIGHTINGPOWERSTATERTC_H_ */
