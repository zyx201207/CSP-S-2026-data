#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll c, t, n, d, x[2000010], ans, to[2000010];

void dfs(int xx, int y, ll cnt)
{
    if (xx == y)
    {
        to[cnt]++;
        return;
    }
    for (int i = xx+1; i <= y; i++)
    {
        if (x[i] - x[xx] > d)
            break;
        dfs(i, y, cnt+1);
    }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        ans = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i+1; j <= n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    to[k] = 0;
                }
                dfs(i, j, 0);
                for (int i = 1; i <= n; i++)
                {
                    if (to[i] != 0)
                    {
                        if (to[i] == 2)
                            ans++;
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
