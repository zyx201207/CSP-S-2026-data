#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long

using namespace std;

typedef pair<int, int> PII;

const int N = 510, M = 500010, INF = 1e18;

int n, m, d, q;
int w[M];
int g[N][N];
vector<PII> f[M];
int dist[N][N], st[N];

void dijkstra(int S, int dist[])
{
    for (int i = 1; i <= n; i ++ ) dist[i] = INF, st[i] = false;
    dist[S] = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
        if (t == -1) break;
        st[t] = true;
        for (int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int test_id;
    cin >> test_id >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++ ) cin >> w[i];
    for (int i = 1; i <= n; i ++ )
    {
        int k;
        cin >> k;
        while (k -- )
        {
            int a, t;
            cin >> a >> t;
            f[a].push_back({i, t});
        }
    }
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ ) g[i][j] = INF;
    for (int i = 1; i <= m; i ++ )
        for (int j = 0; j < f[i].size(); j ++ )
            for (int k = j + 1; k < f[i].size(); k ++ )
            {
                int x = f[i][j].first, y = f[i][k].first;
                int len = f[i][j].second + f[i][k].second;
                g[x][y] = min(g[x][y], len);
                g[y][x] = min(g[y][x], len);
            }
    
    for (int i = 1; i <= n; i ++ )
        dijkstra(i, dist[i]);
    
    while (q -- )
    {
        int x, y;
        cin >> x >> y;
        if (x == y) cout << 0 << '\n';
        else
        {
            int ans = 1e18;
            //cout << x << ' ' << y << '\n';return 0;
            for (auto t1 : f[x])
                for (auto t2 : f[y])
                    //cout << t1.first << ' ' << t2.first << '\n';
                    ans = min(ans, t1.second + t2.second + dist[t1.first][t2.first]);
            cout << ans + w[x] + w[y] << '\n';
        }
    }

    return 0;
}
