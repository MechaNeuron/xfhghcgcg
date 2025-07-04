#include <SD.h>
#include <SPI.h>
#include <WiFi.h>
#include <HTTPClient.h>


// SD card chip select pin
#define SD_CS 5


// WiFi credentials
const char* ssid = "Airtel_aadi_0056";
const char* password = "air65319";


// Server URLs
const char* postUrl = "https://pixelads.onrender.com/api/daily/upload";
const char* getUrl = "https://pixelads.onrender.com/api/location/hotspotdata";


// Car ID
const char* carId = "HR36A1905";


unsigned long lastDataSendTime = 0;
const unsigned long dataSendInterval = 10000; // Send data every 1 minute


// Function prototypes
void postToServer(const char* carID, const char* filename);
void getFromServer();


void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);


  // Initialize SD card
  Serial.print("Initializing SD card...");
  if (!SD.begin(SD_CS)) {
    Serial.println("Card failed, or not present");
    while (1);
  }
  Serial.println("Card initialized.");


  // Connect to WiFi
  Serial.print("Connecting to WiFi SSID: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);


  unsigned long startAttemptTime = millis();


  // Attempt to connect to WiFi for 10 seconds
  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
    delay(500);
    Serial.print(".");
  }


  // Check if connected to WiFi
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected.");
  } else {
    Serial.println("\nFailed to connect to WiFi.");
    while (1); // Don't proceed, loop forever
  }


  Serial.println("Setup complete, entering loop.");
}


void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastDataSendTime >= dataSendInterval) {
    lastDataSendTime = currentMillis;


    // Send entire file content to server
    postToServer(carId, "/rd.txt");
  }


  // Periodically fetch data from server
  static unsigned long lastGetRequestTime = 0;
  if (currentMillis - lastGetRequestTime >= 10000) { // Fetch data every 60 seconds
    lastGetRequestTime = currentMillis;

