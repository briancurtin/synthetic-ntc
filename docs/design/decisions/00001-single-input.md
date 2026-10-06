---
status: proposed
date: 2026-09-30
decision-makers: <@briancurtin>
---

# Compute temperature from a singular input

## Context and Problem Statement

This device aims to support one or more existing temperature sensors to
synthesize an NTC sensor read by the thermostat. How those devices end up
a part of the calculation could be handled a few different ways. When starting
this project, my knowledge of esp32 and ESPHome was near zero, so I didn't
have an obviously correct way of going about this.

## Decision Drivers

* Push as much to Home Assistant as possible
* Minimize build-time variables
* Maximize accuracy between device and thermostat

## Considered Options

* Collect multiple source readings on-device
* Collect a single input from Home Assistant

## Decision Outcome

Chosen option: *Collect a single input from Home Assistant*, 

### Collect multiple source readings on-device 

One of my first ideas was for this device to be pull-based, pulling temperature
readings from other networked devices. In my particular case, the source devices
are also ESP32s—three Apollo AIR-1s that are connected to Home Assistant via
ESPHome.

This idea only concerned the collection of inputs, not of anything electronic
in producing the output.

This is...
* Good, because the data is neatly available from the devices (in my case)
* Neutral, because while the data is available to consume, building this
specifically for reading from AIR-1s would be unnecessarily limiting.
* Bad, because it increases the amount of configuration needed, either at
build or run time, or both. The nodes need to either be baked in the image,
which would be a hassle for any users, including myself.
* Bad, because any sort of movement of the nodes, such as to a different host
name or IP, reduces the accuracy of any output by this device since it would
not be acting on all of the inputs needed to properly evaluate the temperature.

### Collect a single input from Home Assistant

In following the principle of pushing the most to Home Assistant, letting
HA coordinate the participating temperature devices and having it compute
a value between them is likely the better approach.

This is...
* Good, because it pushes device coordination to HA. No build or runtime settings
need to change if a device is added, removed, or unreachable.
* Good, because it can leverage HA's automations. For example, I currently
have an "Upstairs Temperature" helper sensor which was created as with
the "Combine the state of several sensors" setting. This synthetic sensor
determines the median temperature of three SEN55 temperature sensors
(via Apollo AIR-1). Right away this is the single value I want to be reaching
the thermostat via this device.
