#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main() {
    // !!!!!!!!!
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int n; i64 m;
    cin >> n >> m;
    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    i64 used = 0; int ans = 1;
    for (int r = 1, l = 0; r < n; r++) {
        int w = r - l;
        i64 h = a[r] - a[r-1];
        used += w * h;
        while (used > m) {
            used -= a[r] - a[l++];
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
}
