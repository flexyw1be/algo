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

int n;
int a[100000];     
int tree[400004]; 

void build_tree(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build_tree(v * 2, tl, tm);
        build_tree(v * 2 + 1, tm + 1, tr);
        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);  
    }
}


int get_min(int l, int r, int v, int tl, int tr) {

    if (l <= tl && tr <= r) {
        return tree[v];
    }

    if (tr < l || r < tl) {
        return INT_MAX;     
    }


    int tm = (tl + tr) / 2;
    return min(get_min(l, r, v * 2,     tl,     tm),   
               get_min(l, r, v * 2 + 1, tm + 1, tr));
}

void update(int idx, int val, int v, int tl, int tr) {
    if (idx <= tl && tr <= idx) {    
        a[idx] = val;
        tree[v] = val;
        return;
    }

    if (tr < idx || idx < tl) {
        return;
    }
    int tm = (tl + tr) / 2;
    update(idx, val, v * 2,     tl,     tm);
    update(idx, val, v * 2 + 1, tm + 1, tr);
    tree[v] = min(tree[v * 2], tree[v * 2 + 1]); 
}

int main() {
    ifstream fin("window.in");
    ofstream fout("window.out");
    int n, k, i, x;
    fin >> n >>k;
    for(i=0; i < n; i ++){fin >> x; a[i] = x;}
    

    build_tree(1, 0, n - 1);
    for(i = 0; i < n - k + 1; i ++){
        fout << get_min(i, i + k - 1, 1, 0, n - 1) << endl;
    }
    

}
