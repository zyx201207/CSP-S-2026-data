#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[200020];
long long dp[200020];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(m==1)
    {
        cout<<a[n];
        return 0;
    }
    if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++) ans=ans&a[i];
        cout<<ans;
        return 0;
    }
    memset(dp,0,sizeof(dp));
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=min(i,m);j++)
        {
            if(j==1) dp[j]=a[i];
            else dp[j]=max(dp[j],dp[j-1]&a[i-1]);
        }
    }
    cout<<dp[m];
    return 0;
}
