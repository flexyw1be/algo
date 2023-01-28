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

int main() {
    ifstream ifst("input.txt");
    ofstream ofst("output.txt");
    int n;
    ifst >> n;
    vector <vector<int>> field(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            ifst >> c;
            field[i][j] = (c == '1');
        }
    }
    int field_max = field[0][0];
    for (int i = 0; i < n; i++) {
        if (true == field[i][n - 1] || true == field[n - 1][i]) {
            field_max = 1;
            break;
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 2; j >= 0; --j) {
            if (field[i][j]) {
                field[i][j] = min(field[i + 1][j], field[i][j + 1]);
                field[i][j] = min(field[i][j], field[i + 1][j + 1]);
                field[i][j]++;
            }
            field_max = max(field[i][j], field_max);
        }
    }
    ofst << field_max * field_max;
}