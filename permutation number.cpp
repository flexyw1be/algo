//Rucode 6
// В первой строке входных данных записано единственное целое число n (1 ≤ n ≤ 10**3) — длина перестановки.
// Во второй строке записано n целых различных чисел a[i] (1 ≤ a[i] ≤ n) — сама перестановка.


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
#define loop(i, x, n) for(ll i = i; i < n; i++)
#define eps 1e-12
#define sqr(a) ((a)*(a))

using namespace std;
using ll = long long;
typedef long double ld;
ll MAXN = 1e6 + 1;


int main() {
    int n;
    cin >> n;
    vector<int> usd(n + 1);
    ll ans = 0;
    vector <ll> f(n);
    f[0] = 1;
    for (int i = 1; i < n; i++) {
        f[i] = f[i - 1] * i;
        f[i] %= MOD;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int cnt = 0;
        for (int j = 1; j < x; j++) {
            if (!usd[j]) cnt++;
        }
        ans += cnt * f[n - i - 1];
        ans %= MOD;
        usd[x] = 1;
    }
    cout << ans + 1;
    return 0;
}