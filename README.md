# 🔥 Smart Earthquake & Smoke Alert System

An Arduino-based real-time alert system that detects **earthquakes** and **smoke/fire** and responds with **LED indicators**, **buzzer**, **voice alerts**, and **LCD notifications**.

---

## 🏫 Developed At
**United International University (UIU)**  
Department of Computer Science & Engineering  
By: **Sam Shawon**

---

## 🎯 Project Overview

This project aims to save lives by quickly detecting seismic and smoke events using sensors and initiating multi-level alerting via:
- Audio voice notifications (via DFPlayer Mini)
- Visual warnings (LEDs)
- Audible buzzers
- LCD-based display alerts

---

## ⚙️ Components Used

| Component             | Description                           |
|-----------------------|---------------------------------------|
| Arduino UNO           | Main microcontroller board            |
| DFPlayer Mini         | Audio module for voice alerts         |
| Vibration Sensor (SW-420) | Earthquake detection sensor     |
| MQ-2 Smoke Sensor     | Detects smoke or gas concentration    |
| 20x4 I2C LCD          | Displays status messages              |
| Buzzer                | Sound-based alert                     |
| Red & Green LEDs      | Visual indicators                     |
| Power Supply          | 5V regulated supply                   |

---

## 🔌 Circuit Connections

| Pin                  | Arduino Pin |
|----------------------|-------------|
| Vibration Sensor     | D7          |
| Smoke Sensor (MQ-2)  | A0          |
| Green LED            | D6          |
| Red LED              | D4          |
| Buzzer               | D5          |
| DFPlayer RX          | D10         |
| DFPlayer TX          | D11         |
| LCD SDA/SCL          | A4/A5 (I2C) |

---

## 🧠 Features

✅ Dual hazard detection (earthquake + smoke)  
✅ Resettable alert logic (avoids repeated alerts)  
✅ LCD interface with real-time status  
✅ Voice alerts using DFPlayer Mini  
✅ Compact and power-efficient design

---

## 🖥️ LCD Display States

- `System Ready...`
- `Detected Quakes`
- `Smoke Alert!` with sensor value
- `System Monitoring...` (after alerts)

---

## 🧾 How It Works

1. **Startup:** LCD shows "System Ready..."
2. **Earthquake Detection:** On high vibration, red LED + buzzer + audio + LCD alert.
3. **Smoke Detection:** When smoke value crosses threshold, similar multi-level alerting.
4. **Recovery:** System resets alerts once sensors return to normal.

---

## 🔊 Audio Files

You’ll need:
- `001.mp3` → Smoke Alert Voice
- `002.mp3` → Earthquake Alert Voice  
Place them on a microSD card in the DFPlayer Mini.

---

## 📸 Demo & Media

🎥 [Watch Demo Video](https://drive.google.com/file/d/1bPQbc_6IUq-6yguOpEWpzUcPXFkNZBc1/view?usp=drive_link)  
📷 [Project Images](assets/image)

---

## 📂 Repository Structure
Smart-Earthquake-Smoke-Alert/
├── Arduino_Code/
│ └── SmartAlertSystem.ino
├── Circuit_Diagram/
│ └── fritzing_schematic.png
├── Audio/
│ └── 001.mp3 (Smoke)
│ └── 002.mp3 (Earthquake)
├── README.md


---

## 👨‍💻 Author

**Sam Shawon**  
🎓 CSE, United International University  
🔗 [GitHub](https://github.com/samshawon10)  
🔗 [LinkedIn](https://linkedin.com/in/shawon-akando)

---

## 🏁 License

This project is open-source and free to use.

---

## ⭐ If you like this project, consider giving it a star 🌟 on GitHub!


