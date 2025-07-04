📢 Targeted Ad Display Automation using ESP32
🎯 Objective
To automate targeted ad display, log operational data, and update real-time data via seamless server integration.

🚀 Features
Automated Ad Display: Displays targeted ads every 10 seconds on a 0.96" OLED display, using content from a Micro SD card.

Operational Data Logging: Logs Date, Time, GPS Location, Ad Name, and Toggle State at regular intervals for traceability.

Real-Time Server Integration: Connects to a remote server via Wi-Fi to update ad settings daily at midnight and upload logs.

🔧 Hardware Used
🧠 ESP32 — main controller with Wi-Fi capability

📍 NEO-6M GPS Module — captures real-time location data

🖥️ 0.96" OLED Display — displays the ads

💾 Micro SD Card & Reader — stores ad content and logs

🎚️ Toggle Switch — manually controls display state

📶 How It Works
On boot, ESP32 reads available ads from SD card.

Every 10 seconds, a new ad is displayed on the OLED screen.

GPS module fetches current location, which is logged with other details.

At midnight, the ESP32 connects to the server to update ad configurations and upload logs.

🛠️ Setup Instructions
Format a Micro SD card and upload ad images/text files.

Connect ESP32 to the OLED display, GPS module, SD card reader, and toggle switch as per circuit diagram.

Flash the code using Arduino IDE or PlatformIO.

Ensure Wi-Fi credentials and server URLs are configured in the code.

Power up the ESP32 and monitor the serial output for debugging.

🔄 Future Improvements
Add OTA updates for remote firmware upgrades

Improve UI for OLED ad transitions

Add web-based dashboard for remote log monitoring
