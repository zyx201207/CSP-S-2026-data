#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;

constexpr int MAXN = 5e5 + 10;

int n, ans;
ll m, a[MAXN], pre[MAXN];

inline void check(int pos) {
    ll x = a[pos], lim = m - pos * a[pos] + pre[pos - 1];
    // cout << pos << ' ' << lim << '\n';
    int l = 1, r = pos - 1, res = pos;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (pre[mid - 1] - mid * a[pos] <= lim) res = mid, r = mid - 1;
        else l = mid + 1;
    }

    ans = max(ans, pos - res + 1);
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (register int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (register int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
    for (register int i = 1; i <= n; ++i) check(i);
    cout << ans << '\n';
    return 0;
}

/*
5 8
-3 -1 2 2 7
*/