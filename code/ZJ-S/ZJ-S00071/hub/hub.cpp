#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
using ll = long long;
constexpr int N = 1007;
constexpr int Uc = 0x3f3f3f3f;
int c, t;
int n, k;
int dis[N][N], ans = 0x3f3f3f3f;
bool vis[N];
void dfs(int st1, int st2, int sz)
{
    if (sz > k)
        return;
    if (sz == k)
    {
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            int dist = 0x3f3f3f3f;
            for (int j = 1; j <= n; ++j)
                if (vis[j])
                    dist = min(dist, dis[i][j]);
            res = max(res, (vis[i] ? 0 : dist));
        }
        ans = min(ans, res);
    }
    for (int i = 1; i <= n; ++i)
    {
        if ((dis[i][st1] != Uc || dis[i][st2] != Uc) && !vis[i])
        {
            vis[i] = true;
            dfs(i, st1, sz + 1);
            dfs(i, st2, sz + 1);
            vis[i] = false;
        }
    }
}
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> k;
        memset(dis, 0x3f, sizeof(dis));
        for (int i = 1, u, v; i <= n - 1; ++i)
        {
            cin >> u >> v;
            dis[u][v] = dis[v][u] = 1;
        }
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
            {
                if (i == k)
                    continue;
                for (int j = 1; j < i; ++j)
                    if (k != j)
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
            }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                if (i == j)
                    continue;
                dfs(i, j, 2);
            }
        cout << ans << "\n";
    }
    return 0;
}
