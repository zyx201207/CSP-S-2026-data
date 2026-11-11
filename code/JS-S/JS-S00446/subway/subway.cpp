#include<bits/stdc++.h>
using namespace std;
inline int rd()
{
    int a = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        ch = getchar();
    }
    while (isdigit(ch))
    {
        a = (a << 3) + (a << 1) + (ch ^ 48);
        ch = getchar();
    }
    return a;
}
const int M = 1e4 + 10, N = 505, inf = 0x3f3f3f3f;
int m, n, c, d, q;
int w[M], k[N], dis[M][N], e[M][N], a[M][N], t;
bool vis[M];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = rd();n = rd();m = rd();d = rd(); q = rd();
    memset(vis, 0, sizeof(vis));
    memset(dis, inf, sizeof(dis));
    for (int i = 1; i <= m; ++i)
    {
        w[i] = rd();
    }
    for (int i = 1; i <= n; ++i)
    {
        k[i] = rd();
        for (int j = 1; j <= k[i]; ++j)
        {
            a[i][j] = rd(), t = rd();
            e[a[i][j]][i] = t;
        }
    }
    for (int u = 1; u <= m; u++)
    {
        for (int i = 1; i <= n; i++)
        {
            if(e[u][i])
            {
                for (int j = 1; j <= k[i]; j++)
                {
                    dis[u][a[i][j]] = min(dis[u][a[i][j]], e[u][i] + e[a[i][j]][i]);
                }
            }
        }
    }
    for (int u = 1; u <= m; u++)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (dis[u][i] > dis[u][j] + dis[j][i])
                {
                    dis[u][i] = dis[u][j] + dis[j][i];
                }
            }
        }
    }
    for (int i = 1; i <= q; ++i)
    {
        int x = rd(), y = rd();
        int xx = dis[x][y] + w[x] + w[y];
        printf("%d\n", xx);
    }
    return 0;
}
