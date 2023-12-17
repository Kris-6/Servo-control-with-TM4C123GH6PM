// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// Modified for Energia/Stellaris Launchpad by Kevin Balke <fughilli@gmail.com>
// This example code is in the public domain.

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(PF_1);
  Serial.begin(9600); // attaches the servo on Port F, pin 1 (Red LED pin) to the servo object
} 
 
 
void loop() 
{ 
  if (Serial.available() > 0) {
    String command = Serial.readString(); // Read the entire command as a string
    int angle = command.toInt(); // Convert the string to an integer

    Serial.print("angle");
    myservo.write(angle);
  }

}
