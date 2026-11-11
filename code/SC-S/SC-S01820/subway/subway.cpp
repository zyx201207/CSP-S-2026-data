#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 5e5 + 9;

int tid, n, m, d, q, W[N];

vector < int > a[N], t[N];

vector < pair < int, int > > L[N];

LL dis[509][509];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &tid, &n, &m, &d, &q);
    for (int i = 1;i <= m;++ i)
        scanf("%d", &W[i]);
    for (int i = 1;i <= n;++ i)
        for (int j = 1;j <= n;++ j)
            if (i != j)
                dis[i][j] = 1e18;
            else
                dis[i][j] = 0;
    for (int i = 1, k;i <= n;++ i)
    {
        scanf("%d", &k);
        for (int x, y, j = 0;j < k;++ j)
        {
            scanf("%d%d", &x, &y);
            a[i].push_back(x), t[i].push_back(y);
            L[x].push_back({i, j});
        }
    }
    for (int i = 1;i <= m;++ i)
        for (auto it1 : L[i])
            for (auto it2 : L[i])
            {
                int x = it1.first, ix = it1.second;
                int y = it2.first, iy = it2.second;
                dis[x][y] = min(dis[x][y], 1ll * t[x][ix] + t[y][iy]);
            }
    for (int k = 1;k <= n;++ k)
        for (int i = 1;i <= n;++ i)
            for (int j = 1;j <= n;++ j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for (int x, y;q --;)
    {
        scanf("%d%d", &x, &y);
        LL ans = 1e18;
        for (auto itx : L[x])
            for (auto ity : L[y])
            {
                int u = itx.first, iu = itx.second;
                int v = ity.first, iv = ity.second;
                ans = min(ans, dis[u][v] + t[u][iu] + t[v][iv]);
            }
        printf("%lld\n", ans + W[x] + W[y]);
    }

    return 0;
}