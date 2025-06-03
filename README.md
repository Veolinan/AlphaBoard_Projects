# AlphoBoard_Projects

Welcome to the AlphoBoard Projects repository! This repo contains example code and projects designed to test and utilize the AlphoBoard’s buttons, LEDs, and buzzer.

---

## Setting Up Your AlphoBoard on Arduino IDE

### Step 1: Connect and Configure

- Connect your AlphoBoard to your computer via USB.
- Open **Arduino IDE** (version 1.8.x or newer recommended).
- Go to **Tools > Board > Arduino AVR Boards** and select **Arduino Micro**.
- Select the correct **COM port** for your AlphoBoard under **Tools > Port**.
- Leave the Processor as the default.

### Step 2: Test Hardware with Example Code

Before uploading the full projects, use the example sketches provided in the `example/` folder to verify that the buttons, LEDs, and buzzer on your AlphoBoard are working correctly.

- Open an example sketch (such as `ButtonLEDTest.ino`).
- Upload it to your AlphoBoard.
- Press the buttons and confirm the corresponding LEDs light up and the buzzer sounds.

Once you’ve confirmed everything works as expected, proceed to upload the main project sketches in the `projects/` folder.

---

## Repository Structure

- `example/` — Simple test sketch for testing all individual onboard components.
- `projects/` — Full projects including the Simon Says game and Button-LED-Sound demo.

---

## Projects Overview

### Safe Cracker

A security-style puzzle where pressing the correct button sequence disables a buzzer and lights up LEDs to indicate success.

### Simon Says Game

A memory game where the player repeats LED sequences by pressing buttons, with buzzer feedback.

---
