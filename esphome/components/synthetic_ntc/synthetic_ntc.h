#pragma once

#include "esphome/core/component.h"

namespace esphome::synthetic_ntc {

class SyntheticNTC final : public esphome::Component {
    public:
        void setup() override;
        void loop() override;

    private:
        bool setup_mapping();
};

} // namespace esphome::synthetic_ntc
