// Do not remove the include below
#include "LightController.h"

#include "LightingEffect.h"
#include "LightingLightingEffectColorCrossfader.h"

#include "LightingPowerState.h"
#include "LightingPowerStateRTC.h"


#define PS_CONTROL_PIN 	2

#define LIGHTS_ON_AT_HOUR  20

LightingEffect *effect;
LightingPowerState *power;



//The setup function is called once at startup of the sketch
void setup(){

	Serial.begin(9600);

	Serial.println("begin");

	pinMode(PS_CONTROL_PIN, OUTPUT);


	effect = new LightingEffectColorCrossfader();

	power = new LightingPowerStateRTC(LIGHTS_ON_AT_HOUR);

	Serial.println("initializing effects and power control");
	effect->initialize();
	power->initialize();



}



// The loop function is called in an endless loop
void loop(){

	if (power->isOn()){
		Serial.println("show");
		lightsOn();

		effect->show();

	}
	else{
		lightsOut();
		// sleep for 30 minutes
		int hoursLeftOff = power->hoursLeftOff();
		Serial.print(hoursLeftOff);
		Serial.println(" hours until lights on.");

		if (hoursLeftOff > 10){
			hoursLeftOff = 1;
		}

		long sleepMS = (long)hoursLeftOff * 60l * 60l * 1000l;
		Serial.print("Sleeping for ");
		Serial.print(sleepMS);
		Serial.println(" miliseconds");

		delay(sleepMS);
		Serial.println("wake up and check again.");
	}

	// check every minute once we're under an hour 'til lights on
	delay(60000);

}

void lightsOut(){

	Serial.println("Turning out the lights");

	effect->lightsOut();
	digitalWrite(PS_CONTROL_PIN, LOW);
}

void lightsOn(){
	digitalWrite(PS_CONTROL_PIN, HIGH);

}
