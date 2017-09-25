/* ENGR 450
   Milestone 1
   Button Controlled Buzzer

   created: 1 Sep 2017
   last modified: 8 Sep 2017
   Authors: Parker Lyman & Tim Logan

   Plays tunes on button presses allowing for one pending button
*/
#include "pitches.h"

//constants
const int button1Pin = 3; //defines location of button one
const int button2Pin = 4; //defines location of button two
const int tonePin = 8; //defines location of buzzer

//variables will change:
int currentState; //is the state at which the code currently is 
int patternPlaying; //says which tune pattern is playing
int patternPending; //say which tune pattern is pending 
int thisNote; 
int note = 0; //The note that the tune is on
int priorTime = 0; //The time of the perivous note
int pauseBetweenNotes = 400; //Sets a pause time between notes

unsigned long patternStartTime; //Creates a long number for the start time





void setup() {
  //initialize the button pin as an input
  pinMode(tonePin, OUTPUT);

  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  state1Setup();


}

void loop() {
  switch (currentState) { //This switch statment allows the code to step back and forth between the diffrent states
    case 1:
      //Waiting
      state1();
      break;
    case 2:
      //Playing
      state2();
      break;
    case 3:
      //Pending-Playing
      state3();
      break;
  }

}

