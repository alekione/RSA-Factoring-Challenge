#!/usr/bin/python3
import random

with open("test", "w") as op:
    i = 0;
    while i < 100:
        num = random.randint(100, 10000)
        op.write(str(num))
        op.write("\n")
        i += 1
