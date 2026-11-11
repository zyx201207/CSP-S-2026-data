#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],dp[5050][5050],ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++) dp[i][1] = a[i],dp[i][0] = (1 << 40) - 1;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - 1] & a[i]);
    for(int i = 1;i <= n;i++) ans = max(ans,dp[i][m]);
    cout<<ans<<endl;
    return 0;
}
