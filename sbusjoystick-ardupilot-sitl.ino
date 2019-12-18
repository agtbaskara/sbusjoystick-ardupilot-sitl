#include "Joystick.h"
#include "FUTABA_SBUS.h"

Joystick_ Joystick;
FUTABA_SBUS sbus;

uint16_t channels[12];

void setup() {
  Joystick.setXAxisRange(172, 1811);
  Joystick.setYAxisRange(172, 1811);
  Joystick.setRxAxisRange(172, 1811);
  Joystick.setRyAxisRange(172, 1811);
  Joystick.setZAxisRange(172, 1811);
  Joystick.setRzAxisRange(172, 1811);

  sbus.begin();

  Joystick.begin(false);
}

void loop() {
  sbus.FeedLine();
  if (sbus.toChannels == 1) {
    sbus.UpdateServos();
    sbus.UpdateChannels();
    sbus.toChannels = 0;

    channels[0] = sbus.channels[0];
    channels[1] = sbus.channels[1];
    channels[2] = sbus.channels[2];
    channels[3] = sbus.channels[3];
    channels[4] = sbus.channels[4];
    channels[5] = sbus.channels[5];
    channels[6] = sbus.channels[6];
    channels[7] = sbus.channels[7];
    channels[8] = sbus.channels[8];
    channels[9] = sbus.channels[9];
    channels[10] = sbus.channels[10];
    channels[11] = sbus.channels[11];
  }

  Joystick.setXAxis(channels[0]);
  Joystick.setYAxis(channels[1]);
  Joystick.setRxAxis(channels[2]);
  Joystick.setRyAxis(channels[3]);

  Joystick.setButton(0, channels[4] <= 982);
  Joystick.setButton(1, channels[4] > 982 && channels[4] < 1002);
  Joystick.setButton(2, channels[4] >= 1002);

  Joystick.setButton(3, channels[5] <= 982);
  Joystick.setButton(4, channels[5] > 982 && channels[5] < 1002);
  Joystick.setButton(5, channels[5] >= 1002);

  Joystick.setButton(6, channels[6] <= 982);
  Joystick.setButton(7, channels[6] > 982 && channels[6] < 1002);
  Joystick.setButton(8, channels[6] >= 1002);

  Joystick.setButton(9, channels[7] <= 982);
  Joystick.setButton(10, channels[7] > 982 && channels[7] < 1002);
  Joystick.setButton(11, channels[7] >= 1002);

  Joystick.setButton(12, channels[8] <= 982);
  Joystick.setButton(13, channels[8] >= 1002);

  Joystick.setButton(14 ,channels[9] <= 982);
  Joystick.setButton(15 ,channels[9] >= 1002);

  Joystick.setZAxis(channels[10]);
  Joystick.setRzAxis(channels[11]);
  
  Joystick.sendState();
}