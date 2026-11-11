#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define ull unsigned ll
#define pii pair<int, int>
#define file(s) freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
using namespace std;
template <typename T> inline bool ckmax(T &x, T y) {return x < y && (x = y, true);}
template <typename T> inline bool ckmin(T &x, T y) {return y < x && (x = y, true);}
mt19937_64 rnd(random_device{}());
int n = 500000, k;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << n << ' ' << rnd() % 1000000000000000000 + 1 << '\n';
    for (int i = 1; i <= n; ++ i) cout << rnd() % 1000000000000 + 1 << '\n';
    return 0;
}