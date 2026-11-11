#include <bits/stdc++.h>
using namespace std;

#define NAME "hub"
#define CASE
#define int long long
const int N = 1e5+5, mod = 1e9+7;

#define File(name) freopen(name".in", "r" ,stdin), freopen(name".out","w",stdout);
#define For(i,l,r) for (int i = l; i <= r; i++)
#define rFor(i,l,r) for (int i = r; i >= l; i--)
#define rg(c) c.begin(), c.end()
#define ms(c,v) memset(c, v, sizeof v)
#define l first
#define r second
#define endl '\n'
#define ll long long

int qpow(int a, int b, int m = mod) {
    if (b == 0) return 1;
    int v = qpow(a, b>>1, m);
    return (ll)v * v % m * ((b&1)?a:1) % m;
} 

void solve();

signed main() {
    File(NAME);
    int t = 1;
#ifdef CASE
    cin >> t >> t;
#endif
    while(t--) {
        solve();
    }
    return 0;
}

void solve() {
    cout << 1 << endl;
}