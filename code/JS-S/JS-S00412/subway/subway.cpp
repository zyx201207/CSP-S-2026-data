#include <bits/stdc++.h>
using namespace std;

const int N = 505, M = 20005;
int c, n, m, d, q;
int k[N], a[N][M], t[N][M], dis[M][M], w[M];
vector < int > edge[M];

void dfs(int u, int pa, int w)
{
    for (int v : edge[u])
    {
        if (v == pa) continue;
        dfs(v, u, dis[u][v]);
        dis[pa][v] = dis[v][pa] = min(dis[pa][v], w + dis[u][v]);
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            dis[i][j] = 1e9;
    for (int i = 1; i <= m; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k[i]);
        for (int j = 1; j <= k[i]; j++)
            scanf("%d%d", &a[i][j], &t[i][j]);
        for (int j = 1; j <= k[i]; j++)
            for (int p = j + 1; p <= k[i]; p++)
            {
                int x = a[i][j], y = a[i][p];
                int tx = t[i][j], ty = t[i][p];
                edge[x].push_back(y);
                edge[y].push_back(x);
                dis[x][y] = dis[y][x] = min(dis[x][y], tx + ty);
            }
    }
    dfs(1, 0, 0);
    for (int i = 1, s, e; i <= q; i++)
    {
        scanf("%d%d", &s, &e);
        int ans = w[s] + dis[s][e] + w[e];
        printf("%d\n", ans);
    }
    return 0;
}
