n = int(input())
a = [list(map(int, input().split())) for i in range(n)]
s = []
d = [[0 for i in range(n)] for j in range(n)]
d[0][0] = a[0][0]

for i in range(1, n):
    d[i][0] = d[i - 1][0] + a[i][0]
for i in range(1, n):
    d[0][i] = d[0][i - 1] + a[0][i]

for i in range(1, n):
    for j in range(1, n):
        d[i][j] = max(d[i - 1][j], d[i][j - 1]) + a[i][j]
print(d[-1][-1])