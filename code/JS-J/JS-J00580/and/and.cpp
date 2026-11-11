#include<bits/stdc++.h>
//#define int long long
using namespace std;
int dp[1000000],m,n;
char ai;
int a[1000000];
int vis[1000000];
int ans,now;
void dfs(int step,int now)
{
    a[step]=dp[now];
    if(step==m)
    {
        int s=2147483647;
        for(int i=1;i<=m;i++)
        {
            s=(s&a[i]);
            //cout<<a[i]<<' ';

        }
        //cout<<endl;
        ans=max(s,ans);
        return;
    }
    for(int i=now+1;i<=n;i++)
    {
         dfs(step+1,i);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>dp[i];
    }
    if(n<=30) for(int j=0;j<=n;j++) dfs(0,j);
    else
    {
        sort(dp+1,dp+n+1);
        cout<<dp[m]<<endl;
        return 0;
    }
    cout<<ans<<endl;
}
