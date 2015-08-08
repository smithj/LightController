/*
 * EffectColorCrossfader.h
 *
 *  Created on: Aug 7, 2015
 *      Author: james
 */

#ifndef LIGHTINGLIGHTINGEFFECTCOLORCROSSFADER_H_
#define LIGHTINGLIGHTINGEFFECTCOLORCROSSFADER_H_

#include "LightingEffect.h"
#include <Arduino.h>


class LightingEffectColorCrossfader : public LightingEffect  {
public:
	LightingEffectColorCrossfader();
	virtual ~LightingEffectColorCrossfader();



	inline virtual void initialize(){

		Serial.println("crossfade initialize");


		pinMode(redPin, OUTPUT);   // sets the pins as output
		pinMode(grnPin, OUTPUT);
		pinMode(bluPin, OUTPUT);


	}


	virtual void show(){

		Serial.println("crossfade show");

		int black[3]  = { 0, 0, 0 };
		int white[3]  = { 100, 100, 100 };
		int red[3]    = { 100, 0, 0 };
		int green[3]  = { 0, 100, 0 };
		int blue[3]   = { 0, 0, 100 };
		int yellow[3] = { 40, 95, 0 };
		int dimWhite[3] = { 30, 30, 30 };

		crossFade(red);
		crossFade(green);
		crossFade(blue);
		crossFade(yellow);



	}

private:

	const static int intensityLeftShift = 2;  // divide the output brightness by this number
	const static int redPin = 9;   // Red LED,   connected to digital pin 9
	const static int grnPin = 10;  // Green LED, connected to digital pin 10
	const static int bluPin = 11;  // Blue LED,  connected to digital pin 11

	int calculateStep(int prevValue, int endValue);
	int calculateVal(int step, int val, int i);
	void crossFade(int color[3]) ;


};

#endif /* LIGHTINGLIGHTINGEFFECTCOLORCROSSFADER_H_ */
