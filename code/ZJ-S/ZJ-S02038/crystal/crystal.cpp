#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, t, ans;
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> t;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end(), [&](int x, int y) { return x > y; });
    for (int i = 1; i <= n; i++) {
        int p = i + 1, cnt = 1, m = t;
        while (p <= n && a[i] - a[p] <= m)
            cnt++, m -= a[i] - a[p], p++;
        ans = max(ans, cnt);
        if (p > n) break;
    }
    return cout << ans, 0;
}