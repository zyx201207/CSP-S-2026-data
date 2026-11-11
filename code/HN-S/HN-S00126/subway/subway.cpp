#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <ios>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

static constexpr int MAX_SIZE = 5e5;

static int test_id, roads_cnt, stations_cnt, max_roads, queries_cnt;
static long long base[MAX_SIZE + 5];

namespace force {
    static constexpr int MAX_STATIONS = 400;
    static long long dp[MAX_STATIONS + 5][20][MAX_STATIONS + 5][20];
    static std::vector<int> roads[MAX_STATIONS + 5];
    static std::vector<long long> cost[MAX_STATIONS + 5];

    static void solve();
}

namespace spec_a {
    static constexpr int MAX_STATIONS = 1000 * 2;
    
    static std::vector<std::pair<int, long long>> adj[MAX_STATIONS + 5];
    static long long dist[MAX_STATIONS + 5][MAX_STATIONS + 5];

    static void solve();
    static void dijkstra(int start);
}

static void solve();

int main() {
    std::freopen("subway.in", "r", stdin);
    std::freopen("subway.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // auto memory = sizeof(test_id) + sizeof(roads_cnt) + sizeof(stations_cnt) + sizeof(max_roads) + sizeof(queries_cnt) + sizeof(base) + sizeof(force::dp) + sizeof(force::roads) + sizeof(force::cost) + sizeof(spec_a::adj) + sizeof(spec_a::dist);
    // std::cerr << "Static Memory: " << (memory / 1024.0 / 1024.0) << " MB" << '\n';

    solve();

    return 0;
}

static void solve() {
    std::cin >> test_id >> roads_cnt >> stations_cnt >> max_roads >> queries_cnt;
    for (int i = 1; i <= stations_cnt; i++) {
        std::cin >> base[i];
    }

    // spec_a::solve();

    if (test_id <= 6) {
        force::solve();
    } else if (test_id <= 11) {
        spec_a::solve();
    }
}

namespace force {
    static void solve() {
        std::memset(dp, 0x3f, sizeof(dp));
        
        for (int i = 1; i <= roads_cnt; i++) {
            int len;
            std::cin >> len;
            int last_node = -1;
            for (int j = 1; j <= len; j++) {
                int node;
                long long wt;
                std::cin >> node >> wt;
                roads[node].push_back(i);
                cost[node].push_back(wt);
                if (last_node != -1) {
                    dp[last_node][roads[last_node].size() - 1][node][roads[node].size() - 1] = 0;
                    dp[node][roads[node].size() - 1][last_node][roads[last_node].size() - 1] = 0;
                }
                last_node = node;
            }
        }

        for (int i = 1; i <= stations_cnt; i++) {
            for (int j = 0; j < (int)roads[i].size(); j++) {
                dp[i][j][i][j] = 0;
            }
        }

        for (int k = 1; k <= stations_cnt; k++) {
            for (int i = 1; i <= stations_cnt; i++) {
                for (int j = 1; j <= stations_cnt; j++) {
                    for (int a = 0; a < (int)roads[i].size(); a++) {
                        for (int b = 0; b < (int)roads[j].size(); b++) {
                            for (int c = 0; c < (int)roads[k].size(); c++) {
                                for (int d = 0; d < (int)roads[k].size(); d++) {
                                    long long change_cost = ((c == d) ? 0 : (cost[k][c] + cost[k][d]));
                                    dp[i][a][j][b] = std::min(dp[i][a][j][b], dp[i][a][k][c] + dp[k][d][j][b] + change_cost);
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int q = 1; q <= queries_cnt; q++) {
            int start, end;
            std::cin >> start >> end;
            long long answer = 1e18;
            for (int i = 0; i < (int)roads[start].size(); i++) {
                for (int j = 0; j < (int)roads[end].size(); j++) {
                    answer = std::min(answer, cost[start][i] + cost[end][j] + dp[start][i][end][j]);
                }
            }
            std::cout << (answer + base[start] + base[end]) << '\n';
        }
    }
}

namespace spec_a {
    static void solve() {
        int virtual_cnt = 0;
        for (int i = 1; i <= roads_cnt; i++) {
            int len;
            std::cin >> len;
            if (len == 1) {
                int node;
                long long wt;
                std::cin >> node >> wt;
            } else {
                int node1, node2;
                long long wt1, wt2;
                virtual_cnt++;
                int vnode = stations_cnt + virtual_cnt;
                std::cin >> node1 >> wt1 >> node2 >> wt2;
                adj[node1].emplace_back(vnode, wt1);
                adj[vnode].emplace_back(node1, wt1);
                adj[node2].emplace_back(vnode, wt2);
                adj[vnode].emplace_back(node2, wt2);
            }
        }

        std::memset(dist, 0x3f, sizeof(dist));
        for (int i = 1; i <= stations_cnt; i++) {
            dijkstra(i);
        }

        for (int q = 1; q <= queries_cnt; q++) {
            int start, end;
            std::cin >> start >> end;
            std::cout << (dist[start][end] + base[start] + base[end]) << '\n';
        }
    }

    static void dijkstra(int start) {
        dist[start][start] = 0;
        using Entry = std::pair<long long, int>;
        std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> pq;
        pq.emplace(0, start);
        while (!pq.empty()) {
            auto entry = pq.top();
            pq.pop();
            int node = entry.second;
            if (entry.first != dist[start][node]) {
                continue;
            }
            for (const auto& edge : adj[node]) {
                if (dist[start][edge.first] > dist[start][node] + edge.second) {
                    dist[start][edge.first] = dist[start][node] + edge.second;
                    pq.emplace(dist[start][edge.first], edge.first);
                }
            }
        }
    }
}
