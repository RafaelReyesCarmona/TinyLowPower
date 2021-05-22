/*
TinyLowPower_use.ino - Ligth Arduino library for low power.
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


#include <Arduino.h>
#include <TinyLowPower.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Run loop code and at the end enter call TinyLowPower(period).");
  Serial.println("Available Periods:");
  Serial.println("WDTO_15MS, WDTO_30MS, WDTO_60MS, WDTO_120MS, WDTO_250MS,");
  Serial.println("WDTO_500MS, WDTO_1S, WDTO_2S, WDTO_4S, WDTO_8S.");
  Serial.println("-------------------------------------------------------------");
  Serial.println("Enter in Low Power mode (SLEEP_MODE_EXT_STANDBY).");

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
   *
   * Use TinyLowPower at the end of loop() function.
   */
  TinyLowPower(WDTO_120MS);
}
