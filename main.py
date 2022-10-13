#!/usr/bin/python3
import sys
from datetime import datetime

now = datetime.now().strftime("%H : %M : %S")
print(f"time: {now}")
if len(sys.argv) != 2:
    print(f"Usage: {sys.argv[0]} <file>")
    sys.exit(1)
with open(sys.argv[1], "r") as op:
    for line in op:
        print(f"-->lne: {line.strip()}")
        num = int(line.strip())
        print(f"-->num: {num}")
        i = 2
        while i < num:
            if num % i == 0:
                print(f"{num} = {num / i} * {i}")
                break;
            i += 1
        print()
print("done!")
now = datetime.now().strftime("%H : %M : %S")
print(f"time: {now}")
