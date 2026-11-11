#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000],mx,dp[200000];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    dp[1]=a[0];
    for(int j=2;j<n;j++)
    {
        dp[j]=max(dp[j-1],dp[j-m]+(dp[j-1]&a[j]));
    }
    cout<<dp[m];
}
