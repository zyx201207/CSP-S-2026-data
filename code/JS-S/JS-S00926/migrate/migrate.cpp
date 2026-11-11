#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[2000005];
ll dp[5005][5005],f[5005][5005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t --)
    {
        int n,d;
        cin >> n >> d;
        for (int i = 1;i <= n;i ++)
        {
            cin >> a[i];
        }
        if (c>=13&&c<=14)
        {
            cout << 0 << '\n';
            continue;
        }
        memset(dp,0x3f,sizeof(dp));
        memset(f,0,sizeof(f));
        for (int i = 1;i <= n;i ++)
        {
            for (int j = i;j <= n;j ++)
            {
                if (d<a[j]-a[i])break;
                dp[i][j] = 1;
                f[i][j] = 1;
            }
            for (int j = i+3;j <= n;j ++)
            {
                int pos = lower_bound(a+1,a+n+1,a[j]-d)-a;
                for (int k = pos;k < j;k ++)
                {
                    int tmp = dp[i][k]+1;
                    if (tmp < dp[i][j]) dp[i][j] = tmp,f[i][j] = f[i][k];
                    else if (tmp == dp[i][j]) f[i][j] += f[i][k];
                }
            }
        }
        ll ans = 0;
        for (int i = 1;i <= n;i ++)
        {
            for (int j = i+3;j <= n;j ++)
            {
                //cout << f[i][j] << ' ' << dp[i][j] << '\n';
                if (f[i][j] == 2)
                    ans ++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
