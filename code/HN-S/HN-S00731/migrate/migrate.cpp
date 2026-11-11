#include <bits/stdc++.h>
#define N 2000005
#define fi first
#define se second
#define ll long long
#define ull unsigned ll
#define pii pair<int, int>
#define file(s) freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)
using namespace std;
template <typename T> inline bool ckmax(T &x, T y) {return x < y && (x = y, true);}
template <typename T> inline bool ckmin(T &x, T y) {return y < x && (x = y, true);}
int cas, T, n, L[N], R[N], ctL[N], ctR[N], pre[N], suf[N]; ll d, a[N];
inline int getr(int x)
{
    int res = ctL[x] - (L[x + 1] == x) - (L[x] == x);
    if (L[R[x + 1]] == x) res += suf[R[x + 1]];
    return res;
}
inline int getl(int x)
{
    int res = ctR[x] - (R[x - 1] == x) - (R[x] == x);
    if (R[L[x - 1]] == x) res += pre[L[x - 1]];
    return res;
}
inline ll calc(int l, int r)
{
    for (int i = l, t = l; i <= r; L[i ++] = t, ++ ctL[t])
        while (a[i] - a[t] > d) ++ t;
    for (int i = r, t = r; i >= l; R[i --] = t, ++ ctR[t])
        while (a[t] - a[i] > d) -- t;
    for (int i = l; i <= r; ++ i)
        if (R[L[i]] == i) pre[i] = pre[L[i]] + ctR[i];
        else pre[i] = ctR[i];
    for (int i = r; i >= l; -- i)
        if (L[R[i]] == i) suf[i] = suf[R[i]] + ctL[i];
        else suf[i] = ctL[i];
    ll res = 0;
    for (int i = l + 1; i <= r; ++ i) res += 1ll * getr(i - 1) * getl(i);
    return res;
}
inline void solve()
{
    cin >> n >> d;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    memset(ctL + 1, 0x00, n << 2), memset(ctR + 1, 0x00, n << 2); ll ans = 0;
    for (int l = 1, r; l <= n; ans += calc(l, r), l = r + 1)
        for (r = l; r < n && a[r + 1] - a[r] <= d; ++ r);
    cout << ans << '\n';
}
signed main()
{
    file(migrate);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for (cin >> cas >> T; T --; solve());
    return 0;
}