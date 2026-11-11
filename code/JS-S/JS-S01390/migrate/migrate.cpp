#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long x[2000002];
struct node
{
    long long nu,ti;//the number of ways,the times of taking off
}dp[2000002];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        long long ans=0;
        for(int k=1;k<=n;k++)
        {
        for(int i=n;i>=1;i--) x[i]-=x[k]-1;
        for(int i=k;i<=n;i++) dp[i].ti=ceil(1.0*(x[i]-1)/d);
        dp[k].nu=1;
        for(int i=k+1;i<=n;i++)
        {
            long long j=0;
            while(1)
            {
                j++;
                if(d<x[i]-x[i-j]||i-j<1) break;
                if(dp[i-j].ti+1>dp[i].ti) continue;
                dp[i].nu+=dp[i-j].nu;
            }
            if(dp[i].nu==2) ans++;
        }
        }
        cout<<ans<<'\n';
        memset(dp,0,sizeof(dp));
    }
    return 0;
}
