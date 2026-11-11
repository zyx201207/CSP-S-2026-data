#include<bits/stdc++.h>

using namespace std;

typedef pair<long long, int> PLI;
const int N = 1e6 + 5;
int c, n, m, d, q, w[N], vis[N], dep[N], dp[N][25];
long long dis[N];
vector<PLI> G[N];

void dij(int st) {
    priority_queue<PLI, vector<PLI>, greater<PLI>> q;
    memset(dis, 0x7f, sizeof(dis));
    dis[st] = 0;
    q.push({0, st});
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        vis[u] = 1;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].second;
            if (vis[v]) continue;
            long long w = G[u][i].first;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
                dp[v][0] = u;
            }
        }
    }
}

void dfs(int u) {
    dep[u] = 1;
    int v = dp[u][0];
    if (!vis[v]) dfs(v);
    dep[u] += dep[v];
}

int LCA(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    int ca = dep[v] - dep[u];
    for (int i = 19; i >= 0; i--) {
        if (ca & (1 << i)) v = dp[v][i];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i], v = dp[v][i];
        }
    }
    return dp[u][0];
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &w[i]);
    }
    int tot = m;
    for (int i = 1; i <= n; i++) {
        int x, u = 0;
        scanf("%d", &x);
        while (x--) {
            int v, w;
            scanf("%d%d", &v, &w);
            tot++;
            G[v].push_back({w, tot}), G[tot].push_back({w, v});
            if (u) G[u].push_back({0, tot}), G[tot].push_back({0, u});
            u = tot;
        }
    }
    dij(1);
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    for (int i = 1; i <= tot; i++) {
        if (!vis[i]) dfs(i);
    }
    for (int j = 1; j <= 19; j++) {
        for (int i = 1; i <= tot; i++) {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
    while (q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%lld\n", dis[u] + dis[v] - 2 * dis[LCA(u, v)] + w[u] + w[v]);
    }
    return 0;
}
