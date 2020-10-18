/*
  BasicJoystick.h

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

#ifndef BASICJOYSTICK_h
#define BASICJOYSTICK_h

#include "HID.h"

#if !defined(_USING_HID)

#warning "Using legacy HID core (non pluggable)"

#else

//================================================================================
//================================================================================
//  Mouse

typedef union JoyState
{
    struct
    {
        uint8_t     xAxis;
        uint8_t     yAxis;
        uint16_t   button_1: 1;
        uint16_t   button_2: 1;
    };
    
    uint8_t data[3];

} JoyState_t;

class BasicJoystick_
{
public:
    BasicJoystick_();

    void setState(const JoyState_t & joySt);
};

extern BasicJoystick_ BasicJoystick;

#endif
#endif
