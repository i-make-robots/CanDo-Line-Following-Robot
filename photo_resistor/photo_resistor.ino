//------------------------------------------------------------------------------
// CanDo line-following robot
// dan@marginallycelver.com 2012-06-08
// reading a value from a photo resistor
//------------------------------------------------------------------------------
// Copyright at end of file.
// please see http://www.github.com/i-make-robots/CanDo for more information.



//------------------------------------------------------------------------------
// GLOBALS
// Globals are places to store information that can be accessed from anywhere
// in your program.
//------------------------------------------------------------------------------


// the darkest color the eyes have ever seen
int xmin, xmax;


//------------------------------------------------------------------------------
// METHODS
// Methods describe how to do a given job.  Some methods can call others.
//------------------------------------------------------------------------------


// setup is called once when the board resets.
void setup() {
  // Phone the computer to report results.  9600 is how fast to talk.
  Serial.begin(9600);
  xmin=1024;
  xmax=0;
}


// loop is called over and over again after setup is done.
void loop() {
  // Read in what the eyes are seeing.
  int x = analogRead(A0);

  // this is a simple example of using if() to make decisions.
  // for more options, read about "if/else" and "switch".
  if(xmax < x) xmax = x;
  if(xmin > x) xmin = x;

  // if we are connected to the computer, spit out important information to explain what is going on.  
  Serial.print(x);
  Serial.print("\t");
  Serial.print(xmax);
  Serial.print("\t");
  Serial.print(xmin);
  Serial.print("\n");  // same as Serial.println("");
  
  // no nothing for a little while
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


