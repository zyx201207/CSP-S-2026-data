#include <bits/stdc++.h>
using namespace std;

const int N = 510, M = 500010;
int c, n, m, d, q, k[N], w[M], a[N][M], t[N][M];
long long dis[1510][1510];
vector<pair<int, int>> e[1510];

void dijk(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    for (int i = 1; i <= n + m; i++)
        dis[start][i] = 1ll << 60;
    dis[start][start] = 0;
    while (!pq.empty()) {
        int u = pq.top().second, dd = pq.top().first;
        pq.pop();
        if (dd > dis[start][u]) continue;
        for (auto [v, time] : e[u]) {
            if (dis[start][v] > dis[start][u] + time) {
                dis[start][v] = dis[start][u] + time;
                pq.push(make_pair(dis[start][v], v));
            }
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++) scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
        for (int j = 1; j <= k[i]; j++) {
            scanf("%d%d", &a[i][j], &t[i][j]);
        }
    }
    if (c <= 11) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= k[i]; j++)
                e[m + i].emplace_back(a[i][j], t[i][j]),
                e[a[i][j]].emplace_back(m + i, t[i][j]);
        for (int i = 1; i <= n + m; i++) {
            dijk(i);
        }
        while (q--) {
            int st, en;
            scanf("%d%d", &st, &en);
            printf("%lld\n", w[st] + w[en] + dis[st][en]);
        }
    }
    return 0;
}
