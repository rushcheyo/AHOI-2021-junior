import os
import random
import sys

n = int(sys.argv[1])
print(n)
for i in range(0, n - 1):
  for j in range(0, n - i):
    print(1, end=('\n' if j + 1 == n - i else ' '))
