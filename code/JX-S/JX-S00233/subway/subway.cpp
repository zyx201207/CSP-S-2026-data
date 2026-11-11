
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, d, c, q;
ll a[505][5005], val[505][5005];
ll w[200005], k[505];
bool vis[505];
ll dfs(ll u, ll e, ll line)
{
    ll ans = 0;
    cout << a[line][e] << ' ' << e << ' ' << line << "\n";
    if (a[line][e] != 0) return val[line][e] + val[line][u] + w[e];
    for (int i = 1; i <= n; i++)
        if (vis[i] && a[i][u] != 0)
        {
            vis[i] = false;
            for (int j = 1; j <= d; j++)
                if (a[i][j] != 0)
                    ans = min(ans, dfs(a[i][j], e, i)) + val[i][u] + val[i][a[i][j]];
        }
    return ans;
}

int main()
{
    //freopen("filename.in", "r", stdin);
    //freopen("filename.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            int x, y; cin >> x >> y; a[i][x] = x; val[i][x] = y;
        }
    }
    while(q--)
    {
        memset(vis, true, sizeof(vis));
        int l, r;
        cin >> l >> r;
        ll sum = 0;
        for (int i = 1; i <= d; i++) if (a[i][l] != 0) for (int j = 1; j <= d; j++) if (a[i][j] != 0) sum = min(sum, dfs(a[i][j], r, i) + (j == l ? 0 : val[i][j]));
        cout << sum + w[l] << "\n";
    }
    return 0;
}
