N = 83
M = 7
print(N)
print(M)
print(M)
for i in range(N):
    s = '0' * (M + 2 - len(bin(i))) + bin(i)[2:]
    print(*s)
for i in range(N):
    s = '0' * (M + 2 - len(bin(i))) + bin(i)[2:]
    print(*s)
for i in range(M):
    print(1, end=' ')
