#include <bits/stdc++.h>
using namespace std;

#define NAME "crystal"
//#define CASE
#define int long long
const int N = 5e5+5, mod = 1e9+7;

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
    cin >> t;
#endif
    while(t--) {
        solve();
    }
    return 0;
}

int n, a[N];

void solve() {
    int m;
    cin >> n >> m;
    For(i,1,n) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int ans = 1;
    int j = 1;
    For(i,2,n) {
        m -= (ll)(i-j) * (a[i] - a[i-1]);
        while (m < 0 && j < i) m += a[i] - a[j], j++;
        ans = max(ans, i-j+1);
    }
    cout << ans << endl;
}