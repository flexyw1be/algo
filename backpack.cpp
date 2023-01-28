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

int n, m, i, j, w[1000], c[1000];


int main() {
    cin >> n >> m;
    for (i = 0; i < n; i++) cin >> w[i];
    for (i = 0; i < n; i++) cin >> c[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (i = 0; i < n; i++) {
        copy(dp[i].begin(), dp[i].end(), dp[i + 1].begin());
        for (j = 0; j + w[i] <= m; j++) {
            if (dp[i + 1][j + w[i]] < dp[i][j] + c[i]) {dp[i + 1][j + w[i]] = dp[i][j] + c[i]; }
        }
    }

    vector<int> s;
    for (i = n, j = m; i != 0; i--) {
        if (dp[i][j] != dp[i - 1][j]) {
            s.push_back(i);
            j -= w[i - 1];
        }
    }
    reverse(s.begin(), s.end());
    cout << s.size() << endl;
    for (auto i: s)
        cout << i << ' ';
}
