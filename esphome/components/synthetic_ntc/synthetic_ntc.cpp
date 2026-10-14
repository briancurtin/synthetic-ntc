/*
*/

#include "esphome/core/log.h"
#include "synthetic_ntc.h"

namespace esphome::synthetic_ntc {

// We depend on I2C bus
float SyntheticNTC::get_setup_priority() const {
    return setup_priority::BUS;
}

void SyntheticNTC::setup() {

}

void SyntheticNTC::loop() {

}

bool SyntheticNTC::setup_mapping() {

}

}
