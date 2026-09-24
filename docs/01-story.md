# The conversion story

## Why an RC car

Our first useful decision was to start with existing vehicle mechanics. An RC car offers a four-wheel platform, drive train, and a physical steering mechanism. The racing course still requires autonomous decisions: the original remote operator performs perception, planning, correction, and braking. Our challenge is to move those decisions onboard while keeping the mechanical platform measurable and stable.

The shared conversations show a proposed Arduino Uno and sensor build, followed by instructions for wiring three ultrasonic sensors. A WLtoys K989 was **suggested** as a donor chassis, but no source confirms that it is the car actually used. A Pixy2, 20 A class brushed motor driver, and LM2596 regulator were **proposed purchases**, not verified installed components. Record receipts, photos, and exact component markings before changing this status.

## Five engineering transitions

| Stage | Previously | Conversion work | Evidence to preserve |
| --- | --- | --- | --- |
| 1. Mobility | Human operates an RC mechanism | Identify drive motor, actual steering actuator, wheelbase, gearing, mass | Six car views, component markings, turning radius |
| 2. Sensing | Human estimates wall and object distance | Install left/front/right HC-SR04 and verify distance readings | Pin/photo map, serial logs, calibration table |
| 3. Control | Transmitter commands steering and speed | Electrically isolate/replace radio control and wire verified actuator interfaces | Annotated schematic and bench video |
| 4. Autonomy | Human adapts to corners and signs | Implement a local state machine and test color perception | Source code, state log, failure cases |
| 5. Evaluation | Human sees whether the car worked | Repeat trials on known and shuffled courses | Raw results, videos linked to run IDs |

## Decision register

| Decision | Rationale | Alternative / uncertainty | Test that decides |
| --- | --- | --- | --- |
| Keep donor RC mechanics | Reduces initial mechanical construction work; moves effort to sensing and control | Steering may be proprietary and difficult to command | Inspect car; record servo connector, travel, current |
| Use three distance sensors for the prototype | Independent left, front, and right clearance measurements | Acoustic cross talk and angled wall echoes | Trigger sequentially; compare readings at marked distances and corners |
| Candidate Arduino Uno | Familiar USB upload and sufficient pins for a sensor-first build | Memory and processing may limit camera integration | Benchmark loop period with final camera protocol and actuator outputs |
| Candidate color camera | Red/green sign classification is not possible from ultrasonic range alone | Placement, lighting, training, and processing interface unresolved | Labeled images in several light levels and positions |
| Power actuator subsystem separately from USB prototype | Motor surges and servo current can destabilize sensor/control rails | Exact battery/driver/regulator unknown | Measure loaded voltages and worst observed current |

## What changed in software

The most important diagram in our story is the loop: **measure → validate → choose a driving state → limit steering and speed → actuate → measure again**. A programmed state is useful only if it has an observation that triggers it, an action that follows, an exit condition, and a failure response. For example, a near front wall could cause a corner state, but it could also be a traffic sign; the distinction requires context and testing. A stale or invalid distance must never be interpreted as unlimited free space.

The initial repository ships a sensor diagnostic rather than pretending that a final controller was captured by the shared chats. When the team adds autonomous driving firmware, record the exact commit, code architecture, input units, actuation limits, and observed behavior in the journal. This is the real transformation from RC hardware to software governed autonomy.

## Iteration entries to complete

Use one entry per actual build/test date in [the engineering journal](07-engineering-journal.md). Include a before/after photo where hardware moved. Explain why a sensor angle, steering setting, or threshold changed and attach trials showing whether it improved. Do not create historical dates or improvements from memory.
