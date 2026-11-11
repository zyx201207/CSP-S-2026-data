#include <bits/stdc++.h>
#define cyn cin
using namespace std;

const int N = 510, M = 500100;

int w[M];
vector <int> a[M], t[M];
long long dis[N][N];

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cyn.tie(0);
    cout.tie(0);
    int c, n, m, d, q;
    cyn >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
        cyn >> w[i];
    int k, ia, it;
    for (int i = 1; i <= n; i++)
    {
        cyn >> k;
        while (k--)
            cyn >> ia >> it,
            a[ia].push_back(i),
            t[ia].push_back(it);
    }
    memset(dis, -1, sizeof dis);
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < a[i].size(); j++)
            for (int k = 0; k < a[i].size(); k++)
                if (dis[a[i][j]][a[i][k]] == -1 || dis[a[i][j]][a[i][k]] > t[i][j] + t[i][k])
                    dis[a[i][j]][a[i][k]] = t[i][j] + t[i][k];
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] == -1 || dis[k][j] == -1)
                    continue;
                if (dis[i][j] == -1 || dis[i][j] > dis[i][k] + dis[k][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
    long long ans;
    int x, y;
    while (q--)
    {
        cyn >> x >> y;
        ans = LLONG_MAX;
        for (int i = 0; i < a[x].size(); i++)
            for (int j = 0; j < a[y].size(); j++)
                ans = min(ans, t[x][i] + t[y][j] + dis[a[x][i]][a[y][j]]);
        cout << ans + w[x] + w[y] << "\n";
    }
    return 0;
}