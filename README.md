# ESP32-S3-Remote-Controller
An ESP32-S3 based remote controller for controlling FPV drones and other vraious remote controller applications. This custom pcb reads analog inputs of two joysticks and joystick button presses. There is also a small RGB-LED installed to quickly test device functionality.

# Hardware features
- SoC: Espressif ESP32-S3 System-On-Chip dual core with clock speeds up to 240 MHz + Wi-Fi with in buiilt USB CDC with speeds up to 12 Mbit/s
- External Memory: 8 MByte QSPI NOR-Flash, 8 MByte QSPI PSRAM
- RGB LED common anode (ASMB-MTB1-0B3A2)
- 2x THB001P Joysticks
- 2.54 mm pitch connector for connecting an additional I2C device
- 2.54 mm pitch connector for plugging in an USB to FTDI adapter

# Applications
- Remote Controller for FPV drones or EDF Planes
- Game controller
- Smart home
- Other Remote controller Applications

# Absolute Maximum Ratings
Supply Voltage: +5V0 to +5V5 (recommended: +5V0) USB supplied. On board Texas Instrumaents Switching Voltage regulator regulating voltage down to +3,3 V. Digital logic levels: +3,3 V.

# Manufacturing Information
- Length = 40mm, Width = 100mm, Thickness = 1.6 mm
- Layers = 4
- Min. Via Hole diameter = 0.3 mm
- Via-Type: Plugged
- Impedance Control: JLC04161H-3313
- Surface Finish: LeadFree HASL
- Material Type: FR-4 TG135-140

# Progress
- Schematic design: complete
- Layouting: complete
- Manufacturing & assembly: complete
- Bring-Up: PSRAM untested and desoldered for hardware debugging reasons and jet to be teseted, Wi-Fi jet to be tested (Waiting for Antennas and IPX connector order), Joystick, RGB-LED successfully tested

# Difficulties and Guide for bring up
- Uploading / Flashing from Arduino IDE does not work
- Used and working IDE Visual Studio Code with PlatformIO (Arduino Serial Monitor + Plotter working when reading serial data, note: Close serial monitor in PlatformIO in order to work with other serial terminals)
- While Hardware bring-up the vdd_sdio Voltage was set to +1.8 V by factory default. The used QSPI NOR-Flash (W25Q64JVZEIQ) has a minimum operating voltage of +2,7 V (so +3,3 V Logic levels). The vdd_sdio voltage needs to be set up. Download the [ESPtool](https://github.com/espressif/esptool) from Espressif repository. Navigate trough command window to the ESPtool directory and input following
```
python -m espefuse --chip esp32-s3 --port COM3 set_flash_voltage 3.3V
