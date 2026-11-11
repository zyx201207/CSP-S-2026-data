#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6+5;
int n, k;
vector<int> g[N+5];
bool check(int d) {
    int m = n / 2;
    int idx = d;
    int nidx = d + k / 2;//wai
    int nnidx = nidx + d*2-2;
    int nnnidx = nnidx + k / 2 + (k % 2);//wai
    return nnnidx >= m - d + 2;
}
int solve(int c) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    if (k == n) return 0;
    if (c == 0 || c == 13 || c == 14) {
        int m = n / 2;
        if (k >= m) return 1;
        int l = 1, r = n + 5;
        while (l + 1 < r) {
            int mid = l + ((r-l)>>1);
            if (check(mid)) r = mid;
            else l = mid;
        }
        return r;
    }
}
signed main() {
    // !!!!!!!!!
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--) cout << solve(c);
}
