/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Configuration.h
 *
 * Basic settings such as:
 *
 * - Type of electronics
 * - Type of temperature sensor
 * - Printer geometry
 * - Endstop configuration
 * - LCD controller
 * - Extra features
 *
 * Advanced settings can be found in Configuration_adv.h
 */
#define CONFIGURATION_H_VERSION 02010300

//===========================================================================
//============================= Getting Started =============================
//===========================================================================

/**
 * Here are some useful links to help get your machine configured and calibrated:
 *
 * Example Configs:     https://github.com/MarlinFirmware/Configurations/branches/all
 *
 * Průša Calculator:    https://blog.prusa3d.com/calculator_3416/
 *
 * Calibration Guides:  https://reprap.org/wiki/Calibration
 *                      https://reprap.org/wiki/Triffid_Hunter%27s_Calibration_Guide
 *                      https://web.archive.org/web/20220907014303/sites.google.com/site/repraplogphase/calibration-of-your-reprap
 *                      https://youtu.be/wAL9d7FgInk
 *                      https://teachingtechyt.github.io/calibration.html
 *
 * Calibration Objects: https://www.thingiverse.com/thing:5573
 *                      https://www.thingiverse.com/thing:1278865
 */

// @section info

// Author info of this build printed to the host during boot and M115
#define STRING_CONFIG_H_AUTHOR "(Erik Eldridge)" // Original author or contributor.
//#define CUSTOM_VERSION_FILE Version.h // Path from the root directory (no quotes)

// @section machine

// Choose the name from boards.h that matches your setup
#ifndef MOTHERBOARD
  #define MOTHERBOARD teensy4.1
#endif

// @section serial

/**
 * Select the serial port on the board to use for communication with the host.
 * This allows the connection of wireless adapters (for instance) to non-default port pins.
 * Serial port -1 is the USB emulated serial port, if available.
 * Note: The first serial port (-1 or 0) will always be used by the Arduino bootloader.
 *
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
 */
#define SERIAL_PORT 0

/**
 * Serial Port Baud Rate
 * This is the default communication speed for all serial ports.
 * Set the baud rate defaults for additional serial ports below.
 *
 * 250000 works in most cases, but you might try a lower speed if
 * you commonly experience drop-outs during host printing.
 * You may try up to 1000000 to speed up SD file transfer.
 *
 * :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000]
 */
#define BAUDRATE 250000

//#define BAUD_RATE_GCODE     // Enable G-code M575 to set the baud rate

/**
 * Select a secondary serial port on the board to use for communication with the host.
 * Currently Ethernet (-2) is only supported on Teensy 4.1 boards.
 * :[-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
 */
//#define SERIAL_PORT_2 -1
//#define BAUDRATE_2 250000   // :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000] Enable to override BAUDRATE

/**
 * Select a third serial port on the board to use for communication with the host.
 * Currently supported for AVR, DUE, SAMD51, LPC1768/9, STM32/STM32F1/HC32, and Teensy 4.x
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
 */
//#define SERIAL_PORT_3 1
//#define BAUDRATE_3 250000   // :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000] Enable to override BAUDRATE

/**
 * Select a serial port to communicate with RS485 protocol
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
 */
//#define RS485_SERIAL_PORT 1
#ifdef RS485_SERIAL_PORT
  //#define M485_PROTOCOL 1   // Check your host for protocol compatibility
  //#define RS485_BUS_BUFFER_SIZE 128
#endif

// Enable the Bluetooth serial interface on AT90USB devices
//#define BLUETOOTH

// Name displayed in the LCD "Ready" message and Info menu
//#define CUSTOM_MACHINE_NAME "3D Printer"
//#define CONFIGURABLE_MACHINE_NAME // Add G-code M550 to set/report the machine name

// Printer's unique ID, used by some programs to differentiate between machines.
// Choose your own or use a service like https://www.uuidgenerator.net/version4
//#define MACHINE_UUID "00000000-0000-0000-0000-000000000000"

// @section stepper drivers

/**
 * Stepper Drivers
 *
 * These settings allow Marlin to tune stepper driver timing and enable advanced options for
 * stepper drivers that support them. You may also override timing options in Configuration_adv.h.
 *
 * Use TMC2208/TMC2208_STANDALONE for TMC2225 drivers and TMC2209/TMC2209_STANDALONE for TMC2226 drivers.
 *
 * Options: A4988, A5984, DRV8825, LV8729, TB6560, TB6600, TMC2100,
 *          TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
 *          TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
 *          TMC2660, TMC2660_STANDALONE, TMC5130, TMC5130_STANDALONE,
 *          TMC5160, TMC5160_STANDALONE
 * :['A4988', 'A5984', 'DRV8825', 'LV8729', 'TB6560', 'TB6600', 'TMC2100', 'TMC2130', 'TMC2130_STANDALONE', 'TMC2160', 'TMC2160_STANDALONE', 'TMC2208', 'TMC2208_STANDALONE', 'TMC2209', 'TMC2209_STANDALONE', 'TMC2660', 'TMC2660_STANDALONE', 'TMC5130', 'TMC5130_STANDALONE', 'TMC5160', 'TMC5160_STANDALONE']
 */
#define X_DRIVER_TYPE  A4988
#define Y_DRIVER_TYPE  A4988
//#define Z_DRIVER_TYPE  A4988
//#define X2_DRIVER_TYPE A4988
//#define Y2_DRIVER_TYPE A4988
//#define Z2_DRIVER_TYPE A4988
//#define Z3_DRIVER_TYPE A4988
//#define Z4_DRIVER_TYPE A4988
//#define I_DRIVER_TYPE  A4988
//#define J_DRIVER_TYPE  A4988
//#define K_DRIVER_TYPE  A4988
//#define U_DRIVER_TYPE  A4988
//#define V_DRIVER_TYPE  A4988
//#define W_DRIVER_TYPE  A4988
//#define E0_DRIVER_TYPE A4988
//#define E1_DRIVER_TYPE A4988
//#define E2_DRIVER_TYPE A4988
//#define E3_DRIVER_TYPE A4988
//#define E4_DRIVER_TYPE A4988
//#define E5_DRIVER_TYPE A4988
//#define E6_DRIVER_TYPE A4988
//#define E7_DRIVER_TYPE A4988

/**
 * Additional Axis Settings
 *
 * Define AXISn_ROTATES for all axes that rotate or pivot.
 * Rotational axis coordinates are expressed in degrees.
 *
 * AXISn_NAME defines the letter used to refer to the axis in (most) G-code commands.
 * By convention the names and roles are typically:
 *   'A' : Rotational axis parallel to X
 *   'B' : Rotational axis parallel to Y
 *   'C' : Rotational axis parallel to Z
 *   'U' : Secondary linear axis parallel to X
 *   'V' : Secondary linear axis parallel to Y
 *   'W' : Secondary linear axis parallel to Z
 *
 * Regardless of these settings the axes are internally named I, J, K, U, V, W.
 */
#ifdef I_DRIVER_TYPE
  #define AXIS4_NAME 'A' // :['A', 'B', 'C', 'U', 'V', 'W']
  #define AXIS4_ROTATES
#endif
#ifdef J_DRIVER_TYPE
  #define AXIS5_NAME 'B' // :['B', 'C', 'U', 'V', 'W']
  #define AXIS5_ROTATES
#endif
#ifdef K_DRIVER_TYPE
  #define AXIS6_NAME 'C' // :['C', 'U', 'V', 'W']
  #define AXIS6_ROTATES
#endif
#ifdef U_DRIVER_TYPE
  #define AXIS7_NAME 'U' // :['U', 'V', 'W']
  //#define AXIS7_ROTATES
#endif
#ifdef V_DRIVER_TYPE
  #define AXIS8_NAME 'V' // :['V', 'W']
  //#define AXIS8_ROTATES
#endif
#ifdef W_DRIVER_TYPE
  #define AXIS9_NAME 'W' // :['W']
  //#define AXIS9_ROTATES
#endif

// @section extruder

// This defines the number of extruders
// :[0, 1, 2, 3, 4, 5, 6, 7, 8]
#define EXTRUDERS 0

// Generally expected filament diameter (1.75, 2.85, 3.0, ...). Used for Volumetric, Filament Width Sensor, etc.
#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75


//===========================================================================
//============================= Mechanical Settings =========================
//===========================================================================

// @section kinematics

// @section scara

/**
 * MORGAN_SCARA was developed by QHARLEY in South Africa in 2012-2013.
 * Implemented and slightly reworked by JCERNY in June, 2014.
 *
 * Mostly Printed SCARA is an open source design by Tyler Williams. See:
 *   https://www.thingiverse.com/thing:2487048
 *   https://www.thingiverse.com/thing:1241491
 */
#define MORGAN_SCARA
//#define MP_SCARA
#if ANY(MORGAN_SCARA, MP_SCARA)
  // If movement is choppy try lowering this value
  #define DEFAULT_SEGMENTS_PER_SECOND 200

  // Length of inner and outer support arms. Measure arm lengths precisely.
  #define SCARA_LINKAGE_1 100       // (mm)
  #define SCARA_LINKAGE_2 120       // (mm)

  // SCARA tower offset (position of Tower relative to bed zero position)
  // This needs to be reasonably accurate as it defines the printbed position in the SCARA space.
  #define SCARA_OFFSET_X  0       // (mm)
  #define SCARA_OFFSET_Y  100       // (mm)

  #if ENABLED(MORGAN_SCARA)

    //#define DEBUG_SCARA_KINEMATICS
    #define FEEDRATE_SCALING        // Convert XY feedrate from mm/s to degrees/s on the fly

    // Radius around the center where the arm cannot reach
    #define MIDDLE_DEAD_ZONE_R   0  // (mm)

#endif

//===========================================================================
//============================== Endstop Settings ===========================
//===========================================================================

// @section endstops

// Enable pullup for all endstops to prevent a floating state
#define ENDSTOPPULLUPS
#if DISABLED(ENDSTOPPULLUPS)
  // Disable ENDSTOPPULLUPS to set pullups individually
  //#define ENDSTOPPULLUP_XMIN
  //#define ENDSTOPPULLUP_YMIN
  //#define ENDSTOPPULLUP_ZMIN
  //#define ENDSTOPPULLUP_IMIN
  //#define ENDSTOPPULLUP_JMIN
  //#define ENDSTOPPULLUP_KMIN
  //#define ENDSTOPPULLUP_UMIN
  //#define ENDSTOPPULLUP_VMIN
  //#define ENDSTOPPULLUP_WMIN
  //#define ENDSTOPPULLUP_XMAX
  //#define ENDSTOPPULLUP_YMAX
  //#define ENDSTOPPULLUP_ZMAX
  //#define ENDSTOPPULLUP_IMAX
  //#define ENDSTOPPULLUP_JMAX
  //#define ENDSTOPPULLUP_KMAX
  //#define ENDSTOPPULLUP_UMAX
  //#define ENDSTOPPULLUP_VMAX
  //#define ENDSTOPPULLUP_WMAX
  //#define ENDSTOPPULLUP_ZMIN_PROBE
#endif

// Enable pulldown for all endstops to prevent a floating state
//#define ENDSTOPPULLDOWNS
#if DISABLED(ENDSTOPPULLDOWNS)
  // Disable ENDSTOPPULLDOWNS to set pulldowns individually
  //#define ENDSTOPPULLDOWN_XMIN
  //#define ENDSTOPPULLDOWN_YMIN
  //#define ENDSTOPPULLDOWN_ZMIN
  //#define ENDSTOPPULLDOWN_IMIN
  //#define ENDSTOPPULLDOWN_JMIN
  //#define ENDSTOPPULLDOWN_KMIN
  //#define ENDSTOPPULLDOWN_UMIN
  //#define ENDSTOPPULLDOWN_VMIN
  //#define ENDSTOPPULLDOWN_WMIN
  //#define ENDSTOPPULLDOWN_XMAX
  //#define ENDSTOPPULLDOWN_YMAX
  //#define ENDSTOPPULLDOWN_ZMAX
  //#define ENDSTOPPULLDOWN_IMAX
  //#define ENDSTOPPULLDOWN_JMAX
  //#define ENDSTOPPULLDOWN_KMAX
  //#define ENDSTOPPULLDOWN_UMAX
  //#define ENDSTOPPULLDOWN_VMAX
  //#define ENDSTOPPULLDOWN_WMAX
  //#define ENDSTOPPULLDOWN_ZMIN_PROBE
