---
status: proposed
date: 2026-09-30
decision-makers: Brian Curtin <@briancurtin>
consulted: Craig Curtin <@craigcurtin>
---

# Compute resistance for a potentiometer

## Context and Problem Statement

This device must emulate a Negative Temperature Coefficient thermistor by taking
its temperature reading from other sensors and communicating a value back to
the connected thermostat. A real NTC does this by decreasing resistance
on the line as temperature increases.

See [Sensor Specifications](../sensor_specifications.md) for the required
temperature-to-resistance table.

## Decision Drivers

* Push as much to Home Assistant as possible
* Maximize accuracy between device and thermostat

## Considered Options

* Compute return voltage
* Compute resistance for a potentiometer

## Decision Outcome

Chosen option: *Compute resistance for a potentiometer*, because it will result in the simplest, most accurate device.

## Pros and Cons of the Options

### Compute return voltage

Knowing that the thermostat is going to measure the voltage it's getting back, 
providing it with what it needs seemed like a good starting point. I knew that
the external temperature sensor datasheet provided a resistance table
to represent each temperature within the range, though I initially looked
at that more as a variable in computing the voltage than a target value itself.

This is...
* Bad, because it'd cause us to need to compute the resistance relative to
the input voltage to provide the appropriate output voltage, which probably
duplicates work done on the thermostat side and would likely make accuracy
more difficult. Given `V = I x R`, I'd be in control of computing a `R`
to produce the expected `V`<sub>out</sub>, but the thermostat documents `R`
because it's in control of its own `V`<sub>out</sub>, `I`, and knows
the expected `V`<sub>in</sub>. I'd be measuring `V` myself and trying
to replicate it, which could work but is probably harder to do accurately.
Say I expect `V`<sub>in</sub>=`3.3V`, if it's ever 3.25 or the current dips,
my output math would be off which would result in the wrong temperature
being represented.

### Compute resistance for a potentiometer

Given that the resistance table is provided in the datasheet, we can forget about
reading or calculating `V`<sub>in</sub> or `V`<sub>out</sub> by adjusting
the resistance of a potentiometer. A digital potentiometer can set wiper values
that modify resistance in code. Specifically,
the [Adafruit DS1841](https://www.adafruit.com/product/4570) I2C log potentiometer
supports modifying its lookup table to match the mapping we need to support
temperature-to-resistance. The NTC sensor this device will be synthesizing uses
a two-wire system, where the input wire should be connected to the RH terminal
of a DS1841, and the output wire to the RW terminal.

It may be worth looking at ESPHome's
[sensor filtering](https://esphome.io/components/sensor/#to-ntc-resistance-filter)
to handle conversion and mapping. In our case we have the entire mapping from
the spec sheet, so we wouldn't do the same thing in the examples and let it
compute a curve.

This is...
* Good, because it does the least amount of work and relies entirely on setting
the resistance value based on the datasheet. This will provide the closest
representation of the parent sensor device.
