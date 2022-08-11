# IoT Based Forest Fire Detection System
## Project : Code-Red (In Collaboration with NOKIA)
#### [Download](https://github.com/Nokia-IoT/Forest-Fire-Detection)
A wildfire, forest fire, bushfire, wild-land fire or rural fire is an unplanned, uncontrolled fire in an area of combustible vegetation starting in rural and urban areas. The approach addresses the need for an early detection of the forest fire before it spreads to a large scale and causes a number of casualties.
The Device helps in detecting the fire in its initial stages to avoid catastrophic damage and intimidate the authorities at the earliest.
##### [Click](https://drive.google.com/file/d/1biDBTwWqfK0Ubjh_4VI0WeSi-aqg2-dI/view?usp=sharing) here to watch the video.
## Major Components
- MQ138 sensor
- DHT11 Sensor
- Flame Sensor
- Arduino Uno
- SIM 808 Module

The sensors sense the environment and measure the concentration of CO2, Temperature, Humidity. If the Flame sensor is activated, then these 3 parameters are used to calculate the intensity and take appropriate action.
## Formula Proposed
##### I = [k * (T*C/H)] - 1.2
where, k = 5.397 x 10^-3 ( RH per ppm per degree) 
## Features
- Determining the Fire Intensity.
- Intimidating the Authority over the call.
- Sending the Details about the incident via SMS.
- Sending the Data to the cloud to picturize the change in physical parameters.
- Storing the clips of the place over the cloud.
- Buzzing Alarm at the site.

## Execution
- Download the repository.
- Install Arduino IDE. 
- Integrate the hardware.
- Connect the device to the system an run the code.
