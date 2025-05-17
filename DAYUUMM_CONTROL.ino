#include <ESP32Servo.h>
#include <Arduino.h>


// Define Servo Pins
const int GatePin1 = 25;
const int GatePin2 = 26;
const int GatePin3 = 27;

// Define Switch Pins
const int Water_pin_LOW = 32;
const int Water_pin_MID = 33;
const int Water_pin_FULL = 34;

// Define Servo Objects
Servo servo1;
Servo servo2;
Servo servo3;


void setup() {

  servo1.attach(GatePin1);
  servo2.attach(GatePin2);
  servo3.attach(GatePin3);

  // Set Servo Initial Position
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);

  // Set Pin Modes
  pinMode(Water_pin_LOW, INPUT);
  pinMode(Water_pin_MID, INPUT);
  pinMode(Water_pin_FULL, INPUT);
}

void loop() {

  int switch1State = analogRead(Water_pin_LOW); 
  int switch2State = analogRead(Water_pin_MID); 
  int switch3State = analogRead(Water_pin_FULL); 


  if (switch1State < 20 && switch2State < 20 && switch3State < 20) {
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  }

  if (switch1State > 20 && switch2State < 20 && switch3State < 20) {
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  }

  if (switch1State > 20 && switch2State > 20 && switch3State < 20) {
  servo1.write(0);
  servo2.write(90);
  servo3.write(0);
  }

  if (switch1State > 20 && switch2State > 20 && switch3State > 20) {
  servo1.write(90);
  servo2.write(150);
  servo3.write(90);
  }
  
  delay(50); // Small delay for stability
}
