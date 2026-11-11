#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int w[500005], t[500005][505];
int dis[1005][1005];
vector <int> xl[500005];
vector <int> tl[505];
bool f[500005][505];
int main()
{
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    ios::sync_with_stdio (false);
    cin.tie (0), cout.tie (0);
    memset (dis, 0x3f, sizeof dis);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++)
        cin >> w[i], dis[i][i] = 0;
    for (int i = 1; i <= n; i ++)
    {
        int k, x, y;
        cin >> k;
        for (int j = 1; j <= k; j ++)
            cin >> x >> y, tl[i].push_back (x), t[x][i] = y, xl[x].push_back (i);
        for (auto s : tl[i])
        {
            for (auto j : tl[i])
            {
                if (s == j)
                    continue;
                dis[s][j] = min (dis[s][j], t[s][i] + t[j][i]);
            }
        }
    }
    vector <int> ve;
    for (int i = 1; i <= m; i ++)
        if (xl[i].size() > 1)
            ve.push_back (i);
    for (auto k : ve)
    {
        for (int x = 0; x < xl[k].size(); x ++)
        {
            for (int xx = x + 1; xx < xl[k].size(); xx ++)
            {
                for (auto y : tl[xl[k][x]])
                {
                    for (auto yy : tl[xl[k][xx]])
                    {
                        dis[y][yy] = min (dis[y][yy], dis[y][k] + dis[k][yy]);
                        dis[yy][y] = min (dis[yy][y], dis[yy][k] + dis[k][y]);
                    }
                }
            }
        }
        for (auto x : xl[k])
        {
            for (auto y : tl[x])
            {
                if (y == k)
                    continue;
                if (xl[y].size() > 1)
                    for (auto tmp : xl[k])
                        if (t[y][tmp] == 0)
                            xl[y].push_back (tmp);
            }
        }
    }
    while (q --)
    {
        int x, y;
        cin >> x >> y;
        cout << dis[x][y] + w[x] + w[y] << '\n';
    }
    return 0;
}