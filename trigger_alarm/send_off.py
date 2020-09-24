#!/usr/bin/python3
import serial
import time

ser = serial.Serial('/dev/ttyUSB0')
time.sleep(2)
ser.write(b'0') # off
ser.close()

print('SEND OFF HOOK script: sent 0 code')
