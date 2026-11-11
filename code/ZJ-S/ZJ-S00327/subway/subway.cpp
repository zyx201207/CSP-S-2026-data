#include <bits/stdc++.h>
using namespace std;

#define int long long 

constexpr int maxm = 5e5 + 100;
constexpr int maxn = 5e2 + 100;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;

int w[maxm];

int dis[maxn][maxn];

vector<pair<int, int>> has_station[maxm];

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int c, n, m, d, q;
    scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);

    for(int i = 1; i <= m; ++i)
    {
        scanf("%lld", &w[i]);
    }

    for(int i = 1; i <= n; ++i)
    {
        int k;
        scanf("%lld", &k);

        for(int j = 1; j <= k; ++j)
        {
            int a, t;
            scanf("%lld%lld", &a, &t);

            has_station[a].emplace_back(i, t);
        }
    }

    memset(dis, 0x3f, sizeof(dis));
    for(int i = 1; i <= n; ++i)
    {
        dis[i][i] = 0;
    }

    for(int i = 1; i <= m; ++i)
    {
        int station_cnt = has_station[i].size();
        for(int j = 0; j < station_cnt; ++j)
        {
            for(int k = 0; k < station_cnt; ++k)
            {
                int station1 = has_station[i][j].first;
                int station2 = has_station[i][k].first;

                dis[station1][station2] = min(dis[station1][station2], has_station[i][j].second + has_station[i][k].second);
            }
        }
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            for(int k = 1; k <= n; ++k)
            {
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }

    for(int i = 1; i <= q; ++i)
    {
        int x, y;
        scanf("%lld%lld", &x, &y);

        int ans = INF;

        int station_cnt_x = has_station[x].size();
        int station_cnt_y = has_station[y].size();

        for(int d1 = 0; d1 < station_cnt_x; ++d1)
        {
            for(int d2 = 0; d2 < station_cnt_y; ++d2)
            {
                int station_x = has_station[x][d1].first;
                int station_y = has_station[y][d2].first;

                ans = min(ans, has_station[x][d1].second + has_station[y][d2].second + dis[station_x][station_y]);
            }
        }
        
        ans += w[x] + w[y];
        printf("%lld\n", ans);
    }
}