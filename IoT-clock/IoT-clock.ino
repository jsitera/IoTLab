#include "FastLED.h"
#include <Wire.h>
#include "RTClib.h"

FASTLED_USING_NAMESPACE

// Setup of LED ring
#define DATA_PIN    5
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    60
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          96

DateTime now; // actual time to display

// RTC module
// Connection: +5V and GDN, A4 to SDA, A5 to SCL
// Or see https://github.com/adafruit/RTClib
RTC_DS1307 rtc;

void setup() {
  Serial.begin(115200);
  delay(2500);  // Power-up delay
  
  //FastLED init
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  fill_solid(leds, NUM_LEDS, CHSV(0,0,0));  // init to black

  // RTC init - stucks here if not working
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  } 

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT initialized! Setting to compile time.");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  
  getRTCTime();
}

// plot Time into leds array
void time2Leds() { // using global variables
  fill_solid(leds, NUM_LEDS, CHSV(0,0,0));  // init to black

  // hours
  int hourLed = mapf(now.hour()%12+now.minute()*1.0/60,0,12,0,NUM_LEDS);
  leds[hourLed] += CRGB::Blue;
  leds[(hourLed-1)%60] += CRGB::Blue;
  leds[(hourLed-1)%60].fadeLightBy(192);
  leds[(hourLed+1)%60] += CRGB::Blue;
  leds[(hourLed+1)%60].fadeLightBy(192);

  // minutes
  leds[now.minute()] += CRGB::Red;

  // seconds
  leds[now.second()] += CRGB::Green;

  //transform to real setup - LED 29 up, LED 0 down
  CRGB ledsx[NUM_LEDS];
  for(int i = 0; i < NUM_LEDS; i++) {
    ledsx[(i+30)%NUM_LEDS] = leds[i];
  }
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ledsx[i];
  }
  
}

// get time from RTC module and setup time global variable
void getRTCTime() {
  now = rtc.now();
  
  //now = DateTime(2017, 1, 1, 9, 30, 0);
  //now = DateTime(F(__DATE__), F(__TIME__));
}

// called when time changed / update clock now
void secondsChanged () {
  time2Leds();
  FastLED.show();
}

void loop() {
  
  FastLED.show(); // call this every loop or only on the change?
  FastLED.delay(100); // this loop runs ten times per second
  
  EVERY_N_SECONDS( 1 ) { now = now + 1; secondsChanged(); } //call this each second, better on beginning of it
}

double mapf(double val, double in_min, double in_max, double out_min, double out_max) {
    return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


