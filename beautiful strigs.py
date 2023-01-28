# Rucode 6

# Назовём строку, составленную из букв A,B и С красивой, если в ней нет двух подряд идущих букв A.
# Найти количество различных красивых строк длины N.

n = int(input())
a, dp = [0 for i in range(n + 1)], [0 for i in range(n + 1)]
a[1], dp[1] = 1, 2
for i in range(2, n + 1):
a[i], dp[i] = dp[i - 1], dp[i - 1] * 2 + a[i - 1] * 2
print(a[n] + dp[n])
