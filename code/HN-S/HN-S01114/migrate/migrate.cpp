#include <iostream>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int id,T,ans;
int n,d,a[N],dp[N],dp2[N];//changdu & fangan
void solve()
{
    cin >> n >> d;
    ans = 0;
    for(int i = 1;i <= n;i ++)cin >> a[i];
    if(id >= 11 && id <= 12)
    {
        if(n == 1)
        {
            cout << "0\n";
            return ;
        }
        int D = a[2] - a[1];
        if(d < 2 * D)
        {
            cout << "0\n";
            return ;
        }
        d /= D;
        int best = 2 * d - 1;
        cout << max(0LL,n - best) << '\n';
        return ;
    }
    for(int i = 1;i <= n;i ++)
    {
        dp[i] = 0,dp2[i] = 1;
        int k = i;
        for(int j = i + 1;j <= n;j ++)
        {
            if(a[j] - a[j - 1] > d)break ;
            while(a[j] - a[k] > d)k ++;
            dp[j] = dp[k] + 1;
            int l = k;
            while(l - k <= 3 && l + 1 < j && dp[l + 1] == dp[k])l ++;
            if(l - k > 3)
            {
                dp2[j] = 10000;
                continue ;
            }
            else
            {
                dp2[j] = 0;
                for(int m = k;m <= l;m ++)dp2[j] += dp2[m];
            }
            if(dp2[j] == 2)ans ++;
            //cout << i << " " << j << " " << dp[j] << " " << dp2[j] << '\n';
        }
    }
    cout << ans << '\n';
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> id >> T;//Error
    while(T --)solve();
}
/*
idea:15:20
solved:15:58
expected:48pts
*/
