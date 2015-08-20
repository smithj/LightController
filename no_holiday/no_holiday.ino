#include <math.h>


int ledR = 11;
int ledG = 10;
int ledB = 9;

int flashDuration = 200;

int allPins[6] = {3,5,6,9,10,11};
int allPinValues[6] = {0,255,0,0,128,0};


void setup() {
  Serial.begin(115200);
 
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);  
  pinMode(3, OUTPUT);  
  
  
  pinMode(13, INPUT);
}

void refreshAllPins(){
   for (int i=0; i<6; i++){  
      analogWrite(allPins[i],allPinValues[i]);
   } 
}

void allPinsDark() {
  
   for (int i=0; i<6; i++) {
      analogWrite(allPins[i],0);
   }
}


void loop() {
 
   int lights_on = digitalRead(13);
   
   if (lights_on == HIGH){
      refreshAllPins();   
      Serial.println("lights on");
   }
   else{
      allPinsDark();
      Serial.println("lights off");
   }
   
   delay(3600000);

}
