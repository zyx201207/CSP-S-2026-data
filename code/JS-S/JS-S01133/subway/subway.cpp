#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair <LL, LL> PII;
const int N = 510, M = 500010;
const long long INF = 1e18;

int c, n, m, d, q;
bool st[N][N];
LL dist[N][N], g[N][N], w[M];
vector <PII> a[M];

void dijkstra()
{
    for (int s = 1; s <= n; s ++ )
    {
        for (int i = s; i <= n; i ++ ) dist[s][i] = INF;
        dist[s][s] = 0;

        for (int i = s; i <= n; i ++ )
        {
            int t = -1;
            for (int j = s; j <= n; j ++ )
                if (!st[s][j] && (t == -1 || dist[s][j] < dist[s][t])) t = j;
            st[s][t] = true;
            for (int j = s; j <= n; j ++ ) dist[s][j] = min(dist[s][j], dist[s][t] + g[t][j]);
        }
    }
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i ++ ) scanf("%lld", &w[i]);
    for (int i = 1; i <= n; i ++ )
    {
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; j ++ )
        {
            LL x, t;
            scanf("%lld%lld", &x, &t);
            a[x].push_back({i, t});
        }
    }
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ ) g[i][j] = INF;

    for (int i = 1; i <= m; i ++ )
    {
        int s = (int)a[i].size();
        for (int j = 0; j < s; j ++ )
            for (int k = j + 1; k < s; k ++ )
            {
                g[a[i][j].first][a[i][k].first] = min(g[a[i][j].first][a[i][k].first], a[i][j].second + a[i][k].second);
                g[a[i][k].first][a[i][j].first] = g[a[i][j].first][a[i][k].first];
            }
    }
    dijkstra();

    while (q -- )
    {
        int x, y;
        scanf("%d%d", &x, &y);

        LL res = INF;
        for (int i = 0; i < a[x].size(); i ++ )
            for (int j = 0; j < a[y].size(); j ++ )
                if (a[x][i].first < a[y][j].first)
                    res = min(res, w[x] + w[y] + a[x][i].second + a[y][j].second + dist[a[x][i].first][a[y][j].first]);
                else res = min(res, w[x] + w[y] + a[x][i].second + a[y][j].second + dist[a[y][j].first][a[x][i].first]);
        printf("%lld\n", res);
    }

    return 0;
}
