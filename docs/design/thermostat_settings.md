# Thermostat Settings

The following are some project-relevant details from the
"T6 Pro Z-Wave™ Programmable Thermostat — Professional Install Guide" documentation.
Only the TH6320ZW2007 model is being used during development.

The official documentation should be considered the true source of information.
This information is provided for reference purposes only.

# Wiring

This device should be connected via 18/2 thermostat wire to the two `S` terminals
on the back of the thermostat.

# Installer setup options

In the `Advanced` menu, the `Device Setup` area requires the following options
to be set:

| ISU # | ISU Name            | Value        | Notes               |
|------:|:--------------------|:-------------|:--------------------|
| 130   | Outdoor Temp        | No           | Only one sensor type is supported, and this project is indoor only. | 
| 500   | Indoor Sensor       | Yes          | Displays only when 130 is **No** | 
| 515   | Sensor type         | 10k          | Displays only when 500 is **Yes**. This project is not designed for the 20k sensor. |
| 520   | Temperature Control | See below    | |

## Temperature Control option

ISU 520 supports three options, which are up to you. This project provides the 
sensor support, but how you want to use the sensor with your thermostat depends
on your own need.

* **Thermostat** bypasses the sensor reading and uses only the thermostat's reading. You probably don't want this if you're here.
* **Wired** uses only the sensor's reading.
* **Average** (default) averages the thermostat's reading with the sensor's reading.
