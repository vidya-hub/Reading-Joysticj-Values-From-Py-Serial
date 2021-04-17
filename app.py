import serial
import sys
from time import sleep

try:
    ser = serial.Serial("/dev/ttyUSB0", 9600, timeout=0, parity=serial.PARITY_NONE,
                        stopbits=serial.STOPBITS_ONE, bytesize=serial.EIGHTBITS)
except:
    sys.exit("Error connecting device")

while True:
    queue = ser.inWaiting()
    if queue > 0:
        ser_bytes = ser.readline()
        decoded_bytes = (ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
        data_list=str(decoded_bytes).split("\t")
        x=data_list[0]
        y=data_list[1]
        print("x value  "+x)
        print("y value  "+y)
        
    sleep(0.2)
