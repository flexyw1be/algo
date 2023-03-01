def fib_mod(n, m):
    if n == 1:
        return 1
    d = [0 for i in range(3)]
    d[1], d[2] = 1, 1
    for j in range(3, n + 1):
        d+= [(d[j - 1] + d[j - 2]) % m]
        if d[-1] == 1 and d[-2] ==0:
            # print(1)
            t = len(d) - 2
            return d[n % t]
    return d[-1] % m


def main():
    n, m = map(int, input().split())
    print(fib_mod(n, m))


if __name__ == "__main__":
    main()
