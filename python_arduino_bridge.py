# Importing Libraries
import serial
import time

arduino = serial.Serial(port='COM3', baudrate=9600, timeout=1)

def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.8)
    data = arduino.readline()
    return data

def read_file():
    file = open("TestInputText.txt", "r")
    read_file = file.read()

    for char in read_file:
        print(char)
        write_read(char)

    file.close()

# while True:
#     num = input("Enter a number: ")
#     value = write_read(num)
#     print(value)
read_file()








