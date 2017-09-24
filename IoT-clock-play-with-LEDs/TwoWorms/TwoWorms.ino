// teaching do-while using IoT-clock ring shaped LEDs
// introduces modulo for mapping into the 0-59 range

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
  twoWorms();
}

void twoWorms() {
  
  int x = 0;
  int y = 60;

  do {

    fill_solid(leds, NUM_LEDS, CHSV(0,0,0));  // init to black
        
    leds[x] = CRGB::Blue;
    leds[x].fadeLightBy(215);
    
    leds[(x+1)%60] = CRGB::Blue;
    leds[(x+1)%60].fadeLightBy(192);

    leds[(x+2)%60] = CRGB::Blue;
    leds[(x+2)%60].fadeLightBy(128);
    
    leds[(x+3)%60] = CRGB::Blue;

    leds[y] += CRGB::Green;
    leds[y].fadeLightBy(215);
    
    leds[(y-1)%60] += CRGB::Green;
    leds[(y-1)%60].fadeLightBy(192);

    leds[(y-2)%60] += CRGB::Green;
    leds[(y-2)%60].fadeLightBy(128);
    
    leds[(y-3)%60] += CRGB::Green;

    
    FastLED.show();

    FastLED.delay(50);

    x++;
    y--;

   } while (x < 60);
}


