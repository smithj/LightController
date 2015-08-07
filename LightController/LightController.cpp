// Do not remove the include below
#include "LightController.h"

#include "LightingEffect.h"
#include "LightingLightingEffectColorCrossfader.h"

LightingEffect *effect;




//The setup function is called once at startup of the sketch
void setup(){

	Serial.begin(9600);

	Serial.println("begin");


	effect = new LightingEffectColorCrossfader();

	effect->initialize();


// Add your initialization code here
}



// The loop function is called in an endless loop
void loop(){

	Serial.println("show");
	effect->show();

	delay(1000);

//Add your repeated code here
}