#endif

/**
 * Endstop "Hit" State
 * Set to the state (HIGH or LOW) that applies to each endstop.
 */
#define X_MIN_ENDSTOP_HIT_STATE HIGH
#define X_MAX_ENDSTOP_HIT_STATE HIGH
#define Y_MIN_ENDSTOP_HIT_STATE HIGH
#define Y_MAX_ENDSTOP_HIT_STATE HIGH
#define Z_MIN_ENDSTOP_HIT_STATE HIGH
#define Z_MAX_ENDSTOP_HIT_STATE HIGH
#define I_MIN_ENDSTOP_HIT_STATE HIGH
#define I_MAX_ENDSTOP_HIT_STATE HIGH
#define J_MIN_ENDSTOP_HIT_STATE HIGH
#define J_MAX_ENDSTOP_HIT_STATE HIGH
#define K_MIN_ENDSTOP_HIT_STATE HIGH
#define K_MAX_ENDSTOP_HIT_STATE HIGH
#define U_MIN_ENDSTOP_HIT_STATE HIGH
#define U_MAX_ENDSTOP_HIT_STATE HIGH
#define V_MIN_ENDSTOP_HIT_STATE HIGH
#define V_MAX_ENDSTOP_HIT_STATE HIGH
#define W_MIN_ENDSTOP_HIT_STATE HIGH
#define W_MAX_ENDSTOP_HIT_STATE HIGH
#define Z_MIN_PROBE_ENDSTOP_HIT_STATE HIGH

// Enable this feature if all enabled endstop pins are interrupt-capable.
// This will remove the need to poll the interrupt pins, saving many CPU cycles.
//#define ENDSTOP_INTERRUPTS_FEATURE

/**
 * Endstop Noise Threshold
 *
 * Enable if your probe or endstops falsely trigger due to noise.
 *
 * - Higher values may affect repeatability or accuracy of some bed probes.
 * - To fix noise install a 100nF ceramic capacitor in parallel with the switch.
 * - This feature is not required for common micro-switches mounted on PCBs
 *   based on the Makerbot design, which already have the 100nF capacitor.
 *
 * :[2,3,4,5,6,7]
 */
//#define ENDSTOP_NOISE_THRESHOLD 2

// Check for stuck or disconnected endstops during homing moves.
//#define DETECT_BROKEN_ENDSTOP

//=============================================================================
//============================== Movement Settings ============================
//=============================================================================
// @section motion

/**
 * Default Settings
 *
 * These settings can be reset by M502
 *
 * Note that if EEPROM is enabled, saved values will override these.
 */

/**
 * With this option each E stepper can have its own factors for the
 * following movement settings. If fewer factors are given than the
 * total number of extruders, the last value applies to the rest.
 */
//#define DISTINCT_E_FACTORS

/**
 * Default Axis Steps Per Unit (linear=steps/mm, rotational=steps/°)
 * Override with M92 (when enabled below)
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 */
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 3200, 3200, 0, 0 }

/**
 * Enable support for M92. Disable to save at least ~530 bytes of flash.
 */
#define EDITABLE_STEPS_PER_UNIT

/**
 * Default Max Feed Rate (linear=mm/s, rotational=°/s)
 * Override with M203
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 */
#define DEFAULT_MAX_FEEDRATE          { 300, 300, 5, 25 }

//#define LIMITED_MAX_FR_EDITING        // Limit edit via M203 or LCD to DEFAULT_MAX_FEEDRATE * 2
#if ENABLED(LIMITED_MAX_FR_EDITING)
  #define MAX_FEEDRATE_EDIT_VALUES    { 600, 600, 10, 50 } // ...or, set your own edit limits
#endif

/**
 * Default Max Acceleration (speed change with time) (linear=mm/(s^2), rotational=°/(s^2))
 * (Maximum start speed for accelerated moves)
 * Override with M201
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 */
#define DEFAULT_MAX_ACCELERATION      { 3000, 3000, 100, 10000 }

//#define LIMITED_MAX_ACCEL_EDITING     // Limit edit via M201 or LCD to DEFAULT_MAX_ACCELERATION * 2
#if ENABLED(LIMITED_MAX_ACCEL_EDITING)
  #define MAX_ACCEL_EDIT_VALUES       { 6000, 6000, 200, 20000 } // ...or, set your own edit limits
#endif

/**
 * Default Acceleration (speed change with time) (linear=mm/(s^2), rotational=°/(s^2))
 * Override with M204
 *
 *   M204 P    Acceleration
 *   M204 R    Retract Acceleration
 *   M204 T    Travel Acceleration
 */
#define DEFAULT_ACCELERATION          3000    // X, Y, Z and E acceleration for printing moves
#define DEFAULT_RETRACT_ACCELERATION  3000    // E acceleration for retracts
#define DEFAULT_TRAVEL_ACCELERATION   3000    // X, Y, Z acceleration for travel (non printing) moves

/**
 * Default Jerk limits (mm/s)
 * Override with M205 X Y Z . . . E
 *
 * "Jerk" specifies the minimum speed change that requires acceleration.
 * When changing speed and direction, if the difference is less than the
 * value set here, it may happen instantaneously.
 */
//#define CLASSIC_JERK
#if ENABLED(CLASSIC_JERK)
  #define DEFAULT_XJERK 10.0
  #define DEFAULT_YJERK 10.0
  #define DEFAULT_ZJERK  0.3
  #define DEFAULT_EJERK  5.0
  //#define DEFAULT_IJERK  0.3
  //#define DEFAULT_JJERK  0.3
  //#define DEFAULT_KJERK  0.3
  //#define DEFAULT_UJERK  0.3
  //#define DEFAULT_VJERK  0.3
  //#define DEFAULT_WJERK  0.3

  //#define TRAVEL_EXTRA_XYJERK 0.0     // Additional jerk allowance for all travel moves

  //#define LIMITED_JERK_EDITING        // Limit edit via M205 or LCD to DEFAULT_aJERK * 2
  #if ENABLED(LIMITED_JERK_EDITING)
    #define MAX_JERK_EDIT_VALUES { 20, 20, 0.6, 10 } // ...or, set your own edit limits
  #endif
#endif

/**
 * Junction Deviation Factor
 *
 * See:
 *   https://reprap.org/forum/read.php?1,739819
 *   https://blog.kyneticcnc.com/2018/10/computing-junction-deviation-for-marlin.html
 */
#if DISABLED(CLASSIC_JERK)
  #define JUNCTION_DEVIATION_MM 0.013 // (mm) Distance from real junction edge
  #define JD_HANDLE_SMALL_SEGMENTS    // Use curvature estimation instead of just the junction angle
                                      // for small segments (< 1mm) with large junction angles (> 135°).
#endif

/**
 * S-Curve Acceleration
 *
 * This option eliminates vibration during printing by fitting a Bézier
 * curve to move acceleration, producing much smoother direction changes.
 *
 * See https://github.com/synthetos/TinyG/wiki/Jerk-Controlled-Motion-Explained
 */
#define S_CURVE_ACCELERATION

//===========================================================================
//============================= Z Probe Options =============================
//===========================================================================

// @section stepper drivers

// For Inverting Stepper Enable Pins (Active Low) use 0, Non Inverting (Active High) use 1
// :['LOW', 'HIGH']
#define X_ENABLE_ON LOW
#define Y_ENABLE_ON LOW
#define Z_ENABLE_ON LOW
#define E_ENABLE_ON LOW // For all extruders
//#define I_ENABLE_ON LOW
//#define J_ENABLE_ON LOW
//#define K_ENABLE_ON LOW
//#define U_ENABLE_ON LOW
//#define V_ENABLE_ON LOW
//#define W_ENABLE_ON LOW

// Disable axis steppers immediately when they're not being stepped.
// WARNING: When motors turn off there is a chance of losing position accuracy!
//#define DISABLE_X
//#define DISABLE_Y
//#define DISABLE_Z
//#define DISABLE_I
//#define DISABLE_J
//#define DISABLE_K
//#define DISABLE_U
//#define DISABLE_V
//#define DISABLE_W

// Turn off the display blinking that warns about possible accuracy reduction
//#define DISABLE_REDUCED_ACCURACY_WARNING

// @section extruder

//#define DISABLE_E               // Disable the extruder when not stepping
#define DISABLE_OTHER_EXTRUDERS   // Keep only the active extruder enabled

// @section motion

// Invert the stepper direction. Change (or reverse the motor connector) if an axis goes the wrong way.
#define INVERT_X_DIR false
#define INVERT_Y_DIR true
#define INVERT_Z_DIR false
//#define INVERT_I_DIR false
//#define INVERT_J_DIR false
//#define INVERT_K_DIR false
//#define INVERT_U_DIR false
//#define INVERT_V_DIR false
//#define INVERT_W_DIR false

// @section extruder

// For direct drive extruder v9 set to true, for geared extruder set to false.
#define INVERT_E0_DIR false
#define INVERT_E1_DIR false
#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false
#define INVERT_E5_DIR false
#define INVERT_E6_DIR false
#define INVERT_E7_DIR false

// @section homing

#define NO_MOTION_BEFORE_HOMING // Inhibit movement until all axes have been homed. Also enable HOME_AFTER_DEACTIVATE for extra safety.
//#define HOME_AFTER_DEACTIVATE   // Require rehoming after steppers are deactivated. Also enable NO_MOTION_BEFORE_HOMING for extra safety.

/**
 * Set Z_IDLE_HEIGHT if the Z-Axis moves on its own when steppers are disabled.
 *  - Use a low value (i.e., Z_MIN_POS) if the nozzle falls down to the bed.
 *  - Use a large value (i.e., Z_MAX_POS) if the bed falls down, away from the nozzle.
 */
//#define Z_IDLE_HEIGHT Z_HOME_POS

//#define Z_CLEARANCE_FOR_HOMING  4   // (mm) Minimal Z height before homing (G28) for Z clearance above the bed, clamps, ...
                                      // You'll need this much clearance above Z_MAX_POS to avoid grinding.

//#define Z_AFTER_HOMING         10   // (mm) Height to move to after homing (if Z was homed)
//#define XY_AFTER_HOMING { 10, 10 }  // (mm) Move to an XY position after homing (and raising Z)

//#define EVENT_GCODE_AFTER_HOMING "M300 P440 S200"  // Commands to run after G28 (and move to XY_AFTER_HOMING)

// Direction of endstops when homing; 1=MAX, -1=MIN
// :[-1,1]
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1
//#define I_HOME_DIR -1
//#define J_HOME_DIR -1
//#define K_HOME_DIR -1
//#define U_HOME_DIR -1
//#define V_HOME_DIR -1
//#define W_HOME_DIR -1

/**
 * Safety Stops
 * If an axis has endstops on both ends the one specified above is used for
 * homing, while the other can be used for things like SD_ABORT_ON_ENDSTOP_HIT.
 */
//#define X_SAFETY_STOP
//#define Y_SAFETY_STOP
//#define Z_SAFETY_STOP
//#define I_SAFETY_STOP
//#define J_SAFETY_STOP
//#define K_SAFETY_STOP
//#define U_SAFETY_STOP
//#define V_SAFETY_STOP
//#define W_SAFETY_STOP

// @section geometry

// The size of the printable area
#define X_BED_SIZE 200
#define Y_BED_SIZE 200

// Travel limits (linear=mm, rotational=°) after homing, corresponding to endstop positions.
#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define X_MAX_POS X_BED_SIZE
#define Y_MAX_POS Y_BED_SIZE
#define Z_MAX_POS 200
//#define I_MIN_POS 0
//#define I_MAX_POS 50
//#define J_MIN_POS 0
//#define J_MAX_POS 50
//#define K_MIN_POS 0
//#define K_MAX_POS 50
//#define U_MIN_POS 0
//#define U_MAX_POS 50
//#define V_MIN_POS 0
//#define V_MAX_POS 50
//#define W_MIN_POS 0
//#define W_MAX_POS 50

