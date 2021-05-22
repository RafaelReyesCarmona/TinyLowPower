/*
TinyLowPower.h - Ligth Arduino library for low power.
v0.1

Copyright © 2021 Francisco Rafael Reyes Carmona.
All rights reserved.

rafael.reyes.carmona@gmail.com


  This file is part of TinyLowPower Library.

  TinyLowPower Library is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  TinyLowPower Library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with TinyLowPower Library.  If not, see <https://www.gnu.org/licenses/>.

*/

/**
 * Ligth Library for Arduino Enveroment to make low power using STANDBY mode.
 */
#if ARDUINO >= 100
  #include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef TinyLowPower_H
#define TinyLowPower_H

#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/power.h>
#include <avr/interrupt.h>

#ifndef cbi
  #define cbi(sfr, bit)   ((sfr) &= ~(1 << (bit)))
#endif
#ifndef sbi
  #define sbi(sfr, bit)   ((sfr) |= (1 << (bit)))
#endif

/* Periods for TinyLowPower:
 * - WDTO_15MS
 * - WDTO_30MS
 * - WDTO_60MS
 * - WDTO_120MS
 * - WDTO_250MS
 * - WDTO_500MS
 * - WDTO_1S
 * - WDTO_2S
 * - WDTO_4S
 * - WDTO_8S
 */

#define TinyLowPower(period)                  \
  do {                                        \
      wdt_enable(period);                     \
      WDTCSR |= (1 << WDIE);                  \
      set_sleep_mode(SLEEP_MODE_EXT_STANDBY); \
      cli();                                  \
      sleep_enable();                         \
      ADCSRA &= ~(_BV(ADEN));                 \
      sei();                                  \
      sleep_cpu();                            \
      sleep_disable();                        \
      ADCSRA |= _BV(ADEN);                    \
      sei();                                  \
  } while (0);

#endif
