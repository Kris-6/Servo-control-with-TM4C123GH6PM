import serial
import time

try:
    ser = serial.Serial('COM6', 9600)  # Replace 'COMX' with the correct COM port
    print("Serial connection established successfully.")
except serial.SerialException as e:
    print(f"Error: {e}")
    exit()

def send_command(command):
    ser.write(command.encode('utf-8'))

try:
    while True:
        command = input("Enter angle: ")
        send_command(command)
        time.sleep(1)  # Optional: Add a delay if needed

        # Read and print received data
        #received_data = ser.readline().decode('utf-8').strip()
        #print(f"Received data from TM4C board: {received_data}")

except KeyboardInterrupt:
    print("Program terminated by user.")
finally:
    ser.close()
    print("Serial connection closed.")