/**
 * Software Endstops
 *
 * - Prevent moves outside the set machine bounds.
 * - Individual axes can be disabled, if desired.
 * - X and Y only apply to Cartesian robots.
 * - Use 'M211' to set software endstops on/off or report current state
 */

// Min software endstops constrain movement within minimum coordinate bounds
#define MIN_SOFTWARE_ENDSTOPS
#if ENABLED(MIN_SOFTWARE_ENDSTOPS)
  #define MIN_SOFTWARE_ENDSTOP_X
  #define MIN_SOFTWARE_ENDSTOP_Y
  #define MIN_SOFTWARE_ENDSTOP_Z
  #define MIN_SOFTWARE_ENDSTOP_I
  #define MIN_SOFTWARE_ENDSTOP_J
  #define MIN_SOFTWARE_ENDSTOP_K
  #define MIN_SOFTWARE_ENDSTOP_U
  #define MIN_SOFTWARE_ENDSTOP_V
  #define MIN_SOFTWARE_ENDSTOP_W
#endif

// Max software endstops constrain movement within maximum coordinate bounds
#define MAX_SOFTWARE_ENDSTOPS
#if ENABLED(MAX_SOFTWARE_ENDSTOPS)
  #define MAX_SOFTWARE_ENDSTOP_X
  #define MAX_SOFTWARE_ENDSTOP_Y
  #define MAX_SOFTWARE_ENDSTOP_Z
  #define MAX_SOFTWARE_ENDSTOP_I
  #define MAX_SOFTWARE_ENDSTOP_J
  #define MAX_SOFTWARE_ENDSTOP_K
  #define MAX_SOFTWARE_ENDSTOP_U
  #define MAX_SOFTWARE_ENDSTOP_V
  #define MAX_SOFTWARE_ENDSTOP_W
#endif

#if ANY(MIN_SOFTWARE_ENDSTOPS, MAX_SOFTWARE_ENDSTOPS)
  //#define SOFT_ENDSTOPS_MENU_ITEM  // Enable/Disable software endstops from the LCD
#endif

/**
 * @section filament runout sensors
 *
 * Filament Runout Sensors
 * Mechanical or opto endstops are used to check for the presence of filament.
 *
 * IMPORTANT: Runout will only trigger if Marlin is aware that a print job is running.
 * Marlin knows a print job is running when:
 *  1. Running a print job from media started with M24.
 *  2. The Print Job Timer has been started with M75.
 *  3. The heaters were turned on and PRINTJOB_TIMER_AUTOSTART is enabled.
 *
 * RAMPS-based boards use SERVO3_PIN for the first runout sensor.
 * For other boards you may need to define FIL_RUNOUT_PIN, FIL_RUNOUT2_PIN, etc.
 */
//#define FILAMENT_RUNOUT_SENSOR
#if ENABLED(FILAMENT_RUNOUT_SENSOR)
  #define FIL_RUNOUT_ENABLED_DEFAULT true // Enable the sensor on startup. Override with M412 followed by M500.
  #define NUM_RUNOUT_SENSORS   1          // Number of sensors, up to one per extruder. Define a FIL_RUNOUT#_PIN for each.

  #define FIL_RUNOUT_STATE     LOW        // Pin state indicating that filament is NOT present.
  #define FIL_RUNOUT_PULLUP               // Use internal pullup for filament runout pins.
  //#define FIL_RUNOUT_PULLDOWN           // Use internal pulldown for filament runout pins.
  //#define WATCH_ALL_RUNOUT_SENSORS      // Execute runout script on any triggering sensor, not only for the active extruder.
                                          // This is automatically enabled for MIXING_EXTRUDERs.

  // Override individually if the runout sensors vary
  //#define FIL_RUNOUT1_STATE LOW
  //#define FIL_RUNOUT1_PULLUP
  //#define FIL_RUNOUT1_PULLDOWN

  //#define FIL_RUNOUT2_STATE LOW
  //#define FIL_RUNOUT2_PULLUP
  //#define FIL_RUNOUT2_PULLDOWN

  //#define FIL_RUNOUT3_STATE LOW
  //#define FIL_RUNOUT3_PULLUP
  //#define FIL_RUNOUT3_PULLDOWN

  //#define FIL_RUNOUT4_STATE LOW
  //#define FIL_RUNOUT4_PULLUP
  //#define FIL_RUNOUT4_PULLDOWN

  //#define FIL_RUNOUT5_STATE LOW
  //#define FIL_RUNOUT5_PULLUP
  //#define FIL_RUNOUT5_PULLDOWN

  //#define FIL_RUNOUT6_STATE LOW
  //#define FIL_RUNOUT6_PULLUP
  //#define FIL_RUNOUT6_PULLDOWN

  //#define FIL_RUNOUT7_STATE LOW
  //#define FIL_RUNOUT7_PULLUP
  //#define FIL_RUNOUT7_PULLDOWN

  //#define FIL_RUNOUT8_STATE LOW
  //#define FIL_RUNOUT8_PULLUP
  //#define FIL_RUNOUT8_PULLDOWN

  // Commands to execute on filament runout.
  // With multiple runout sensors use the %c placeholder for the current tool in commands (e.g., "M600 T%c")
  // NOTE: After 'M412 H1' the host handles filament runout and this script does not apply.
  #define FILAMENT_RUNOUT_SCRIPT "M600"

  // After a runout is detected, continue printing this length of filament
  // before executing the runout script. Useful for a sensor at the end of
  // a feed tube. Requires 4 bytes SRAM per sensor, plus 4 bytes overhead.
  //#define FILAMENT_RUNOUT_DISTANCE_MM 25

  #ifdef FILAMENT_RUNOUT_DISTANCE_MM
    // Enable this option to use an encoder disc that toggles the runout pin
    // as the filament moves. (Be sure to set FILAMENT_RUNOUT_DISTANCE_MM
    // large enough to avoid false positives.)
    //#define FILAMENT_MOTION_SENSOR

    #if ENABLED(FILAMENT_MOTION_SENSOR)
      //#define FILAMENT_SWITCH_AND_MOTION
      #if ENABLED(FILAMENT_SWITCH_AND_MOTION)
        #define NUM_MOTION_SENSORS   1          // Number of sensors, up to one per extruder. Define a FIL_MOTION#_PIN for each.
        //#define FIL_MOTION1_PIN    -1

        // Override individually if the motion sensors vary
        //#define FIL_MOTION1_STATE LOW
        //#define FIL_MOTION1_PULLUP
        //#define FIL_MOTION1_PULLDOWN

        //#define FIL_MOTION2_STATE LOW
        //#define FIL_MOTION2_PULLUP
        //#define FIL_MOTION2_PULLDOWN

        //#define FIL_MOTION3_STATE LOW
        //#define FIL_MOTION3_PULLUP
        //#define FIL_MOTION3_PULLDOWN

        //#define FIL_MOTION4_STATE LOW
        //#define FIL_MOTION4_PULLUP
        //#define FIL_MOTION4_PULLDOWN

        //#define FIL_MOTION5_STATE LOW
        //#define FIL_MOTION5_PULLUP
        //#define FIL_MOTION5_PULLDOWN

        //#define FIL_MOTION6_STATE LOW
        //#define FIL_MOTION6_PULLUP
        //#define FIL_MOTION6_PULLDOWN

        //#define FIL_MOTION7_STATE LOW
        //#define FIL_MOTION7_PULLUP
        //#define FIL_MOTION7_PULLDOWN

        //#define FIL_MOTION8_STATE LOW
        //#define FIL_MOTION8_PULLUP
        //#define FIL_MOTION8_PULLDOWN
      #endif
    #endif // FILAMENT_MOTION_SENSOR
  #endif // FILAMENT_RUNOUT_DISTANCE_MM
#endif // FILAMENT_RUNOUT_SENSOR

//===========================================================================
//=============================== Bed Leveling ==============================
//===========================================================================
// @section calibrate

/**
 * Choose one of the options below to enable G29 Bed Leveling. The parameters
 * and behavior of G29 will change depending on your selection.
 *
 *  If using a Probe for Z Homing, enable Z_SAFE_HOMING also!
 *
 * - AUTO_BED_LEVELING_3POINT
 *   Probe 3 arbitrary points on the bed (that aren't collinear)
 *   You specify the XY coordinates of all 3 points.
 *   The result is a single tilted plane. Best for a flat bed.
 *
 * - AUTO_BED_LEVELING_LINEAR
 *   Probe several points in a grid.
 *   You specify the rectangle and the density of sample points.
 *   The result is a single tilted plane. Best for a flat bed.
 *
 * - AUTO_BED_LEVELING_BILINEAR
 *   Probe several points in a grid.
 *   You specify the rectangle and the density of sample points.
 *   The result is a mesh, best for large or uneven beds.
 *
 * - AUTO_BED_LEVELING_UBL (Unified Bed Leveling)
 *   A comprehensive bed leveling system combining the features and benefits
 *   of other systems. UBL also includes integrated Mesh Generation, Mesh
 *   Validation and Mesh Editing systems.
 *
 * - MESH_BED_LEVELING
 *   Probe a grid manually
 *   The result is a mesh, suitable for large or uneven beds. (See BILINEAR.)
 *   For machines without a probe, Mesh Bed Leveling provides a method to perform
 *   leveling in steps so you can manually adjust the Z height at each grid-point.
 *   With an LCD controller the process is guided step-by-step.
 */
//#define AUTO_BED_LEVELING_3POINT
//#define AUTO_BED_LEVELING_LINEAR
//#define AUTO_BED_LEVELING_BILINEAR
//#define AUTO_BED_LEVELING_UBL
//#define MESH_BED_LEVELING

/**
 * Commands to execute at the start of G29 probing,
 * after switching to the PROBING_TOOL.
 */
//#define EVENT_GCODE_BEFORE_G29 "M300 P440 S200"

/**
 * Commands to execute at the end of G29 probing.
 * Useful to retract or move the Z probe out of the way.
 */
//#define EVENT_GCODE_AFTER_G29 "G1 Z10 F12000\nG1 X15 Y330\nG1 Z0.5\nG1 Z10"

/**
 * Normally G28 leaves leveling disabled on completion. Enable one of
 * these options to restore the prior leveling state or to always enable
 * leveling immediately after G28.
 */
//#define RESTORE_LEVELING_AFTER_G28
//#define ENABLE_LEVELING_AFTER_G28

/**
 * Auto-leveling needs preheating
 */
//#define PREHEAT_BEFORE_LEVELING
#if ENABLED(PREHEAT_BEFORE_LEVELING)
  #define LEVELING_NOZZLE_TEMP 120   // (°C) Only applies to E0 at this time
  #define LEVELING_BED_TEMP     50
#endif

/**
 * Enable detailed logging of G28, G29, M48, etc.
 * Turn on with the command 'M111 S32'.
 * NOTE: Requires a lot of flash!
 */
//#define DEBUG_LEVELING_FEATURE

#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_UBL, PROBE_MANUALLY)
  // Set a height for the start of manual adjustment
  #define MANUAL_PROBE_START_Z 0.2  // (mm) Comment out to use the last-measured height
#endif

#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_BILINEAR, AUTO_BED_LEVELING_UBL)
  /**
   * Gradually reduce leveling correction until a set height is reached,
   * at which point movement will be level to the machine's XY plane.
   * The height can be set with M420 Z<height>
   */
  #define ENABLE_LEVELING_FADE_HEIGHT
  #if ENABLED(ENABLE_LEVELING_FADE_HEIGHT)
    #define DEFAULT_LEVELING_FADE_HEIGHT 10.0 // (mm) Default fade height.
  #endif

  /**
   * For Cartesian machines, instead of dividing moves on mesh boundaries,
   * split up moves into short segments like a Delta. This follows the
   * contours of the bed more closely than edge-to-edge straight moves.
   */
  #define SEGMENT_LEVELED_MOVES
  #define LEVELED_SEGMENT_LENGTH 5.0 // (mm) Length of all segments (except the last one)

  /**
   * Enable the G26 Mesh Validation Pattern tool.
   */
  //#define G26_MESH_VALIDATION
  #if ENABLED(G26_MESH_VALIDATION)
    #define MESH_TEST_NOZZLE_SIZE    0.4  // (mm) Diameter of primary nozzle.
    #define MESH_TEST_LAYER_HEIGHT   0.2  // (mm) Default layer height for G26.
    #define MESH_TEST_HOTEND_TEMP  205    // (°C) Default nozzle temperature for G26.
    #define MESH_TEST_BED_TEMP      60    // (°C) Default bed temperature for G26.
    #define G26_XY_FEEDRATE         20    // (mm/s) Feedrate for G26 XY moves.
    #define G26_XY_FEEDRATE_TRAVEL 100    // (mm/s) Feedrate for G26 XY travel moves.
    #define G26_RETRACT_MULTIPLIER   1.0  // G26 Q (retraction) used by default between mesh test elements.
  #endif

