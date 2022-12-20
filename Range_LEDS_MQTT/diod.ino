#include <FastLED.h>
#define NUM_LEDS 15
#define DATA_PIN 3
#define CLOCK_PIN 13


void setup() { 
    Serial.begin(9600);    
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  
    CRGB leds[NUM_LEDS];
    
}

void loop() { 

  if (Serial.available() > 0){
    char diodStatus = Serial.read();
    if(diodStatus == '1'){
 
      for (int i = 0; i < 15; i++){
        leds[i] = CRGB::Green;
      }
      FastLED.show();
      delay(500); 
    }
    else if(diodStatus == '0'){
    
      for (int i = 0; i < 15; i++){
        leds[i] = CRGB::Black;
      }
      FastLED.show();
      delay(500);
    }
  }
  
}
