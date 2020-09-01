#include <Adafruit_NeoPixel.h>
#define LED_PIN    9          //아두이노에 연결된 네오픽셀 신호선의 디지털핀 번호
#define LED_COUNT 24          //구매한 네오픽셀의 LED 갯수
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  // put your setup code here, to run once:
  strip.begin();            // 네오픽셀 초기화
  strip.show();             // 처음에 검정(꺼짐)으로 설정
  strip.setBrightness(255); // 전체LED의 밝기 최대값은 255
}

void loop() {
  // 각 예제 부분의 주석을 풀고 실해 보아요.
  //  1번 예제
  //  strip.setPixelColor(0, strip.Color(255,   0,   0));
  //  strip.setPixelColor(1, strip.Color(  0, 255,   0));
  //  strip.setPixelColor(2, strip.Color(  0,   0, 255));
  //  strip.show();

  //2번 예제
//    for (int i = 0; i < strip.numPixels(); i += 3) {
//      strip.setPixelColor(i, strip.Color(255,   0,   0));
//      strip.setPixelColor(i + 1, strip.Color(  0, 255,   0));
//      strip.setPixelColor(i + 2, strip.Color(  0,   0, 255));
//    }
//    strip.show();

  // 3번 예제
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
