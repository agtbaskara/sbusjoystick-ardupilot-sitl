# SBUS to USB Joystick Converter with Ardupilot SITL Support

## Requirement
- PC with Linux OS (Tested on Ubuntu 18.04)
- RC Transmitter (Tested on Frsky Taranis QX7)
- SBUS RC Receiver (Tested on Frsky X8R and FX400R)
- Arduino Pro Micro (or another ATmega32U4 based Arduino)
- SBUS Inverter (DIY Schematic and PCB design file in repository)

## Setup Instruction
- Install Arduino Joystick Library library (https://github.com/MHeironimus/ArduinoJoystickLibrary)
- Install this fork of FUTABA_SBUS library (https://github.com/agtbaskara/FUTABA_SBUS)
- Upload `sbusjoystick-ardupilot-sitl.ino` to Arduino
- (Optional) for Ardupilot SITL support copy `sbusjoystick.yml` to `~/.local/lib/python2.7/site-packages/MAVProxy/modules/mavproxy_joystick/joysticks`

## Button Mapping:
- Axis 0: Channel 0
- Axis 1: Channel 1
- Axis 2: Channel 10
- Axis 3: Channel 2
- Axis 4: Channel 3
- Axis 5: Channel 11
- Button 0: Channel 4 Low
- Button 1: Channel 4 Mid
- Button 2: Channel 4 High
- Button 3: Channel 5 Low
- Button 4: Channel 5 Mid
- Button 5: Channel 5 High
- Button 6: Channel 6 Low
- Button 7: Channel 6 Mid
- Button 8: Channel 6 High
- Button 9: Channel 7 Low
- Button 10: Channel 7 Mid
- Button 11: Channel 7 High
- Button 12: Channel 8 Low
- Button 13: Channel 8 High
- Button 14: Channel 9 Low
- Button 15: Channel 9 High

## To Do
- Add PPM RC Receiver Support

## Reference
- Source code based on https://github.com/Robinhuett/sbuscontroller, https://github.com/mikeshub/FUTABA_SBUS, and https://github.com/MHeironimus/ArduinoJoystickLibrary
- Hardware design based on https://oscarliang.com/diy-sbus-usb-converter/
- Configuration based on https://github.com/ArduPilot/MAVProxy/blob/master/docs/JOYSTICKS.md