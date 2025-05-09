# Voltage Divider for 5V to 3.3V Conversion

This repository documents the creation of a simple voltage divider circuit to step down 5V to 3.3V using two resistors: 1kΩ and 2kΩ. This is particularly useful for connecting 5V sensors or components to 3.3V logic-level microcontrollers like the Arduino Nano ESP32, Raspberry Pi, and ESP32.

## Components Used:
- 1kΩ Resistor (R1)
- 2kΩ Resistor (R2)
- Arduino Nano ESP32

## Circuit Explanation:

The voltage divider is built using two resistors:
- **R1 (1kΩ)**: Connected between the 5V input and the output (3.3V).
- **R2 (2kΩ)**: Connected between the output and ground (GND).

The output voltage (3.3V) is calculated using the voltage divider formula:

\[
V_{out} = V_{in} \times \frac{R2}{R1 + R2}
\]

With **5V** as the input, the output will be **3.3V**.

### Connection Table

| From Component   | From Pin   | To Component          | To Pin         |
|------------------|------------|-----------------------|----------------|
| HC-SR04          | VCC        | Arduino Nano ESP32     | 5V             |
| HC-SR04          | GND        | Arduino Nano ESP32     | GND            |
| HC-SR04          | TRIG       | Arduino Nano ESP32     | D2 (GPIO 2)    |
| HC-SR04          | ECHO       | Resistor (1kΩ)         | Terminal 1     |
| Resistor (1kΩ)   | Terminal 2 | Resistor (2kΩ)         | Terminal 1     |
| Resistor (2kΩ)   | Terminal 2 | Arduino Nano ESP32     | GND            |
| Between R1 & R2  | —          | Arduino Nano ESP32     | D3 (GPIO 3)    |


## Explanation of Output:
### Distance: 
This value represents the distance between the HC-SR04 sensor and the object in front of it. The distance is calculated based on the time it takes for the ultrasonic pulse to travel to the object and back.

### Voltage: 
The voltage is a calculated approximation, mapped from the pulse duration of the ECHO pin. This is intended to give you an idea of how long the pulse is, which can be roughly interpreted as a voltage. However, it’s not directly related to real-world voltage but is simply a scaled version of the pulse width.

### How the Calculation Works:
The duration is the time it takes for the ultrasonic pulse to travel from the TRIG pin to the object and back to the ECHO pin.

The distance is calculated from the duration using the speed of sound (0.0344 cm/us).

The voltage calculation is a basic map function that translates the pulse width into a voltage range between 0 and 5V. This is just an example to demonstrate the idea, and may not provide a precise voltage value related to actual sensor measurements.
