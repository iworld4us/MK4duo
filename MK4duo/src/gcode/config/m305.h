/**
 * MK4duo 3D Printer Firmware
 *
 * Based on Marlin, Sprinter and grbl
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 * Copyright (C) 2013 - 2017 Alberto Cotronei @MagoKimbra
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * mcode
 *
 * Copyright (C) 2017 Alberto Cotronei @MagoKimbra
 */

#if ENABLED(PIDTEMPCHAMBER)

  #define CODE_M305

  // M305: Set chamber PID parameters P I and D
  inline void gcode_M305(void) {
    if (parser.seen('P')) thermalManager.chamberKp = parser.value_float();
    if (parser.seen('I')) thermalManager.chamberKi = parser.value_float();
    if (parser.seen('D')) thermalManager.chamberKd = parser.value_float();

    thermalManager.updatePID();
    SERIAL_SMV(OK, " p:", thermalManager.chamberKp);
    SERIAL_MV(" i:", thermalManager.chamberKi);
    SERIAL_EMV(" d:", thermalManager.chamberKd);
  }

#endif // NABLED(PIDTEMPCHAMBER)
