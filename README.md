# 🎡Arduino UNO R4 WiFi – Motorized Pinwheel with Toggle Switch

**Modified Project 09 from the official [Arduino Starter Kit R4](https://store-usa.arduino.cc/collections/arduino-starter-kit-collection/products/starter-kit-r4)**

One click turns the fan/pinwheel **ON** and it stays spinning. One more click turns it **OFF**. Perfect beginner project for learning motor control, transistors, and button debouncing!

![Motorized Pinwheel in action](https://your-image-link-here.jpg)  

<img src = 'https://github.com/user-attachments/assets/a6cfc682-23aa-4ec8-8cf0-6bd06922a1d9' align = right height = 600 width = 600 />




### ✨ Features
- Toggle control (press once = ON, press again = OFF)
- Motor stays running after button release
- Proper back-voltage protection with diode
- Uses MOSFET/transistor as a switch
- Clean, beginner-friendly code with edge detection & debounce

### 🛠️ Tools & Components Used
- **Arduino UNO R4 WiFi** (from Arduino Starter Kit R4)
- Breadboard + jumper wires
- DC Motor + yellow pinwheel attachment
- Pushbutton switch
- N-Channel MOSFET / Transistor (IRF520 or equivalent from kit)
- 1N4007 Diode (back-EMF protection)
- 10kΩ resistor (pull-down)
- 9V Battery + snap connector

## 📋 Project Steps

1. **Gather components** – All parts are included in the official Arduino UNO R4 Starter Kit.
2. **Build the circuit** – Follow the wiring diagram on page 96 of the project book (transistor, diode, 10kΩ resistor, button, motor, and 9V battery).
3. **Connect the Arduino** – Use USB-C to upload code.
4. **Upload the toggle code** (see below).
5. **Test** – Press the button once to start the pinwheel, press again to stop it.
6. **Experiment** – Try changing the debounce delay or adding an LED indicator.

## 💻 Code
```
const int switchPin = 2;
const int motorPin = 9;
int switchState = 0;
int lastSwitchState = 0;
bool motorOn = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
  digitalWrite(motorPin, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);

  if (switchState == HIGH && lastSwitchState == LOW){
    motorOn = !motorOn;

    if (motorOn) {
      digitalWrite(motorPin, HIGH);
    } else {
      digitalWrite(motorPin, LOW);
    }

    delay(50);
  }

  lastSwitchState = switchState;
}
```
## 🔧 How It Works
1.  The pushbutton is read with edge detection (only reacts to the moment you press it).

2.  A boolean motorOn remembers the current state.

3.  The transistor acts as a high-power switch for the motor.

4.  The diode protects the Arduino from back-voltage spikes when the motor stops.

## 📚 Based On
Official Project 09: Motorized Pinwheel from the [Arduino Starter Kit R4](https://store-usa.arduino.cc/collections/arduino-starter-kit-collection/products/starter-kit-r4) book.
