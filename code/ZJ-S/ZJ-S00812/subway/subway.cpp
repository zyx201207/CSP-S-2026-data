#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int N = 505;
constexpr int M = 5e5 + 5;

int C, n, m, d, q;
i64 w[M];
struct Node {
    int id;
    i64 t;

    bool friend operator < (const Node &lhs, const Node &rhs) {
        if (lhs.t != rhs.t) return lhs.t < rhs.t;
        return lhs.id < rhs.id;
    }
};
std::vector<Node> sta[M];
i64 dis[N][N];

void sol() {
    std::cin >> C >> n >> m >> d >> q;
    // n: line  m: station
    for (int i = 1; i <= m; i++) {
        std::cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        std::cin >> k;
        for (int j = 1; j <= k; j++) {
            int id;
            i64 t;
            std::cin >> id >> t;
            sta[id].push_back(Node{i, t});
        }
    }
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= m; i++) {
        for (Node ii : sta[i]) {
            for (Node jj : sta[i]) {
                dis[ii.id][jj.id] = std::min(dis[ii.id][jj.id], ii.t + jj.t);
                dis[jj.id][ii.id] = std::min(dis[jj.id][ii.id], ii.t + jj.t);
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         std::cout << i << " " << j << ": " << dis[i][j] << "\n";
    //     }
    // }
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    while (q--) {
        int u, v;
        std::cin >> u >> v;
        i64 ans = 1e18L;
        for (Node i : sta[u]) {
            for (Node j : sta[v]) {
                ans = std::min(ans, dis[i.id][j.id] + i.t + j.t);
            }
        }
        std::cout << ans + w[u] + w[v] << "\n";
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int T = 1;
    // std::cin >> T;
    while (T--) sol();

    return 0;
}