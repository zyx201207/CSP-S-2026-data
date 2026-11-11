#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, t;
int n, d;
ll x[2000005];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        int ff[50][50];
        int ans = 0;
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                if (u == v) break;
                memset(ff, 0, sizeof(ff));
                ff[0][u] = 1;
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        for (int k = 1; k <= n; k++)
                        {
                            if (j == k) continue;
                            if (abs(x[j] - x[k]) <= d)
                            {
                                ff[i][j] += ff[i - 1][k];
                            }
                        }
                    }
                }
                for (int i = 1; i <= n; i++)
                {
                    if (ff[i][v] == 0 && ff[i + 1][v] == 2)
                    {
                        ans++;
                    }
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
