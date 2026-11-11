#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int n,m,a[2005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) dp[0][i]=a[i];
    for (int i=1;i<=m;i++)
    {
        dp[i][i]=a[1];
    }
    for (int i=1;i<=m;i++)
    {
        for (int j=i+1;j<=i+n-m+1;j++)
        {
            dp[i][j]=dp[i-1][j-1]&a[j-1];
            if (j<=i+n-m)
            {
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[m][n];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
