#include <bits/stdc++.h>

#define int long long

struct Ln {
    int idx, t;
};

int w[500010];
int lndis[510][510];
int dis[20010][510];
std::vector<Ln> sta[500010];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    memset(lndis, 0x3f, sizeof(lndis));
    memset(dis, 0x3f, sizeof(dis));

    std::istream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int c, n, m, d, q;
    std::cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        std::cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        std::cin >> k;
        for (int j = 1; j <= k; j++) {
            int a, t;
            std::cin >> a >> t;
            sta[a].push_back({i, t});
            dis[a][i] = t;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < sta[i].size(); j++) {
            lndis[j][j] = 0;
            for (int k = 0; k < sta[i].size(); k++) {
                lndis[sta[i][j].idx][sta[i][k].idx] = std::min(lndis[j][k], sta[i][j].t + sta[i][k].t);
            }
        }
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                lndis[i][j] = std::min(lndis[i][j], lndis[i][k] + lndis[k][j]);
            }
        }
    }

    while (q--) {
        int x, y;
        std::cin >> x >> y;

        int ans = LONG_LONG_MAX;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ans = std::min(ans, dis[x][i] + lndis[i][j] + dis[y][j]);
            }
        }

        std::cout << ans + w[x] + w[y] << '\n';
    }
}
