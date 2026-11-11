#include<bits/stdc++.h>
using namespace std;
long long int dp[4000005][3];
int c,t,n,d;
long long int island[4000006];
int ans;
void init()
{
    for(int i=1;i<=n;i++)
    {
        dp[i][2]=0;
    }
}
void input()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) scanf("%lld",island+i);
}
void solve()
{
    ans=0;
    for(int i=1;i<=n;i++)
    {
        init();
        dp[i][1]=1;
        for(int j=i+1;j<=n;j++)
        {
            int k=j-1;
            while(island[j]-island[k]<=d&&k>=i)
            {
                if(dp[j][2]==dp[k][2]+1) dp[j][1]+=dp[k][1];
                else if(dp[j][2]>dp[k][2]+1||dp[j][2]==0) dp[j][1]=dp[k][1],dp[j][2]=dp[k][2]+1;
                k--;
            }
        }
        for(int j=i;j<=n;j++)
        {
            if(dp[j][1]==2) ans++;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        input();
        solve();
    }
    return 0;
}
