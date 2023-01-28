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

vector<int> z_function(int n, string s) {
    vector<int> z(n);
    z[0] = n;
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;

}

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> ans;
    vector<int> z = z_function(a.size() + b.size(), b + a);
    for (int i = 0; i < a.size(); i++) {
        int j = i + b.size();
        if (z[j] >= b.size())ans.pb(i);
    }
    cout(ans);
}