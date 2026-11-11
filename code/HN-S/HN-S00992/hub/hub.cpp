// BLuemoon_
#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int kMaxN = 1e6 + 5, kMaxM = 1e3 + 5;
const LL kP = 1e9 + 7;

LL cT, T = 1, n, k, a[kMaxN], ans = 1e18, t[kMaxN], tot, vis[kMaxN], dis[kMaxM][kMaxM];
vector<int> g[kMaxN];
vector<pair<LL, LL>> f[kMaxM];

void DFS1(int u, int fa, int rt) {
    for (int v : g[u]) {
        if (v != fa) {
            dis[rt][v] = dis[rt][u] + 1, DFS1(v, u, rt);
        }
    }
}
void DFS(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v] && t[v]) {
            DFS(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout);
    for (cin >> cT >> T; T; T--, ans = 1e18) {
        cin >> n >> k;
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
        }
        if (cT <= 3) {
            for (int i = 1; i <= n; i++) {
                DFS1(i, 0, i);
            }
            for (int i = 0; i < 1 << n; i++) {
                if (__builtin_popcount(i) != k) {
                    continue;
                }
                for (int j = 1; j <= n; j++) {
                    t[j] = (i >> (j - 1) & 1), vis[j] = 0;
                }
                tot = 0;
                for (int j = 1; j <= n; j++) {
                    if (!vis[j] && t[j]) {
                        tot++, DFS(j);
                    }
                }
                if (tot > 2) {
                    continue;
                }
                LL mx = 0;
                for (int j = 1; j <= n; j++) {
                    if (!t[j]) {
                        LL mn = 1e18;
                        for (int l = 1; l <= n; l++) {
                            t[l] && (mn = min(mn, dis[j][l]));
                        }
                        mx = max(mx, mn);
                    }
                }
                ans = min(ans, mx);
            }
            cout << ans << '\n';
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dis[i][j] = 0;
                }
            }
        } else if (cT == 13 || cT == 14) {
            int m = n / 2;
            if (k == n) {
                cout << "0\n";
            } else if (k >= m) {
                cout << "1\n";
            } else {
                cout << (m - k + 3) / 4 + 1 << '\n';
            }
        }
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
    }
    return 0;
}
// g++ hub.cpp -o hub -O2 -static -Wall && time ./hub