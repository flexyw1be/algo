//Найдите все простые в диапазоне [A. . B].
//Даны 1 ≤ A ≤ B ≤ 10**12. Дополнительно известно ∣B − A∣ ≤ 10**6.
//Rucode 6

#include <bits/stdc++.h>

#define pb push_back
#define pf push_front
#define F first
#define mn 10e9 + 7
#define S second
#define MOD 1000000007
#define endl "\n"
#define cin(x) for(auto &o : x) cin >> o
#define cout(x) for(auto o : x) cout << o << ' '; cout << '\n'
#define loop(x, n) for(ll i = x; i < n; i++)
#define eps 1e-12
#define sqr(a) ((a)*(a))

using namespace std;
using ll = long long;
typedef long double ld;
ll MAXN = 1e6 + 1;

ll max(ll a, ll b) { return a > b ? a : b; }

int main() {
    ll a, b;
    cin >> a >> b;
    bool prime[MAXN], ans[MAXN];
    memset(prime, true, MAXN);
    memset(ans, true, MAXN);
    prime[0] = prime[1] = false;
    ll mmax = MAXN - 1;
    for (ll i = 2; i <= mmax; ++i) {
        if (prime[i]) {
            ll r = a % i;
            r = (i - r) % i;
            if (a + r > i && r < MAXN)
                ans[r] = false;
            if (i + r < MAXN && a + r + i > i)
                ans[i + r] = false;
            for (ll j = 2 * i; j <= mmax; j += i) {
                prime[j] = false;
                if (a <= j && j - a < MAXN)
                    ans[j - a] = false;
                if (j + r < MAXN) {
                    ans[j + r] = false;
                }
            }
        }
    }
    for (ll i = 0; i <= b - a; ++i) {
        if (ans[i] && a + i >= 2)
            cout << a + i << ' ';
    }
}