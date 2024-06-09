from machine import Pin

'''
SETUP
'''
sensor_pin = 5
led = Pin(25, Pin.OUT)
sensor = Pin(5, Pin.IN, Pin.PULL_DOWN)

'''
MAIN LOOP
'''
while True:
    print(sensor.value())
    if(sensor.value()):
        led.toggle()
    else:
        print("Value: " + sensor.value())
