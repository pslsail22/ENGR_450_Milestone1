void state2Setup() {
  currentState = 2; //allows the switch statment to know it is in state two
  patternStartTime = millis(); //begins counting the start time
}
boolean done;
void state2() {
  if (note > 2) { //to avoid debounce issues only looks for button presses to queue if the first song is already on the second note
    int button1 = digitalRead(button1Pin); 
    if (button1 == LOW) { 
      patternPending = 1; //sets the pending pattern to tune 1
      state3Setup(); //moves to state3
    }
    int button2 = digitalRead(button2Pin);
    if (button2 == LOW) {
      patternPending = 2; //sets the pending pattern to tune 2
      state3Setup(); //moves to state3
    }
  }
  //if there are not button presses for a second tune to play this next part of the code will play the tunes. 
  unsigned long currentTime = millis(); //sets the current time to be used in the playTune functions
  if (patternPlaying == 1) { //if the tune to play was 1 it will play Harry Potter
    done = playTune1(currentTime - patternStartTime);
  }
  if (patternPlaying == 2) { //if the tune to play was 2 it will play Lost Woods
    done = playTune2(currentTime - patternStartTime);
  }
  if (done == true) { //if the tune playing is done it will go back to state1 the waiting state. 
    state1Setup();
  }

}






