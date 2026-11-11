#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5, M = 505, INF = 1e9;
ll c, n, m, d, q, x, y;
ll w[N], dp[M][M];
void floyd()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int z = 1; z <= m; z++)
            {
                dp[i][j] = min(dp[i][z] + dp[z][j], dp[i][j]);
            }
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    memset(dp, INF, sizeof(dp));
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        ll k;
        cin >> k;
        ll a, b, f, e;
        cin >> a >> b;
        for (int j = 1; j < k; j++)
        {
            cin >> e >> f;
            dp[a][e] = b;
            dp[e][a] = b;
            cout << dp[a][e] << ' ' << dp[e][a] << '\n';
            a = e;
            b = f;
        }
    }
    while (q--)
    {
        cin >> x >> y;
        ll s;
        cout << s << '\n';
    }
    return 0;
}
