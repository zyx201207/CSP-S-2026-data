#include <bits/stdc++.h>
using namespace std;
int c, t, n, d, cnt;
long long minl, a[2000005];
void dfs(int x, int len, int t) {
    if (len > minl) {
        return ;
    }
    if (x >= t) {
        if (len < minl) {
            minl = len, cnt = 1;
        } else if (len == minl) {
            ++cnt;
        }
        return ;
    }
    for (int i = x + 1; a[i] - a[x] <= d && i <= t; ++i) {
        dfs(i, len + 1, t);
    }
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            for (int j = 1; j < i; ++j) {
                minl = LLONG_MAX, cnt = 0;
                dfs(j, 0, i);
                ans += (cnt == 2);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
