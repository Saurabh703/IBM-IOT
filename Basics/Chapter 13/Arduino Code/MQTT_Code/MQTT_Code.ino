#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define WIFI_SSID "realme 7"
#define WIFI_PASS "saurabh123"

#define MQTT_SERV "io.adafruit.com"
#define MQTT_PORT 1883
#define MQTT_NAME "Sylenger2"
#define MQTT_PASS "aio_njXF71UxCyW6UX8zI0ywbiYbR4hJ"

int led = D7;

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, MQTT_SERV, MQTT_PORT, MQTT_NAME, MQTT_PASS);

Adafruit_MQTT_Subscribe onoff = Adafruit_MQTT_Subscribe(&mqtt, MQTT_NAME "/f/ONOFF");
Adafruit_MQTT_Publish LightsStatus = Adafruit_MQTT_Publish(&mqtt, MQTT_NAME "/f/LightsStatus");

void setup() {
  Serial.begin(9600);
  pinMode(LED_BULLTIN, OUTPUT);

  //Connect to Wifi
  Serial.print("\n\nConnecting Wifi>");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  digitalWrite(LED_BULLTIN, LOW);

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(">");
    delay(50);
    }

    Serial.println("OK!");

    //Subscribe to the onoff topic
    mqtt.subscribe($onoff);

    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
  // put your setup code here, to run once:
}

void loop() {
  //Connect/Reconnect to MQTT
  MQTT_connect();

  //Read from our subscription queue until we run out, or 
  //wait up to 5 seconds for subsscription to update
  Adafruit_MQTT_Subscribe * subscription;
  while(subscription = mqtt.readSubscription(5000)){
    //If we're in here, a subscription updated....
    if(subscription == &onoff){
      //Print the new value to the serial monitor
      Serial.print("onoff: ");
      Serial.println((char *) onoff.lastread);

      //If the new value is "ON", turn the light on.
      //Otherwise, turn it off.
      if(!strcmp((char *) onoff.lastread, "ON")){
        //active low logic
//        digitalWrite(led,HIGH);
//        LightsStatus.publish("ON");
//        }else if(!strcmp((char *) onoff.lastread, "OFF")){
//        //active low logic
//        digitalWrite(led, LOW);
//        LightsStatus.publish("OFF");
//        }
//        else{
//          LightsStatus.publish("ERROR");
//          }
      }
    
    }
  // put your main code here, to run repeatedly:
}

void MQTT_connect()
{
  // Stop if already connected
  if(mqtt.connected() && mqtt.ping()){
    
    }
  }
