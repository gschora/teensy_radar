#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>


// GUItool: begin automatically generated code
AudioInputAnalog         audioInput(A1);           //xy=124,104
AudioAnalyzeFFT1024       myFFT;       //xy=326,513
AudioConnection          patchCord1(audioInput,0, myFFT,0);
// GUItool: end automatically generated code

void setup() {
  Serial.begin(57600);
  AudioMemory(12);
  myFFT.windowFunction(AudioWindowHanning1024);
}

void loop() {
  float n;
  int i;

  if (myFFT.available()) {
    // each time new FFT data is available
    // print it all to the Arduino Serial Monitor
    Serial.print("FFT: ");
    for (i=0; i<40; i++) {
      n = myFFT.read(i);
      if (n >= 0.01) {
        Serial.print(n);
        Serial.print(" ");
      } else {
        Serial.print("  -  "); // don't print "0.00"
      }
    }
    Serial.println();
  }

  // delay(100);
}
