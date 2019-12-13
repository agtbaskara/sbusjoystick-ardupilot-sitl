# SBUS to USB Converter with Ardupilot SITL Support

## Requirement
- PC with Linux OS (Tested on Ubuntu 18.04)
- RC Transmitter (Tested on Frsky Taranis QX7)
- RC Receiver (Tested on Frsky X8R and FX400R)
- SBUS to USB Converter board (https://oscarliang.com/diy-sbus-usb-converter/)

## Instruction
- Setup Ardupilot SITL (http://ardupilot.org/dev/docs/setting-up-sitl-on-linux.html)
- Configure STM32Duino support (https://github.com/rogerclarkmelbourne/Arduino_STM32/wiki/Installation)
- Install SBUS arduino library (https://github.com/DarrenLouw/SBUS)
- Upload `sbusjoystick-ardupilot-sitl.ino` to the SBUS to USB Converter board
- Copy `sbusjoystick.yml` to `~/.local/lib/python2.7/site-packages/MAVProxy/modules/mavproxy_joystick/joysticks`

## Notes
Channels 1-4 are for Roll, Pitch, Throttle, and Yaw
Channels 5-8 are for 4 Switch (High, Mid, Low)

## Reference
- Source code based on https://github.com/DarrenLouw/SBUS
- Hardware based on https://oscarliang.com/diy-sbus-usb-converter/
- Configuration based on https://github.com/ArduPilot/MAVProxy/blob/master/docs/JOYSTICKS.md