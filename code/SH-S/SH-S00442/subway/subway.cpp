#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 509, M = 5e5 + 9;
int w[M];
struct LINES
{
    int k;
    vector<int> a;
    vector<int> t;
}a[N];
int c, n, m, d, q;
vector<pair<int, int>> bel[M];
LL dist[N][N];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(dist, 0x3f, sizeof(dist));
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;
    for (int i = 1; i <= m; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        a[i].k = k;
        a[i].a.resize(k + 1);
        a[i].t.resize(k + 1);
        for (int j = 1; j <= k; j++)
        {
            scanf("%d%d", &a[i].a[j], &a[i].t[j]);
            bel[a[i].a[j]].push_back({i, a[i].t[j]});
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int sz = bel[i].size();
        if (sz == 1)
            continue;
        for (int j = 0; j < sz - 1; j++)
        {
            for (int k = j + 1; k < sz; k++)
            {
                dist[bel[i][j].first][bel[i][k].first] = min(dist[bel[i][j].first][bel[i][k].first], (LL)bel[i][j].second + bel[i][k].second);
                dist[bel[i][k].first][bel[i][j].first] = dist[bel[i][j].first][bel[i][k].first];
            }
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        LL ans = 1e18;
        for (int i = 0; i < bel[x].size(); i++)
        {
            for (int j = 0; j < bel[y].size(); j++)
                ans = min(ans, bel[x][i].second + bel[y][j].second + dist[bel[x][i].first][bel[y][j].first]);
        }
        ans += w[x] + w[y];
        printf("%lld\n", ans);
    }
}
