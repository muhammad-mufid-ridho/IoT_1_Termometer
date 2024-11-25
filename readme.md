# ESP32 Temperature Monitoring with Ubidots

This project demonstrates how to send temperature data from an ESP32 using a DHT22 sensor to Ubidots for monitoring. The data is sent over WiFi, and it can be visualized in a Ubidots dashboard.

## Components Used:
- **ESP32**: A powerful microcontroller with built-in WiFi.
- **DHT22 Sensor**: A sensor for measuring temperature and humidity.
- **Ubidots Account**: A cloud platform to store and visualize data.

## Libraries Used:
- **WiFi.h**: For connecting to WiFi.
- **HTTPClient.h**: For sending HTTP requests.
- **DHT.h**: For reading the temperature and humidity from the DHT22 sensor.

## Setup

### 1. Install the Required Libraries
To use this project, you need to install the following libraries in the Arduino IDE:

- **WiFi**: Used to connect the ESP32 to the WiFi network.
- **HTTPClient**: For making HTTP requests to send data to Ubidots.
- **DHT sensor library**: To interface with the DHT22 sensor.

You can install them using the Library Manager in Arduino IDE:
1. Go to **Sketch > Include Library > Manage Libraries**.
2. Search and install the **WiFi**, **HTTPClient**, and **DHT** libraries.

### 2. Ubidots Setup
1. Create an account on [Ubidots](https://ubidots.com/).
2. After logging in, create a new device called `ESP32_Termometer` and add a new variable called `temperature` to it.
3. Obtain your **Ubidots API token** from the Ubidots dashboard by going to **Account Settings > API Keys**.

### 3. WiFi Configuration
Update the following WiFi credentials in the code:

```cpp
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
