#include <bits/stdc++.h>
using namespace std;

int n, x[15], c, t, d, cnt, mn;

void dfs(int now, int v, int tot)
{
    if (now > v) return;
    if (now == v)
    {
        if (tot < mn)
        {
            mn = tot;
            cnt = 1ll;
        }
        if (tot == mn) cnt = cnt + 1ll;
        return;
    }
    for (int nxt = now + 1ll; x[nxt] - x[now] <= d;nxt++) dfs(nxt, v, tot + 1ll);
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d; int ans = 0ll;
        for (int i = 1ll;i <= n;i++) cin >> x[i];
        for (int u = 1ll;u <= n;u++)
        {
            for (int v = u + 1;v <= n;v++)
            {
                mn = 100ll; cnt = 0ll; dfs(u, v, 0ll);
                if (cnt == 2ll) ++ans;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
