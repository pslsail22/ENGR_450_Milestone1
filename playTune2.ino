



boolean playTune2(int elapsedTime) {
  //notes for melody 2 (Lost Woods)
  int melody2[] = {NOTE_F5, NOTE_A5, NOTE_B5, NOTE_F5, NOTE_A5, NOTE_B5, NOTE_F5, NOTE_A5, NOTE_B5, NOTE_E6, NOTE_D6, NOTE_B5,
                   NOTE_C6, NOTE_B5, NOTE_G5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_G5, NOTE_E5
                  };
  //note durations for melody 2 (Lost Woods)
  int noteDurations2[] = {8, 8, 4, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 2, 8, 8, 8, 2};


  
  // iterate over the notes of the melody:
  if (elapsedTime - priorTime > pauseBetweenNotes) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations2[note];
    tone(tonePin, melody2[note], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    pauseBetweenNotes = noteDuration * 1.30;
    priorTime = elapsedTime;
    note = note + 1;

  }
  // Check if done
  if (note == 20) {

    note = 1;
    priorTime = 0;
    return true;
  }
  else return false;
}
