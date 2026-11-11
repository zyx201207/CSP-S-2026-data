#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2 + 1, M = 5e5 + 1;

inline int read()
{
    int res = 0, f = 1, c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') f = -1;
        c = getchar();
    }
    while ('0' <= c && c <= '9') res = res * 10 + (c - '0'), c = getchar();
    return res * f;
}

int pt_numb, n, m, d, q, w[M];
ll dis[N][N];
vector <pair<int, int>> g[M];

int main()
{
    freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);

    pt_numb = read();
    n = read(); 
    m = read();
    d = read();
    q = read();
    for (int i = 1; i <= m; ++i) w[i] = read();
    for (int i = 1, k; i <= n; ++i) // lines
    {
        k = read();
        for (int j = 1, u, v; j <= k; ++j) // stations
        {
            u = read(), v = read();
            g[u].push_back({ i, v });
        }
    }
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; ++i) dis[i][i] = 0;
    for (int u = 1; u <= m; ++u)
    {
        for (int i = 0; i < g[u].size(); ++i)
        {
            for (int j = i + 1; j < g[u].size(); ++j)
            {
                int x = g[u][i].first, y = g[u][j].first;
                ll w = (ll)g[u][i].second + g[u][j].second;
                dis[x][y] = dis[y][x] = min(dis[x][y], w);
            }
        }
    }
    for (int k = 1; k <= n; ++k) 
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    while (q --)
    {
        int x = read(), y = read();
        ll res = 0x7f7f7f7f7f7f7f7f;
        for (int i = 0; i < g[x].size(); ++i)
        {
            for (int j = 0; j < g[y].size(); ++j)
            {
                ll fst = (ll)w[x] + w[y];
                ll sec = (ll)g[x][i].second + g[y][j].second;
                res = min(res, fst + sec + dis[g[x][i].first][g[y][j].first]);    
            }
        }
        printf("%lld\n", res);
    }

    return 0;
}