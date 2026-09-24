# 2026 documentation rubric map

The [official 2026 rubric](https://wro-association.org/wp-content/uploads/WRO-2026-Future-Engineers-Documentation-Rubric.pdf) has five criteria worth 0, 2, 4, or 6 points each, for 30 maximum. This table maps existing text and missing evidence. It is **not a predicted score**.

| Criterion | What this repo currently shows | Missing evidence for a strong submission |
| --- | --- | --- |
| Mobility and mechanical design | [Mobility reasoning and measurement protocol](02-mobility.md), RC conversion tradeoff | Actual chassis and linkage photos, dimensional drawing, turning radius/speed/torque data, iteration |
| Power and sensor architecture | [Sensor pin map, rail checks, calibration plan](03-power-and-sensing.md), diagnostic code | As-built wiring diagram, measured current budget, mounted photos, calibration and fault tests |
| Software and obstacle strategy | [Proposed modules, state machine, edge cases, metrics](04-software-and-strategy.md), working sensor-only sketch | Final autonomous source, color and parking logic, algorithm tests, performance evidence |
| Systems thinking and engineering decisions | [Conversion story](01-story.md), decision table, [journal template](07-engineering-journal.md) | Dated before/after decisions backed by actual failures and measurements |
| Reproducibility and GitHub quality | README, source with upload instructions, test and media inventory | Final code, six views, team photo, two videos, CAD/mounts if used, complete BOM, authentic commit history |

## Competition gate

- [ ] Public English GitHub repository URL submitted by organizer deadline.
- [ ] At least three genuine commits meeting applicable timing milestones. Current creation cannot backdate them.
- [x] README describes the intended solution in more than 5,000 characters.
- [ ] Complete commented source for every programmed competition component.
- [ ] Final electrical schematic and actual components / mounts.
- [ ] Car photos: front, rear, left, right, top, underside; plus team photo.
- [ ] One accessible YouTube video of at least 30 seconds autonomous driving **for each** Open and Obstacle Challenge.
- [ ] Dated structured engineering journal with tests and iterations.
- [ ] Verify hardcopy requirement and local event instructions.

Read the [official general rules](https://wro-association.org/wp-content/uploads/WRO-2026-Future-Engineers-Self-Driving-Cars-General-Rules.pdf) and the organizer's version; the README and this map are summaries.
