#include "stm32f3xx_hal.h"
#include "usb_device.h"
#include "usbd_hid.h"

inline void USB_Send_Key_Press(uint8_t scanCode, uint8_t modifier)
{  
  // Modifier + reserved + 6 keys + ???
  #define USB_HID_KB_REPORT_SIZE 9
  static uint8_t report[USB_HID_KB_REPORT_SIZE];
  
  for (uint32_t i = 0; i < USB_HID_KB_REPORT_SIZE; ++i)
    report[i] = 0;
  
  report[0] = modifier;
  report[2] = (uint8_t)scanCode;
  
  USBD_HID_SendReport(&hUsbDeviceFS, report, USB_HID_KB_REPORT_SIZE);
}

inline void USB_Send_All_Keys_Released()
{  
  USB_Send_Key_Press(0, 0);
}