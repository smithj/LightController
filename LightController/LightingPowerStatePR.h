/*
 * LightingPowerStatePV.h
 *
 *  Created on: Aug 16, 2015
 *      Author: james
 */

#ifndef LIGHTINGPOWERSTATEPR_H_
#define LIGHTINGPOWERSTATEPR_H_

#include "LightingPowerState.h"

class LightingPowerStatePR: public LightingPowerState {
public:
	LightingPowerStatePR();
	virtual ~LightingPowerStatePR();

	void setup();
	bool powerOn();


};

#endif /* LIGHTINGPOWERSTATEPR_H_ */