#endif

#if ANY(AUTO_BED_LEVELING_LINEAR, AUTO_BED_LEVELING_BILINEAR)

  // Set the number of grid points per dimension.
  #define GRID_MAX_POINTS_X 3
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  // Probe along the Y axis, advancing X after each column
  //#define PROBE_Y_FIRST

  #if ENABLED(AUTO_BED_LEVELING_BILINEAR)

    // Beyond the probed grid, continue the implied tilt?
    // Default is to maintain the height of the nearest edge.
    //#define EXTRAPOLATE_BEYOND_GRID

    //
    // Subdivision of the grid by Catmull-Rom method.
    // Synthesizes intermediate points to produce a more detailed mesh.
    //
    //#define ABL_BILINEAR_SUBDIVISION
    #if ENABLED(ABL_BILINEAR_SUBDIVISION)
      // Number of subdivisions between probe points
      #define BILINEAR_SUBDIVISIONS 3
    #endif

  #endif

#elif ENABLED(AUTO_BED_LEVELING_UBL)

  //===========================================================================
  //========================= Unified Bed Leveling ============================
  //===========================================================================

  //#define MESH_EDIT_GFX_OVERLAY   // Display a graphics overlay while editing the mesh

  #define MESH_INSET 1              // Set Mesh bounds as an inset region of the bed
  #define GRID_MAX_POINTS_X 10      // Don't use more than 15 points per axis, implementation limited.
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  //#define UBL_HILBERT_CURVE       // Use Hilbert distribution for less travel when probing multiple points

  //#define UBL_TILT_ON_MESH_POINTS         // Use nearest mesh points with G29 J for better Z reference
  //#define UBL_TILT_ON_MESH_POINTS_3POINT  // Use nearest mesh points with G29 J0 (3-point)

  #define UBL_MESH_EDIT_MOVES_Z     // Sophisticated users prefer no movement of nozzle
  #define UBL_SAVE_ACTIVE_ON_M500   // Save the currently active mesh in the current slot on M500

  //#define UBL_Z_RAISE_WHEN_OFF_MESH 2.5 // When the nozzle is off the mesh, this value is used
                                          // as the Z-Height correction value.

  //#define UBL_MESH_WIZARD         // Run several commands in a row to get a complete mesh

  /**
   * Probing not allowed within the position of an obstacle.
   */
  //#define AVOID_OBSTACLES
  #if ENABLED(AVOID_OBSTACLES)
    #define CLIP_W  23  // Bed clip width, should be padded a few mm over its physical size
    #define CLIP_H  14  // Bed clip height, should be padded a few mm over its physical size

    // Obstacle Rectangles defined as { X1, Y1, X2, Y2 }
    #define OBSTACLE1 { (X_BED_SIZE) / 4     - (CLIP_W) / 2,                       0, (X_BED_SIZE) / 4     + (CLIP_W) / 2, CLIP_H }
    #define OBSTACLE2 { (X_BED_SIZE) * 3 / 4 - (CLIP_W) / 2,                       0, (X_BED_SIZE) * 3 / 4 + (CLIP_W) / 2, CLIP_H }
    #define OBSTACLE3 { (X_BED_SIZE) / 4     - (CLIP_W) / 2, (Y_BED_SIZE) - (CLIP_H), (X_BED_SIZE) / 4     + (CLIP_W) / 2, Y_BED_SIZE }
    #define OBSTACLE4 { (X_BED_SIZE) * 3 / 4 - (CLIP_W) / 2, (Y_BED_SIZE) - (CLIP_H), (X_BED_SIZE) * 3 / 4 + (CLIP_W) / 2, Y_BED_SIZE }

    // The probed grid must be inset for G29 J. This is okay, since it is
    // only used to compute a linear transformation for the mesh itself.
    #define G29J_MESH_TILT_MARGIN ((CLIP_H) + 1)
  #endif

#elif ENABLED(MESH_BED_LEVELING)

  //===========================================================================
  //=================================== Mesh ==================================
  //===========================================================================

  #define MESH_INSET 10          // Set Mesh bounds as an inset region of the bed
  #define GRID_MAX_POINTS_X 3    // Don't use more than 7 points per axis, implementation limited.
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  //#define MESH_G28_REST_ORIGIN // After homing all axes ('G28' or 'G28 XYZ') rest Z at Z_MIN_POS

#endif // BED_LEVELING

/**
 * Add a bed leveling sub-menu for ABL or MBL.
 * Include a guided procedure if manual probing is enabled.
 */
//#define LCD_BED_LEVELING

#if ENABLED(LCD_BED_LEVELING)
  #define MESH_EDIT_Z_STEP  0.025 // (mm) Step size while manually probing Z axis.
  #define LCD_PROBE_Z_RANGE 4     // (mm) Z Range centered on Z_MIN_POS for LCD Z adjustment
  //#define MESH_EDIT_MENU        // Add a menu to edit mesh points
#endif

// Add a menu item to move between bed corners for manual bed adjustment
//#define LCD_BED_TRAMMING

#if ENABLED(LCD_BED_TRAMMING)
  #define BED_TRAMMING_INSET_LFRB { 30, 30, 30, 30 } // (mm) Left, Front, Right, Back insets
  #define BED_TRAMMING_HEIGHT      0.0        // (mm) Z height of nozzle at tramming points
  #define BED_TRAMMING_Z_HOP       4.0        // (mm) Z raise between tramming points
  //#define BED_TRAMMING_INCLUDE_CENTER       // Move to the center after the last corner
  //#define BED_TRAMMING_USE_PROBE
  #if ENABLED(BED_TRAMMING_USE_PROBE)
    #define BED_TRAMMING_PROBE_TOLERANCE 0.1  // (mm)
    #define BED_TRAMMING_VERIFY_RAISED        // After adjustment triggers the probe, re-probe to verify
    //#define BED_TRAMMING_AUDIO_FEEDBACK
  #endif

  /**
   * Corner Leveling Order
   *
   * Set 2 or 4 points. When 2 points are given, the 3rd is the center of the opposite edge.
   *
   *  LF  Left-Front    RF  Right-Front
   *  LB  Left-Back     RB  Right-Back
   *
   * Examples:
   *
   *      Default        {LF,RB,LB,RF}         {LF,RF}           {LB,LF}
   *  LB --------- RB   LB --------- RB    LB --------- RB   LB --------- RB
   *  |  4       3  |   | 3         2 |    |     <3>     |   | 1           |
   *  |             |   |             |    |             |   |          <3>|
   *  |  1       2  |   | 1         4 |    | 1         2 |   | 2           |
   *  LF --------- RF   LF --------- RF    LF --------- RF   LF --------- RF
   */
  #define BED_TRAMMING_LEVELING_ORDER { LF, RF, RB, LB }
#endif

// @section homing

// The center of the bed is at (X=0, Y=0)
//#define BED_CENTER_AT_0_0

// Manually set the home position. Leave these undefined for automatic settings.
// For DELTA this is the top-center of the Cartesian print volume.
//#define MANUAL_X_HOME_POS 0
//#define MANUAL_Y_HOME_POS 0
//#define MANUAL_Z_HOME_POS 0
//#define MANUAL_I_HOME_POS 0
//#define MANUAL_J_HOME_POS 0
//#define MANUAL_K_HOME_POS 0
//#define MANUAL_U_HOME_POS 0
//#define MANUAL_V_HOME_POS 0
//#define MANUAL_W_HOME_POS 0

/**
 * Use "Z Safe Homing" to avoid homing with a Z probe outside the bed area.
 *
 * - Moves the Z probe (or nozzle) to a defined XY point before Z homing.
 * - Allows Z homing only when XY positions are known and trusted.
 * - If stepper drivers sleep, XY homing may be required again before Z homing.
 */
//#define Z_SAFE_HOMING

#if ENABLED(Z_SAFE_HOMING)
  #define Z_SAFE_HOMING_X_POINT X_CENTER  // (mm) X point for Z homing
  #define Z_SAFE_HOMING_Y_POINT Y_CENTER  // (mm) Y point for Z homing
  //#define Z_SAFE_HOMING_POINT_ABSOLUTE  // Ignore home offsets (M206) for Z homing position
#endif

// Homing speeds (linear=mm/min, rotational=°/min)
#define HOMING_FEEDRATE_MM_M { (50*60), (50*60), (4*60) }

// Edit homing feedrates with M210 and MarlinUI menu items
//#define EDITABLE_HOMING_FEEDRATE

// Validate that endstops are triggered on homing moves
#define VALIDATE_HOMING_ENDSTOPS

// @section calibrate

/**
 * Bed Skew Compensation
 *
 * This feature corrects for misalignment in the XYZ axes.
 *
 * Take the following steps to get the bed skew in the XY plane:
 *  1. Print a test square (e.g., https://www.thingiverse.com/thing:2563185)
 *  2. For XY_DIAG_AC measure the diagonal A to C
 *  3. For XY_DIAG_BD measure the diagonal B to D
 *  4. For XY_SIDE_AD measure the edge A to D
 *
 * Marlin automatically computes skew factors from these measurements.
 * Skew factors may also be computed and set manually:
 *
 *  - Compute AB     : SQRT(2*AC*AC+2*BD*BD-4*AD*AD)/2
 *  - XY_SKEW_FACTOR : TAN(PI/2-ACOS((AC*AC-AB*AB-AD*AD)/(2*AB*AD)))
 *
 * If desired, follow the same procedure for XZ and YZ.
 * Use these diagrams for reference:
 *
 *    Y                     Z                     Z
 *    ^     B-------C       ^     B-------C       ^     B-------C
 *    |    /       /        |    /       /        |    /       /
 *    |   /       /         |   /       /         |   /       /
 *    |  A-------D          |  A-------D          |  A-------D
 *    +-------------->X     +-------------->X     +-------------->Y
 *     XY_SKEW_FACTOR        XZ_SKEW_FACTOR        YZ_SKEW_FACTOR
 */
//#define SKEW_CORRECTION

#if ENABLED(SKEW_CORRECTION)
  // Input all length measurements here:
  #define XY_DIAG_AC 282.8427124746
  #define XY_DIAG_BD 282.8427124746
  #define XY_SIDE_AD 200

  // Or, set the XY skew factor directly:
  //#define XY_SKEW_FACTOR 0.0

  //#define SKEW_CORRECTION_FOR_Z
  #if ENABLED(SKEW_CORRECTION_FOR_Z)
    #define XZ_DIAG_AC 282.8427124746
    #define XZ_DIAG_BD 282.8427124746
    #define YZ_DIAG_AC 282.8427124746
    #define YZ_DIAG_BD 282.8427124746
    #define YZ_SIDE_AD 200

    // Or, set the Z skew factors directly:
    //#define XZ_SKEW_FACTOR 0.0
    //#define YZ_SKEW_FACTOR 0.0
  #endif

  // Enable this option for M852 to set skew at runtime
  //#define SKEW_CORRECTION_GCODE
#endif

//=============================================================================
//============================= Additional Features ===========================
//=============================================================================

// @section eeprom

/**
 * EEPROM
 *
 * Persistent storage to preserve configurable settings across reboots.
 *
 *   M500 - Store settings to EEPROM.
 *   M501 - Read settings from EEPROM. (i.e., Throw away unsaved changes)
 *   M502 - Revert settings to "factory" defaults. (Follow with M500 to init the EEPROM.)
 */
