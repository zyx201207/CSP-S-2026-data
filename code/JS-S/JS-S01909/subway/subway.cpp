#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
ll c, n, m, d, q;
ll w[N * 5], k[505], a[505][N], t[505][N], ans = 0;
ll x, y;
bool to[505][505];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < k[i]; j++)
        {
            to[a[i][j]][a[i][j + 1]] = 1;
            to[a[i][j + 1]][a[i][j]] = 1;
        }
    }
    while(q--)
    {
        cin >> x >> y;
        ll sum = 0;
        sum += w[x] + w[y] + t[1][x] + t[2][y];
        if (to[x][y])
        {
            cout << sum << '\n';
            continue;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (to[x][i] && to[i][y])
                {
                    sum += t[1][i] + t[2][i];
                }
            }
        }
        cout << sum << '\n';
    }
    return 0;
}