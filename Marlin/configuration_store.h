/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef CONFIGURATION_STORE_H
#define CONFIGURATION_STORE_H

#include "MarlinConfig.h"

void Config_ResetDefault();
void Config_StoreSettings();


#ifdef OutageTest

static bool RestartFlag=false;
void OutageSave();
void OutageRead();
extern float last_position[4];
extern long last_sd_position[1];
#endif
void SaveMyZoffset();
void ReadMyZoffset();
extern float Current_z_offset;
//extern float last_z_offset[1];
extern float last_z_offset;
extern unsigned char FirstBootFlag;
void SaveFirstBootFlag();
void readFirstBootFlag();

extern float Current_z_offset;
//extern float last_z_offset[1];


extern unsigned char FirstBootFlag;
void SaveFirstBootFlag();
void readFirstBootFlag();

#if DISABLED(DISABLE_M503)
  void Config_PrintSettings(bool forReplay=false);
#else
  FORCE_INLINE void Config_PrintSettings(bool forReplay=false) {}
#endif

#if ENABLED(EEPROM_SETTINGS)
  void Config_RetrieveSettings();
#else
  FORCE_INLINE void Config_RetrieveSettings() { Config_ResetDefault(); Config_PrintSettings(); }
#endif

#endif //CONFIGURATION_STORE_H
