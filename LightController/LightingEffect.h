/*
 * Effect.h
 *
 *  Created on: Aug 7, 2015
 *      Author: james
 */

#ifndef LIGHTINGEFFECT_H_
#define LIGHTINGEFFECT_H_

class LightingEffect {
public:
	LightingEffect();
	virtual ~LightingEffect();

	inline virtual void initialize(){   };
	virtual void show(){};
	virtual void lightsOut(){};

};

#endif /* LIGHTINGEFFECT_H_ */
