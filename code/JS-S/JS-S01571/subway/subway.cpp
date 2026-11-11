#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q, w[500010], a[500010], t[500010], g[510][510];
vector<pair<int, int>> s[500010];
signed main()
{
    memset(g, 0x3f, sizeof g);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++)
        scanf("%lld", w + i);
    for (int k, i = 1; i <= n; i++)
    {
        g[i][i] = 0;
        scanf("%lld", &k);
        for (int j = 1; j <= k; j++)
        {
            scanf("%lld%lld", a + j, t + j);
            s[a[j]].emplace_back(i, t[j]);
        }
        // for (int j = 1; j < k; j++)
        // {
        //     g[a[j]].emplace_back(a[j + 1], t[j] + t[j + 1]);
        //     g[a[j + 1]].emplace_back(a[j], t[j] + t[j + 1]);
        // }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < s[i].size(); j++)
            for (int k = 0; k < s[i].size(); k++)
            {
                int xx = s[i][j].first, yy = s[i][k].first;
                g[xx][yy] = min(g[xx][yy], s[i][j].second + s[i][k].second);
            }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    for (int x, y; q--;)
    {
        scanf("%lld%lld", &x, &y);
        int sum = 1e18;
        for (int i = 0; i < s[x].size(); i++)
            for (int j = 0; j < s[y].size(); j++)
                sum = min(sum, g[s[x][i].first][s[y][j].first] + s[x][i].second + s[y][j].second);
        printf("%lld\n", sum + w[x] + w[y]);
    }
}