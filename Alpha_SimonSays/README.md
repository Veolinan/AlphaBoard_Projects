# Alpha Simon Says - AlphaBoard Project

## Overview

Alpha Simon Says is a classic memory game implemented on the AlphoBoard. The board generates a sequence of LED lights and corresponding buzzer tones that the player must memorize and reproduce by pressing the correct buttons. With each successful round, the sequence length increases, challenging the player’s memory and reflexes.

This project demonstrates button input handling, random sequence generation, timing control, and feedback using LEDs and buzzer on the AlphaBoard.

---

## Components Used (All onboard)

- **Green LED:** Pin 11
- **Red LED:** Pin 13
- **Buzzer:** Pin 9
- **Green Button:** Pin A5 (active LOW with internal pull-up)
- **Red Button:** Pin A4 (active LOW with internal pull-up)

---

## How It Works

1. **Sequence Generation:**  
   At startup, a random sequence of 3 steps is generated, where each step corresponds to either the green or red LED/button.

2. **Gameplay Loop:**  
   - The game plays back the current sequence of LEDs and buzzer tones.
   - The player must reproduce the sequence by pressing the corresponding buttons.
   - Each correct input lights the respective LED and plays a tone for feedback.
   - If the player completes the sequence correctly, the sequence length increases by one (up to the maximum length).
   - If the player inputs a wrong button, the fail sequence runs, and the game resets.

3. **Feedback:**  
   - **Success:** Plays a short success beep and advances the level.
   - **Fail:** Lights the red LED and sounds a buzzer tone multiple times.
   - **Win:** After successfully completing all sequence levels, a celebratory LED and buzzer sequence plays.

4. **Intro Sequence:**  
   When the board powers on, both LEDs blink twice with buzzer sounds as a welcome signal.

---

## Pin Configuration

| Component      | Pin Number |
|----------------|------------|
| Green LED      | 11         |
| Red LED        | 13         |
| Buzzer         | 9          |
| Green Button   | A5         |
| Red Button     | A4         |

---

## Installation and Setup

1. **Install Arduino IDE:**  
   Download and install the Arduino IDE from [https://arduino.cc/en/software](https://arduino.cc/en/software).

2. **Connect the AlphoBoard:**  
   Plug your AlphoBoard into your computer via USB.

3. **Select Board and Port:**  
   - Go to **Tools > Board** and select **Arduino Micro** (as used in your setup).  
   - Select the appropriate COM port under **Tools > Port**.

4. **Upload the Code:**  
   Open the `AlphaSimonSays.ino` file from this repository and click the Upload button.

5. **Open Serial Monitor:**  
   Set baud rate to 9600 to view game status messages.

---

## Usage Instructions

- When powered on, watch the LEDs and listen to the buzzer play the intro sequence.
- Observe the sequence of LEDs lighting up along with tones.
- Press the green or red buttons in the exact order of the sequence.
- Correct inputs provide instant LED and tone feedback.
- Completing the sequence correctly will extend the sequence length for the next round.
- Wrong input triggers the fail sequence and resets the game.
- Successfully finishing all rounds triggers the win sequence.

---

## Code Highlights

- `generateSequence()` — Randomly creates the sequence for the game.
- `playLED(int color)` — Lights up the LED and plays tone for the given color.
- `getPlayerInput()` — Waits for the player to press a button and returns the color pressed.
- `failSequence()` and `winSequence()` — Visual and audio feedback on losing or winning.
- Button inputs are read with internal pull-ups, assuming buttons pull pins LOW when pressed.

---

## Troubleshooting

| Issue                         | Possible Cause              | Solution                        |
|-------------------------------|-----------------------------|--------------------------------|
| No LEDs or buzzer feedback    | Board not connected or faulty | Check USB connection and board functionality |
| Buttons not registering press | Wiring or button hardware issue | Confirm buttons are connected correctly, press firmly |
| Sequence repeats incorrectly  | Code logic issue or reset   | Ensure code is uploaded correctly, reset board |
| No serial output              | Incorrect serial monitor settings | Set baud rate to 9600 in Serial Monitor |

---

## Customization

- Change `sequenceLength` to increase or decrease maximum sequence difficulty.
- Adjust buzzer frequencies and LED timings for different sound and visual effects.
- Add more colors/buttons if you expand your hardware setup.
- Modify delays for faster or slower gameplay pace.

---

## License

This project is licensed under the MIT License — feel free to use and modify!

---

## Author

Developed by **Felix Masigwa Morara**

GitHub: [https://github.com/Veolinan]  
Email: [masigwafelix@gmail.com]

---

Enjoy your memory challenge with Alpha Simon Says! 🟢🔴🎵
