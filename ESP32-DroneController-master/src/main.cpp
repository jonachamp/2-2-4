#include <Arduino.h>
#include <string.h>
#include <drone.h>
#include <joystick.h>

String ssid = "TELLO-FE2F6B";
String password = "";

Drone drone(ssid, password);
Joystick joystick(15, 34, 35); // pins: btn, x, y

void setup()
{
  Serial.begin(9600);

  drone.joystick = &joystick; 

  for (size_t i = 0; i < 5; i++)
  {
    Serial.println(i);
  

    delay(1000);
  }

  joystick.addButtonListener(&drone);
  
  drone.connect();
  //drone.setIp ("192.168.1.146"); // pc packetsender ip adresse
  drone.setIp("192.168.10.1"); //dronens ip adresse

  
}

void loop()
{
  
  joystick.loop();
  drone.loop();;
} 