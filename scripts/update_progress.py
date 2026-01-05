from pathlib import Path
import subprocess
from datetime import date


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