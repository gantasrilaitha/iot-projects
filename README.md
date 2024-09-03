# IoT-projects

**1. Weather Monitoring System**
This project focuses on creating a highly localized weather monitoring system using IoT technology. The core of the system is the NodeMCU-8266 microcontroller, integrated with several sensors:

***a) DHT11 Temperature Sensor***: Measures the ambient temperature.<br>
***b) BMP180 Pressure Sensor***: Captures barometric pressure data.<br>
***c) Rain Sensor***: Detects the presence of rainfall.<br>
***d) Air Quality Sensor***: Monitors the surrounding air quality.<br>
The data from these sensors are transmitted to ThingSpeak, a cloud-based IoT analytics platform. This setup allows for real-time monitoring of environmental conditions. An additional feature is a buzzer that alerts the user when rainfall is detected, ensuring timely action can be taken. This project is ideal for applications requiring detailed, real-time weather information in specific locations.

**2. Water Level Monitoring System**
Designed to assist farmers in maintaining optimal soil moisture levels, this system uses a combination of IoT components:

***a) Water Level Sensor*** Monitors the water level in the soil.<br>
***b) Arduino***: Acts as the central processing unit, controlling the system.<br>
***c) LED Indicators***: Display the current status of the soil moisture levels.<br>
Motors and Sprinklers: Automatically activate to water the field when the soil moisture drops below a predefined threshold.
The system is set up to alert farmers when the water level falls too low, preventing crop damage due to insufficient watering. The automated sprinklers ensure that the field is watered consistently, optimizing water usage and enhancing crop yield.

**3. Digital Thyroid Band**
This innovative project involves a wearable device that predicts thyroid levels—hypothyroidism, hyperthyroidism, or normal—by monitoring various physiological parameters. The system comprises:

***a) NodeMCU-8266 Microcontroller***: The brain of the device.<br>
***b) DHT22 Temperature Sensor***: Measures body temperature.<br>
***c) Pulse Oximeter***: Tracks oxygen levels and pulse rate.<br>
***d)Sound Sensor***: Monitors voice changes, a potential indicator of thyroid issues.<br>
Sensor data is captured and stored in Firebase, a cloud-hosted database. An Android application, developed using Android Studio, displays the data to the user. A Machine Learning (ML) model is planned to be integrated into the system to analyze the data and provide predictions on thyroid health status.


