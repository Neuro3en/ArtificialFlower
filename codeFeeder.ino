// Feeding part of the artificial flower.
// by Benjamin H Paffhausen; MIT Licence
// Steppermotor controlled by analoginputs that measure if teh sucrosewater 
// is present in certain parts of the feeding tube.
// Most of this code is based on: https://github.com/tardate/X113647Stepper


int Pin0 = 8;
int Pin1 = 9;
int Pin2 = 10;
int Pin3 = 11;
boolean forward = false;

int max_steps = 65;
int step = 0;
  int belohnung = HIGH;   
unsigned long previousMillis = 0;  
unsigned long interval = 60000; 

void setup() {
      pinMode(4,INPUT);
      pinMode(12,OUTPUT);
      
  Serial.begin(9600);

  pinMode(Pin0, OUTPUT);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
 
  
}

void loop() {
//  if (digitalRead(4)==HIGH){
//  if (analogRead(A0)<400){
 unsigned long currentMillis = millis();
 if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
   // int belohnung=1;
   if (belohnung == LOW) {
      belohnung = HIGH;

      interval = 20000;
    } else {
      belohnung = LOW;
      interval = 380000;
    }
    }
if (belohnung == HIGH){
  // analogWrite(3, 3);  // LED on pin D3, brightness 3 out of 255
   digitalWrite(3, HIGH);

digitalWrite(12, HIGH);
}else{
   //  analogWrite(3, 0);  // LED on pin D3, OFF
     digitalWrite(12, LOW);
digitalWrite(3, LOW);

}

 
   
int sensorValue = analogRead(A6);
  int sensorValue2 = analogRead(A5);  

if (sensorValue>400 && belohnung == HIGH){  // should be full and it is
digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
}
if (sensorValue<400 && belohnung == LOW){  // should be empty and it is
digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
}
  
if (sensorValue<400 && belohnung == HIGH){  // should be full but it's not
  
    forward = true;
  switch(step) {
    case 0:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      break;
    case 1:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, HIGH);
      break;
    case 2:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      break;
    case 3:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      break;
    case 4:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 5:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 6:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 7:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      break;
  }

  if(forward) {
    step++;
  } else {
    step--;
  }
  if(step>7) {
    step=0;
  }
  if(step<0) {
    step=7;
  }
  delay(1);
}


if (sensorValue2<400 && belohnung == LOW){  // should be halfway but it's below

      forward = true;

  switch(step) {
    case 0:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      break;
    case 1:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, HIGH);
      break;
    case 2:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      break;
    case 3:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      break;
    case 4:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 5:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 6:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 7:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      break;
  }

  if(forward) {
    step++;
  } else {
    step--;
  }
  if(step>7) {
    step=0;
  }
  if(step<0) {
    step=7;
  }
  delay(1);
  }
 
if (sensorValue>400 && belohnung == LOW){  // should be halfway but it's full

      forward = false;

  switch(step) {
    case 0:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      break;
    case 1:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, HIGH);
      break;
    case 2:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      break;
    case 3:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      break;
    case 4:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 5:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 6:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 7:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      break;
  }

  if(forward) {
    step++;
  } else {
    step--;
  }
  if(step>7) {
    step=0;
  }
  if(step<0) {
    step=7;
  }
  delay(1);
  
 }
}
