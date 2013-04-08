/*
  Game of Thrones - Opening Intro
 
  Plays a simple version of the opening credits to Game of Thrones when the button is pressed.
 
 
 The circuit:
 * 330ohm resistor from pin 8 to piezo speaker then speaker to ground
   (you'll want to use a 100ohm resistor here, but I only had a 330) 
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 

 created 2013
 by Sam Brasseale at HobbyChips ( http://hobbychips.com )
 modified from tone tutorial ( http://arduino.cc/en/Tutorial/Tone )
 by by Tom Igoe 2011
 
 */
 
 // pitches.h lists common notes with their respective frequencies
 #include "pitches.h"
 
 
// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

int fireice[] = {
  // Key of Eb
  //  Eb == D#, Bb == A#, Ab == G# 
  // 1
  NOTE_G3, 
  NOTE_C3, 
  // 2
  NOTE_C3, 
  NOTE_F3, 
  NOTE_G3,
  NOTE_C3, 
  NOTE_C3,
  NOTE_DS3, // D# or Eb
  // 3
  NOTE_D3,
  // 4
 
  // 5
  NOTE_F3,
  NOTE_AS2, // A# or Bb
  // 6
  NOTE_AS2,
  NOTE_DS3,
  NOTE_F3,
  NOTE_AS2,
  NOTE_DS3,
  NOTE_D3,
  // 7
  NOTE_C3,
  // 8
  
  // 9 
  NOTE_G3,
  NOTE_C3,
  // 10
  NOTE_C3,
  NOTE_F3,
  NOTE_G3,
  NOTE_C3,
  NOTE_C3,
  NOTE_DS3,
  // 11
  NOTE_D3,
  // 12
  
  // 13
  NOTE_F3,
  NOTE_AS2,
  // 14
  NOTE_D3,
  NOTE_DS3,
  NOTE_D3,
  NOTE_AS2,
  // 15
  NOTE_C3,  
};

// All note durations multiplied by 10 to allow for increased range of duration
int noteDurations[] = {
  // 1 
  20, // DOTTED QUARTER
  20, // DOTTED QUARTER
  // 2 
  80, // EIGHTH 
  80,
  40, // QUARTER
  40, 
  80,
  80, 
  // 3
  10, // DOTTED HALF
  // 4
  
  // 5
  20,
  20,
  // 6 
  80, 
  80,
  40,
  40,
  80,
  80,
  // 7
  10, 
  // 8
  
  // 9
  20,
  20,
  // 10
  80, 
  80,
  40,
  40,
  80,
  80,
  // 11
  10, 
  // 12
  
  // 13
  20,
  20,
  // 14
  70, // Dotted Eighth
  70,
  70,
  70,
  // 15
  10, 
  // 16
  
  // 13
  
  
};
void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == 1) { 
         
    // start tune (Start on note 0, play for 34 notes, then stop:    
    for (int thisNote = 0; thisNote < 34; thisNote++) {

      // Normally to calculate the note duration, take one second 
      // divided by the note type.
      // e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      // I have modified this to allow for greater lengths of notes. 
      // Arduino seems to have a hard time with note fraction note durations using this method, 
      // so I increased the range of note durations available by a factor of 10. 
      // I also extended the timing from 1 second to 1.7 seconds to get the BPM correct
      int noteDuration = 17000/noteDurations[thisNote];
      tone(8, fireice[thisNote], noteDuration);
      
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 20% seems to work well for me:
      int pauseBetweenNotes = noteDuration * 1.20;
      delay(pauseBetweenNotes);
      
      // stop the tone playing:
      noTone(8);
    } 
  }
}
