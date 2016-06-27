/******************************************************************
 * SparkFun Inventor's Kit
 * Example sketch 11
 * 
 * BUZZER
 * 
 * This sketch uses the buzzer to play songs.
 * The Arduino's tone() command will play notes of a given frequency.
 * 
 * This sketch was written by SparkFun Electronics,
 * with lots of help from the Arduino community.
 * (This sketch was originally developed by D. Cuartielles for K3)
 * This code is completely free for any use.
 * Visit http://learn.sparkfun.com/products/2 for SIK information.
 * Visit http://www.arduino.cc to learn about the Arduino.
 * 
 * Version 2.0 6/2012 MDG
 * Version 2.1 9/2014 BCH
 *****************************************************************/

/*****************************************************************
 * This sketch uses the tone() command to play notes.
 * 
 * Usage: tone([pin], [frequency]);
 * 
 * note  frequency
 * c     262 Hz
 * d     294 Hz
 * e     330 Hz
 * f     349 Hz
 * g     392 Hz
 * a     440 Hz
 * b     494 Hz
 * C     523 Hz
 * 
 * Other useful commands: noTone([pin]); and delay([time_ms]);
 * 
 * For more information, see http://arduino.cc/en/Tutorial/Tone
 ****************************************************************/

const int buzzerPin = 9;    // connect the buzzer to pin 9 and GND
const int songLength = 18;  // sets the number of notes of the song.

// Notes is an array of text characters corresponding to the notes
// in your song. A space represents a rest (no tone)
//
// Here we introduce an array or a list. Here is an array called notes[] that is
// an array of individual characters. Each character is designated by a ' ' and separated
// by commas. The spaces ' ' represent a rest note.
char notes[songLength] = {
  'c', 'd', 'f', 'd', 'a', ' ', 'a', 'g', ' ', 'c', 'd', 'f', 'd', 'g', ' ', 'g', 'f', ' '}; 

// beats[] is an array of values for each note. A "1" represents a quarter-note, 
// 2 a half-note, etc.
// Don't forget that the rests (spaces) need a length as well.

int beats[songLength] = {
  1, 1, 1, 1, 1, 1, 4, 4, 2, 1, 1, 1, 1, 1, 1, 4, 4, 2};

int tempo = 150;  // The tempo is how fast to play the song.

void setup() 
{
  pinMode(buzzerPin, OUTPUT);  // sets the pin as an OUTPUT
}


void loop() 
{
  int i, duration;

  for (i = 0; i < songLength; i++) // for loop is used to index through the arrays
  {
    duration = beats[i] * tempo;  // length of note/rest in ms

    if (notes[i] == ' ')          // is this a rest? 
      delay(duration);            // then pause for a moment
    else                          // otherwise, play the note
    {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);            // wait for tone to finish
    }
    delay(tempo/10);              // brief pause between notes
  }

  // We only want to play the song once, so we'll pause forever:
  while(true){
  }
  // If you'd like your song to play over and over, remove the while(true)
  // statement above
}


// frequency() is a specially written function takes a note as a character (a-g), 
// and returns the corresponding frequency in Hz for the tone() function.
int frequency(char note) 
{
  int i;
  const int numNotes = 8;  // number of notes we're storing
  char names[numNotes] = { 
    'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'    };
  int frequencies[numNotes] = {
    262, 294, 330, 349, 392, 440, 494, 523    };

  // Now we'll search through the letters in the array, and if
  // we find it, we'll return the frequency for that note.

  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(frequencies[i]);     // Yes! Return the frequency and exit function.
    }
  }
  return(0);  // We looked through everything and didn't find it,
  // but we still need to return a value, so return 0.
}





