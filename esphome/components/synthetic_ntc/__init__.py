# https://developers.esphome.io/architecture/components/#minimum-requirements

import esphome.config_validation as cv
import esphome.codegen as cg

from esphome.const import CONF_ID

DOMAIN = "synthetic_ntc"

synthetic_ntc_ns = cg.esphome_ns.namespace("synthetic_ntc")
SyntheticNTC = synthetic_ntc_ns.class_("SyntheticNTC", cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(SyntheticNTC),
})

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])

    await cg.register_component(var, config)
