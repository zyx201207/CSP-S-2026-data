#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 500510;
const unsigned long long INF = 1e18;

int C, n, m, D, Q, w[500010];

vector <int> g[500010], d[500010];

unsigned long long dis[510][510];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> C >> n >> m >> D >> Q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int a, t; cin >> a >> t;
            g[a].push_back(i);
            d[a].push_back(t);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
            dis[j][i] = dis[i][j] = INF;
        dis[i][i] = 0;
    }

    for (int x = 1; x <= m; x++)
        for (int i = 0; i < g[x].size(); i++)
            for (int j = i+1; j < g[x].size(); j++)
                {
                    int u = g[x][i], v = g[x][j];
                    dis[v][u] = dis[u][v] = min(dis[u][v], 1ull*d[x][i] + 1ull*d[x][j]);
                }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = i+1; j <= n; j++)
                if (dis[i][k] != INF && dis[k][j] != INF && dis[i][j] > dis[i][k] + dis[k][j])
                    dis[j][i] = dis[i][j] = dis[i][k] + dis[k][j];

    while (Q--)
    {
        int x, y; cin >> x >> y;
        unsigned long long dist = INF;
        for (int i = 0; i < g[x].size(); i++)
            for (int j = 0; j < g[y].size(); j++)
                dist = min(dist , 1ull*d[x][i] + dis[g[x][i]][g[y][j]] + 1ull*d[y][j]);
        cout << 1ull*w[x] + dist + 1ull*w[y] << '\n';
    }
    return 0;
}
