# synthetic-ntc
An esp32 project to synthesize a Negative Temperature Coefficient thermistor using inputs from networked temperature sensors

## Goal
The Honeywell T6 Pro thermostat offers Z-Wave compatibility, giving local control capabilities to platforms such as Home Assistant. As is common in many households, the upstairs temperature differs from the downstairs temperature, where the thermostat is commonly placed. The T6 Pro supports a hardwired remote sensor—the C7189U1005, a NTC thermistor—that can be placed elsewhere in the home, allowing the thermostat to take its temperature from elsewhere in the home. For many Home Assistant users, this is antithetical to their setup of remotely connected sensors. In my specific case, I have Apollo AIR-1 air quality sensors in many rooms, and would prefer automations within Home Assistant provide a temperature to the thermostat instead of a single, static, hardwired sensor.

This project aims to explore building an esp32 device with a digital potentiometer, synthesizing measurements taken by other sensors and converting to the appropriate resistance on the line as a real NTC would do.

This project is currently in the design phase, learning about what is possible with esp32 and ESPHome, the different hardware options there are, and whatever else it may take to make this happen.