//#define EEPROM_SETTINGS     // Persistent storage with M500 and M501
//#define DISABLE_M503        // Saves ~2700 bytes of flash. Disable for release!
#define EEPROM_CHITCHAT       // Give feedback on EEPROM commands. Disable to save flash.
#define EEPROM_BOOT_SILENT    // Keep M503 quiet and only give errors during first load
#if ENABLED(EEPROM_SETTINGS)
  //#define EEPROM_AUTO_INIT  // Init EEPROM automatically on any errors.
  //#define EEPROM_INIT_NOW   // Init EEPROM on first boot after a new build.
#endif

// @section host

//
// Host Keepalive
//
// When enabled Marlin will send a busy status message to the host
// every couple of seconds when it can't accept commands.
//
#define HOST_KEEPALIVE_FEATURE        // Disable this if your host doesn't like keepalive messages
#define DEFAULT_KEEPALIVE_INTERVAL 2  // Number of seconds between "busy" messages. Set with M113.
#define BUSY_WHILE_HEATING            // Some hosts require "busy" messages even during heating

// @section units

//
// G20/G21 Inch mode support
//
//#define INCH_MODE_SUPPORT

//
// M149 Set temperature units support
//
//#define TEMPERATURE_UNITS_SUPPORT

// @section temperature

//
// Preheat Constants - Up to 10 are supported without changes
//
#define PREHEAT_1_LABEL       "PLA"
#define PREHEAT_1_TEMP_HOTEND 180
#define PREHEAT_1_TEMP_BED     70
#define PREHEAT_1_TEMP_CHAMBER 35
#define PREHEAT_1_FAN_SPEED     0 // Value from 0 to 255

#define PREHEAT_2_LABEL       "ABS"
#define PREHEAT_2_TEMP_HOTEND 240
#define PREHEAT_2_TEMP_BED    110
#define PREHEAT_2_TEMP_CHAMBER 35
#define PREHEAT_2_FAN_SPEED     0 // Value from 0 to 255

/**
 * @section nozzle park
 *
 * Nozzle Park
 *
 * Park the nozzle at the given XYZ position on idle or G27.
 *
 * The "P" parameter controls the action applied to the Z axis:
 *
 *    P0  (Default) If Z is below park Z raise the nozzle.
 *    P1  Raise the nozzle always to Z-park height.
 *    P2  Raise the nozzle by Z-park amount, limited to Z_MAX_POS.
 */
//#define NOZZLE_PARK_FEATURE

#if ENABLED(NOZZLE_PARK_FEATURE)
  // Specify a park position as { X, Y, Z_raise }
  #define NOZZLE_PARK_POINT { (X_MIN_POS + 10), (Y_MAX_POS - 10), 20 }
  #define NOZZLE_PARK_MOVE          0   // Park motion: 0 = XY Move, 1 = X Only, 2 = Y Only, 3 = X before Y, 4 = Y before X
  #define NOZZLE_PARK_Z_RAISE_MIN   2   // (mm) Always raise Z by at least this distance
  #define NOZZLE_PARK_XY_FEEDRATE 100   // (mm/s) X and Y axes feedrate (also used for delta Z axis)
  #define NOZZLE_PARK_Z_FEEDRATE    5   // (mm/s) Z axis feedrate (not used for delta printers)
#endif

/**
 * @section nozzle clean
 *
 * Clean Nozzle Feature
 *
 * Adds the G12 command to perform a nozzle cleaning process.
 *
 * Parameters:
 *   P  Pattern
 *   S  Strokes / Repetitions
 *   T  Triangles (P1 only)
 *
 * Patterns:
 *   P0  Straight line (default). This process requires a sponge type material
 *       at a fixed bed location. "S" specifies strokes (i.e. back-forth motions)
 *       between the start / end points.
 *
 *   P1  Zig-zag pattern between (X0, Y0) and (X1, Y1), "T" specifies the
 *       number of zig-zag triangles to do. "S" defines the number of strokes.
 *       Zig-zags are done in whichever is the narrower dimension.
 *       For example, "G12 P1 S1 T3" will execute:
 *
 *          --
 *         |  (X0, Y1) |     /\        /\        /\     | (X1, Y1)
 *         |           |    /  \      /  \      /  \    |
 *       A |           |   /    \    /    \    /    \   |
 *         |           |  /      \  /      \  /      \  |
 *         |  (X0, Y0) | /        \/        \/        \ | (X1, Y0)
 *          --         +--------------------------------+
 *                       |________|_________|_________|
 *                           T1        T2        T3
 *
 *   P2  Circular pattern with middle at NOZZLE_CLEAN_CIRCLE_MIDDLE.
 *       "R" specifies the radius. "S" specifies the stroke count.
 *       Before starting, the nozzle moves to NOZZLE_CLEAN_START_POINT.
 *
 *   Caveats: The ending Z should be the same as starting Z.
 */
//#define NOZZLE_CLEAN_FEATURE

#if ENABLED(NOZZLE_CLEAN_FEATURE)
  #define NOZZLE_CLEAN_PATTERN_LINE     // Provide 'G12 P0' - a simple linear cleaning pattern
  #define NOZZLE_CLEAN_PATTERN_ZIGZAG   // Provide 'G12 P1' - a zigzag cleaning pattern
  #define NOZZLE_CLEAN_PATTERN_CIRCLE   // Provide 'G12 P2' - a circular cleaning pattern

  // Default pattern to use when 'P' is not provided to G12. One of the enabled options above.
  #define NOZZLE_CLEAN_DEFAULT_PATTERN 0

  #define NOZZLE_CLEAN_STROKES     12   // Default number of pattern repetitions

  #if ENABLED(NOZZLE_CLEAN_PATTERN_ZIGZAG)
    #define NOZZLE_CLEAN_TRIANGLES  3   // Default number of triangles
  #endif

  // Specify positions for each tool as { { X, Y, Z }, { X, Y, Z } }
  // Dual hotend system may use { {  -20, (Y_BED_SIZE / 2), (Z_MIN_POS + 1) },  {  420, (Y_BED_SIZE / 2), (Z_MIN_POS + 1) }}
  #define NOZZLE_CLEAN_START_POINT { {  30, 30, (Z_MIN_POS + 1) } }
  #define NOZZLE_CLEAN_END_POINT   { { 100, 60, (Z_MIN_POS + 1) } }

  #if ENABLED(NOZZLE_CLEAN_PATTERN_CIRCLE)
    #define NOZZLE_CLEAN_CIRCLE_RADIUS 6.5                      // (mm) Circular pattern radius
    #define NOZZLE_CLEAN_CIRCLE_FN 10                           // Circular pattern circle number of segments
    #define NOZZLE_CLEAN_CIRCLE_MIDDLE NOZZLE_CLEAN_START_POINT // Middle point of circle
  #endif

  // Move the nozzle to the initial position after cleaning
  #define NOZZLE_CLEAN_GOBACK

  // For a purge/clean station that's always at the gantry height (thus no Z move)
  //#define NOZZLE_CLEAN_NO_Z

  // For a purge/clean station mounted on the X axis
  //#define NOZZLE_CLEAN_NO_Y

  // Require a minimum hotend temperature for cleaning
  #define NOZZLE_CLEAN_MIN_TEMP 170
  //#define NOZZLE_CLEAN_HEATUP       // Heat up the nozzle instead of skipping wipe

  // Explicit wipe G-code script applies to a G12 with no arguments.
  //#define WIPE_SEQUENCE_COMMANDS "G1 X-17 Y25 Z10 F4000\nG1 Z1\nM114\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 Z15\nM400\nG0 X-10.0 Y-9.0"

#endif

// @section host

/**
 * Print Job Timer
 *
 * Automatically start and stop the print job timer on M104/M109/M140/M190/M141/M191.
 * The print job timer will only be stopped if the bed/chamber target temp is
 * below BED_MINTEMP/CHAMBER_MINTEMP.
 *
 *   M104 (hotend, no wait)  - high temp = none,        low temp = stop timer
 *   M109 (hotend, wait)     - high temp = start timer, low temp = stop timer
 *   M140 (bed, no wait)     - high temp = none,        low temp = stop timer
 *   M190 (bed, wait)        - high temp = start timer, low temp = none
 *   M141 (chamber, no wait) - high temp = none,        low temp = stop timer
 *   M191 (chamber, wait)    - high temp = start timer, low temp = none
 *
 * For M104/M109, high temp is anything over EXTRUDE_MINTEMP / 2.
 * For M140/M190, high temp is anything over BED_MINTEMP.
 * For M141/M191, high temp is anything over CHAMBER_MINTEMP.
 *
 * The timer can also be controlled with the following commands:
 *
 *   M75 - Start the print job timer
 *   M76 - Pause the print job timer
 *   M77 - Stop the print job timer
 */
#define PRINTJOB_TIMER_AUTOSTART

// @section stats

/**
 * Print Counter
 *
 * Track statistical data such as:
 *
 *  - Total print jobs
 *  - Total successful print jobs
 *  - Total failed print jobs
 *  - Total time printing
 *
 * View the current statistics with M78.
 */
//#define PRINTCOUNTER
#if ENABLED(PRINTCOUNTER)
  #define PRINTCOUNTER_SAVE_INTERVAL 60 // (minutes) EEPROM save interval during print. A value of 0 will save stats at end of print.
#endif

// @section security

/**
 * Password
 *
 * Set a numerical password for the printer which can be requested:
 *
 *  - When the printer boots up
 *  - Upon opening the 'Print from Media' Menu
 *  - When SD printing is completed or aborted
 *
 * The following G-codes can be used:
 *
 *  M510 - Lock Printer. Blocks all commands except M511.
 *  M511 - Unlock Printer.
 *  M512 - Set, Change and Remove Password.
 *
 * If you forget the password and get locked out you'll need to re-flash
 * the firmware with the feature disabled, reset EEPROM, and (optionally)
 * re-flash the firmware again with this feature enabled.
 */
//#define PASSWORD_FEATURE
#if ENABLED(PASSWORD_FEATURE)
  #define PASSWORD_LENGTH 4                 // (#) Number of digits (1-9). 3 or 4 is recommended
  #define PASSWORD_ON_STARTUP
  #define PASSWORD_UNLOCK_GCODE             // Unlock with the M511 P<password> command. Disable to prevent brute-force attack.
  #define PASSWORD_CHANGE_GCODE             // Change the password with M512 P<old> S<new>.
  //#define PASSWORD_ON_SD_PRINT_MENU       // This does not prevent G-codes from running
  //#define PASSWORD_AFTER_SD_PRINT_END
  //#define PASSWORD_AFTER_SD_PRINT_ABORT
  //#include "Configuration_Secure.h"       // External file with PASSWORD_DEFAULT_VALUE
#endif

// @section media

/**
 * SD CARD
 *
 * SD Card support is disabled by default. If your controller has an SD slot,
 * you must uncomment the following option or it won't work.
 */
//#define SDSUPPORT

/**
 * SD CARD: ENABLE CRC
 *
 * Use CRC checks and retries on the SD communication.
 */
#if ENABLED(SDSUPPORT)
  //#define SD_CHECK_AND_RETRY
#endif

// @section interface

/**
 * LCD LANGUAGE
 *
 * Select the language to display on the LCD. These languages are available:
 *
 *   en, an, bg, ca, cz, da, de, el, el_CY, es, eu, fi, fr, gl, hr, hu, it,
 *   jp_kana, ko_KR, nl, pl, pt, pt_br, ro, ru, sk, sv, tr, uk, vi, zh_CN, zh_TW
 *
 * :{ 'en':'English', 'an':'Aragonese', 'bg':'Bulgarian', 'ca':'Catalan', 'cz':'Czech', 'da':'Danish', 'de':'German', 'el':'Greek (Greece)', 'el_CY':'Greek (Cyprus)', 'es':'Spanish', 'eu':'Basque-Euskera', 'fi':'Finnish', 'fr':'French', 'gl':'Galician', 'hr':'Croatian', 'hu':'Hungarian', 'it':'Italian', 'jp_kana':'Japanese', 'ko_KR':'Korean (South Korea)', 'nl':'Dutch', 'pl':'Polish', 'pt':'Portuguese', 'pt_br':'Portuguese (Brazilian)', 'ro':'Romanian', 'ru':'Russian', 'sk':'Slovak', 'sv':'Swedish', 'tr':'Turkish', 'uk':'Ukrainian', 'vi':'Vietnamese', 'zh_CN':'Chinese (Simplified)', 'zh_TW':'Chinese (Traditional)' }
 */
