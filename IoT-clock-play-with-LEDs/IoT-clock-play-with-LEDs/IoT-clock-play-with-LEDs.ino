// install FastLED (sketch -> include library -> Library manager)
#include "FastLED.h"


FASTLED_USING_NAMESPACE

// Setup of LED ring
#define DATA_PIN    5
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    60
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          32


void setup() {
  Serial.begin(115200);
  delay(1000);  // Power-up delay
  
  //FastLED init
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  fill_solid(leds, NUM_LEDS, CHSV(0,0,0));  // init to black
}


void loop() { 
// uncoment single routine each step

  //singleRotating1();

  singleRotating2();

  //fourRotating();

  //colorWorm();
  
  //worm();
}


void singleRotating1() {

  for(int x = 0; x < 60; x++) {

    leds[x] = CRGB::Blue; // change color here

    FastLED.show();

    FastLED.delay(300); // change speed here

  }
}

void singleRotating2() {

  for(int x = 0; x < 60; x++) {

    leds[x] = CRGB::Blue; // change color here

    FastLED.show();

    FastLED.delay(30); // change speed here

    leds[x] = CRGB::Black;
  
  }
}

void fourRotating() {

  for(int x = 0; x < 60; x++) {

    fill_solid(leds, NUM_LEDS, CHSV(0,0,0));  // init to black

    leds[x] = CRGB::Red; // change color here

    int y = x+15;
    if (y > 59) {
      y = y - 60; 
    }
    leds[y] = CRGB::Red;

    y = x+30;
    if (y > 59) {
      y = y - 60; 
    }
    leds[y] = CRGB::Red;

    y = x+45;
    if (y > 59) {
      y = y - 60; 
    }
    leds[y] = CRGB::Red;

    FastLED.show();

    FastLED.delay(3); // change speed here
  
  }
}




void worm() {

  for(int x = 0; x < 60; x++) {
    
    fill_solid(leds, NUM_LEDS, CHSV(0,0,0));  // init to black
    
    leds[x] = CRGB::Blue;
    leds[x].fadeLightBy(215);
    int y = x+1;
    if (y > 59) {
      y = y - 60; 
    }
    leds[y] = CRGB::Blue;
    leds[y].fadeLightBy(192);

    y = x+2;
    if (y > 59) {
      y = y - 60; 
    }
    leds[y] = CRGB::Blue;
    leds[y].fadeLightBy(128);

    y = x+3;
    if (y > 59) {
      y = y - 60; 
    }
    leds[y] = CRGB::Blue;
    
    FastLED.show();

    FastLED.delay(20);

  }
}

void colorWorm() {

  for(int x = 0; x < 60; x++) {
    
    fill_solid(leds, NUM_LEDS, CHSV(0,0,0));  // init to black
    
    leds[x] = CRGB::Green;
    int y = x+2;
    if (y > 59) {
      y = y - 60; 
    }
    leds[y] = CRGB::Orange;
    
    y = x+4;
    if (y > 59) {
      y = y - 60; 
    }
    leds[y] = CRGB::Red;
    
    y = x+6;
    if (y > 59) {
      y = y - 60; 
    }
    leds[y] = CRGB::Yellow;
    
    FastLED.show();

    FastLED.delay(20);

  }
}

