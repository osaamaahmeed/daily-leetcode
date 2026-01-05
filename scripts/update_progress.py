from pathlib import Path

def count_solutions():
    return len(list(Path(".").rglob("*.cpp")))

if __name__ == "__main__":
    total = count_solutions()
    print(f"Total solved problems: {total}")