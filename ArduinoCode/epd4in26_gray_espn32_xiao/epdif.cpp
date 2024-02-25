/**
 *  @filename   :   epdif.cpp
 *  @brief      :   Implements EPD interface functions
 *                  Users have to implement all the functions in epdif.cpp
 *  @author     :   Yehui from Waveshare
 *
 *  Copyright (C) Waveshare     August 10 2017
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documnetation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to  whom the Software is
 * furished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "epdif.h"
#include <SPI.h>

static const int spiClk = 1000000; // 1 MHz

SPIClass *vspi;  
EpdIf::EpdIf() {
};

EpdIf::~EpdIf() {
};

void EpdIf::DigitalWrite(int pin, int value) {
    digitalWrite(pin, value);
}

int EpdIf::DigitalRead(int pin) {
    return digitalRead(pin);
}

void EpdIf::DelayMs(unsigned int delaytime) {
    delay(delaytime);
}

void EpdIf::SpiTransfer(unsigned char data) {
    digitalWrite(CS_PIN, LOW);
    vspi->transfer(data);
    digitalWrite(CS_PIN, HIGH);
}

int EpdIf::IfInit(void) {

  pinMode(PIN_SPI_BUSY,  INPUT);
    pinMode(PIN_SPI_RST , OUTPUT);
    pinMode(PIN_SPI_DC  , OUTPUT);
    
    pinMode(PIN_SPI_SCK, OUTPUT);
    pinMode(PIN_SPI_DIN, OUTPUT);
    pinMode(PIN_SPI_CS , OUTPUT);

    digitalWrite(PIN_SPI_CS , HIGH);
    digitalWrite(PIN_SPI_SCK, LOW);
    

  
    pinMode(CS_PIN, OUTPUT);
    pinMode(RST_PIN, OUTPUT);
    pinMode(DC_PIN, OUTPUT);
    pinMode(BUSY_PIN, INPUT); 

    //SPI.begin ( PIN_SPI_SCK,  MISO_PIN,  PIN_SPI_DIN,  PIN_SPI_CS);
    //SPI.setDataMode(SPI_MODE0);
    //SPI.setClockDivider(SPI_CLOCK_DIV2);
     vspi = new SPIClass(SPI);

     vspi->begin(VSPI_SCLK, VSPI_MISO, VSPI_MOSI, VSPI_SS); //SCLK, MISO, MOSI, SS

     pinMode(vspi->pinSS(), OUTPUT); //VSPI SS
    // vspi->beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
     vspi->setDataMode(SPI_MODE0);
     vspi->setClockDivider(SPI_CLOCK_DIV2);
    
    return 0;
}
