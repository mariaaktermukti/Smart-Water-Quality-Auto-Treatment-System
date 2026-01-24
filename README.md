# Smart-Water-Quality-Auto-Treatment-System
This project presents a smart water quality monitoring system using Arduino Uno. It measures pH, TDS, and temperature in real time and displays the data on an OLED screen. The system automatically detects unsafe water, activates purification, and sends alerts via ESP32 for remote monitoring.


⚙️ Updated System Functionalities

🔹 Feature 1: Real-Time Water Quality Monitoring
Measures pH, TDS, and temperature of drinking water continuously
Displays real-time sensor values on an OLED display
Arduino Uno works as the main controller
Provides instant visual feedback of water condition

🔹 Feature 2: Intelligent Water Safety Decision & Automatic Purification
System continuously evaluates water quality parameters
Automatically determines SAFE or UNSAFE water condition
If water is SAFE:
     System remains idle
     No motor or purification process is activated
If water is UNSAFE:
     The water treatment motor/pump turns ON automatically
     The purification process starts without any user intervention
     Motor runs for a predefined fixed treatment time
Ensures efficient use of electricity and water
Eliminates the need for manual monitoring or control

🔹 Feature 3: ESP-Based Notification & Remote Monitoring
Real-time water quality data is sent to ESP32
ESP32 monitors water safety status remotely
Instant notification/alert is sent to the user when water becomes unsafe
Enables remote awareness without physical presence
Improves safety, reliability, and user convenience

🧠 Water Safety Logic (Decision Flow):
Condition	            System Action
Water SAFE	          Motor OFF, Monitoring continues
Water UNSAFE	        Motor ON, Automatic purification starts
Unsafe detected	      ESP32 sends notification

🖥️ OLED Display Output:
The OLED display shows:
pH value
TDS value (ppm)
Temperature (°C)
Final water status: SAFE / NOT SAFE

🔄 System Workflow :
Sensors collect pH, TDS, and temperature data
Arduino analyzes the data using predefined thresholds
Water safety status is determined
If unsafe:
    Motor turns ON
    Purification process starts
    
ESP32 sends alert to the user
If safe:
   System continues monitoring

🚀 Extended Benefits:
Fully automatic operation
No manual intervention required
Reduces human error

Saves electricity and water

Suitable for smart homes and rural water systems
