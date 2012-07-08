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


// servos go from 0 (full backwards) to 180 (full forwards) but servos
// aren't always 90=no movement.  So here is where you can adjust the
// settings.
#define NO_MOVE_R 92
#define NO_MOVE_L 91

// How fast are we moving forward?
// Set this to zero to test NO_MOVE_* are correct.
#define SPEED 8

// shouldn't have to change this...
#define MOVE_R (NO_MOVE_R+SPEED)
#define MOVE_L (NO_MOVE_L-SPEED)


//------------------------------------------------------------------------------
// GLOBALS
// Globals are places to store information that can be accessed from anywhere
// in your program.
//------------------------------------------------------------------------------


Servo l_wheel;
Servo r_wheel;

// the darkest color the eyes have ever seen
int lmin=1024;
int rmin=1024;

// the brightest color the eyes have ever seen
int lmax=0;
int rmax=0;


//------------------------------------------------------------------------------
// METHODS
// Methods describe how to do a given job.  Some methods can call others.
//------------------------------------------------------------------------------


// setup is called once when the board resets.
void setup() {
  // Phone the computer to report results.  9600 is how fast to talk.
  Serial.begin(9600);
  // Tell the arduino where the wheels are connected.  
  l_wheel.attach(2);
  r_wheel.attach(4);
}


// loop is called over and over again after setup is done.
void loop() {
  // Read in what the eyes are seeing.
  int raw_l_sensor = analogRead(A0);
  int raw_r_sensor = analogRead(A1);

  // adjust for the light in the room
  if(lmax<raw_l_sensor) lmax=raw_l_sensor;
  if(rmax<raw_r_sensor) rmax=raw_r_sensor;
  if(lmin>raw_l_sensor) lmin=raw_l_sensor;
  if(rmin>raw_r_sensor) rmin=raw_r_sensor;

  // adjust the speed of each wheel based on the amount of light in each eye.
  // darker eyes means slower wheels.
  int lval=SPEED*(float)(raw_l_sensor-lmin)/(float)(lmax-lmin);
  int rval=SPEED*(float)(raw_r_sensor-rmin)/(float)(rmax-rmin);
  
  // send the new speed to each wheel.
  l_wheel.write(NO_MOVE_L-lval);
  r_wheel.write(NO_MOVE_R+rval);

  // if we are connected to the computer, spit out important information to explain what is going on.  
  Serial.print(raw_l_sensor);
  Serial.print('\t');
  Serial.print(lmax);
  Serial.print('\t');
  Serial.print(lmin);
  Serial.print('\t');
  Serial.print(lval);
  Serial.print("\t\t");
  Serial.print(raw_r_sensor);
  Serial.print('\t');
  Serial.print(rmax);
  Serial.print('\t');
  Serial.print(rmin);
  Serial.print('\t');
  Serial.print(rval);
  Serial.print('\n');
  
  delay(25);
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


