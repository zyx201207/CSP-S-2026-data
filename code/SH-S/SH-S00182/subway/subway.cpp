#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <tuple>
#include <algorithm>
int c, n, m, d, q;
long long w[500001];
// 前500000是地铁站，后500是地铁虚拟节点
std::vector<std::pair<int, long long>> edges[501001];
long long dist[501001];
std::tuple<int, int, int> questions[100001];
long long answer[100001];
int main(void) {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; ++i) scanf("%lld", &w[i]);
    long long t;
    for (int i = 1, k, a; i <= n; ++i) {
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d %lld", &a, &t);
            int u = a, v = m + i;
            long long w = t;
            edges[u].push_back({v, w});
            edges[v].push_back({u, w});
        }
    }
    /*
    应该要离线一下
    int s, t;
    while (q--) {
        scanf("%d %d", &s, &t);
        int ans = w[s] + w[t];
        memset(dist, 0x3f, sizeof(dist));
        dist[s] = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        for (const auto& i : edges[s]) {
            pq.push({i.second, i.first});
        }
        while (!pq.empty()) {
            auto pair = pq.top();
            pq.pop();
            for (const auto& i : edges[pair.second]) {
                int to = i.first, time = pair.first + i.second;
                if (time < dist[to]) {
                    dist[to] = time;
                    pq.push({time, to});
                }
            }
        }
        printf("%d\n", dist[t] + ans);
    }
    */
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &std::get<0>(questions[i]), &std::get<1>(questions[i]));
        std::get<2>(questions[i]) = i;
    }
    std::sort(questions, questions + q);
    for (int i = 0, lasts = -1; i < q; ++i) {
        int s = std::get<0>(questions[i]), t = std::get<1>(questions[i]), idx = std::get<2>(questions[i]);
        if (s != lasts) {
            memset(dist, 0x3f, sizeof(dist));
            dist[s] = 0;
            std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
            for (const auto& i : edges[s]) {
                pq.push({i.second, i.first});
            }
            while (!pq.empty()) {
                auto pair = pq.top();
                pq.pop();
                for (const auto& i : edges[pair.second]) {
                    int to = i.first;
                    long long time = pair.first + i.second;
                    if (time < dist[to]) {
                        dist[to] = time;
                        pq.push({time, to});
                    }
                }
            }
            lasts = s;
        }
        answer[idx] = w[s] + dist[t] + w[t];
    }
    for (int i = 0; i < q; ++i) printf("%lld\n", answer[i]);
    // 16：16，预计60pts
    return 0;
}