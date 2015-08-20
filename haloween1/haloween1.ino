#include <math.h>


int ledR = 11;
int ledG = 10;
int ledB = 9;

int flashDuration = 200;

int allPins[6] = {3,5,6,9,10,11};
int allPinValues[6] = {0,255,0,0,255,0};


void setup() {
  Serial.begin(115200);
 
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);  
  pinMode(3, OUTPUT);  
  
  
  pinMode(13, OUTPUT);
  
  digitalWrite(13,LOW);

}

void flash(int pin, int duration){
   
 analogWrite(pin, 255);
 delay(duration);
 analogWrite(pin,0);
}

void flashAll(int duration){
 
   for (int i=0; i<6; i++){  
      analogWrite(allPins[i], 255);
   }
   
   delay(duration);
   
   refreshAllPins();

}

void refreshAllPins(){
   for (int i=0; i<6; i++){  
      analogWrite(allPins[i],allPinValues[i]);
   } 
}


void fade(int pinIndex, int startB, int stopB, int stepDuration){
  
   if (startB > stopB){
      startB = 0 - startB;
      stopB = 0 - stopB;
   }   
   for (int i=startB; i<stopB; i++){
       analogWrite(allPins[pinIndex],abs(i));
       allPinValues[allPins[pinIndex]] = abs(i);
       delay(stepDuration);
   }
   
}


void lightening(){
  
   digitalWrite(13,HIGH);
   delay(1000);
   digitalWrite(13,LOW);

   flashAll(flashDuration);
   delay(100);
   flashAll(flashDuration*2);
   delay(20);
   flashAll(flashDuration);
   delay(100);
   flashAll(flashDuration*2);
   
   
}


void loop() {
 
   refreshAllPins();   
   
   int brightMin = random(0,64);
   int stepDuration = random(30,200);
   
   Serial.print("bright min: ");
   Serial.println(brightMin);
   Serial.print("step duration: ");
   Serial.println(stepDuration);

   fade(1, 255, brightMin, stepDuration);
   
   int lighteningStrike = random(0,4);
   
//   if (lighteningStrike != 0){
      
      Serial.println("boom");
      lightening();      
//   }
   
   fade(1, brightMin, 255, stepDuration);

   
}
