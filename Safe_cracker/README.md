# Safe Cracker - AlphaBoard Project

## Overview

Safe Cracker is a simple yet engaging puzzle game that uses two potentiometers and a submit button to simulate entering a secret combination to unlock a safe. The system reads analog values from two potentiometers, representing the "combination dials," and checks if they match a preset target combination within a defined tolerance. When the submit button is pressed, the entered combination is validated, and the board provides audible and visual feedback to indicate success or failure.

This project is ideal for learning analog input handling, button debouncing, conditional checks, and feedback through LEDs and a buzzer on the AlphoBoard.

---

## Hardware Components (Onboard)

- **Potentiometers:** Connected to analog pins A1 and A2 (Pot1 and Pot2)
- **LEDs:** Green (pin 11), Red (pin 13), Orange (pin 12)
- **Buzzer:** Pin 9
- **Submit Button:** Connected to analog pin A5, configured with internal pull-up resistor

_All components are onboard the AlphoBoard; no external wiring needed._

---

## How It Works

1. The program continuously reads analog values from the two potentiometers.
2. When you press the submit button, the current potentiometer values are checked against the preset combination (`combo1` and `combo2`) with a tolerance range.
3. If both potentiometers are within the tolerance of the target values, a success sequence runs:
   - Green LED blinks twice
   - The buzzer plays a short pleasant tone
4. If the combination is incorrect, a failure sequence runs:
   - Red LED lights up
   - The buzzer sounds a continuous low tone for 1 second
5. The serial monitor outputs the potentiometer values continuously and logs the result of each submission.

---

## Constants and Settings

| Name       | Description                          | Value     |
|------------|------------------------------------|-----------|
| `combo1`   | Target value for potentiometer 1   | 450       |
| `combo2`   | Target value for potentiometer 2   | 850       |
| `tolerance`| Allowed range around target values | ±30       |

You can adjust these values to change the "correct" combination or sensitivity.

---

## Software Setup

1. **Install Arduino IDE** if you haven't yet: [https://arduino.cc/en/software](https://arduino.cc/en/software)
2. **Connect AlphoBoard** via USB to your computer.
3. **Set Board Type:** In Arduino IDE, go to **Tools > Board > Arduino AVR Boards > Arduino Micro**
4. **Select COM Port:** Under **Tools > Port**, select the appropriate port for your board.
5. **Upload Code:** Open the `SafeCracker.ino` sketch from this repository and click Upload.

---

## Usage Tips

- Turn the potentiometers to select your combination.
- Press the submit button to check if the combination is correct.
- Watch the LEDs and listen to the buzzer for feedback.
- Open the Serial Monitor (baud rate 9600) to see real-time potentiometer readings and submission results.

---

## Troubleshooting

| Problem                  | Cause                         | Solution                         |
|--------------------------|-------------------------------|---------------------------------|
| No LED or buzzer feedback | Board not powered or faulty  | Ensure USB connection and board functionality |
| Potentiometer values stuck | Potentiometer malfunction or hardware issue | Test potentiometers separately or reset board |
| Button not registering   | Button wiring issue or debounce problem | Press firmly and ensure button is released fully |
| Combination never matches | Incorrect target values or tolerance too narrow | Adjust `combo1`, `combo2`, or `tolerance` in code |

---

## Future Enhancements

- Add more potentiometers or buttons for complex combinations.
- Implement an LCD display to show instructions or status.
- Store multiple saved combinations.
- Add timer for speed challenges.
- Create a physical safe lock actuator interface.

---

Enjoy cracking the safe with your AlphoBoard! 🔐
