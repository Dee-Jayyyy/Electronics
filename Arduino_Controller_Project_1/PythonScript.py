import serial
import keyboard
import time

SerialPort = 'COM3'
SerialRate = 9600

SerilaMonitor = serial.Serial(SerialPort, SerialRate)
time.sleep(2)

while True:
    try:
        Line = SerilaMonitor.readline().decode('utf-8').strip()
        print(Line)
        if Line == 'j':
            keyboard.press('j')
            print("PRESSING j", flush=True)
        elif Line == 'J':
            keyboard.release('j')
            print("RELEASING j", flush=True)
        elif Line == 'k':
            keyboard.press('k')
            print("PRESSING k", flush=True)
        elif Line == 'K':
            keyboard.release('k')
            print("RELEASING k", flush=True)
        elif Line == 'l':
            keyboard.press('l')
            print("PRESSING l", flush=True)
        elif Line == 'L':
            keyboard.release('l')
            print("RELEASING l", flush=True)
    except Exception as e:
        print("Error", e)