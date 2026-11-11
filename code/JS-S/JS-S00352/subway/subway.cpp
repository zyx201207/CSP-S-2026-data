#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, n, m, d, q;
int w[505];
ll dis[1000][1000];
int k[505];
vector<int> a[505];
vector<int> t[505];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= m + n; i++)
    {
        for (int j = 1; j <= m + n; j++)
        {
            if (i != j) dis[i][j] = 0x3f3f3f3f3f3f3f3fll;
        }
    }
    if (9 <= c && c <= 11)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> k[i];
            if (k[i] == 1)
            {
                int xxx, yyy;
                cin >> xxx >> yyy;
                continue;
            }
            int s1, s2, d1, d2;
            cin >> s1 >> d1 >> s2 >> d2;
            dis[s1][s2] = d1 + d2;
            dis[s2][s1] = d1 + d2;
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> k[i];
            a[i].resize(k[i] + 1);
            t[i].resize(k[i] + 1);
            for (int j = 1; j <= k[i]; j++)
            {
                cin >> a[i][j] >> t[i][j];
                dis[m + i][a[i][j]] = t[i][j];
                dis[a[i][j]][m + i] = t[i][j];
            }
        }
    }
    int td;
    if (9 <= c && c <= 11) td = n;
    else td = m + n;
    for (int k = 1; k <= td; k++)
    {
        for (int i = 1; i <= td; i++)
        {
            for (int j = 1; j <= td; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int xr, yr;
        cin >> xr >> yr;
        ll ans = 0;
        ans += w[xr];
        ans += w[yr];
        ans += dis[xr][yr];
        cout << ans << '\n';
    }
    return 0;
}
