#!/usr/bin/env python3
"""Audit submission evidence without inventing or awarding a competition score."""
from pathlib import Path
import csv
import re
import sys

ROOT = Path(__file__).resolve().parents[1]
issues = []

readme = (ROOT / "README.md").read_text(encoding="utf-8")
if len(readme) < 5000:
    issues.append(f"README is {len(readme)} characters; 2026 rules require >=5000.")

for link in re.findall(r"\[[^]]+\]\(([^)]+)\)", readme):
    if link.startswith(("http://", "https://", "#", "mailto:")):
        continue
    target = link.split("#", 1)[0]
    if target and not (ROOT / target).exists():
        issues.append(f"README link target missing: {link}")

photos = [
    "vehicle-front", "vehicle-back", "vehicle-left", "vehicle-right",
    "vehicle-top", "vehicle-bottom", "team",
]
for stem in photos:
    if not any((ROOT / "media" / f"{stem}.{ext}").exists()
               for ext in ("jpg", "jpeg", "png", "webp")):
        issues.append(f"Missing original photo: media/{stem}.jpg")

media = (ROOT / "media/README.md").read_text(encoding="utf-8")
if media.count("| TBD |") >= 2:
    issues.append("Two challenge video links and corresponding run IDs still need verification.")

with (ROOT / "hardware/bom.csv").open(newline="", encoding="utf-8") as handle:
    parts = list(csv.DictReader(handle))
if not parts or any(row["status"] != "verified installed" for row in parts):
    issues.append("As-built BOM has candidate, unknown, or unverified parts.")

with (ROOT / "data/trials-template.csv").open(newline="", encoding="utf-8") as handle:
    fields = next(csv.reader(handle))
if not {"run_id", "firmware_commit", "success", "failure_reason"}.issubset(fields):
    issues.append("Trial template is missing required traceability columns.")
if not list((ROOT / "data").glob("trials-20*.csv")):
    issues.append("No dated real trial results are present.")

if not any(p.suffix in (".ino", ".cpp", ".py") and "diagnostic" not in str(p)
           for p in (ROOT / "src").rglob("*") if p.is_file()):
    issues.append("No final autonomous driving source code is present.")

print(f"README length: {len(readme)} characters")
print(f"Audit: {len(issues)} outstanding items.")
for item in issues:
    print(f"- {item}")
print("This is a completion audit, not an official WRO score.")
sys.exit(0 if not issues else 1)
