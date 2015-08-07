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


		}


		virtual void show(){


				Serial.println("crossfade show");



			}

};

#endif /* LIGHTINGLIGHTINGEFFECTCOLORCROSSFADER_H_ */
