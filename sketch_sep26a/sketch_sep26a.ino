#include <Adafruit_CircuitPlayground.h>
int presets[3][2][3] = {
  {{22, 255, 22}, {255, 22, 22}},
  {{22, 22, 255}, {128, 128, 22}},
  {{255, 22, 22}, {128, 128, 128}}
};
int preset = 0;
//bool lastRightPress = false;
//bool lastLeftPress = false;
bool lastLight =false;
void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();


}

void loop() {
  bool light = CircuitPlayground.lightSensor();
  if (light&&(lastLight==false)) {
    preset=(preset + 1)%3;
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(
        i, presets[preset][i % 2][0], presets[preset][i % 2][1], presets[preset][i % 2][2]);
    }
             Serial.println("lighting");
  }
  lastLight=light;
  //
//bool LeftPress = CircuitPlayground.leftButton();
//    if (LeftPress && (lastLeftPress== false)) {
//      preset=((preset-1)+3)%3;
//    for (int i = 0; i < 10; i++) {
//      CircuitPlayground.setPixelColor(
//        i, presets[preset][i % 2][0], presets[preset][i % 2][1], presets[preset][i % 2][2]);
//    }
//      Serial.println("Left button pressed!");
//    }
//    lastLeftPress = LeftPress;
//
//
//  bool rightPress = CircuitPlayground.rightButton();
//  if (rightPress && (lastRightPress == false)) {
//    preset=(preset + 1)%3;
//    for (int i = 0; i < 10; i++) {
//      CircuitPlayground.setPixelColor(
//        i, presets[preset][i % 2][0], presets[preset][i % 2][1], presets[preset][i % 2][2]);
//    }
//             Serial.println("Right button pressed!");
//  }
//  lastRightPress = rightPress;

//  float acc=abs(CircuitPlayground.motionX())+abs(CircuitPlayground.motionY())+abs(CircuitPlayground.motionZ());
//  if (acc > 25) {
//    preset = rand() % 3;
//    for (int i = 0; i < 10; i++) {
//      CircuitPlayground.setPixelColor(
//        i, presets[preset][i % 2][0], presets[preset][i % 2][1], presets[preset][i % 2][2]);
//    }
//  }
  delay(5);
}
