# Mobility and mechanical design

**Status:** donor RC chassis proposed, final model and measurements pending.

## Mechanical bill of facts

| Measurement | Actual value | How to obtain |
| --- | --- | --- |
| Chassis manufacturer and model | **TBD** | Label or receipt and photo |
| Length × width × height with all attachments | **TBD mm** | Calipers/ruler on finished car |
| Total vehicle mass with battery | **TBD g** | Scale, photograph readout |
| Wheelbase, axle-to-axle | **TBD mm** | Mark tire contact centers |
| Front and rear track | **TBD mm** | Wheel center spacing |
| Driven axle / gearing | **TBD** | Inspect underside and drivetrain |
| Steering actuator and range | **TBD** | Photograph connector and measure left/right angles |
| Minimum turn radius, both directions | **TBD mm** | Low-speed floor circle, three repeats |
| Speed, voltage and battery state | **TBD** | Timed 1 m runs, at least five repeats |
| Stopping distance at chosen speed | **TBD mm** | Mark command point and wheel stop |

The 2026 international constraints are 300 × 200 × 300 mm maximum, 1.5 kg maximum, four wheels, a driving axle, and one steering actuator. No differential drive in place of steering. Verify against the actual event document. An RC donor often satisfies the steering geometry conceptually, but adding the Arduino, mounts, battery, and sensors changes the complete car's size, weight, and center of mass.

## Drive and steering interfaces

Draw the physical chain after inspection: battery → verified motor driver → drive motor → gears/differential → wheels; controller → verified steering interface → steering linkage → front wheels. Avoid claiming a standard three-wire servo until the actual connector and device markings are checked. Some RC cars contain integrated receiver/ESC electronics or a nonstandard steering actuator. The driver must be matched to the measured motor current, battery voltage, direction requirement, and braking behavior. A motor driver's **advertised 20 A** is not a measured motor current.

## Quantitative design notes

At a measured wheel radius `r` and wheel rotational speed `n` in revolutions per second, estimate ground speed `v = 2πrn`. Check with a timed track distance because slip and gearing losses matter. Estimate required wheel torque from measured acceleration and incline rather than guessing from a motor listing. For steering, compare minimum measured turn radius `R` with the shortest usable path through a field corner after allowing the car's half-width and a wall safety margin. Measure both left and right because linkage asymmetry can change the limiting direction.

Mount sensors firmly enough that the aim stays the same after braking or impacts. Document the sensor positions relative to the front axle and wall, the mounting height, and left/right outward angle. Photograph clearance with steering fully left and right. For a no-solder breadboard prototype, secure wires and check connectors after each run; replace loose connections before calling the system competition ready.

## Iteration experiment

1. Record mass, wheelbase, steering endpoint settings, battery voltage, and surface.
2. Drive three clockwise and three counterclockwise low-speed circles using a verified bench control method; measure outermost wheel trace radius.
3. Change only one endpoint or mount parameter.
4. Repeat the circles and calculate median radius and any wheel/body contact.
5. Note if the improvement changes stopping distance, sensor field of view, or the competition size limit.

Add the actual measurements and photos here; no successful mobility result has been supplied.
