import board
import digitalio
import analogio
import time

def read_voltage(pin):
    return (pin.value * 3.3) / 65535

print("Conducting self test.")

print("Testing pump.")
motor = digitalio.DigitalInOut(board.D6)
motor.direction = digitalio.Direction.OUTPUT
motor.value = False

led = digitalio.DigitalInOut(board.D5)  # LED pin
led.direction = digitalio.Direction.OUTPUT

button = digitalio.DigitalInOut(board.D4)  
button.direction = digitalio.Direction.INPUT
button.pull = digitalio.Pull.UP  

sensor = analogio.AnalogIn(board.A0)

motor.value = True
time.sleep(0.5)
motor.value = False

print("Testing photocell.")
volts = read_voltage(sensor)
print(f"A0 reading: {sensor.value} (raw), {volts:.2f} V")
print("Success!")

def main():
    print("1. Start timer\n2. Change settings\n3. Exit\n4. Test Mode")
    choice=input("Select an option: ")
    set_time=2000 # in ms!
    win=False
    if choice not in ["1", "2", "3", "4"]:
        print("Not a choice.")
    else:
        if choice == "1":
            print("Timer started!")
            run_time = 0
            while run_time <= set_time:
                time.sleep(0.5)
                run_time+=500
                raw=sensor.value
                print(f"Photocell value: {raw}")
                if raw>60000:
                    win=True
                    break
                elif not win and raw<60000:
                    win=False
            if not win:
                motor.value = True
                time.sleep(1)
                motor.value = False
                print("You lose!")
            else:
                print("You win!")
                main()
        if choice == "2":
            pass
        if choice == "3":
            pass
        if choice == "4":
            print("Testing motor.")
            while True:
                motor.value = True
                
            time.sleep(0.5)
            motor.value = False
            print("Testing photocell.")
            volts = read_voltage(sensor)
            print(f"A0 reading: {sensor.value} (raw), {volts:.2f} V")
            print("Completed!")
            main()

def run_timer():
    print("Timer started!")
    win=False
    run_time = 0
    set_time=2000 # in ms!
    while run_time <= set_time:
        time.sleep(0.5)
        run_time+=500
        raw=sensor.value
        print(f"Photocell value: {raw}")
        if raw>60000:
            win=True
            break
        elif not win and raw<60000:
            win=False
    if not win:
        motor.value = True
        time.sleep(1)
        motor.value = False
        print("You lose!")
    else:
        print("You win!")
        led.value = True
        time.sleep(4)
        led.value = False
    
while True:
    if not button.value:  # LOW means pressed
        run_timer()
    #else:
        #print("Button released")
    time.sleep(0.02)  # debounce delay

#while True:
    #time.sleep(0.5)
    #raw = sensor.value  
    #print(f"A0 raw: {raw}")
    #motor.value = True
    #if raw < 50000:
        #motor.value = False
    #else:
        #motor.value = True
    #time.sleep(0.1)


