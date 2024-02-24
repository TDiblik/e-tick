#include <Arduino.h>
#include <SPI.h>
#include "watch.h"
#include "debug.h"

#define USE_WATCH_VP_HEAP true

#if USE_WATCH_VP_HEAP
static unsigned char* __virtual_paint_img = (unsigned char*)malloc(sizeof(unsigned char) * 1024);
#else
static unsigned char __virtual_paint_img[1024];
#endif
static Watch watch = Watch(__virtual_paint_img);

void setup() {
  // Setup
  Serial.begin(9600);
  debug_println("Serial connection setup ... done");

  if (__virtual_paint_img == NULL) {
    while (true) {
      Serial.println("Unable to allocate memory for virtual paint. Restart the device!");
      delay(500);
    }
  }
  watch.Setup();

  watch.DrawCircle();
}

void loop() {
  debug_println("lajs");
  delay(500);
}