#include <bits/stdc++.h>
using namespace std;

const int MAXN = 507, MAXM = 5e5 + 7, MAXD = 25;
int c, n, m, q, d;
long long dis[MAXN][MAXN];
int w[MAXM];
int a[MAXM][MAXD], t[MAXM][MAXD], cnt[MAXM];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
    memset(dis, 0x37, sizeof(dis));
    for (int i = 1; i <= m; i++)
        scanf("%d", w + i);
    for (int i = 1; i <= n; i++)
    {
        int k1, a1, t1;
        dis[i][i] = 0;
        scanf("%d", &k1);
        for (int j = 1; j <= k1; j++)
        {
            scanf("%d %d", &a1, &t1);
            a[a1][++cnt[a1]] = i;
            t[a1][cnt[a1]] = t1;
        }
    }
    for (int k = 1; k <= m; k++)
    {
        for (int i = 1; i <= cnt[k]; i++)
        {
            for (int j = 1; j < i; j++)
                dis[a[k][i]][a[k][j]] = dis[a[k][j]][a[k][i]] = min<long long>(dis[a[k][i]][a[k][j]], t[k][i] + t[k][j]);
        }
    }
    /*
        我被我自己蠢哭了
        gdb20分钟没调出来结果发现n写的是MAXN.......
    */
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < i; j++)
                dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        long long ans = LONG_LONG_MAX;
        for (int i = 1; i <= cnt[x]; i++)
            for (int j = 1; j <= cnt[y]; j++)
                ans = min(ans, t[x][i] + t[y][j] + dis[a[x][i]][a[y][j]]);
        ans += w[x] + w[y];
        printf("%lld\n", ans);
    }
    return 0;
}