#include <SBUS.h>
#include <USBComposite.h>

USBHID HID;
HIDJoystick Joystick(HID);
SBUS sbus(Serial2);

void setup()
{
  sbus.begin();
  setupTimer2();
  HID.begin(HID_JOYSTICK);
  Joystick.setManualReportMode(true);
}

void loop()
{
    Joystick.X(map(sbus._channels[0], 172, 1811, 0, 1023));
    Joystick.Y(map(sbus._channels[1], 172, 1811, 0, 1023));
    Joystick.Xrotate(map(sbus._channels[2], 172, 1811, 0, 1023));
    Joystick.Yrotate(map(sbus._channels[3], 172, 1811, 0, 1023));
    
    Joystick.button(1,sbus._channels[4] <= 982);
    Joystick.button(2,sbus._channels[4] > 982 && sbus._channels[4] < 1002);
    Joystick.button(3,sbus._channels[4] >= 1002);
    
    Joystick.button(4,sbus._channels[5] <= 982);
    Joystick.button(5,sbus._channels[5] > 982 && sbus._channels[5] < 1002);
    Joystick.button(6,sbus._channels[5] >= 1002);

    Joystick.button(7,sbus._channels[6] <= 982);
    Joystick.button(8,sbus._channels[6] > 982 && sbus._channels[6] < 1002);
    Joystick.button(9,sbus._channels[6] >= 1002);

    Joystick.button(10,sbus._channels[7] <= 982);
    Joystick.button(11,sbus._channels[7] > 982 && sbus._channels[7] < 1002);
    Joystick.button(12,sbus._channels[7] >= 1002);
    
    Joystick.send();
}

void setupTimer2()
{
  Timer2.setMode(TIMER_CH1, TIMER_OUTPUTCOMPARE);
  Timer2.setPeriod(249);
  Timer2.setCompare(TIMER_CH1, 1);
  Timer2.attachInterrupt(TIMER_CH1, sbusProcess);
}

void sbusProcess()
{
  sbus.process();
}
