#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL35S2a0jQP"
#define BLYNK_TEMPLATE_NAME "ServoControl"
#define BLYNK_AUTH_TOKEN "26THcgkObVMEALkXjxd-8kHDD2aq-qCc"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo;

  int lastPosition = 0;
  int onnPos = 1550;  // clockwise direction
  int offPos = 1400;  // counter-clockwise direction

  char auth[] = BLYNK_AUTH_TOKEN;

  char ssid[] = "Your_SSID";
  char pass[] = "Your_Password";


void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  servo.attach(D4);
}

  void loop() {
    Blynk.run();
  }

  BLYNK_WRITE(V0) {
    int value = param.asInt();
    Serial.println(value);

    if (value == 1 && lastPosition != onnPos) {
      servo.attach(D4);
      servo.writeMicroseconds(onnPos);
      delay(500);
      servo.detach();
      lastPosition = onnPos;
    } else if (value == 0 && lastPosition != offPos) {
      servo.attach(D4);
      servo.writeMicroseconds(offPos);
      delay(500);
      servo.detach();
      lastPosition = offPos;
    }
  }
