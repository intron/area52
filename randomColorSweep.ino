#include <DmxSimple.h>


void setup() {
  // time between color changes, in ms
  int timer = 5000;
  
  // propagation speed of color across panels, in ms
  int speed = 20;
  
  // average brightness of the random colors
  int brightness = 255;
  
  // starting index of each panel
  int panels[] = {
    79, 82, 85, 88, 91, 94, 97
  };
  
  // read from analog pin to set pseudo-random seed
  randomSeed(analogRead(0));
  
  // helper function to set all three channels of panel
  // assumes consecutive channels correspond to R, G, B
  void setPanelColor(int panel, int R, int G, int B) {
    DmxSimple.write(panel, R);       // Set red channel
    DmxSimple.write(panel + 1, G);   // Set green channel
    DmxSimple.write(panel + 2, B);   // Set blue channel
  }
}



void loop() {
  // set "random" color each time
  // R, G, B channels not actually equally bright
  // so not all colors equally represented
  int R = random(brightness);
  int G = random(brightness);
  int B = random(brightness);
   
  // set all panels to random color 
  for (int thisPanel = 0; thisPanel < sizeof(panels) + 1; thisPanel++) {
    setPanelColor(panels[thisPanel], R, G, B);
    // time for color to "spread" across panels
    delay(speed);
  }
  delay(timer);
}
