/*
  BasicJoystick.cpp

  Copyright (c) 2020, Ryan Armstrong

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "BasicJoystick.h"

#if defined(_USING_HID)

static const uint8_t _hidReportDescriptor[] PROGMEM = {
  
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
    0x15, 0x00,                    // LOGICAL_MINIMUM (0)
    0x09, 0x04,                    // USAGE (Joystick)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x85, 0x03,                    //   REPORT_ID (3)
    0x05, 0x01,                    //   USAGE_PAGE (Generic Desktop)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x26, 0xff, 0x00,              //   LOGICAL_MAXIMUM (255)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x09, 0x01,                    //   USAGE (Pointer)
    0xa1, 0x00,                    //   COLLECTION (Physical)
    0x09, 0x30,                    //     USAGE (X)
    0x09, 0x31,                    //     USAGE (Y)
    0x95, 0x02,                    //     REPORT_COUNT (2)
    0x81, 0x02,                    //     INPUT (Data,Var,Abs)
    0xc0,                          //   END_COLLECTION
    0x05, 0x09,                    //   USAGE_PAGE (Button)
    0x19, 0x01,                    //   USAGE_MINIMUM (Button 1)
    0x29, 0x02,                    //   USAGE_MAXIMUM (Button 2)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,                    //   REPORT_SIZE (1)
    0x95, 0x02,                    //   REPORT_COUNT (2)
    0x55, 0x00,                    //   UNIT_EXPONENT (0)
    0x65, 0x00,                    //   UNIT (None)
    0x81, 0x02,                    //   INPUT (Data,Var,Abs)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x75, 0x06,                    //   REPORT_SIZE (6)
    0x81, 0x03,                    //   INPUT (Cnst,Var,Abs)
    0xc0                           // END_COLLECTION
};

//================================================================================
//================================================================================
// BasicJoystick

BasicJoystick_::BasicJoystick_()
{
    static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
    HID().AppendDescriptor(&node);
}


void BasicJoystick_::setState(const JoyState_t & joySt)
{
    HID().SendReport(3, joySt.data, sizeof(JoyState_t));
    // The joystick is specified as using report 3 in the descriptor. That's where the "3" comes from
}


BasicJoystick_ BasicJoystick;

#endif
