# ESP32-S3-Remote-Controller
An ESP32-S3 based remote controller for controlling FPV drones and other various remote controller applications. This custom pcb reads analog inputs of two joysticks and joystick button presses. There is also a small RGB-LED installed to quickly test device functionality. This will be used to send commands to a flight controller in a future project.

# Hardware features
- SoC: Espressif ESP32-S3 System-On-Chip dual core with clock speeds up to 240 MHz + Wi-Fi with in buiilt USB CDC with speeds up to 12 Mbit/s
- External Memory: 8 MByte QSPI NOR-Flash, 8 MByte QSPI PSRAM
- RGB LED common anode (ASMB-MTB1-0B3A2)
- 2x THB001P Joysticks
- 2.54 mm pitch connector for connecting an additional I2C device
- 2.54 mm pitch connector for plugging in an USB to FTDI adapter
- USB Type C connector

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
- Bring-Up: PSRAM untested and desoldered for hardware debugging reasons and yet to be teseted, Wi-Fi yet to be tested (Waiting for Antennas and IPX connector order), Joystick, RGB-LED successfully tested

# Difficulties and guide for bring up
- Uploading / Flashing from Arduino IDE does not work
- Used and working IDE: Visual Studio Code with PlatformIO (Arduino Serial Monitor + Plotter working when reading serial data, note: Close serial monitor in PlatformIO in order to work with other serial terminals)
- While Hardware bring-up the vdd_sdio Voltage was set to +1.8 V by factory default. The used QSPI NOR-Flash (W25Q64JVZEIQ) has a minimum operating voltage of +2,7 V (so +3,3 V Logic levels). The vdd_sdio voltage needs to be set up. Download the [ESPtool](https://github.com/espressif/esptool) from Espressif repository. Navigate trough command window to the ESPtool directory and input following
```
python -m espefuse --chip esp32-s3 --port COM3 set_flash_voltage 3.3V
```
- You can also erase the flash by writing following line
```
python -m esptool --chip esp32-s3 --port COM3 erase_flash
```
- For PlatformIO following configurations worked for my custom hardware for the platformio.ini
```
[env:esp32s3]
platform = espressif32
board = esp32-s3-devkitc-1
framework = arduino
monitor_speed = 115200
upload_speed = 921600
board_build.flash_mode = qio      ; QIO für schnelle Übertragung
board_build.flash_size = 8MB     ; 8MB Flash
board_build.partitions = default_8MB.csv
upload_port = COM3
monitor_port = COM3

build_flags =
   -DARDUINO_USB_MODE=1
   -DARDUINO_USB_CDC_ON_BOOT=1
```
- Note to configure the COM-Port according to device manager and how it is recognized by the End device

# Examples
Developed custom pcb

![test](https://github.com/myildirim6198/ESP32-S3-Remote-Controller/blob/main/Images/RemoteControllerImage.jpg?raw=true)

Serial plotter curves of the moved joysticks

![test](https://github.com/myildirim6198/ESP32-S3-Remote-Controller/blob/main/Images/JoysticksImage.png?raw=true)

I make no guarantees as to device funtionality. Please review the components, schematics before production. Make sure all connections are soldered properly!
