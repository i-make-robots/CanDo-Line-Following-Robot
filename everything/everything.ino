//------------------------------------------------------------------------------
// CanDo line-following robot
// dan@marginallycelver.com 2012-06-08
//------------------------------------------------------------------------------
// Copyright at end of file.
// please see http://www.github.com/i-make-robots/CanDo for more information.



//------------------------------------------------------------------------------
// INCLUDES
// Includes save a lot of time by allowing you to use previously written code
// without copying and pasting it into this file (which would make a giant mess)
//------------------------------------------------------------------------------



// Servos are complicated and I don't want to reinvent the wheel, so I
// include someone else's code that does all the heavy lifting for me.
#include <Servo.h>



//------------------------------------------------------------------------------
// DEFINES
// Defines are values that will not change while the program is running.
//------------------------------------------------------------------------------



// Servos have a speed from 0 (full speed backward) to 180 (full speed forward)
// NO_MOVE is the value where they don't move at all in the middle.
#define NO_MOVE  92
// If our servos don't move then the robot won't go.  What should our forward
// speed be?
#define SPEED    8
#define ACCEL    5



//------------------------------------------------------------------------------
// GLOBALS
// Globals store information that needs to be used everywhere in the program.
//------------------------------------------------------------------------------



Servo left_wheel;
Servo right_wheel;


// Here I'm storing information about the sensors.  I made this a complicated
// because I want it to work right the first time for everybody.
int left_max,left_min,left_first;
int right_max,right_min,right_first;
int first;
int c;



//------------------------------------------------------------------------------
// METHODS
// Methods describe what the robot does - that is to say, how it reads,
// writes, and calculates information to achieve a result.
//------------------------------------------------------------------------------



// Run once when the program starts
void setup() {
  // Get ready to send messages from the Arduino to the human, if need be.
  Serial.begin(9600);

  // Each wheel is connected to a digital pin on the Arduino.
  // Here we tell the included code which one so they can talk to each other.
  left_wheel.attach( 2 );
  right_wheel.attach( 4 );

  //
  first=1;
  c=0;
}



// Run over and over again
void loop() {
  // What do the robot eyes see?  analogRead gives a value from 0 to 1023
  int left_sensor  = analogRead( A0 );
  int right_sensor = analogRead( A1 );

  // smooth the left sensor to always be between 1 and 0.
  if(first==1) {
    left_first=left_max=left_min=left_sensor;
  }
  if(left_sensor > left_max) {
    left_max++;
    left_sensor=left_max;
  }
  if(left_sensor < left_min) {
    left_min--;
    left_sensor=left_min;
  }
  
  // smooth the right sensor to always be between 1 and 0.
  if(first==1) {
    right_first=right_max=right_min=right_sensor;
  }
  if(right_sensor > right_max) {
    right_max++;
    right_sensor=right_max;
  }
  if(right_sensor < right_min) {
    right_min--;
    right_sensor=right_min;
  }
  
  
  float left  = (float)( left_sensor  - left_min  ) / (float)( left_max  - left_min  );
  float right = (float)( right_sensor - right_min ) / (float)( right_max - right_min );

  // Do the eyes see the same thing?
  // If the difference is 0 then they see the same thing.
  // The difference will always be between +1.0 and -1.0
  float difference = left - right;

  // change is always between +ACCEL and -ACCEL
  int change = ACCEL * difference;

  if(++c > 10 ) {
    c=0;
    if(right_max>right_first) right_max--;
    if(right_min<right_first) right_min++;
    if(left_max>left_first) left_max--;
    if(left_min<left_first) left_min++;
  }
  
  first=0;

  Serial.print(left);            Serial.print(' ');
  Serial.print(left_max);        Serial.print(' ');
  Serial.print(left_min);        Serial.print('\t');
  Serial.print(right);           Serial.print(' ');
  Serial.print(right_max);       Serial.print(' ');
  Serial.print(right_min);       Serial.print('\t');
  Serial.print(difference);      Serial.print('\t');
  Serial.print(change,DEC);      Serial.print('\n');
  
  change=5;
  // Adjust the wheel speed.  Servo::write() accepts a number from 0 to 180.
  // NO_MOVE is in the middle.  180 is full speed forward.
  left_wheel .write( NO_MOVE - SPEED - change );
  right_wheel.write( NO_MOVE + SPEED - change );
  
  // give the brain a short rest to let the servos do their thing.
  delay(20);  // milliseconds
}



//------------------------------------------------------------------------------
// Copyright (C) 2012 Dan Royer (dan@marginallyclever.com)
// Permission is hereby granted, free of charge, to any person obtaining a 
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation 
// the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the 
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//------------------------------------------------------------------------------


