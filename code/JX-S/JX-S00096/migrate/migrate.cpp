#include <bits/stdc++.h>

using namespace std;
map<long long, int> vis;
int d[2000010], id[2000010], n, m, a[2000010];
void dfs(int s, int sum)
{
    if (sum < d[s]) d[s] = sum, id[s] = 1;
    else if (sum == d[s]) id[s]++;
    if (s > n) return;
    for (int i = 1; i <= m; ++i)
    {
        if(vis[a[s] + i]) dfs(vis[a[s] + i], sum + 1);
    }
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        int ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) vis[a[i]] = i;
        for (int i = 1; i <= n; ++i)
        {
            memset(d, 0x3f, sizeof(d));
            dfs(i, 0);
            for (int j = i + 1; j <= n; ++j)
            {
                if (id[j] == 2) ++ans;
            }
        }
        for (int i = 1; i <= n; ++i) vis[a[i]] = 0;
        cout << ans << endl;
    }
    return 0;
}
