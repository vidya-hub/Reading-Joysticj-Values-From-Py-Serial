
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int mapX = 0;
int mapY = 0;
char auth[] = "4ssDYO0LRRoMwQHFPWvlakkGF0bYaptf";
char ssid[] = "Sagar";
char pass[] = "password";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}
BLYNK_WRITE(V1) 
{
  int pinData_x = param[0].asInt(); 
  int pinData_y = param[1].asInt();
  Serial.print(pinData_x);
  Serial.print("\t");
  Serial.println(pinData_y);
}

void loop()
{
  Blynk.run();
}
