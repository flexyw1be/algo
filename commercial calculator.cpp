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


ll n, x, sum, res = 0;
priority_queue<int, vector<int>, greater<int> > h;

int main() {
    cin >> n;
    while (n--) cin >> x, h.push(x);
    while (h.size() > 1) {
        sum = h.top();
        h.pop();
        res += sum += h.top();
        h.pop();
        h.push(sum);
    }
    printf("%.2f", res * 0.05);
    return 0;
}