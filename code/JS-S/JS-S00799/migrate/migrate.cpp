#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int N =2e6+5;
int n;
i64 d, a[N+5], cc[N+5];
int xx, cnt;
void dfs(int src, int dst, int x) {
    if (cc[src] < x) return;
    cc[src] = x;
    if (src == dst) {
        if (x < xx) xx = x, cnt = 0;
        cnt++;
    }
    for (int i = src + 1; i <= dst; i++) {
        if (a[i] - a[src] > d) break;
        dfs(i, dst, x + 1);
    }
}
int solve() {
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    //cerr << n << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = i+2; j < n; j++) {
            xx = n + 500, cnt = 0;
            memset(cc, 0x3f, sizeof cc);
            dfs(i, j, 0);
            if (cnt == 2) ans++;
            //cerr << i << ' ' << j << ' ' << xx << ' ' << cnt << '\n';
        }
    }
    return ans;
}
signed main() {
    // !!!!!!!!!
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int c, t; cin >> c >> t;
    while (t--) cout << solve() << '\n';
}
