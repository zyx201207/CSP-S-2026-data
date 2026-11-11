#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005];
vector<pair<int, int>>e[510000];
long long dis[510000];
int tot;
long long dij(int s, int t) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
    for (int i = 1; i < tot; i++) {
        dis[i] = LLONG_MAX - 5;
    }
    dis[s] = 0;
    pq.push({0,s});
    while (pq.size()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d > dis[u])continue;
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i].first, W = e[u][i].second;
            if (W + d < dis[v]) {
                dis[v] = W + d;
                pq.push({W + d, v});
            }
        }
    }
    return dis[t];
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &w[i]);
    }
    tot = m + 1;
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            int a, b;
            scanf("%d%d", &a, &b);
            e[a].push_back({tot, b});
            e[tot].push_back({a, b});
            if (j > 1) {
                e[tot].push_back({tot - 1, 0});
                e[tot - 1].push_back({tot, 0});
            }
            tot++;
        }
    }
    while (q--) {
        int s, t;
        scanf("%d%d", &s, &t);
        printf("%lld\n", dij(s, t) + w[s] + w[t]);
    }
    return 0;
}
