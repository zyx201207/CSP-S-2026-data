#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=2e5+10;
int n,m;
int a[maxn];
int dp[maxn];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    if(n==m)
    {
        int ans=a[1];
        for(int i=2;i<=n;++i)ans&=a[i];
        cout<<ans;
    }
    else if(m==1)
    {
        int ans=0;
        for(int i=1;i<=n;++i)ans=max(ans,a[i]);
        cout<<ans;
    }
    else
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=m;j>=1;--j)
            {
                dp[j]=max(dp[j-2]&a[i],dp[j-1]&a[i]);
            }
        }
        cout<<dp[n];
    }
    return 0;
}