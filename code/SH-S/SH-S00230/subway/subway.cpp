#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 8;
const int INF = 0x3f3f3f3f;
int c, n, m, d, q, x, y, dis[MAXN][MAXN], a[MAXN];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    memset(dis, INF, sizeof(dis));
    for(int i = 1; i <= m; i++)
        cin >> a[i];

    for(int u = 1, k; u <= n; u++)
    {
        cin >> k;
        for(int j = 1, v, w; j <= k; j++)
            cin >> v >> w, dis[u][v] = w, dis[v][u] = w;
    }

    while(q--)
    {
        cin >> x >> y;
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= m; i++)
                for(int j = 1; j <= m; j++)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        cout << dis[x][y] + a[x] + a[y] << "\n";
    }
    return 0;
}
