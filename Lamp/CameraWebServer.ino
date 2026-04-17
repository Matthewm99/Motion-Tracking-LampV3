#include "esp_camera.h"
#include <WiFi.h>
#include <ESP32Servo.h>
#include <WiFiUdp.h>
#include "board_config.h"

const char* ssid = "LuxoLamp";
const char* password = "12345678";

WiFiUDP udp;
const int udpPort = 4210;
char packetBuffer[10];

Servo servoY;

void startCameraServer();

void setup() {
  Serial.begin(115200);

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_QVGA;
  config.jpeg_quality = 15;
  config.fb_count = 1;
  config.grab_mode = CAMERA_GRAB_LATEST;
  config.fb_location = CAMERA_FB_IN_PSRAM;

  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed: 0x%x", err);
    return;
  }

  sensor_t *s = esp_camera_sensor_get();
  s->set_vflip(s, 1);

  WiFi.softAP(ssid, password);
  Serial.println("WiFi AP started");
  Serial.println(WiFi.softAPIP());

  // 🔥 THIS IS THE MISSING PIECE
  startCameraServer();

  udp.begin(udpPort);
  servoY.attach(14);
}

void loop() {
  int packetSize = udp.parsePacket();

  if (packetSize) {
    int len = udp.read(packetBuffer, 10);
    if (len > 0) packetBuffer[len] = 0;

    int y = atoi(packetBuffer);

    int angle = map(y, 0, 240, 30, 150);
    angle = constrain(angle, 30, 150);

    servoY.write(angle);

    Serial.println(angle);
  }

  delay(5);
}