#define LCD_LANGUAGE en

/**
 * LCD Character Set
 *
 * Note: This option is NOT applicable to Graphical Displays.
 *
 * All character-based LCDs provide ASCII plus one of these
 * language extensions:
 *
 *  - JAPANESE ... the most common
 *  - WESTERN  ... with more accented characters
 *  - CYRILLIC ... for the Russian language
 *
 * To determine the language extension installed on your controller:
 *
 *  - Compile and upload with LCD_LANGUAGE set to 'test'
 *  - Click the controller to view the LCD menu
 *  - The LCD will display Japanese, Western, or Cyrillic text
 *
 * See https://marlinfw.org/docs/development/lcd_language.html
 *
 * :['JAPANESE', 'WESTERN', 'CYRILLIC']
 */
#define DISPLAY_CHARSET_HD44780 JAPANESE

/**
 * Info Screen Style (0:Classic, 1:Průša, 2:CNC)
 *
 * :[0:'Classic', 1:'Průša', 2:'CNC']
 */
#define LCD_INFO_SCREEN_STYLE 0

/**
 * LCD Menu Items
 *
 * Disable all menus and only display the Status Screen, or
 * just remove some extraneous menu items to recover space.
 */
//#define NO_LCD_MENUS
//#define SLIM_LCD_MENUS

//
// ENCODER SETTINGS
//
// This option overrides the default number of encoder pulses needed to
// produce one step. Should be increased for high-resolution encoders.
//
//#define ENCODER_PULSES_PER_STEP 4

//
// Use this option to override the number of step signals required to
// move between next/prev menu items.
//
//#define ENCODER_STEPS_PER_MENU_ITEM 1

/**
 * Encoder Direction Options
 *
 * Test your encoder's behavior first with both options disabled.
 *
 *  Reversed Value Edit and Menu Nav? Enable REVERSE_ENCODER_DIRECTION.
 *  Reversed Menu Navigation only?    Enable REVERSE_MENU_DIRECTION.
 *  Reversed Value Editing only?      Enable BOTH options.
 */

//
// This option reverses the encoder direction everywhere.
//
//  Set this option if CLOCKWISE causes values to DECREASE
//
//#define REVERSE_ENCODER_DIRECTION

//
// This option reverses the encoder direction for navigating LCD menus.
//
//  If CLOCKWISE normally moves DOWN this makes it go UP.
//  If CLOCKWISE normally moves UP this makes it go DOWN.
//
//#define REVERSE_MENU_DIRECTION

//
// This option reverses the encoder direction for Select Screen.
//
//  If CLOCKWISE normally moves LEFT this makes it go RIGHT.
//  If CLOCKWISE normally moves RIGHT this makes it go LEFT.
//
//#define REVERSE_SELECT_DIRECTION

//
// Encoder EMI Noise Filter
//
// This option increases encoder samples to filter out phantom encoder clicks caused by EMI noise.
//
//#define ENCODER_NOISE_FILTER
#if ENABLED(ENCODER_NOISE_FILTER)
  #define ENCODER_SAMPLES 10
#endif

//
// Individual Axis Homing
//
// Add individual axis homing items (Home X, Home Y, and Home Z) to the LCD menu.
//
//#define INDIVIDUAL_AXIS_HOMING_MENU
//#define INDIVIDUAL_AXIS_HOMING_SUBMENU

//
// SPEAKER/BUZZER
//
// If you have a speaker that can produce tones, enable it here.
// By default Marlin assumes you have a buzzer with a fixed frequency.
//
//#define SPEAKER

//
// The duration and frequency for the UI feedback sound.
// Set these to 0 to disable audio feedback in the LCD menus.
//
// Note: Test audio output with the G-Code:
//  M300 S<frequency Hz> P<duration ms>
//
//#define LCD_FEEDBACK_FREQUENCY_DURATION_MS 2
//#define LCD_FEEDBACK_FREQUENCY_HZ 5000

//
// Tone queue size, used to keep beeps from blocking execution.
// Default is 4, or override here. Costs 4 bytes of SRAM per entry.
//
//#define TONE_QUEUE_LENGTH 4

//
// A sequence of tones to play at startup, in pairs of tone (Hz), duration (ms).
// Silence in-between tones.
//
//#define STARTUP_TUNE { 698, 300, 0, 50, 523, 50, 0, 25, 494, 50, 0, 25, 523, 100, 0, 50, 554, 300, 0, 100, 523, 300 }

//=============================================================================
//======================== LCD / Controller Selection =========================
//========================   (Character-based LCDs)   =========================
//=============================================================================
// @section lcd

//
// RepRapDiscount Smart Controller.
// https://reprap.org/wiki/RepRapDiscount_Smart_Controller
//
// Note: Usually sold with a white PCB.
//
//#define REPRAP_DISCOUNT_SMART_CONTROLLER

//
// GT2560 (YHCB2004) LCD Display
//
// Requires Testato, Koepel softwarewire library and
// Andriy Golovnya's LiquidCrystal_AIP31068 library.
//
//#define YHCB2004

//
// Original RADDS LCD Display+Encoder+SDCardReader
// https://web.archive.org/web/20200719145306/doku.radds.org/dokumentation/lcd-display/
//
//#define RADDS_DISPLAY

//
// ULTIMAKER Controller.
//
//#define ULTIMAKERCONTROLLER

//
// ULTIPANEL as seen on Thingiverse.
//
//#define ULTIPANEL

//
// PanelOne from T3P3 (via RAMPS 1.4 AUX2/AUX3)
// https://reprap.org/wiki/PanelOne
//
//#define PANEL_ONE

//
// GADGETS3D G3D LCD/SD Controller
// https://reprap.org/wiki/RAMPS_1.3/1.4_GADGETS3D_Shield_with_Panel
//
// Note: Usually sold with a blue PCB.
//
//#define G3D_PANEL

//
// RigidBot Panel V1.0
//
//#define RIGIDBOT_PANEL

//
// Makeboard 3D Printer Parts 3D Printer Mini Display 1602 Mini Controller
// https://www.aliexpress.com/item/32765887917.html
//
//#define MAKEBOARD_MINI_2_LINE_DISPLAY_1602

/**
 * ANET and Tronxy 20x4 Controller
 * LCD2004 display with 5 analog buttons.
 *
 * NOTE: Requires ADC_KEYPAD_PIN to be assigned to an analog pin.
 * This LCD is known to be susceptible to electrical interference which
 * scrambles the display. Press any button to clear it up.
 */
//#define ZONESTAR_LCD

//
// Generic 16x2, 16x4, 20x2, or 20x4 character-based LCD.
//
//#define ULTRA_LCD

//=============================================================================
//======================== LCD / Controller Selection =========================
//=====================   (I2C and Shift-Register LCDs)   =====================
//=============================================================================

//
// CONTROLLER TYPE: I2C
//
// Note: These controllers require the installation of Arduino's LiquidCrystal_I2C
// library. For more info: https://github.com/kiyoshigawa/LiquidCrystal_I2C
//

//
// Elefu RA Board Control Panel
// https://web.archive.org/web/20140823033947/www.elefu.com/index.php?route=product/product&product_id=53
//
//#define RA_CONTROL_PANEL

//
// Sainsmart (YwRobot) LCD Displays
//
// These require LiquidCrystal_I2C library:
//   https://github.com/MarlinFirmware/New-LiquidCrystal
//   https://github.com/fmalpartida/New-LiquidCrystal/wiki
//
//#define LCD_SAINSMART_I2C_1602
//#define LCD_SAINSMART_I2C_2004

//
// Generic LCM1602 LCD adapter
//
//#define LCM1602

//
// PANELOLU2 LCD with status LEDs,
// separate encoder and click inputs.
//
// Note: This controller requires Arduino's LiquidTWI2 library v1.2.3 or later.
// For more info: https://github.com/lincomatic/LiquidTWI2
//
// Note: The PANELOLU2 encoder click input can either be directly connected to
// a pin (if BTN_ENC defined to != -1) or read through I2C (when BTN_ENC == -1).
//
//#define LCD_I2C_PANELOLU2

//
// Panucatt VIKI LCD with status LEDs,
// integrated click & L/R/U/D buttons, separate encoder inputs.
//
//#define LCD_I2C_VIKI

//
// CONTROLLER TYPE: Shift register panels
//

//
// 2-wire Non-latching LCD SR from https://github.com/fmalpartida/New-LiquidCrystal/wiki/schematics#user-content-ShiftRegister_connection
// LCD configuration: https://reprap.org/wiki/SAV_3D_LCD
//
//#define SAV_3DLCD

//
// 3-wire SR LCD with strobe using 74HC4094
// https://github.com/mikeshub/SailfishLCD
// Uses the code directly from Sailfish
//
//#define FF_INTERFACEBOARD

//
// TFT GLCD Panel with Marlin UI
// Panel connected to main board by SPI or I2C interface.
// See https://github.com/Serhiy-K/TFTGLCDAdapter
//
//#define TFTGLCD_PANEL_SPI
//#define TFTGLCD_PANEL_I2C

//=============================================================================
//=======================   LCD / Controller Selection  =======================
//=========================      (Graphical LCDs)      ========================
//=============================================================================

//
// CONTROLLER TYPE: Graphical 128x64 (DOGM)
//
// IMPORTANT: The U8glib library is required for Graphical Display!
//            https://github.com/olikraus/U8glib_Arduino
//
// NOTE: If the LCD is unresponsive you may need to reverse the plugs.
//

//
// RepRapDiscount FULL GRAPHIC Smart Controller
// https://reprap.org/wiki/RepRapDiscount_Full_Graphic_Smart_Controller
//
//#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER

//
// K.3D Full Graphic Smart Controller
//
//#define K3D_FULL_GRAPHIC_SMART_CONTROLLER

//
// ReprapWorld Graphical LCD
// https://reprapworld.com/electronics/3d-printer-modules/autonomous-printing/graphical-lcd-screen-v1-0/
//
//#define REPRAPWORLD_GRAPHICAL_LCD

//
// Activate one of these if you have a Panucatt Devices
// Viki 2.0 or mini Viki with Graphic LCD
// https://www.panucatt.com
//
//#define VIKI2
//#define miniVIKI

//
// Alfawise Ex8 printer LCD marked as WYH L12864 COG
//
//#define WYH_L12864

//
// MakerLab Mini Panel with graphic
// controller and SD support - https://reprap.org/wiki/Mini_panel
//
//#define MINIPANEL

//
// MaKr3d Makr-Panel with graphic controller and SD support.
// https://reprap.org/wiki/MaKrPanel
//
//#define MAKRPANEL

//
// Adafruit ST7565 Full Graphic Controller.
// https://github.com/eboston/Adafruit-ST7565-Full-Graphic-Controller/
//
//#define ELB_FULL_GRAPHIC_CONTROLLER

//
// BQ LCD Smart Controller shipped by
// default with the BQ Hephestos 2 and Witbox 2.
//
//#define BQ_LCD_SMART_CONTROLLER

//
// Cartesio UI
// https://web.archive.org/web/20180605050442/mauk.cc/webshop/cartesio-shop/electronics/user-interface
//
//#define CARTESIO_UI

//
// LCD for Melzi Card with Graphical LCD
//
//#define LCD_FOR_MELZI

//
// Original Ulticontroller from Ultimaker 2 printer with SSD1309 I2C display and encoder
// https://github.com/Ultimaker/Ultimaker2/tree/master/1249_Ulticontroller_Board_(x1)
//
//#define ULTI_CONTROLLER

//
// MKS MINI12864 with graphic controller and SD support
// https://reprap.org/wiki/MKS_MINI_12864
//
//#define MKS_MINI_12864

//
// MKS MINI12864 V3 is an alias for FYSETC_MINI_12864_2_1. Type A/B. NeoPixel RGB Backlight.
//
//#define MKS_MINI_12864_V3

//
// MKS LCD12864A/B with graphic controller and SD support. Follows MKS_MINI_12864 pinout.
// https://www.aliexpress.com/item/33018110072.html
//
//#define MKS_LCD12864A
//#define MKS_LCD12864B

