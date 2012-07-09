//------------------------------------------------------------------------------
// CanDo line-following robot
// dan@marginallycelver.com 2012-06-08
// making a servo move
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
// Globals are places to store information that can be accessed from anywhere
// in your program.
//------------------------------------------------------------------------------


Servo a;


//------------------------------------------------------------------------------
// METHODS
// Methods describe how to do a given job.  Some methods can call others.
//------------------------------------------------------------------------------


// setup is called once when the board resets.
void setup() {
  // Phone the computer to report results.  9600 is how fast to talk.
  Serial.begin(9600);
  // Tell the arduino where the wheels are connected.  
  a.attach(2);
}


// loop is called over and over again after setup is done.
void loop() {
  int i;
  
  // slowly change the speed value of the motor.
  // go all the way from -full speed to +full speed.
  // this is a simple way of doing a loop many times.
  // it goes from 0 to 180 and goes up by one each time.
  // for other options, read about do/while loops.
  for(i=0;i<180;++i) {
    a.write(i);
    Serial.print(rval);
    Serial.print('\n');  
    delay(25);
  }
  // then go back the other way
  for(i=179;i>=0;--i) {
    a.write(i);
    Serial.print(rval);
    Serial.print('\n');  
    delay(20);  // shorter delay means it goes the other way faster.
  }
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


