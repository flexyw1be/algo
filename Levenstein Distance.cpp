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

string a, b;
int i, j, m, n, k;

int main() {
    cin >> a;
    cin >> b;
    m = a.size();
    n = b.size();
    int d[m + 1][n + 1];
    for (i = 0; i <= m; i++) d[i][0] = i;
    for (i = 0; i <= n; i++) d[0][i] = i;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            k = min(d[i - 1][j] + 1, d[i][j - 1] + 1);
            if (a[i - 1] != b[j - 1]) { d[i][j] = min(d[i - 1][j - 1] + 1, k); }
            else { d[i][j] = min(d[i - 1][j - 1], k); }
        }
    }

    cout << d[m][n];
}
