#include <bits/stdc++.h>
using namespace std;

#define int long long

#define N 2007
#define INF 0x3f3f3f3f3f3f3f3f

int c, t;
int n, d;
int x[N];
int dp[N], cnt[N];

signed solve()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> x[i];
    int ans = 0;
    for (int l = 1; l <= n; l++)
    {
    	dp[l] = 0, cnt[l] = 1;
        for (int i = l+1; i <= n; i++)
        {
            dp[i] = INF;
            for (int j = l; j < i; j++)
            {
                if (x[i] - x[j] <= d)
                {
                    if (dp[i] > dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if (dp[i] == dp[j] + 1)
                    {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if (cnt[i] == 2) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) solve();
    return 0;
}
