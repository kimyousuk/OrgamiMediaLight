#include <Adafruit_NeoPixel.h>
#define LED_PIN    9
#define LED_COUNT 24
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  // put your setup code here, to run once:
  strip.begin();            // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();             // Turn OFF all pixels ASAP
  strip.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
  // put your main code here, to run repeatedly:
  //  strip.setPixelColor(0, strip.Color(255,   0,   0));
  //  strip.setPixelColor(1, strip.Color(  0, 255,   0));
  //  strip.setPixelColor(2, strip.Color(  0,   0, 255));
  //  strip.show();

//    for (int i = 0; i < strip.numPixels(); i += 3) {
//      strip.setPixelColor(i, strip.Color(255,   0,   0));
//      strip.setPixelColor(i + 1, strip.Color(  0, 255,   0));
//      strip.setPixelColor(i + 2, strip.Color(  0,   0, 255));
//    }
//    strip.show();
//
//  for (int i = 0; i < strip.numPixels(); i += 1) {
//    strip.setPixelColor(i, strip.Color(255,   0,   0));
//    strip.setPixelColor(i + 1, strip.Color(255,   0,   0));
//    strip.setPixelColor(i + 2, strip.Color(  0, 255,   0));
//    strip.setPixelColor(i + 3, strip.Color(  0, 255,   0));
//    strip.setPixelColor(i + 4, strip.Color(  0,   0, 255));
//    strip.setPixelColor(i + 5, strip.Color(  0,   0, 255));
//    delay(500);
//     strip.show();
//  }
 
  rainbow(20);
}
void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this outer loop:
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the strip
      // (strip.numPixels() steps):
      int pixelHue = firstPixelHue + (i * 65536 / strip.numPixels());
      // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the single-argument hue variant. The result
      // is passed through strip.gamma32() to provide 'truer' colors
      // before assigning to each pixel:
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}
