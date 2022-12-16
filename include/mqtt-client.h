#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include <AsyncMqttClient.h>
#include "wifi-dependent.h"

class MqttClient : public WifiDependent
{

public:
  void init();
  virtual void onWifiConnectionEstablished() override;
  virtual void onWifiConnectionLost() override;

private:
  void connect();
  void onConnect(boolean sessionPresent);
  void onDisconnect(AsyncMqttClientDisconnectReason reason);
  void onMessage(char *topic, char *payload, AsyncMqttClientMessageProperties properties, size_t len, size_t index, size_t total);
};

#endif // MQTT_CLIENT_H