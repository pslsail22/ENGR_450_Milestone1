void state1Setup() {
  currentState = 1; //allows the switch statment to know it is in state one
  patternPlaying = 0; //clears the patternPlaying value
  patternPending = 0; //clears the patternPending value
}
void state1() {
  int button1 = digitalRead(button1Pin); //checks for if button 1 was pressed
  if (button1 == LOW) { //if button one was pressed sets the tune to play to be tune 1 (Harry Potter)
    patternPlaying = 1; 
    state2Setup(); //moves to state2
  }
  int button2 = digitalRead(button2Pin);
  if (button2 == LOW) { //if button two was pressed sets the tune to play to be tune 2 (Lost Woods)
    patternPlaying = 2;
    state2Setup(); //moves to state2
  }
}

