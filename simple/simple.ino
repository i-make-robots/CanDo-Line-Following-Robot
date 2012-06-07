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



//------------------------------------------------------------------------------
// METHODS
// Methods describe what the robot does - that is to say, how it reads,
// writes, and calculates information to achieve a result.
//------------------------------------------------------------------------------



// Run once when the program starts
void setup() {
  left_wheel.attach( 8 );
  right_wheel.attach( 9 );
}



// Run over and over again
void loop() {
  // What do the robot eyes see?  analogRead gives a value from 0 to 1023
  int left_sensor  = analogRead( A0 );
  int right_sensor = analogRead( A1 );

  // Do the eyes see the same thing?
  int difference = left_sensor - right_sensor;
  // If the difference is 0 then they see the same thing.
  // I want range 0 to 128.  More on that in a moment.
  difference /= 16;
  
  // Adjust the wheel speed.  Servo::write() accepts a number from 0 to 255.
  // 127, in the middle, means don't move.  255 is full speed forward.
  left_wheel .write( 127 + difference );
  // The right wheel is backward from the left wheel, so reverse the direction.
  right_wheel.write( 127 - difference );

  // give the brain a short rest to let the servos do their thing.
  delay(50);  // milliseconds
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


