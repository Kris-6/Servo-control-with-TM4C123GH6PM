# Servo Motor Control with TM4C123GH6PM and Energia/Stellaris Launchpad

This project demonstrates servo motor control using two different platforms: Keil IDE with TM4C123GH6PM microcontroller and Energia with Stellaris Launchpad.

## Keil IDE Version

### Prerequisites

- TM4C123GH6PM microcontroller
- Keil IDE

### Circuit Connection

- Connect the control pin of the servo motor to pin PF1 of the TM4C123GH6PM.

### Building and Loading

1. Open the project in Keil IDE.
2. Build the project.
3. Load the generated binary onto the TM4C123GH6PM microcontroller.

### Usage

The basic_servo code  provides an example of servo motor control by sweeping through three angles (0, 90, and 180 degrees) in a continuous loop.

### Code Structure

- `basic_servo.c`: The main code controlling the servo motor movement.
- `Delay_MicroSecond`: Function to generate microsecond delays.
- `Servo_0_Degree`, `Servo_90_Degree`, `Servo_180_Degree`: Functions to control the servo motor at different angles.

### Customization

Feel free to customize the code for your specific servo motor or application.



## Energia/Stellaris Launchpad Version
Inputs sent via python script to energia interface to TM4CBOARD to control the servo motor  
### Prerequisites

- Stellaris Launchpad or compatible hardware
- Energia IDE(1.8.11 ,used here)
- Python 3.8(used here)

### Circuit Connection

- Connect the signal (control) wire of the servo motor to the designated pin on the Stellaris Launchpad (in this example, PF_1).

### Getting Started

1. **Energia Setup:**
   - Open the Energia IDE.
   - Load the provided Energia code into the IDE.
   - Ensure the correct COM port is selected.(You can view the portNo under ports in Device Manager in Windows)
   - Upload the code to the Stellaris Launchpad.

2. **Python Setup:**9
   - Install Python 3.8(or any other compatible versions) on your computer.
   - Open the provided Python script in a text editor.
   - Update the COM port in the script (replace 'COM6' with the correct COM port).
   - Run the Python script.

3. **Control the Servo:**
   - In the Python script, enter the desired angle when prompted.
   - The angle information is sent to the Stellaris Launchpad via the serial connection.

### Code Structure

- `Servo_Control.ino`: Energia code for controlling the servo motor.
- `comm_1.py`: Python script for sending servo angle commands to the microcontroller.

### Customization

- Modify the Energia code to suit your specific servo motor or pin configuration.
- Customize the Python script for additional functionality or integration with other systems.

### References :
https://www.hackster.io/selcuk-cakmak/tiva-launchpad-internet-of-things-iot-with-esp8266-wifi-3e00e2


