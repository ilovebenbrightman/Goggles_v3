#include <FastLED.h>
#include <Button.h>
#define NUM_LEDS 32
#define DATA_PIN 13  
#define COLOR_ORDER GRB
#define divisor 3

CRGB leds[NUM_LEDS];
int fadeAmount = 2;  // Set the amount to fade I usually do 5, 10, 15, 20, 25 etc even up to 255.
int brightness = 0; 
int speed = .5;
int hold = 50;
void setup()
{
  FastLED.addLeds<WS2812, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  Serial.begin(9600);

}

void loop()
{ 
  int r=0;
  int g=0;
  int b=0;
  
  
  for(r=0;r<5;r++)  // Fill Red,  5 steps * 6 speed = 30*speed seconds
    {
        fill_solid(leds, NUM_LEDS, CRGB(r,g,b));
        FastLED.show();
        delay(speed*6);
    }
    
  delay(hold*4);    // Hold Red before going to next color.  This is multiplied by 4 because it takes less time to fade into red (since it's only iterating up to 5, instead of 200 like the other colours)
  
  for(r=5;r>0;r--)  // Empty Red  5 steps * 40 speed = 200*speed seconds
    {
        fill_solid(leds, NUM_LEDS, CRGB(r,g,b));
        FastLED.show();
        delay(speed*40);
    }
    
  for(g=0;g<100;g++)  // Fill Green   100 steps * 2 speed = 200*speed seconds
    {
        fill_solid(leds, NUM_LEDS, CRGB(r,g,b));
        FastLED.show();
        delay(speed*2);
    }
    
    delay(hold);      // Hold Green before going to next color
  
  for(g=100;g>0;g--)  // Empty Green    100 steps * 2 speed = 200 speed seconds
  {
      fill_solid(leds, NUM_LEDS, CRGB(r,g,b));
      FastLED.show();
      delay(speed*2);
  }
  
  
  for(b=0;b<200;b++)  // Fill Blue  200 steps * 1 speed = 200 speed seconds
  {
      fill_solid(leds, NUM_LEDS, CRGB(r,g,b));
      FastLED.show();
      delay(speed);
  }
  delay(hold);        // Hold Green before going to next color
  
  for(b=200;b>0;b--)  // Empty Blue   200 steps * 1 speed = 200 speed seconds
  {
      fill_solid(leds, NUM_LEDS, CRGB(r,g,b));
      FastLED.show();
      delay(speed);
  }

}

 
