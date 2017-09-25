void state3Setup() {
  currentState = 3; //allows the switch statment to know it is in state three
  
}

void state3() {
  //if the buttons where pressed to queue a song this next part of the code will play the current song. 
  unsigned long currentTime = millis();
  
  if (patternPlaying == 1) { 
    done = playTune1(currentTime - patternStartTime);
  }
  if (patternPlaying == 2) { 
    done = playTune2(currentTime - patternStartTime);
  }
  
  if (done == true) { //reads the pattern pending from the button presses in state2
    patternPlaying = patternPending; //redefined the song to play from the song that was queued by the button press. 
    state2Setup(); //goes back to state two to read future possible button presses. 
  }

}
