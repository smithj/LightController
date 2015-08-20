/*
 * LightingPowerState.h
 *
 *  Created on: Aug 16, 2015
 *      Author: james
 */

#ifndef LIGHTINGPOWERSTATE_H_
#define LIGHTINGPOWERSTATE_H_

class LightingPowerState {
public:
	LightingPowerState();
	LightingPowerState(int lightsOnStartHour);

	virtual ~LightingPowerState();

	virtual bool isOn(){};


	inline virtual void initialize(){};

	virtual int hoursLeftOff(){};



};

#endif /* LIGHTINGPOWERSTATE_H_ */
