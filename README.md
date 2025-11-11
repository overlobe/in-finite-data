# ESP32 Code Repository

A comprehensive ESP32 development repository with examples and starter code for building IoT projects.

## Features

- Ready-to-use ESP32 project structure
- Multiple example programs demonstrating ESP32 capabilities
- PlatformIO configuration for easy development
- Support for ESP32, ESP32-S3, and ESP32-C3 boards

## Project Structure

```
.
├── src/              # Main source code
│   └── main.cpp      # WiFi connection example
├── include/          # Header files
├── lib/              # Custom libraries
├── examples/         # Example programs
│   ├── blink.cpp     # Basic LED blink
│   └── wifi_scanner.cpp  # WiFi network scanner
├── platformio.ini    # PlatformIO configuration
└── README.md
```

## Getting Started

### Prerequisites

- [PlatformIO](https://platformio.org/) (recommended) or Arduino IDE
- ESP32 development board
- USB cable for programming

### Installation with PlatformIO

1. Install [Visual Studio Code](https://code.visualstudio.com/)
2. Install the [PlatformIO IDE extension](https://platformio.org/install/ide?install=vscode)
3. Clone this repository:
   ```bash
   git clone <your-repo-url>
   cd <repo-name>
   ```
4. Open the project in VS Code
5. PlatformIO will automatically install dependencies

### Usage

#### 1. WiFi Connection Example (Default)

The main program (`src/main.cpp`) demonstrates WiFi connectivity:

- Update WiFi credentials in `src/main.cpp`
- Build and upload to your ESP32
- Open Serial Monitor (115200 baud) to see connection status

#### 2. WiFi Scanner Example

To use the WiFi scanner:

1. Copy `examples/wifi_scanner.cpp` to `src/main.cpp`
2. Build and upload
3. Open Serial Monitor to see available networks

#### 3. Blink Example

To use the basic blink example:

1. Copy `examples/blink.cpp` to `src/main.cpp`
2. Build and upload
3. Watch the built-in LED blink

### Building and Uploading

#### Using PlatformIO

```bash
# Build the project
pio run

# Upload to board
pio run --target upload

# Open serial monitor
pio device monitor

# Build, upload, and monitor in one command
pio run --target upload && pio device monitor
```

#### Using PlatformIO IDE

- Click the ✓ icon to build
- Click the → icon to upload
- Click the 🔌 icon to open serial monitor

### Board Selection

The project supports multiple ESP32 variants. Edit `platformio.ini` to select your board:

- `env:esp32dev` - Standard ESP32
- `env:esp32-s3` - ESP32-S3
- `env:esp32-c3` - ESP32-C3

Uncomment the desired environment or specify it during build:
```bash
pio run -e esp32-s3
```

## Pin Reference

### ESP32 DevKit v1 (30-pin)

- Built-in LED: GPIO 2
- Touch sensors: GPIO 0, 2, 4, 12, 13, 14, 15, 27, 32, 33
- ADC1: GPIO 32-39
- ADC2: GPIO 0, 2, 4, 12-15, 25-27
- I2C (default): SDA=GPIO21, SCL=GPIO22
- SPI (default): MOSI=GPIO23, MISO=GPIO19, SCK=GPIO18, CS=GPIO5
- UART: TX=GPIO1, RX=GPIO3

### Common GPIO Notes

- Avoid GPIO 6-11 (connected to flash)
- GPIO 0 is used for boot mode selection
- GPIO 34-39 are input-only (no pull-up/pull-down)

## Examples Included

### 1. WiFi Connection (`src/main.cpp`)
- Connect to WiFi network
- Display connection status and IP address
- Auto-reconnect on disconnection
- LED indication (blinking while connecting, solid when connected)

### 2. WiFi Scanner (`examples/wifi_scanner.cpp`)
- Scan for available WiFi networks
- Display SSID, signal strength, channel, and encryption
- Continuous scanning every 5 seconds

### 3. Blink (`examples/blink.cpp`)
- Simple LED blink example
- Good for testing board functionality

## Adding Libraries

Edit `platformio.ini` and add libraries to `lib_deps`:

```ini
lib_deps =
    bblanchon/ArduinoJson@^6.21.3
    knolleary/PubSubClient@^2.8
```

## Troubleshooting

### Upload Issues

- Make sure the correct port is selected
- Press and hold the BOOT button during upload if needed
- Check USB cable (must support data transfer)

### WiFi Not Connecting

- Verify SSID and password are correct
- Ensure 2.4GHz WiFi (ESP32 doesn't support 5GHz)
- Check if WiFi network is in range

### Serial Monitor Shows Garbage

- Ensure baud rate is set to 115200
- Try pressing the EN (reset) button on the board

## Resources

- [ESP32 Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
- [PlatformIO Documentation](https://docs.platformio.org/)
- [Arduino-ESP32 Reference](https://docs.espressif.com/projects/arduino-esp32/en/latest/)

## License

This project is open source and available for educational and commercial use.

## Contributing

Feel free to submit issues and pull requests!
