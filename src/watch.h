#ifndef WATCH_H
#define WATCH_H

#include "epd1in54_V2.h"
#include "epdpaint.h"

class Watch {
private:
    Epd _epd;
    Paint _vp;

    void DrawHalfCircle(uint8_t x_start_circle, uint8_t x_start_frame, uint8_t radius);
public:
    static const uint8_t radius = 95;
    Watch(unsigned char* virtual_paint_img) : _epd(Epd()), _vp(Paint(virtual_paint_img, 0, 0)) {};

    void Setup();
    void DrawCircle();
    void Sleep();
};
#endif