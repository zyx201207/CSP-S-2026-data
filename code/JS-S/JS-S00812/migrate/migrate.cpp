#include<bits/stdc++.h>
#define M 2000005
#define int long long
using namespace std;
int n, d, a[M], nxt[M], dp[M][2][2];
void solve()
{
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> a[i];
    // cout << n << ' ' << d << ' ' << a[1] << ' ' << a[2] << '\n';
    for(int i = n; i >= 1; i--)
    {
        if(i == n) nxt[i] = n;
        else
        {
            nxt[i] = nxt[i + 1];
            while(a[nxt[i]] - a[i] > d) nxt[i]--;
        }
        // cout << i << ' ' << nxt[i] << '\n';
    }
    for(int i = 1; i <= n; i++) dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) if(nxt[i] > i)
    {
        dp[nxt[i]][0][0]++;
        if(i > 1 && (i <= 2 || nxt[i - 2] < nxt[i]))
        {
            if(nxt[i - 1] == nxt[i]) dp[nxt[i]][1][1] += dp[i][0][0];
            else if(nxt[i - 1] == nxt[i] - 1)
            {
                dp[nxt[i]][0][1] += dp[i][0][0] + dp[i][0][1];
                dp[nxt[i]][1][1] += dp[i][1][0] + dp[i][1][1];
            }
            else
            {
                dp[nxt[i]][0][0] += dp[i][0][0] + dp[i][0][1];
                dp[nxt[i]][1][0] += dp[i][1][0] + dp[i][1][1];
            }
        }
        if(i > 1)
        {
            int lb = max(i + 1, nxt[i - 1] + 1), rb = nxt[i];
            ans += max(0ll, rb - lb + 1) * (dp[i][1][0] + dp[i][1][1]);
        }
        if(i > 1)
        {
            int lb = i + 1;
            if(i > 2) lb = max(lb, nxt[i - 2] + 1);
            int rb = nxt[i - 1];
            ans += max(0ll, rb - lb + 1) * dp[i][0][0];
        }
    }
    cout << ans << '\n';
}
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, T;
    cin >> c >> T;
    while(T--) solve();
    return 0;
}
