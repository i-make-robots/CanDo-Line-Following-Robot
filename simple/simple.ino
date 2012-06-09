//------------------------------------------------------------------------------
// Draw robot
// dan@marginallycelver.com 2012 feb 11
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
// GLOBALS
// Globals store information that needs to be used everywhere in the program.
//------------------------------------------------------------------------------



Servo left_wheel;
Servo right_wheel;


int left_max,left_min;
int right_max,right_min;
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
  left_min=512;
  left_max=512;
  right_min=512;
  right_max=512;
  c=0;
}



// Run over and over again
void loop() {
  // What do the robot eyes see?  analogRead gives a value from 0 to 1023
  int left_sensor  = analogRead( A0 );
  int right_sensor = analogRead( A1 );

  if(left_sensor > left_max) {
    left_max++;
    left_sensor=left_max;
  }
  if(left_sensor < left_min) {
    left_min--;
    left_sensor=left_min;
  }
  float left = (float)( left_sensor - left_min ) / (float)( left_max - left_min );
  
  if(right_sensor > right_max) {
    right_max++;
    right_sensor=right_max;
  }
  if(right_sensor < right_min) {
    right_min--;
    right_sensor=right_min;
  }
  float right = (float)( right_sensor - right_min ) / (float)( right_max - right_min );

  if(++c > 10 ) {
    if(right_max>512) right_max--;
    if(right_min<512) right_min++;
    if(left_max>512) left_max--;
    if(left_min<512) left_min++;
    c=0;
  }

  // Do the eyes see the same thing?
  int difference = ( left - right ) * 127;
  // If the difference is 0 then they see the same thing.
  // I want range 0 to 128.  More on that in a moment.
  
  Serial.print(left);
  Serial.print('\t');
  Serial.print(left_max);
  Serial.print('\t');
  Serial.print(left_min);
  Serial.print('\t');
  Serial.print(right);
  Serial.print('\t');
  Serial.print(right_max);
  Serial.print('\t');
  Serial.print(right_min);
  Serial.print('\t');
  Serial.println(difference,DEC);
  
  // Adjust the wheel speed.  Servo::write() accepts a number from 0 to 255.
  // 127, in the middle, means don't move.  255 is full speed forward.
  left_wheel .write( 127 + difference );
  // The right wheel is backward from the left wheel, so reverse the direction.
  right_wheel.write( 127 - difference );

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


