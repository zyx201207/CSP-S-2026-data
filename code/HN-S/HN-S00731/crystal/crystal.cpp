#include <bits/stdc++.h>
#define N 500005
#define fi first
#define se second
#define ll long long
#define ull unsigned ll
#define pii pair<int, int>
#define file(s) freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
using namespace std;
template <typename T> inline bool ckmax(T &x, T y) {return x < y && (x = y, true);}
template <typename T> inline bool ckmin(T &x, T y) {return y < x && (x = y, true);}
int n; ll a[N], m;
signed main()
{
    file(crystal);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    sort(a + 1, a + n + 1); ll sum = 0; int ans = 1;
    for (int i = 2, t = 1; i <= n; ++ i)
    {
        sum += (i - t) * (a[i] - a[i - 1]);
        while (t <= i && sum > m) sum -= a[i] - a[t ++];
        ckmax(ans, i - t + 1);
    }
    return cout << ans, 0;
}