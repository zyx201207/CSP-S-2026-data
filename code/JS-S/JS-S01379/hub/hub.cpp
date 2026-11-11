#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 5, inf = 1e15;
int n, k, dis[N][N], ans = inf;
vector<int> v[N];
bitset<N> mp, mp2;
void dfs2(int x, int fa)
{
    mp2[x] = 1;
    for (auto dx : v[x])
    {
        if (dx == fa || mp[dx] == 0)
            continue;
        dfs2(dx, x);
    }
}
void dfs(int x, int lst)
{
    if (lst > n)
        return;
    if (x == k + 1)
    {
        mp2.reset();
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!mp[i] || mp2[i])
                continue;
            cnt++;
            dfs2(i, -1);
        }
        if (cnt > 2)
            return;
        int maxn = 0;
        for (int i = 1; i <= n; i++)
        {
            int minn = inf;
            if (mp[i])
                continue;
            for (int j = 1; j <= n; j++)
                if (i != j && mp[j] == 1)
                    minn = min(minn, dis[i][j]);
            maxn = max(maxn, minn);
        }
        ans = min(ans, maxn);
        return;
    }
    for (int i = lst + 1; i <= n; i++)
    {
        mp[i] = 1;
        dfs(x + 1, i);
        mp[i] = 0;
    }
}
void solve()
{
    ans = inf;
    mp.reset();
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = inf;
    for (int i = 1; i <= n; i++)
        v[i].clear();
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        dis[x][y] = dis[y][x] = 1;
        dis[i][i] = 0;
    }
    dis[n][n] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    dfs(1, 0);
    cout << ans << "\n";
}
signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int c, t;
    cin >> c >> t;
    while (t--)
        solve();
    return 0;
}