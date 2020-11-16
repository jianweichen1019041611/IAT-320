// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>
int presets[3][3] = {
  {225, 50, 0},
  {0, 50, 255},
  {0, 225, 50}
};
int preset = 0;
boolean loundNoice = false;

#define PIN       6 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 4// Popular NeoPixel ring size
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels


void setup() {
  CircuitPlayground.begin();
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
 
  //  Serial.begin(115200);
}

void loop() {
  double spl = CircuitPlayground.mic.soundPressureLevel(100);
  Serial.println(spl);
  pixels.clear(); // Set all pixel colors to 'off'
  if (spl > 85) {
    if (!loundNoice) {
     preset = (preset + 1) % 3;
    }
    
    for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...
      //    pixels.setPixelColor(i,0,0,225);
      pixels.setPixelColor(i, presets[preset][0], presets[preset][1], presets[preset][2]);
//    CircuitPlayground.setPixelColor(i, presets[preset][0], presets[preset][1], presets[preset][2]);

      pixels.show();   // Send the updated pixel colors to the hardware.


     

    }
    loundNoice = true;
  }

  else {
    loundNoice = false;
  }
//delay(DELAYVAL); // Pause before next pass through loop
}
