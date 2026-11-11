#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int c, t;
ll n, d;
ll a[N], dp[N];
ll cnt;
void dfs(int u, int v)
{
    if (u == v)
    {
        cnt++;
        return;
    }
    for (int i = u + 1; i <= v; i++)
    {
        if (a[i] - a[u] <= d) dfs(i, v);
        else break;
    }
}
void solvea()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i - 3; j++)
        {
            cnt = 0;
            dfs(i, j);
            if (cnt == 2) ans++;
        }
    }
    cout << ans << '\n';
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> t;
    if (11 <= c && c <= 12)
    {
        while (t--)
        {
            ll ans = 0;
            cin >> n >> d;
            for (int i = 1; i <= n; i++) cin >> a[i];
            if (d <= a[2] - a[1])
            {
                cout << 0 << '\n';
                continue;
            }
            ll x = d / (a[2] - a[1]) * (a[2] - a[1]), m = 0;
            while (x)
            {
                m += x;
                x -= (a[2] - a[1]);
            }
            ans = n - m;
            cout << ans << '\n';
        }
    }
    return 0;
}
