# Reproduce the prototype

## 1. Inventory and inspect

Obtain the actual car's exact model, motor/steering markings, battery voltage, Arduino model, HC-SR04 models, and any installed camera/driver/regulator. Photograph each. The shopping list in the shared conversation is a proposal and must not be treated as an as-built bill of materials. Fill [the BOM](../hardware/bom.csv) before actuator wiring.

## 2. Connect the three distance sensors for the USB-only test

With USB disconnected, connect each HC-SR04's printed VCC to Arduino 5 V via a confirmed positive breadboard rail and each GND to Arduino GND via the ground rail. Left TRIG/ECHO → D2/D3, front → D6/D7, right → A0/A1. Wire colors in the shared chat are recorded in [Power and sensing](03-power-and-sensing.md), but printed pin labels and continuity tests take priority. Check polarity and an absence of shorts using a multimeter. Keep the motor, steering, and battery disconnected from this diagnostic setup.

## 3. Upload the diagnostic

Install the official Arduino IDE, attach a USB **data** cable, choose **Arduino Uno** under Tools → Board and the port shown when the board is connected. Open `src/sensor-diagnostic/sensor-diagnostic.ino` and upload. If the port is missing, check the cable and the USB interface/driver on the particular Uno-compatible board. Open Serial Monitor at **115200 baud**. A header and one CSV row per acquisition cycle should appear; `INVALID` means no valid echo inside the bounded timeout. Test each sensor with a flat surface at a known distance and record the observed values. The sketch uses only standard Arduino core functions and no third-party library.

## 4. Add the verified final hardware

Draw an actual wiring schematic showing battery, fuse/switch, regulator, grounds, motor driver, steering, sensor rails, and every signal pin. Use the manufacturer's exact driver and servo specifications and measure voltage under load. Do not infer a safe high-current design from the USB breadboard test. Specify mounting files and attachment details if custom parts are used.

## 5. Install final autonomous software

Once implemented, replace this instruction with the actual controller/build/upload procedure, exact libraries and versions, camera calibration files, device pin configuration, controls, and run modes. The repository currently does **not** include verified competition firmware. Document how to reproduce the software on a second board and how to identify a revision on the vehicle.

## 6. Final checks

Measure the **assembled** vehicle including sensors and battery; verify rules, radio disabled or removed for competition, emergency power cutoff, battery security, and no exposed wiring. Then run `python3 scripts/check_repository.py` to see missing submission evidence. The checker is a checklist, not a competition judge.
