#include <bits/stdc++.h>

using namespace std;

const int MaxN = 50;

int ca, T, n, k, dis[MaxN][MaxN], d[MaxN], fa[MaxN], u[MaxN], v[MaxN];
vector<int> g[MaxN];

int Find(int x) {
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void Clear() {
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    // freopen("hub3.in", "r", stdin);
    // freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    for (cin >> ca >> T; T; T--, Clear()) {
        cin >> n >> k;
        memset(dis, 0x3f, sizeof(dis));
        for (int i = 1; i < n; i++) {
            cin >> u[i] >> v[i];
            dis[u[i]][v[i]] = dis[v[i]][u[i]] = 1;
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        int ans = 1e9;
        for (int s = 0; s < 1 << n; s++) {
            if (__builtin_popcount(s) != k) continue;
            fill(d, d + n + 1, 1e9);
            iota(fa, fa + n + 1, 0);
            for (int i = 1; i < n; i++) {
                if (!(s >> u[i] - 1 & 1) && !(s >> v[i] - 1 & 1)) {
                    if (Find(u[i]) != Find(v[i])) {
                        fa[Find(v[i])] = Find(u[i]);
                    }
                }
            }
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (!(s >> i - 1 & 1)) cnt += Find(i) == i;
            }
            if (cnt > 2) continue;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (s >> i - 1 & 1) {
                        if (!(s >> j - 1 & 1)) {
                            d[j] = min(d[j], dis[i][j]);
                        }
                    }
                }
            }
            int ret = 0;
            for (int i = 1; i <= n; i++) {
                if (!(s >> i - 1 & 1)) ret = max(ret, d[i]);
            }
            ans = min(ans, ret);
        }
        cout << ans << '\n';
    }
    return 0;
}