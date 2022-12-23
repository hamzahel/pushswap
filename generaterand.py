import random as rd
import sys
import os

list = []
value = 0
text = ""
result = ""

try:
    for i in range(int(sys.argv[1])):
        value = rd.randrange((-1 * int(sys.argv[2])), int(sys.argv[2]))
        if(value not in list):
            list.append(value)
    # change to strin
    for i in list:
        text += " " + str(i)
    print("[" + text + "]")
    result = os.system(
        "make;./push_swap {}; echo '[number of operations]'  ; ./push_swap {} | wc -l ".format(text, text))
except:
    print("usage: python generaterand.py [number] [range]")
