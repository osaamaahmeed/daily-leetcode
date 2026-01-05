#!/bin/bash

read -p "Enter problem title (e.g. 3433. Count Mentions Per User): " TITLE

PROBLEM_NUMBER=$(echo "$TITLE" | cut -d'.' -f1)

PROBLEM_NAME=$(echo "$TITLE" | cut -d'.' -f2- | xargs)
SLUG=$(echo "$PROBLEM_NAME" | tr '[:upper:]' '[:lower:]' | tr ' ' '-' | tr -cd 'a-z0-9-')

FILENAME="${PROBLEM_NUMBER}-${SLUG}.cpp"

if [[ "$FILENAME" != *.cpp ]]; then
    FILENAME="$FILENAME.cpp"
fi
# echo "Creating file: $FILENAME"

echo "Choose date solved:"
echo "1) Today"
echo "2) Enter manually (DD/MM/YYYY)"
read -p "Choice: " DATE_CHOICE

if [ "$DATE_CHOICE" = "1" ]; then
    DATE_SOLVED=$(date +"%Y-%m-%d")
else
    read -p "Enter date (DD/MM/YYYY): " INPUT_DATE

    DAY=$(echo "$INPUT_DATE" | cut -d'/' -f1)
    MONTH=$(echo "$INPUT_DATE" | cut -d'/' -f2)
    YEAR=$(echo "$INPUT_DATE" | cut -d'/' -f3)

    DATE_SOLVED="$YEAR-$MONTH-$DAY"
fi

if ! date -d "$DATE_SOLVED" >/dev/null 2>&1; then
    echo "❌ Invalid date. Please use DD/MM/YYYY."
    exit 1
fi

YEAR=$(date -d "$DATE_SOLVED" +"%Y")
MONTH_NUM=$(date -d "$DATE_SOLVED" +"%m")
MONTH_NAME=$(date -d "$DATE_SOLVED" +"%B")

TARGET_DIR="$YEAR/${MONTH_NUM}-${MONTH_NAME}"

echo "Select difficulty:"
echo "1) easy"
echo "2) med"
echo "3) hard"
read -p "Choice: " DIFF_CHOICE

case $DIFF_CHOICE in
    1) DIFFICULTY="Easy" ;;
    2) DIFFICULTY="Medium" ;;
    3) DIFFICULTY="Hard" ;;
    *) DIFFICULTY="Unknown" ;;
esac

mkdir -p "$TARGET_DIR"
FULL_PATH="$TARGET_DIR/$FILENAME"
echo "Creating file at: $FULL_PATH"

cat <<EOF > "$FULL_PATH"
// LeetCode #$PROBLEM_NUMBER - $PROBLEM_NAME
// Date Solved: $DATE_SOLVED
// Difficulty: $DIFFICULTY


/* Problem Summary:

*/

/* Approach:

Complexity:
Time:
Space:

*/

// Notes:

#include <bits/stdc++.h>
using namespace std;


int main() {
    return 0;
}
EOF

echo "✅ Created successfully."

if command -v code >/dev/null 2>&1; then
    code "$FULL_PATH"
else
    echo "⚠️ VS Code not found in PATH. File created but not opened."
fi