# Source code and release status

## Present firmware

`sensor-diagnostic/sensor-diagnostic.ino` reads the three reported HC-SR04 sensor pin pairs on an Arduino Uno and prints serial CSV at 115200 baud. It uses only Arduino core functions. Upload and test steps are in [the build guide](../docs/06-build.md).

**Not competition ready:** this sketch has no steering output, drive output, camera integration, direction detection, lap counting, obstacle avoidance, or parking. No final autonomous controller appears in the three shared chats. Add it to this folder with readable source and a build manifest once your team implements and verifies it.

## Final firmware checklist

- [ ] Pin constants match photographed wiring and exactly identified motor driver/steering parts.
- [ ] Startup produces zero throttle until ready and explicitly started.
- [ ] Invalid/stale essential sensor readings produce a measured safe response.
- [ ] Wireless communication is disabled or absent during competition.
- [ ] Direction, shuffled sign layouts, lap completion, and parking have tests.
- [ ] Code comments explain control units, state transitions, and electrical interfaces.
- [ ] Build tools/library versions and upload instructions reproduce the running binary.
- [ ] Each video identifies firmware commit and run ID.
