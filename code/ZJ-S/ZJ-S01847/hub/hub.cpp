#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int C, T, n, k, vis[N], vis2[N];
vector<int> e[N];
void dfs(int x, int fa) {
    vis2[x] = 1;
    for (int y : e[x]) if (vis[y] && y != fa) dfs(y, x);
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) e[i].clear();
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v, e[u].push_back(v), e[v].push_back(u);
    }
    if (C == 13 || C == 14) {
        int m = (n - 1) / 2;
        if (k >= m + 1) {
            if (k < n) cout << 1 << '\n'; 
            else cout << 0 << '\n';
        } else {
            int rest = (m + 1) - k;
            cout << (rest + 3) / 4 + 1 << '\n';
        } 
    }
    else if (C <= 3) {
        int ans = N - 10;
        for (int i = 1; i < (1 << n); ++i) {
            int cnt = __builtin_popcount(i);
            if (cnt > k) continue;
            queue<pair<int, int> > q;
            for (int j = 1; j <= n; ++j) {
                vis[j] = vis2[j] = 0;
                if (i & (1 << (j - 1))) q.push({j, 0}), vis[j] = 1;
            }
            cnt = 0;
            for (int j = 1; j <= n; ++j) {
                if (!vis2[j] && vis[j]) dfs(j, 0), ++cnt;
            }
            if (cnt > 2) continue;
            int mx = 0;
            while (!q.empty()) {
                int x = q.front().first, s = q.front().second;
                mx = max(mx, s);
                q.pop();
                for (int y : e[x]) if (!vis[y]) {
                    vis[y] = 1, q.push({y, s + 1});
                }
            }
            ans = min(ans, mx);
        }
        cout << ans << '\n';
        return;
    }
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> C >> T;
    while (T--) solve();
}