#include "TASMANTIS_FRAM.h"


TASMANTIS_FRAM::TASMANTIS_FRAM(uint8_t i2c_addr) { /* --------------------------------------------------------------------------
* This CONSTRUCTOR ...
* --------------------------------------------------------------------------------------------------------------------------- */

    this->i2c_addr = i2c_addr;


    fram = Adafruit_FRAM_I2C();
}


void TASMANTIS_FRAM::writeInteger(uint16_t addr, int val) { /* -----------------------------------------------------------------
* This FUNCTION ...
* --------------------------------------------------------------------------------------------------------------------------- */

    TASMANTIS_Utility::intunion_t v;


    v.i = val;

    for (int i = 0; i < 2; i++) writeByte((addr + i), v.b[i]);
}


void TASMANTIS_FRAM::writeFloat(uint16_t addr, float val) { /* -----------------------------------------------------------------
* This FUNCTION ...
* --------------------------------------------------------------------------------------------------------------------------- */

    TASMANTIS_Utility::floatunion_t v;


    v.f = val;

    for (int i = 0; i < 4; i++) writeByte((addr + i), v.b[i]);
}


int TASMANTIS_FRAM::readInteger(uint16_t addr) { /* ----------------------------------------------------------------------------
* This FUNCTION ...
* --------------------------------------------------------------------------------------------------------------------------- */

    TASMANTIS_Utility::intunion_t v;


    for (int i = 0; i < 2; i++) v.b[i] = readByte(addr + i);

    return v.i;
}


float TASMANTIS_FRAM::readFloat(uint16_t addr) { /* ----------------------------------------------------------------------------
* This FUNCTION ...
* --------------------------------------------------------------------------------------------------------------------------- */

    TASMANTIS_Utility::floatunion_t v;


    for (int i = 0; i < 4; i++) v.b[i] = readByte(addr + i);

    return v.f;
}
