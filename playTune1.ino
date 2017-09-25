#include "pitches.h"



boolean playTune1(int elapsedTime) {
  //notes for melody 1 (Harry Potter)
  int melody1[] = {NOTE_B5, NOTE_E5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_B6, NOTE_A6, NOTE_FS5, NOTE_E5, NOTE_G5,
                   NOTE_FS5,  NOTE_DS5, NOTE_F5, NOTE_B4, NOTE_B4
                  };
  //note durations for melody 1 (Harry Potter)               
  int noteDurations1[]  = {8, 6, 16, 8, 4, 8, 3, 3, 6, 16,
                           8, 5, 8, 6, 6
                          };
  if (elapsedTime - priorTime > pauseBetweenNotes) { //this is the funciton that replaces the delay. 

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations1[note];
    tone(tonePin, melody1[note], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    pauseBetweenNotes = noteDuration * 1.30;
    priorTime = elapsedTime;
    note = note + 1; //goes to the next note in the melody 

  }

  // Check if done
  if (note == 15) { 

    note = 1;
    priorTime = 0;
    return true;
  }
  else return false;
}

