#include <iostream>
#include <vector>
#include <queue>
#define int long long

signed main() {
    std::freopen("subway.in", "r", stdin);
    std::freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    std::cin >> c >> n >> m >> d >> q;
    std::vector<int> w(m + 1);
    for (int i = 1; i <= m; ++i) {
        std::cin >> w[i];
    }

    std::vector<std::vector<std::pair<int, int>>> graph(m + 1);
    for (int i = 1; i <= n; ++i) {
        int k;
        std::cin >> k;
        std::vector<int> station(k + 1), time(k + 1);
        for (int j = 1; j <= k; ++j) {
            std::cin >> station[j] >> time[j];
        }
        for (int j = 1; j <= k; ++j) {
            for (int z = j + 1; z <= k; ++z) {
                graph[station[j]].emplace_back(station[z], time[j]+time[z]);
                graph[station[z]].emplace_back(station[j], time[j]+time[z]);
            }
        }
    }

    while (q--) {
        int a, b;
        std::cin >> a >> b;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
        q.push({0, a});
        std::vector<int> dist(m + 1, 1e18);
        dist[a] = 0;

        while (!q.empty()) {
            std::pair<int, int> qtop = q.top();
            q.pop();

            int w1 = qtop.first, u = qtop.second;

            if (w1 != dist[u]) continue;

            for (auto edge : graph[u]) {
                int w2 = edge.second;
                int v = edge.first;

                if (dist[v] > w2 + w1) {
                    dist[v] = w2 + w1;
                    q.push({dist[v], v});
                }
            }
        }
        std::cout << dist[b] + w[a] + w[b] << '\n';
    }
}
