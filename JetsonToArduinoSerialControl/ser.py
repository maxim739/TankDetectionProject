import serial
with serial.Serial('/dev/ttyUSB0', 9600, timeout=10) as ser:  # open serial port
    while True:
        print(ser.readline())
