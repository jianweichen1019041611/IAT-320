#include <Adafruit_CircuitPlayground.h>
 
#define SLOUCH_ANGLE        10.0      
#define SLOUCH_TIME         3000    
#define GRAVITY             9.80665   
#define RAD2DEG             52.29578  
int presets[3][2][3] = {
  {{22, 255, 22}, {255, 22, 22}},
  {{22, 22, 255}, {128, 128, 22}},
  {{255, 22, 22}, {128, 128, 128}}
};
int preset = 0;
 
float currentAngle;
float targetAngle;
unsigned long slouchStartTime;
bool slouching;
 
void setup() {
  CircuitPlayground.begin();
 
  targetAngle = 0;
}
 

void loop() {

  currentAngle = RAD2DEG * asin(-CircuitPlayground.motionZ() / GRAVITY);
 
  if ((CircuitPlayground.leftButton()) || (CircuitPlayground.rightButton())) {
    targetAngle = currentAngle;
    CircuitPlayground.playTone(900,100);
    delay(100);
    CircuitPlayground.playTone(900,100);
    delay(100);
  }
  
  if (currentAngle - targetAngle > SLOUCH_ANGLE) {
    if (!slouching) slouchStartTime = millis();
    slouching =true;
  } else {
    slouching =false;
  }
 
  if (slouching) {
    if (millis() - slouchStartTime > SLOUCH_TIME) {
      // Play a tone
      CircuitPlayground.playTone(800, 500);  
      preset=(preset + 1)%3;
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(
        i, presets[preset][i % 2][0], presets[preset][i % 2][1], presets[preset][i % 2][2]);  
    }    
  }
  }
  }
