#include<bits/stdc++.h>
using namespace std;
int a[200005];
int dp[200005][200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp[1][1]=a[1];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[j][i]=max(dp[j][i-1],dp[j][i-1]&a[j]);
        }
    }
    cout<<dp[n][m];
    return 0;
}