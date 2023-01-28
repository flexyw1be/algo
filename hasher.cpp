#include <bits/stdc++.h>

#define pb push_back
#define pf push_front
#define F first
#define INF 10e9 + 7
#define S second
#define endl "\n"
#define loop(i, l, n) for (ll i = l; i < ll(n); i++)
#define bloop(i, n, l) for (ll i = n; i > ll(l); i--)
#define cin(x) for(auto &o : x) cin >> o
#define cout(x) for(auto o : x) cout << o << ' '; cout << '\n'
#define eps 1e-12
#define sqr(a) ((a)*(a))
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define END {cout<< 0; return 0}

using namespace std;
typedef long long ll;
typedef long double ld;


struct hasher {
    vector <ll> px, h;
    ll x, mod;

    hasher(string s, ll _x, ll _mod) {
        x = _x;
        mod = _mod;
        px.pb(1);
        h.pb(0);
        ll k = 0;
        loop(i, 0, s.size()) {
            k *= x;
            k %= mod;
            k += s[i];
            k %= mod;
            px.pb((px.back() * x) % mod);
            h.pb(k);
        }
    }

    ll sub(ll l, ll r) {
        return (h[r] - (h[l - 1] * px[r - l + 1]) % mod + mod) % mod;
    }
};

int main() {
    return 0;
}