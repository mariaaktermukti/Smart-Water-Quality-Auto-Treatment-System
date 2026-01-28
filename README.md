# 📌 Smart Water Quality Monitoring System

---

## 📘 Project Introduction
This project presents a **smart water quality monitoring system** using Arduino Uno.  
It measures **pH, TDS, and temperature** in real time and displays the data on an **OLED screen**.  
The system automatically detects unsafe water, activates purification, and sends alerts via **ESP32** for remote monitoring.

---

## ⚙️ System Functionalities

### 🔹 Feature 1: Real-Time Water Quality Monitoring
- Measures **pH, TDS, and temperature** continuously  
- Displays real-time sensor values on an **OLED display**  
- **Arduino Uno** works as the main controller  
- Provides instant visual feedback of water condition

---![photo_2026-01-20_18-39-39](https://github.com/user-attachments/assets/c3e1e575-b340-4093-bc62-d611e60fc39b)


### 🔹 Feature 2: Intelligent Water Safety Decision & Automatic Purification
- Continuously evaluates water quality parameters  
- Automatically determines **SAFE / UNSAFE** water condition  

**If Water is SAFE:**  
- System remains idle  
- Motor and purification process remain OFF  

**If Water is UNSAFE:**  
- **Water treatment motor/pump turns ON automatically**  
- Purification starts without user intervention  
- Motor runs for a **predefined fixed treatment time**  
- Reduces electricity and water wastage  

---

### 🔹 Feature 3: ESP-Based Notification & Remote Monitoring
- Real-time water quality data is sent to **ESP32**  
- ESP32 monitors water safety status remotely  
- **Instant alert/notification** is sent to the user when water is unsafe  
- Enables monitoring without physical presence  
- Improves safety and user awareness  

---

## 🧠 Water Safety Logic (Decision Flow)

| Condition       | System Action                                 |
|-----------------|-----------------------------------------------|
| Water SAFE      | Motor OFF, Monitoring continues               |
| Water UNSAFE    | Motor ON, Automatic purification starts       |
| Unsafe detected | ESP32 sends notification                       |

---

## 🖥️ OLED Display Output
The OLED display shows:  
- **pH value**  
- **TDS value (ppm)**  
- **Temperature (°C)**  
- Final water status: **SAFE / NOT SAFE**

---

## 🔄 System Workflow
1. Sensors collect **pH, TDS, and temperature** data  
2. Arduino analyzes the data using **predefined thresholds**  
3. Water safety status is determined  

**If water is unsafe:**  
- Motor turns ON  
- Purification process starts  
- ESP32 sends alert  

**If water is safe:**  
- System continues monitoring  

---

## 🚀 Extended Benefits
- Fully automatic operation  
- No manual intervention required  
- Reduces human error  
- Saves electricity and water  
- Suitable for **smart homes and rural water systems**

---
## 📷 Project Implementation Photographs

Figure 1: pH sensor
![photo_2026-01-28_22-27-16](https://github.com/user-attachments/assets/7f98c441-b3a8-4b8a-89da-4321ccbbb877)

Figure 2: TDS sensor
![photo_2026-01-28_22-27-17](https://github.com/user-attachments/assets/305e30a5-6e16-40b6-84c5-9d879a49a29a)

Figure 3: OLED display showing real-time pH, TDS, and temperature values, overall water safety status (SAFE/UNSAFE), and automatic pump operation (ON/OFF) based on water quality conditions.
![photo_2026-01-28_22-27-21](https://github.com/user-attachments/assets/fd00de20-298e-45aa-8ebb-87264d713dd6)

Figure 4: Complete hardware setup of the Smart Water Quality Monitoring System with all integrated components.
<img width="459" height="558" alt="new" src="https://github.com/user-attachments/assets/09cf6a55-bbf0-448d-988b-d7a84dad1819" />

Figure 5: Complete system setup placed on the laboratory table, including the hardware components and laptop-based monitoring dashboard, illustrating the overall working environment of the smart water quality monitoring system.
![photo_2026-01-28_22-27-20](https://github.com/user-attachments/assets/f293d0b8-9b27-43a6-a6eb-e87b58bcc686)

