/*
 * ESP32 AJAX Demo
 * Updates and Gets data from webpage without page refresh
 * https://circuits4you.com
 */
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#define led 2
//sensores
 
#include "index.h"  //Web page header file
int ADC[] = {36, 39, 34, 35, 32, 33}; // pines ADC de los sensores MAP

 
WebServer server(80);
 
//Enter your SSID and PASSWORD
const char* ssid = "Sir Pepe V";
const char* password = "fasopucci";
 
//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}
 
void handleADC() {
 int sens[6];
 int a;
 digitalWrite(led, HIGH); 
 String responseText="";
 for(a=0; a<6; a++){
    sens[a]= analogRead(ADC[a]);
    responseText += String(sens[a]);
    responseText += "#";
 }
 Serial.println(responseText);
 String adcValue = String(sens[2]);
 
 server.send(200, "text/plane", responseText); //Send ADC value only to client ajax request
 digitalWrite(led, LOW); 
}
 
//===============================================================
// Setup
//===============================================================
 
void setup(void){
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");
 
/*
//ESP32 As access point
  WiFi.mode(WIFI_AP); //Access Point mode
  WiFi.softAP(ssid, password);
*/
//ESP32 connects to your wifi -----------------------------------
  WiFi.mode(WIFI_STA); //Connectto your wifi
  WiFi.begin(ssid, password);
 
  Serial.println("Connecting to ");
  Serial.print(ssid);
 
  //Wait for WiFi to connect
  while(WiFi.waitForConnectResult() != WL_CONNECTED){      
      Serial.print(".");
    }
    
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
//----------------------------------------------------------------
 
  server.on("/", handleRoot);      //This is display page
  server.on("/readADC", handleADC);//To get update of ADC Value only
 
  server.begin();                  //Start server
  Serial.println("HTTP server started");
}
 
//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void loop(void){
  server.handleClient();
  delay(1);
}

