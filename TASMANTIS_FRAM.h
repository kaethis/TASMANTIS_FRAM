#ifndef _TASMANTIS_FRAM_H_

#define _TASMANTIS_FRAM_H_


#include <Arduino.h>

#include "Adafruit_FRAM_I2C.h"

#include "TASMANTIS_Utility.h"

#include "TASMANTIS_FRAM.h"


class TASMANTIS_FRAM { /* ------------------------------------------------------------------------------------------------------
* This CLASS ...
* --------------------------------------------------------------------------------------------------------------------------- */

  public:
    
    TASMANTIS_FRAM(uint8_t);


    bool begin(void)                        { return fram.begin(i2c_addr); }

    void writeByte(uint16_t addr, byte val) { fram.write8(addr, val); }

    void writeInteger(uint16_t, int);

    void writeFloat(uint16_t, float);

    byte readByte(uint16_t addr)            { return fram.read8(addr); }

    int readInteger(uint16_t);

    float readFloat(uint16_t);


  private:

    Adafruit_FRAM_I2C fram;

    uint8_t i2c_addr;
};


#endif /* _TASMANTIS_FRAM_H_ */
