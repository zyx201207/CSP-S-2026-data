#include<bits/stdc++.h>
using namespace std;
int a[200005];
int dp[20005][20005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxn = 0;cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> a[i];
    for(int i = 1;i <= n;i++)
    {
        maxn = max(maxn,a[i]);
        dp[i][1] = maxn;
    }
    for(int j = 1;j <= m;j++)
    {
        for(int i = j;i <= n;i++)
        {
            dp[i][j] = max(dp[i][j],dp[i-1][j-1] & a[i]);
        }
    }
    cout << dp[n][m];
    return 0;
}
