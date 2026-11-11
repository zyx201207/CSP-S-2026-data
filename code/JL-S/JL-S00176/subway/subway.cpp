#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int c, n, m, d, q;
int a[N];
long long dis[505][505];
vector<int> e[N], w[N];
void Floyed() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
            }
        }
    }
}

void Solve() {
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) dis[i][j] = 1e18;
        }
    }
    for (int i = 1, k, x, t; i <= n; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> x >> t;
            e[x].push_back(i), w[x].push_back(t);
        }
    }
    int siz;
    for (int i = 1; i <= m; i++) {
        siz = e[i].size();
        for (int j = 0; j < siz; j++) {
            for (int k = 0; k < siz; k++) {
                if (j == k) continue;
                dis[e[i][j]][e[i][k]] = min(dis[e[i][j]][e[i][k]], (long long)w[i][j] + w[i][k]);
                dis[e[i][k]][e[i][j]] = min(dis[e[i][k]][e[i][j]], (long long)w[i][j] + w[i][k]);
            }
        }
    }
    Floyed();
    int s, t, sizs, sizt;
    long long ans;
    while (q--) {
        cin >> s >> t;
        ans = 1e18;
        sizs = e[s].size(), sizt = e[t].size();
        for (int i = 0; i < sizs; i++) {
            for (int j = 0; j < sizt; j++) {
                ans = min(ans, dis[e[s][i]][e[t][j]] + w[s][i] + w[t][j]);
            }
        }
        cout << ans + a[s] + a[t] << '\n';
    }
}

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--) Solve();
    return 0;
}
