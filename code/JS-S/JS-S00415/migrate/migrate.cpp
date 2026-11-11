#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int x[6000];
int dp[6000][6000];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i=1;i<=n;i++)
        {
            cin >> x[i];
        }
        dp[0][0]=1;
        for(int i=0;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(x[j]-x[i]<=d)
                {
                    dp[i][j]++;
                }
                for(int z=i+1;z<j;z++)
                {
                    if(abs(x[z]-x[i])>d) continue;
                    if(abs(x[j]-x[z])>d) continue;
                    dp[i][j]+=(dp[i][z]*dp[z][j]);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(dp[i][j]==2) ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}