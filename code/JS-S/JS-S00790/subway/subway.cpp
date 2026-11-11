#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 1505;
int c, n, m, d, q;
struct Edge {
    int v, w;
};
vector<Edge> g[N * 3]; // 1~m mean "in", m+1~2m mean "station", 2m+1~3m mean "start"
int dis[N];
bool vis[N];
int ans;

bool operator <(Edge x, Edge y) {
    return x.w > y.w;
}

void solve(int st, int ed) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    priority_queue<Edge> q;
    q.push({st, 0});
    dis[st] = 0;
    while (!q.empty()) {
        int u = q.top().v;
        q.pop();
        if (vis[u] == true)
            continue;
        vis[u] = true;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].v, w = g[u][i].w;
            // cout << v << " " << w << endl;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({v, dis[v]});
            }
        }
    }
    ans = dis[ed];
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++) {
        int w;
        scanf("%d", &w);
        g[i].push_back({m + i, w});
        g[m + i].push_back({i, w});
    }
    for (int i = 1; i <= n; i++) {
        int k, last = 0;
        scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            int a, t;
            scanf("%d %d", &a, &t);
            if (j == 1)
                g[m + a].push_back({2 * m + a, t});
            else
                g[2 * m + last].push_back({m + a, t});
            last = a;
        }
    }
    // for (int i = 1; i <= 3 * m; i++) {
    //     printf("%d turn to: ", i);
    //     for (int j = 0; j < g[i].size(); j++)
    //         printf("{%d, %d} ", g[i][j].v, g[i][j].w);
    //     printf("\n");
    // }

    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);

        solve(x, y);
        // for (int i = 1; i <= m; i++)
        //     printf("%d ", dis[i]);
        // printf("\n");

        printf("%d\n", ans);
    }
    return 0;
}