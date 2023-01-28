//Решите в целых числах систему уравнений:
// x == a(mod n)
// x == b(mod m),
//где n и m взаимно простые. Среди решений выберите наименьшее неотрицательное число.
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

long long gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1 = 0, y1 = 0;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

long long Euclid(ll a, ll m) {
    ll x, y;
    ll res = gcd(a, m, x, y);
    return (x + m) % m;
}

long long kto(vector <ll> &a, vector <ll> &p) {
    long long result = 0;
    long long mul = 1;
    size_t n = a.size();
    vector <vector<ll>> r(n, vector<ll>(n));
    vector <ll> x(n);
    for (int i = 0; i < r.size(); ++i)
        for (int j = i + 1; j < p.size(); ++j) {
            r[i][j] = Euclid(p[i], p[j]);
        }
    for (int i = 0; i < n; ++i) {
        x[i] = a[i];
        for (int j = 0; j < i; ++j) {
            x[i] = (x[i] - x[j]) * r[j][i];
            x[i] = x[i] % p[i];

            if (x[i] < 0) {
                x[i] += p[i];
            }
        }
        result += mul * x[i];
        mul *= p[i];
    }
    return result;
}

int main() {
    vector <ll> a;
    vector <ll> p;
    for (int i = 0; i < 2; ++i) {
        ll aa;
        cin >> aa;
        a.pb(aa);
    }
    for (int i = 0; i < 2; ++i) {
        long long pp;
        cin >> pp;
        p.pb(pp);
    }
    cout << kto(a, p);
    return 0;
}