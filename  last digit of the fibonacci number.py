n = int(input())
if n == 1:
    print(1)
    quit()
d = [0 for i in range(n + 1)]
d[0], d[1] = 1, 1
for j in range(2, n + 1):
    d[j] = d[j - 1] + d[j - 2]
print(str(d[-1])[-1])
