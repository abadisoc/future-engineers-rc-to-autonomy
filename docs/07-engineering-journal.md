# Engineering journal

This journal will become the dated record that links the RC car conversion to experiments. Do not retroactively manufacture build history. Enter the team members' actual names/roles, an as-built photo, and the first verified measurements after physical inspection.

## Known conversation milestones

| Source | Established information | Evidence strength |
| --- | --- | --- |
| RC car and parts discussion | Proposed Uno, Pixy2, 3 ultrasonic sensors, motor driver and regulator; WLtoys K989 recommended as a candidate | Planning, not purchase/build proof |
| Wiring discussion | Explicit left/front/right sensor pin map and breadboard rail explanation | Wiring advice, not a verified photo |
| Laptop connection discussion | Arduino IDE, board/port choice and Blink upload guidance | Setup advice |

## Dated entry template

### YYYY-MM-DD — What changed

- **Team members present and roles:** …
- **Starting revision / commit:** …
- **Question / hypothesis:** …
- **Constraint:** e.g. car width, sensor uncertainty, current limit, time.
- **Before:** photos, measured result, or failure log.
- **Change:** one specific mechanical, electrical, or software modification.
- **Trial setup:** course, lighting, direction, battery voltage, n attempts.
- **Results:** trial IDs, raw files, failures as well as successes.
- **Decision:** keep/revert; what evidence supported it.
- **Next experiment:** …

## Suggested first real entries

1. Identify the actual RC donor, photograph it and measure size/mass.
2. Confirm each HC-SR04 pin and measure the three sensor outputs.
3. Inspect steering and motor interface, then update the electrical schematic.
4. Record first autonomous movement with actual final source code.
5. Compare a baseline with a documented improvement.

Every claim in the final README should have a corresponding measurement, photo, code revision, or independent demonstration.
