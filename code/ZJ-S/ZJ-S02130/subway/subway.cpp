#include <bits/stdc++.h>

#define int long long

const int MAXN = 505;
const int MAXM = 500005;
const int MAXD = 25;

int c, n, m, d, q;
int w[MAXM];

int nways[MAXN]; // j th station has how many ways
std::vector<std::pair<int, int>> a[MAXN];

int dis[MAXN][MAXN];

std::vector<std::pair<int, int>> ways[MAXM];

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> c >> n >> m >> d >> q;

    for (int i = 1; i <= m; ++i)
        std::cin >> w[i];

    for (int i = 1; i <= n; ++i) {
        std::cin >> nways[i];

        a[i].resize(nways[i] + 1);
        for (int j = 1; j <= nways[i]; ++j) {
            std::cin >> a[i][j].first >> a[i][j].second;
            ways[a[i][j].first].emplace_back(i, a[i][j].second);
        }

        std::sort(a[i].begin() + 1, a[i].begin() + nways[i] + 1);
    }

    memset(dis, 0x3f, sizeof(dis));

    for (int i = 1; i <= n; ++i)
        dis[i][i] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int p = 1, q = 1;
            while (p <= nways[i] && q <= nways[j]) {
                if (a[i][p].first == a[j][q].first) {
                    dis[i][j] = dis[j][i] = std::min(dis[i][j], a[i][p].second + a[j][q].second);
                    p++, q++;
                } else if (a[i][p].first < a[j][q].first)
                    p++;
                else
                    q++;
            }
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    int x, y;
    while (q--) {
        std::cin >> x >> y;

        int ans = LLONG_MAX;

        for (const auto &p1 : ways[x]) {
            int u = p1.first;
            int t1 = p1.second;
            for (const auto &p2 : ways[y]) {
                int v = p2.first;
                int t2 = p2.second;

                ans = std::min(ans, t1 + t2 + dis[u][v]);
            }
        }

        std::cout << ans + w[x] + w[y] << '\n';
    }
}