//
// FYSETC variant of the MINI12864 graphic controller with SD support
// https://wiki.fysetc.com/Mini12864_Panel/
//
//#define FYSETC_MINI_12864_X_X    // Type C/D/E/F. No tunable RGB Backlight by default
//#define FYSETC_MINI_12864_1_2    // Type C/D/E/F. Simple RGB Backlight (always on)
//#define FYSETC_MINI_12864_2_0    // Type A/B. Discreet RGB Backlight
//#define FYSETC_MINI_12864_2_1    // Type A/B. NeoPixel RGB Backlight
//#define FYSETC_GENERIC_12864_1_1 // Larger display with basic ON/OFF backlight.

//
// BigTreeTech Mini 12864 V1.0 / V2.0 is an alias for FYSETC_MINI_12864_2_1. Type A/B. NeoPixel RGB Backlight.
// https://github.com/bigtreetech/MINI-12864
//
//#define BTT_MINI_12864

//
// BEEZ MINI 12864 is an alias for FYSETC_MINI_12864_2_1. Type A/B. NeoPixel RGB Backlight.
//
//#define BEEZ_MINI_12864

//
// Factory display for Creality CR-10 / CR-7 / Ender-3
// https://marlinfw.org/docs/hardware/controllers.html#cr10_stockdisplay
//
// Connect to EXP1 on RAMPS and compatible boards.
//
//#define CR10_STOCKDISPLAY

//
// Ender-2 OEM display, a variant of the MKS_MINI_12864
//
//#define ENDER2_STOCKDISPLAY

//
// ANET and Tronxy 128×64 Full Graphics Controller as used on Anet A6
//
//#define ANET_FULL_GRAPHICS_LCD

//
// GUCOCO CTC 128×64 Full Graphics Controller as used on GUCOCO CTC A10S
//
//#define CTC_A10S_A13

//
// AZSMZ 12864 LCD with SD
// https://www.aliexpress.com/item/32837222770.html
//
//#define AZSMZ_12864

//
// Silvergate GLCD controller
// https://github.com/android444/Silvergate
//
//#define SILVER_GATE_GLCD_CONTROLLER

//
// eMotion Tech LCD with SD
// https://www.reprap-france.com/produit/1234568748-ecran-graphique-128-x-64-points-2-1
//
//#define EMOTION_TECH_LCD

//=============================================================================
//==============================  OLED Displays  ==============================
//=============================================================================

//
// SSD1306 OLED full graphics generic display
//
//#define U8GLIB_SSD1306

//
// SAV OLEd LCD module support using either SSD1306 or SH1106 based LCD modules
//
//#define SAV_3DGLCD
#if ENABLED(SAV_3DGLCD)
  #define U8GLIB_SSD1306
  //#define U8GLIB_SH1106
#endif

//
// TinyBoy2 128x64 OLED / Encoder Panel
//
//#define OLED_PANEL_TINYBOY2

//
// MKS OLED 1.3" 128×64 Full Graphics Controller
// https://reprap.org/wiki/MKS_12864OLED
//
// Tiny, but very sharp OLED display
//
//#define MKS_12864OLED          // Uses the SH1106 controller
//#define MKS_12864OLED_SSD1306  // Uses the SSD1306 controller

//
// Zonestar OLED 128×64 Full Graphics Controller
//
//#define ZONESTAR_12864LCD           // Graphical (DOGM) with ST7920 controller
//#define ZONESTAR_12864OLED          // 1.3" OLED with SH1106 controller
//#define ZONESTAR_12864OLED_SSD1306  // 0.96" OLED with SSD1306 controller

//
// Einstart S OLED SSD1306
//
//#define U8GLIB_SH1106_EINSTART

//
// Overlord OLED display/controller with i2c buzzer and LEDs
//
//#define OVERLORD_OLED

//
// FYSETC OLED 2.42" 128×64 Full Graphics Controller with WS2812 RGB
// Where to find : https://www.aliexpress.com/item/4000345255731.html
//#define FYSETC_242_OLED_12864   // Uses the SSD1309 controller

//
// K.3D SSD1309 OLED 2.42" 128×64 Full Graphics Controller
//
//#define K3D_242_OLED_CONTROLLER   // Software SPI

//=============================================================================
//========================== Extensible UI Displays ===========================
//=============================================================================

/**
 * DGUS Touch Display with DWIN OS. (Choose one.)
 *
 * ORIGIN (Marlin DWIN_SET)
 *  - Download https://github.com/coldtobi/Marlin_DGUS_Resources
 *  - Copy the downloaded DWIN_SET folder to the SD card.
 *  - Product: https://www.aliexpress.com/item/32993409517.html
 *
 * FYSETC (Supplier default)
 *  - Download https://github.com/FYSETC/FYSTLCD-2.0
 *  - Copy the downloaded SCREEN folder to the SD card.
 *  - Product: https://www.aliexpress.com/item/32961471929.html
 *
 * HIPRECY (Supplier default)
 *  - Download https://github.com/HiPrecy/Touch-Lcd-LEO
 *  - Copy the downloaded DWIN_SET folder to the SD card.
 *
 * MKS (MKS-H43) (Supplier default)
 *  - Download https://github.com/makerbase-mks/MKS-H43
 *  - Copy the downloaded DWIN_SET folder to the SD card.
 *  - Product: https://www.aliexpress.com/item/1005002008179262.html
 *
 * RELOADED (T5UID1)
 *  - Download https://github.com/Neo2003/DGUS-reloaded/releases
 *  - Copy the downloaded DWIN_SET folder to the SD card.
 *
 * IA_CREALITY (T5UID1)
 *  - Download https://github.com/InsanityAutomation/Marlin/raw/CrealityDwin_2.0/TM3D_Combined480272_Landscape_V7.7z
 *  - Copy the downloaded DWIN_SET folder to the SD card.
 *
 * E3S1PRO (T5L)
 *  - Download https://github.com/CrealityOfficial/Ender-3S1/archive/3S1_Plus_Screen.zip
 *  - Copy the downloaded DWIN_SET folder to the SD card.
 *
 * Flash display with DGUS Displays for Marlin:
 *  - Format the SD card to FAT32 with an allocation size of 4kb.
 *  - Download files as specified for your type of display.
 *  - Plug the microSD card into the back of the display.
 *  - Boot the display and wait for the update to complete.
 *
 * :[ 'ORIGIN', 'FYSETC', 'HYPRECY', 'MKS', 'RELOADED', 'IA_CREALITY', 'E3S1PRO' ]
 */
//#define DGUS_LCD_UI ORIGIN
#if DGUS_UI_IS(MKS)
  #define USE_MKS_GREEN_UI
#elif DGUS_UI_IS(IA_CREALITY)
  //#define LCD_SCREEN_ROTATE 90          // Portrait Mode or 800x480 displays
  //#define IA_CREALITY_BOOT_DELAY 1500   // (ms)
#endif

//
// Touch-screen LCD for Malyan M200/M300 printers
//
//#define MALYAN_LCD

//
// Touch UI for FTDI EVE (FT800/FT810) displays
// See Configuration_adv.h for all configuration options.
//
//#define TOUCH_UI_FTDI_EVE

//
// Touch-screen LCD for Anycubic Chiron
//
//#define ANYCUBIC_LCD_CHIRON

//
// Touch-screen LCD for Anycubic i3 Mega
//
//#define ANYCUBIC_LCD_I3MEGA
#if ENABLED(ANYCUBIC_LCD_I3MEGA)
  //#define ANYCUBIC_LCD_GCODE_EXT  // Add ".gcode" to menu entries for DGUS clone compatibility
#endif

//
// Touch-screen LCD for Anycubic Vyper
//
//#define ANYCUBIC_LCD_VYPER

//
// Sovol SV-06 Resistive Touch Screen
//
//#define SOVOL_SV06_RTS

//
// 320x240 Nextion 2.8" serial TFT Resistive Touch Screen NX3224T028
//
//#define NEXTION_TFT

//
// Third-party or vendor-customized controller interfaces.
// Sources should be installed in 'src/lcd/extui'.
//
//#define EXTENSIBLE_UI

#if ENABLED(EXTENSIBLE_UI)
  //#define EXTUI_LOCAL_BEEPER // Enables use of local Beeper pin with external display
#endif

//=============================================================================
//=============================== Graphical TFTs ==============================
//=============================================================================

/**
 * Specific TFT Model Presets. Enable one of the following options
 * or enable TFT_GENERIC and set sub-options.
 */

//
// 480x320, 3.5", SPI Display with Rotary Encoder from MKS
// Usually paired with MKS Robin Nano V2 & V3
// https://github.com/makerbase-mks/MKS-TFT-Hardware/tree/master/MKS%20TS35
//
//#define MKS_TS35_V2_0

//
// 320x240, 2.4", FSMC Display From MKS
// Usually paired with MKS Robin Nano V1.2
//
//#define MKS_ROBIN_TFT24

//
// 320x240, 2.8", FSMC Display From MKS
// Usually paired with MKS Robin Nano V1.2
//
//#define MKS_ROBIN_TFT28

//
// 320x240, 3.2", FSMC Display From MKS
// Usually paired with MKS Robin Nano V1.2
//
//#define MKS_ROBIN_TFT32

//
// 480x320, 3.5", FSMC Display From MKS
// Usually paired with MKS Robin Nano V1.2
//
//#define MKS_ROBIN_TFT35

//
// 480x272, 4.3", FSMC Display From MKS
//
//#define MKS_ROBIN_TFT43

//
// 320x240, 3.2", FSMC Display From MKS
// Usually paired with MKS Robin
//
//#define MKS_ROBIN_TFT_V1_1R

//
// 480x320, 3.5", FSMC Stock Display from Tronxy
//
//#define TFT_TRONXY_X5SA

//
// 480x320, 3.5", FSMC Stock Display from AnyCubic
//
//#define ANYCUBIC_TFT35

//
// 320x240, 2.8", FSMC Stock Display from Longer/Alfawise
//
//#define LONGER_LK_TFT28

//
// 320x240, 2.8", FSMC Stock Display from ET4
//
//#define ANET_ET4_TFT28

//
// 480x320, 3.5", FSMC Stock Display from ET5
//
//#define ANET_ET5_TFT35

//
// 1024x600, 7", RGB Stock Display with Rotary Encoder from BIQU BX
// https://github.com/bigtreetech/BIQU-BX/tree/master/Hardware
//
//#define BIQU_BX_TFT70

//
// 480x320, 3.5", SPI Stock Display with Rotary Encoder from BIQU B1 SE Series
// https://github.com/bigtreetech/TFT35-SPI/tree/master/v1
//
//#define BTT_TFT35_SPI_V1_0

//
// Generic TFT with detailed options
//
//#define TFT_GENERIC
#if ENABLED(TFT_GENERIC)
  // :[ 'AUTO', 'ST7735', 'ST7789', 'ST7796', 'R61505', 'ILI9328', 'ILI9341', 'ILI9488' ]
  #define TFT_DRIVER AUTO

  // Interface. Enable one of the following options:
  //#define TFT_INTERFACE_FSMC
  //#define TFT_INTERFACE_SPI

  // TFT Resolution. Enable one of the following options:
  //#define TFT_RES_320x240
  //#define TFT_RES_480x272
  //#define TFT_RES_480x320
  //#define TFT_RES_1024x600
#endif

/**
 * TFT UI - User Interface Selection. Enable one of the following options:
 *
 *   TFT_CLASSIC_UI - Emulated DOGM - 128x64 Upscaled
 *   TFT_COLOR_UI   - Marlin Default Menus, Touch Friendly, using full TFT capabilities
 *   TFT_LVGL_UI    - A Modern UI using LVGL
 *
 *   For LVGL_UI also copy the 'assets' folder from the build directory to the
 *   root of your SD card, together with the compiled firmware.
 */
//#define TFT_CLASSIC_UI
//#define TFT_COLOR_UI
//#define TFT_LVGL_UI

