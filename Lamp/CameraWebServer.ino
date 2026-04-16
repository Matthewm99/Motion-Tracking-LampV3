// #include "esp_camera.h"
// #include <WiFi.h>
// #include <ESP32Servo.h>
// #include <WebServer.h>
// #include "board_config.h"

// Servo servoY;
// WebServer server(82);

// const char* ssid = "LuxoLamp";
// const char* password = "12345678";

// void startCameraServer();
// void setupLedFlash();

// void handleServo() {
//   static unsigned long lastMove = 0;

//   if (server.hasArg("y")) {
//     // 🔥 LIMIT SERVO UPDATES (fixes crashing)
//     if (millis() - lastMove > 80) {  // ~12 Hz
//       int y = server.arg("y").toInt();

//       int angle = map(y, 0, 480, 30, 150);
//       angle = constrain(angle, 30, 150);

//       servoY.write(angle);

//       lastMove = millis();
//     }
//   }

//   server.send(200, "text/plain", "OK");
// }

// void setup() {
//   Serial.begin(115200);

//   camera_config_t config;
//   config.ledc_channel = LEDC_CHANNEL_0;
//   config.ledc_timer = LEDC_TIMER_0;
//   config.pin_d0 = Y2_GPIO_NUM;
//   config.pin_d1 = Y3_GPIO_NUM;
//   config.pin_d2 = Y4_GPIO_NUM;
//   config.pin_d3 = Y5_GPIO_NUM;
//   config.pin_d4 = Y6_GPIO_NUM;
//   config.pin_d5 = Y7_GPIO_NUM;
//   config.pin_d6 = Y8_GPIO_NUM;
//   config.pin_d7 = Y9_GPIO_NUM;
//   config.pin_xclk = XCLK_GPIO_NUM;
//   config.pin_pclk = PCLK_GPIO_NUM;
//   config.pin_vsync = VSYNC_GPIO_NUM;
//   config.pin_href = HREF_GPIO_NUM;
//   config.pin_sccb_sda = SIOD_GPIO_NUM;
//   config.pin_sccb_scl = SIOC_GPIO_NUM;
//   config.pin_pwdn = PWDN_GPIO_NUM;
//   config.pin_reset = RESET_GPIO_NUM;

//   config.xclk_freq_hz = 20000000;
//   config.pixel_format = PIXFORMAT_JPEG;

//   // 🔥 PERFORMANCE SETTINGS
//   config.frame_size = FRAMESIZE_QVGA;
//   config.jpeg_quality = 12;
//   config.fb_count = 1;

//   esp_err_t err = esp_camera_init(&config);
//   if (err != ESP_OK) {
//     Serial.println("Camera init failed");
//     return;
//   }

//   sensor_t *s = esp_camera_sensor_get();
//   s->set_framesize(s, FRAMESIZE_QVGA);
//   s->set_vflip(s, 1);   // fix upside down

//   WiFi.softAP(ssid, password);
//   Serial.println("WiFi AP started: 192.168.4.1");

//   startCameraServer();

//   servoY.attach(13);

//   server.on("/servo", handleServo);
//   server.begin();
// }

// void loop() {
//   server.handleClient();
// }