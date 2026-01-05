from pathlib import Path
import subprocess
from datetime import date
from datetime import datetime, timedelta
import re


def count_solutions():
    return len(list(Path(".").rglob("*.cpp")))

if __name__ == "__main__":
    total = count_solutions()
    print(f"Total solved problems: {total}")

def get_commit_dates():
    result = subprocess.run(
        ["git", "log", "--pretty=format:%ad", "--date=short"],
        capture_output=True,
        text=True
    )
    dates = result.stdout.splitlines()
    return sorted(set(dates))

if __name__ == "__main__":
    dates = get_commit_dates()
    print("Commit days:")
    for d in dates:
        print(d)

def calculate_streaks(dates):
    dates = [datetime.strptime(d, "%Y-%m-%d").date() for d in dates]
    dates.sort()

    longest = 0
    current = 0
    streak = 1

    for i in range(1, len(dates)):
        if dates[i] == dates[i - 1] + timedelta(days=1):
            streak += 1
        else:
            longest = max(longest, streak)
            streak = 1

    longest = max(longest, streak)

    today = date.today()
    current = 0
    for d in reversed(dates):
        if d == today or d == today - timedelta(days=current):
            current += 1
        else:
            break

    return current, longest

current, longest = calculate_streaks(dates)
print(f"Current streak: {current}")
print(f"Longest streak: {longest}")

def update_readme(total, current, longest):
    with open("README.md", "r", encoding="utf-8") as f:
        content = f.read()

    new_block = (
        "<!-- PROGRESS-START -->\n"
        f"- Total problems solved: **{total}**\n"
        f"- Current streak: **{current} days**\n"
        f"- Longest streak: **{longest} days**\n"
        "<!-- PROGRESS-END -->"
    )

    content = re.sub(
        r"<!-- PROGRESS-START -->.*?<!-- PROGRESS-END -->",
        new_block,
        content,
        flags=re.DOTALL
    )

    with open("README.md", "w", encoding="utf-8") as f:
        f.write(content)

update_readme(total, current, longest)
print("README updated.")
