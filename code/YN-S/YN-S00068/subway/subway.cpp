#include <bits/stdc++.h>
#define N 505
#define M 500005
#define INF 1000000000
#define pii std::pair<int, int>
typedef long long ll;

int c, n, m, d, q, a[N][M], t[N][M], w[M], k[N];
int g[M][22];
int dis[M];
void bfs(int x, int y)
{
    for (int i = 1; i <= m; i++)
    {
        dis[i] = INF;
    }
    std::queue<int> pp;
    pp.push(x);
    dis[x] = 0;
    while (!pp.empty())
    {
        int u = pp.front();
        pp.pop();
        for (int i = 1; i <= g[u][0]; i++)
        {
            for (int j = 1; j <= k[g[u][i]]; j++)
            {
                int v = a[g[u][i]][j];
                if (dis[v] == INF)
                {
                    if (u == x)
                    // if (false)
                    {
                        dis[v] = dis[u] + t[g[u][i]][v];
                    }
                    else
                    {
                        dis[v] = dis[u] + t[g[u][i]][v] + t[g[u][i]][u];
                    }
                    pp.push(v);
                }
                else
                {
                    if (u == x)
                    // if (false)
                    {
                        dis[v] = std::min(dis[v], dis[u] + t[g[u][i]][v]);
                    }
                    else
                    {
                        dis[v] = std::min(dis[v], dis[u] + t[g[u][i]][v] + t[g[u][i]][u]);
                    }
                }
            }
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k[i]);
        for (int j = 1; j <= k[i]; j++)
        {
            scanf("%d%d", &a[i][j], &t[i][j]);
            g[a[i][j]][++g[a[i][j]][0]] = i;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        // ans = INF;
        bfs(x, y);
        int ans = dis[y];
        // int ans = 0;
        ans += w[x] + w[y];
        printf("%d\n", ans);
    }
    return 0;
}