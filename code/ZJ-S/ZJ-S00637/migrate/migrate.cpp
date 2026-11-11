#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n, m, ans, a[N], dis[N], cnt[N];

int solve()
{
    cin >> n >> m, ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int s = 1; s <= n; s++)
    {
        for (int i = s; i <= n; i++) dis[i] = 1e14, cnt[i] = 0;
        queue<int>q;
        dis[s] = 0, cnt[s] = 1, q.push(s);
        while (q.size())
        {
            int u = q.front(); q.pop();
            for (int v = u + 1; v <= n; v++)
            {
                if (a[v] - a[u] > m) break;
                if (dis[u] + 1 < dis[v]) dis[v] = dis[u] + 1, cnt[v] = cnt[u], q.push(v);
                else if (dis[u] + 1 == dis[v]) cnt[v] += cnt[u];
            }
        }
        for (int i = s; i <= n; i++) ans += cnt[i] == 2;
    }
    return ans;
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--) cout << solve() << "\n";
}

