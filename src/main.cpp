#include <Arduino.h>

#include "main.h"
#include "led.h"
#include "debug.h"
#include "wifi-connection.h"
#include "mqtt-client.h"

// cppcheck-suppress unusedFunction
void setup()
{

  initDebugging();

  pinMode(led_built_in_ESP, OUTPUT);
  pinMode(led_built_in_Node, OUTPUT);
  digitalWrite(led_built_in_Node, HIGH);
  digitalWrite(led_built_in_ESP, HIGH);

  MqttClient mqttClient;
  mqttClient.init();

  std::list<WifiDependent *> deps;
  deps.push_back(&mqttClient);

  WifiConnection::getInstance().init(deps);
}

// cppcheck-suppress unusedFunction
void loop()
{
  blinkLed();
}

void blinkLed()
{
  digitalWrite(led_built_in_Node, LOW);
  delay(2500);
  digitalWrite(led_built_in_Node, HIGH);
  delay(2500);
}