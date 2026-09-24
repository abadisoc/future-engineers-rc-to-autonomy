# Test protocol and metrics

## Evidence policy

Only enter runs that happened. Label a bench test, partial autonomous test, and full challenge run separately. Keep unsuccessful videos/logs. Do not use photos or video from another team as our evidence. Use one ID such as `2026-09-24-open-01` in the CSV, video title, and journal.

## Controlled sequence

1. **Electrical inspection:** battery disconnected; photograph both sides of the board, confirm rails, polarity, and no 5 V/GND short. Record meter values.
2. **Sensor-only bench:** upload diagnostic; compare each of three sensors at known distances; save serial output in `data/raw/` with actual date and conditions.
3. **Actuator bench:** after electrical verification, raise drive wheels and measure steering center, left/right limits, drive direction, and cutoff response. Record current draw.
4. **Low-speed straight:** five 1 m timed trials in each direction; record speed and stopping distance. Keep course and battery state constant.
5. **Wall and corner:** repeat both driving directions on several wall shapes; calculate collision rate and clearance error.
6. **Sign classification:** vary color, light, distance, and pillar order. Build a red/green/unknown confusion table and preserve misclassifications.
7. **Full open and obstacle challenges:** include randomized start and direction. Record every attempt and duration; link uncut autonomous footage.

## Acceptance criteria to set *before* trials

| Metric | Proposed target | Actual result |
| --- | --- | --- |
| Sensor invalid fraction at straight wall, 20–50 cm | Set after bench baseline | TBD |
| Worst-case motor cutoff on invalid critical data | Command throttle to zero within measured cycle budget | TBD |
| Side wall clearance | Team-defined margin based on car width and field | TBD |
| Open challenge completion rate | Team-defined threshold over >= 5 layouts | TBD |
| Colored sign accuracy | Team-defined threshold over balanced samples | TBD |
| Obstacle/parking completion rate | Team-defined threshold over >= 5 layouts | TBD |

These targets are deliberately not fabricated. Record targets and thresholds in a dated journal entry before gathering final validation data. A successful single run is a demonstration, not a reliability estimate.

## Analysis

For each configuration, report successes / attempts, median and maximum time, collisions, invalid sensor rate, and whether the battery was freshly charged. Compare paired before/after runs with the **same** course and lighting. If a change improves lap time but increases sign contacts, explain the tradeoff. The 2026 rubric asks for tests and iteration affecting design, not just a final video.