#if ENABLED(TFT_COLOR_UI)
  /**
   * TFT Font for Color UI. Choose one of the following:
   *
   * NOTOSANS  - Default font with anti-aliasing. Supports Latin Extended and non-Latin characters.
   * UNIFONT   - Lightweight font, no anti-aliasing. Supports Latin Extended and non-Latin characters.
   * HELVETICA - Lightweight font, no anti-aliasing. Supports Basic Latin (0x0020-0x007F) and Latin-1 Supplement (0x0080-0x00FF) characters only.
   */
  #define TFT_FONT  NOTOSANS

  /**
   * TFT Theme for Color UI. Choose one of the following or add a new one to 'Marlin/src/lcd/tft/themes' directory
   *
   * BLUE_MARLIN  - Default theme with 'midnight blue' background
   * BLACK_MARLIN - Theme with 'black' background
   * ANET_BLACK   - Theme used for Anet ET4/5
   */
  #define TFT_THEME BLACK_MARLIN

  //#define TFT_SHARED_IO   // I/O is shared between TFT display and other devices. Disable async data transfer.

  #define COMPACT_MARLIN_BOOT_LOGO  // Use compressed data to save Flash space
#endif

#if ENABLED(TFT_LVGL_UI)
  //#define MKS_WIFI_MODULE // MKS WiFi module
#endif

/**
 * TFT Rotation. Set to one of the following values:
 *
 *   TFT_ROTATE_90,  TFT_ROTATE_90_MIRROR_X,  TFT_ROTATE_90_MIRROR_Y,
 *   TFT_ROTATE_180, TFT_ROTATE_180_MIRROR_X, TFT_ROTATE_180_MIRROR_Y,
 *   TFT_ROTATE_270, TFT_ROTATE_270_MIRROR_X, TFT_ROTATE_270_MIRROR_Y,
 *   TFT_MIRROR_X, TFT_MIRROR_Y, TFT_NO_ROTATION
 *
 * :{ 'TFT_NO_ROTATION':'None', 'TFT_ROTATE_90':'90°', 'TFT_ROTATE_90_MIRROR_X':'90° (Mirror X)', 'TFT_ROTATE_90_MIRROR_Y':'90° (Mirror Y)', 'TFT_ROTATE_180':'180°', 'TFT_ROTATE_180_MIRROR_X':'180° (Mirror X)', 'TFT_ROTATE_180_MIRROR_Y':'180° (Mirror Y)', 'TFT_ROTATE_270':'270°', 'TFT_ROTATE_270_MIRROR_X':'270° (Mirror X)', 'TFT_ROTATE_270_MIRROR_Y':'270° (Mirror Y)', 'TFT_MIRROR_X':'Mirror X', 'TFT_MIRROR_Y':'Mirror Y' }
 */
//#define TFT_ROTATION TFT_NO_ROTATION

//=============================================================================
//============================  Other Controllers  ============================
//=============================================================================

//
// Ender-3 v2 OEM display. A DWIN display with Rotary Encoder.
//
//#define DWIN_CREALITY_LCD           // Creality UI
//#define DWIN_LCD_PROUI              // Pro UI by MRiscoC
//#define DWIN_CREALITY_LCD_JYERSUI   // Jyers UI by Jacob Myers
//#define DWIN_MARLINUI_PORTRAIT      // MarlinUI (portrait orientation)
//#define DWIN_MARLINUI_LANDSCAPE     // MarlinUI (landscape orientation)

//
// Touch Screen Settings
//
//#define TOUCH_SCREEN
#if ENABLED(TOUCH_SCREEN)
  #define BUTTON_DELAY_EDIT      50 // (ms) Button repeat delay for edit screens
  #define BUTTON_DELAY_MENU     250 // (ms) Button repeat delay for menus

  #if ANY(TFT_CLASSIC_UI, TFT_COLOR_UI)
    //#define NO_BACK_MENU_ITEM     // Don't display a top menu item to go back to the parent menu
  #endif

  #define TOUCH_SCREEN_CALIBRATION

  //#define TOUCH_CALIBRATION_X 12316
  //#define TOUCH_CALIBRATION_Y -8981
  //#define TOUCH_OFFSET_X        -43
  //#define TOUCH_OFFSET_Y        257
  //#define TOUCH_ORIENTATION TOUCH_LANDSCAPE

  #if ALL(TOUCH_SCREEN_CALIBRATION, EEPROM_SETTINGS)
    #define TOUCH_CALIBRATION_AUTO_SAVE // Auto save successful calibration values to EEPROM
  #endif

  #if ENABLED(TFT_COLOR_UI)
    //#define SINGLE_TOUCH_NAVIGATION
  #endif
#endif

//
// RepRapWorld REPRAPWORLD_KEYPAD v1.1
// https://reprapworld.com/products/electronics/ramps/keypad_v1_0_fully_assembled/
//
//#define REPRAPWORLD_KEYPAD
#if ENABLED(REPRAPWORLD_KEYPAD)
  //#define REPRAPWORLD_KEYPAD_MOVE_STEP 10.0 // (mm) Distance to move per key-press
#endif

//
// EasyThreeD ET-4000+ with button input and status LED
//
//#define EASYTHREED_UI

//=============================================================================
//=============================== Extra Features ==============================
//=============================================================================

// @section fans

// Set number of user-controlled fans. Disable to use all board-defined fans.
// :[1,2,3,4,5,6,7,8]
//#define NUM_M106_FANS 1

/**
 * Use software PWM to drive the fan, as for the heaters. This uses a very low frequency
 * which is not as annoying as with the hardware PWM. On the other hand, if this frequency
 * is too low, you should also increment SOFT_PWM_SCALE.
 */
//#define FAN_SOFT_PWM

/**
 * Incrementing this by 1 will double the software PWM frequency, affecting heaters, and
 * the fan if FAN_SOFT_PWM is enabled. However, control resolution will be halved for each
 * increment; at zero value, there are 128 effective control positions.
 * :[0,1,2,3,4,5,6,7]
 */
#define SOFT_PWM_SCALE 0

/**
 * If SOFT_PWM_SCALE is set to a value higher than 0, dithering can be used to mitigate the
 * associated resolution loss. If enabled, some of the PWM cycles are stretched so on average
 * the desired duty cycle is attained.
 */
//#define SOFT_PWM_DITHER

// @section extras

// Support for the BariCUDA Paste Extruder
//#define BARICUDA

// @section lights

/**
 * Temperature status LEDs that display the hotend and bed temperature.
 * If all hotends, bed temperature, and target temperature are under 54C
 * the BLUE led is on. Otherwise the RED led is on. (1C hysteresis)
 */
//#define TEMP_STAT_LEDS

// Support for BlinkM/CyzRgb
//#define BLINKM

// Support for PCA9632 PWM LED driver
//#define PCA9632

// Support for PCA9533 PWM LED driver
//#define PCA9533

/**
 * RGB LED / LED Strip Control
 *
 * Enable support for an RGB LED connected to 5V digital pins, or
 * an RGB Strip connected to MOSFETs controlled by digital pins.
 *
 * Adds the M150 command to set the LED (or LED strip) color.
 * If pins are PWM capable (e.g., 4, 5, 6, 11) then a range of
 * luminance values can be set from 0 to 255.
 * For NeoPixel LED an overall brightness parameter is also available.
 *
 *  === CAUTION ===
 *  LED Strips require a MOSFET Chip between PWM lines and LEDs,
 *  as the Arduino cannot handle the current the LEDs will require.
 *  Failure to follow this precaution can destroy your Arduino!
 *
 *  NOTE: A separate 5V power supply is required! The NeoPixel LED needs
 *  more current than the Arduino 5V linear regulator can produce.
 *
 *  Requires PWM frequency between 50 <> 100Hz (Check HAL or variant)
 *  Use FAST_PWM_FAN, if possible, to reduce fan noise.
 */

// LED Type. Enable only one of the following two options:
//#define RGB_LED
//#define RGBW_LED

#if ANY(RGB_LED, RGBW_LED)
  //#define RGB_LED_R_PIN 34
  //#define RGB_LED_G_PIN 43
  //#define RGB_LED_B_PIN 35
  //#define RGB_LED_W_PIN -1
#endif

#if ANY(RGB_LED, RGBW_LED, PCA9632)
  //#define RGB_STARTUP_TEST              // For PWM pins, fade between all colors
  #if ENABLED(RGB_STARTUP_TEST)
    #define RGB_STARTUP_TEST_INNER_MS 10  // (ms) Reduce or increase fading speed
  #endif
#endif

// Support for Adafruit NeoPixel LED driver
//#define NEOPIXEL_LED
#if ENABLED(NEOPIXEL_LED)
  #define NEOPIXEL_TYPE          NEO_GRBW // NEO_GRBW, NEO_RGBW, NEO_GRB, NEO_RBG, etc.
                                          // See https://github.com/adafruit/Adafruit_NeoPixel/blob/master/Adafruit_NeoPixel.h
  //#define NEOPIXEL_PIN                4 // LED driving pin
  //#define NEOPIXEL2_TYPE  NEOPIXEL_TYPE
  //#define NEOPIXEL2_PIN               5
  #define NEOPIXEL_PIXELS              30 // Number of LEDs in the strip. (Longest strip when NEOPIXEL2_SEPARATE is disabled.)
  #define NEOPIXEL_IS_SEQUENTIAL          // Sequential display for temperature change - LED by LED. Disable to change all LEDs at once.
  #define NEOPIXEL_BRIGHTNESS         127 // Initial brightness (0-255)
  //#define NEOPIXEL_STARTUP_TEST         // Cycle through colors at startup

  // Support for second Adafruit NeoPixel LED driver controlled with M150 S1 ...
  //#define NEOPIXEL2_SEPARATE
  #if ENABLED(NEOPIXEL2_SEPARATE)
    #define NEOPIXEL2_PIXELS           15 // Number of LEDs in the second strip
    #define NEOPIXEL2_BRIGHTNESS      127 // Initial brightness (0-255)
    #define NEOPIXEL2_STARTUP_TEST        // Cycle through colors at startup
    #define NEOPIXEL_M150_DEFAULT      -1 // Default strip for M150 without 'S'. Use -1 to set all by default.
  #else
    //#define NEOPIXEL2_INSERIES          // Default behavior is NeoPixel 2 in parallel
  #endif

  // Use some of the NeoPixel LEDs for static (background) lighting
  //#define NEOPIXEL_BKGD_INDEX_FIRST   0 // Index of the first background LED
  //#define NEOPIXEL_BKGD_INDEX_LAST    5 // Index of the last background LED
  //#define NEOPIXEL_BKGD_COLOR         { 255, 255, 255, 0 }  // R, G, B, W
  //#define NEOPIXEL_BKGD_TIMEOUT_COLOR {  25,  25,  25, 0 }  // R, G, B, W
  //#define NEOPIXEL_BKGD_ALWAYS_ON       // Keep the backlight on when other NeoPixels are off
#endif

/**
 * Printer Event LEDs
 *
 * During printing, the LEDs will reflect the printer status:
 *
 *  - Gradually change from blue to violet as the heated bed gets to target temp
 *  - Gradually change from violet to red as the hotend gets to temperature
 *  - Change to white to illuminate work surface
 *  - Change to green once print has finished
 *  - Turn off after the print has finished and the user has pushed a button
 */
#if ANY(BLINKM, RGB_LED, RGBW_LED, PCA9632, PCA9533, NEOPIXEL_LED)
  #define PRINTER_EVENT_LEDS
#endif

// @section servos

/**
 * Number of servos
 *
 * For some servo-related options NUM_SERVOS will be set automatically.
 * Set this manually if there are extra servos needing manual control.
 * Set to 0 to turn off servo support.
 */
//#define NUM_SERVOS 3 // Note: Servo index starts with 0 for M280-M282 commands

// (ms) Delay before the next move will start, to give the servo time to reach its target angle.
// 300ms is a good value but you can try less delay.
// If the servo can't reach the requested position, increase it.
#define SERVO_DELAY { 300 }

// Only power servos during movement, otherwise leave off to prevent jitter
//#define DEACTIVATE_SERVOS_AFTER_MOVE

// Edit servo angles with M281 and save to EEPROM with M500
//#define EDITABLE_SERVO_ANGLES

// Disable servo with M282 to reduce power consumption, noise, and heat when not in use
//#define SERVO_DETACH_GCODE
