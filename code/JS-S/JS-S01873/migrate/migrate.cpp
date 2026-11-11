#include<bits/stdc++.h>
#define int long long
#define PI pair<int,int>
using namespace std;
const int N=5e3+2,inf=1e8;
int n,d,a[N],f[N][N],dp[N][N];
void sol()
{
    cin>>n>>d;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int l=1;l<=n;++l)
    {
        for(int r=l+1;r<=n;++r)
        {
            if(abs(a[l]-a[r])<=d)dp[l][r]=1,f[l][r]=1;
            else dp[l][r]=r-l+2,f[l][r]=0;
        }
    }
    for(int len=1;len<=n;++len)
    {
        for(int l=1;l+len-1<=n;++l)
        {
            int r=l+len-1;
            if(dp[l][r]==1)continue;
            for(int k=r-1;k>=l;--k)
            {
                if(abs(a[k]-a[r])<=d)
                {
                    if(dp[l][k]+dp[k][r]<dp[l][r])
                    {
                        f[l][r]=f[l][k];
                        dp[l][r]=dp[l][k]+dp[k][r];
                    }
                    else if(dp[l][k]+dp[k][r]==dp[l][r])f[l][r]+=f[l][k];
                }
                else break;
            }
            
        }
    }
    int ans=0;
    for(int l=1;l<=n;++l)
        for(int r=l+1;r<=n;++r)if(f[l][r]==2)ans++;
    cout<<ans<<"\n";
}
signed main()
{
#define FILE "migrate"
freopen(FILE".in","r",stdin);
freopen(FILE".out","w",stdout);
cin.tie(0);cout.tie(0);
    int id,_;cin>>id>>_;
    while(_--)sol();
    return 0;
}//24-40pts