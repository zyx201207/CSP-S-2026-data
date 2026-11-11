#include<bits/stdc++.h>
using namespace std;
int a[200005],dp[65538][8105];
int n,m,ans=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i][1]=a[i];
    }
    if(n>65537 || m>8104)
    {
        sort(a+1,a+n+1,greater<int>());
        ans=a[1];
        for(int i=2;i<=m;i++)
            ans&=a[i];
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=2;j<=m;j++)
            for(int k=1;k<i;k++)
                dp[i][j]=max(dp[i][j],dp[i][j-1]&a[k]);
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i][m]);
    cout<<ans;


    return 0;
}
