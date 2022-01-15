#include <Artnet.h>
#include <NativeEthernet.h>
#include <NativeEthernetUdp.h>
#include <SPI.h>
#include <FastLED.h>


/*
  Possible classes:
  amountOfLeds
  channels
  modus

*/


Artnet artnet;
byte ip[] = {192, 160, 10, 199};
byte broadcast[] = {192, 160, 10, 255};
byte mac[] = {0x04, 0xE9, 0xE5, 0x00, 0x69, 0xEC};
uint16_t universe = 1;

uint8_t dmxData[4] = {0, 0, 0, 0};

// it is critical that you use this pin number or other pin numbers using FastLED's Parallel Output procedure
#define DATA_PIN  7

// Teensy 4.1 Stuff ================
#define NUM_LEDS_PER_STRIP 100
#define NUM_STRIPS 1
#define NUM_LEDS   NUM_LEDS_PER_STRIP
CRGB leds[NUM_LEDS_PER_STRIP * NUM_STRIPS];


void setup()
{
  Serial.begin(115200);
  artnet.begin(mac, ip);
  artnet.setBroadcast(broadcast);

  delay(1000);
  // Teensy 4.1 Stuff ==============
  FastLED.addLeds<NUM_STRIPS, WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS_PER_STRIP);

  FastLED.setBrightness(50);
  //FastLED.setMaxPowerInVoltsAndMilliamps(12, 1500);
  //set_max_power_indicator_LED(13);
  FastLED.setMaxRefreshRate(1200);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
}

void loop()
{
  uint16_t r = artnet.read();
  if (r == ART_POLL)
  {
    Serial.println("POLL");
  }

  if ((r == ART_DMX) && (artnet.getUniverse() == universe))
  {
    Serial.println("ArtNet!");

    //dmxData[0] = artnet.getDmxFrame()[0];
    dmxData[1] = artnet.getDmxFrame()[1];
    dmxData[2] = artnet.getDmxFrame()[2];
    dmxData[3] = artnet.getDmxFrame()[3];

    //dmxData = {artnet.getDmxFrame()[0], artnet.getDmxFrame()[1], artnet.getDmxFrame()[2], artnet.getDmxFrame()[3], artnet.getDmxFrame()[4]};
       //delay(2);

    //FastLED.setBrightness(dmxData[0]);
    fill_solid( leds, NUM_LEDS, CRGB(dmxData[1], dmxData[2], dmxData[3]));
    delay(10);
    FastLED.show();

  }
}