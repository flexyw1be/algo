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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    string s;
    while (getline(cin, s)) {
        bool flag = true;
        stack<char> stack;
        for (int i = 0; i < int(s.length()); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
            } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (stack.empty() || ((s[i] == ')') ^ (stack.top() == '(')) || ((s[i] == '}') ^ (stack.top() == '{')) ||
                    ((s[i] == ']') ^ (stack.top() == '['))) {
                    {
                        flag = false;
                        break;
                    }
                }
                stack.pop();
            }
        }
        if (!stack.empty())
            flag = false;
        if (flag == true)
            cout << 0;
        else
            cout << 1;
    }
    return 0;
}