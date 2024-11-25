// inisiasi library
#include <Arduino.h>

#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

// konfigurasi Wifi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

//konfigurasi Ubidots
String ubidotsToken = "BBUS-JgGhcAfTPwZBXfgiw9cawlh0RWPQcJ";
String deviceLabel = "ESP32_Termometer";
String variableLabel = "temperature";

// konfigurasi DHT22
#define DHTPIN 12
#define DHTTYPE DHT22

// inisiasi sensor DHT
DHT dht(DHTPIN, DHTTYPE);

// Prototipe fungsi
void sendToUbidots(float value);

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.print("Sedang menghubungkan ke Wifi");
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("Wifi Terhubung");
  dht.begin();
}

void loop(){
  float temperature = dht.readTemperature();

  if (isnan(temperature)){
    Serial.println("Gagal membaca sensor");
    return;
  };

  Serial.print("Suhu: ");
  Serial.println(temperature);

  if (WiFi.status() == WL_CONNECTED){
    sendToUbidots(temperature);
  } else
  {
    Serial.println("Wifi terputus");
  }
  delay(3000);
}

void sendToUbidots(float value) {
  HTTPClient http;

  String url = "http://industrial.api.ubidots.com/api/v1.6/devices/" + deviceLabel;
  String payload = "{\"" + variableLabel + "\":" + String(value) + "}";

  http.begin(url.c_str());
  http.addHeader("Content-Type", "application/json");
  http.addHeader("X-Auth-Token", ubidotsToken);

  int httpResponseCode = http.POST(payload);

  if (httpResponseCode > 0) {
    Serial.print("Data berhasil dikirim, kode respons: ");
    Serial.println(httpResponseCode);
  } else {
    Serial.print("Gagal mengirim data, kode respons: ");
    Serial.println(httpResponseCode);
  }

  http.end();
  delay(1000);
}

