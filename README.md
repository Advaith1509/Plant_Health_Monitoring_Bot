# Plant Health Monitoring Bot 🌱🤖    

## _FEATURES_  
- **Line-following mechanism**: Enables the bot to navigate predefined paths autonomously.  
- **Environmental Monitoring**:  
  - Temperature and Humidity Sensor (**DHT11**) to track climatic conditions.  
- **Soil Health Monitoring**:  
  - **Soil Moisture Sensor**: Measures the soil's water content, integrated with a solenoid push-pull motor for precise soil interaction.  
- **Real-Time Updates**:  
  - A **GSM Module** sends SMS alerts with details of temperature, humidity, and soil moisture content.  
- **Power Source**: Powered by a rechargeable 24V Lithium-Ion Power Supply for extended operation.  

## _COMPONENTS USED_  
1. **Microcontroller**: (Specify if Arduino, Raspberry Pi, or other)  
2. **DHT11 Sensor**: For temperature and humidity measurements.  
3. **Soil Moisture Sensor**: To measure soil water levels.  
4. **Solenoid Push-Pull Motor**: For deploying the soil moisture sensor.  
5. **Line-following Mechanism**: Sensors for path detection and navigation.  
6. **GSM Module**: For real-time SMS updates.  
7. **24V Lithium-Ion Battery**: Rechargeable power supply.  

## _WORKING_
1. **Navigation**:  
   - The bot follows a predefined path using a line-following mechanism.  
2. **Environment Sensing**:  
   - Temperature and humidity readings are collected using the DHT11 sensor.  
3. **Soil Moisture Analysis**:  
   - The soil moisture sensor, controlled by the solenoid motor, measures soil moisture at intervals.  
4. **Real-Time Updates**:  
   - The GSM module sends SMS alerts with the following details:  
     - Current temperature  
     - Humidity levels  
     - Soil moisture content  
5. **Data Collection**:  
   - The collected data is processed to assess plant health conditions.  

## _FUTURE IMPROVEMENTS_
- Adding wireless data transmission for cloud-based real-time monitoring.  
- Integrating a water dispensing system for automated irrigation.  
- Enhancing navigation for uneven terrains.  
