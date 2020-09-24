#!/usr/bin/python3
import serial
import time

ser = serial.Serial('/dev/ttyUSB0')
time.sleep(2)
ser.write(b'1')

print('SEND ON HOOK script: sent 1 code')
