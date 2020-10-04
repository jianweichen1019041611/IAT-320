#include <Adafruit_CircuitPlayground.h>
int vals[8] = {3, 2, 0, 1, 6, 9, 10,12};
float pitches[8]={261.626,293.665,329.628,349.228,391.995,440.0,493.883,523.251};
int presets[3][2][3] = {

  {{255, 22, 22}, {128, 128, 128}},
  {{22, 22, 255}, {128, 128, 22}},
  {{255, 22, 22}, {128, 128, 128}}

  
};
int preset = 0;
//int c = 0;
void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();


}

void loop() {

  
  //CircuitPlayground.playTone(200 + c*100,2000,false);
 for (int i = 0; i < 8; i++) {
  int x = CircuitPlayground.readCap(vals[i]);
  if(x>600){
    CircuitPlayground.playTone(pitches[i],100);
    preset=(preset + 1)%3;
     for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(
        i, presets[preset][i % 2][0], presets[preset][i % 2][1], presets[preset][i % 2][2]);
    }
    }
 }
 //delay(1000);
 
}
