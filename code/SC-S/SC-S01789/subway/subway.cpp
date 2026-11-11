#include <bits/stdc++.h>
using namespace std;

struct Subway
{
    int u, w;
};

const int N = 505, M = 500005;
long long G [N][N], dis [N][N];
int w [M], cur [M];
Subway stn [M][24];

int main ()
{
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    int c, n, m, d, q;
    scanf ("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++)
    {
        scanf ("%d", w + i);
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf ("%d", &k);
        while (k--)
        {
            int a, t;
            scanf ("%d%d", &a, &t);
            stn [a][++cur [a]] = {i, t};
        }
    }
    memset (G, 0x3f, sizeof (G));
    for (int i = 1; i <= m; i++)
    {
        // printf ("%d\n", stn [i].size ());
        for (int x = 1; x <= cur [i]; x++)
        {
            for (int y = x + 1; y <= cur [i]; y++)
            {
                int u = stn [i][x].u, v = stn [i][y].u, w = stn [i][x].w + stn [i][y].w;
                G [u][v] = min (G [u][v], 1ll * w);
                G [v][u] = min (G [v][u], 1ll * w);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis [i][j] = G [i][j];
        }
        dis [i][i] = 0;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis [i][j] = min (dis [i][j], dis [i][k] + dis [k][j]);
            }
        }
    }
    while (q--)
    {
        int x, y;
        scanf ("%d%d", &x, &y);
        long long ans = 9e18;
        for (int a = 1; a <= cur [x]; a++)
        {
            for (int b = 1; b <= cur [y]; b++)
            {
                Subway i = stn [x][a], j = stn [y][b];
                ans = min (ans, i.w + j.w + dis [i.u][j.u]);
            }
        }
        printf ("%lld\n", ans + w [x] + w [y]);
    }
    return 0;
}