#include "watch.h"
#include "epd1in54_V2.h"
#include "epdpaint.h"
#include "debug.h"

void Watch::DrawHalfCircle(uint8_t x_start_circle, uint8_t x_start_frame, uint8_t radius) {
    this->_vp.Clear(EPD_WHITE);
    this->_vp.DrawCircle(x_start_circle, Y_MID, radius, EPD_BLACK);
    this->_epd.SetFrameMemory(this->_vp.GetImage(), x_start_frame, Y_0_START, this->_vp.GetWidth(), this->_vp.GetHeight());

    this->_vp.Clear(EPD_WHITE);
    this->_vp.DrawCircle(x_start_circle, Y_1_START, radius, EPD_BLACK);
    this->_epd.SetFrameMemory(this->_vp.GetImage(), x_start_frame, Y_1_START, this->_vp.GetWidth(), this->_vp.GetHeight());

    this->_vp.Clear(EPD_WHITE);
    this->_vp.DrawCircle(x_start_circle, Y_0_START, radius, EPD_BLACK);
    this->_epd.SetFrameMemory(this->_vp.GetImage(), x_start_frame, Y_2_START, this->_vp.GetWidth(), this->_vp.GetHeight());

    this->_vp.Clear(EPD_WHITE);
    this->_vp.DrawCircle(x_start_circle, Y_1_START * -1, radius, EPD_BLACK);
    this->_epd.SetFrameMemory(this->_vp.GetImage(), x_start_frame, Y_3_START, this->_vp.GetWidth(), this->_vp.GetHeight());
}

void Watch::Setup() {
    this->_epd.LDirInit();
    this->_vp.SetWidth(X_SECTOR_SIZE);
    this->_vp.SetHeight(Y_SECTOR_SIZE);
    this->_epd.Clear();
    this->_vp.Clear(EPD_WHITE);
    this->_epd.DisplayFrame();
    debug_println("Watch setup ... done");
}

void Watch::DrawCircle() {
    this->DrawHalfCircle(X_1_START, X_0_START, this->radius);
    this->DrawHalfCircle(X_0_START, X_1_START, this->radius);
    this->_epd.DisplayFrame();
}

void Watch::Sleep() {
    this->_epd.Sleep();
}