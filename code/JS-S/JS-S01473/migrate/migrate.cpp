#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,m,a[50005],nex[50005],vis[50005],mindis[50005],ans=0;
void dfs(int u,int depth)
{
    if(depth<mindis[u])
    {
        mindis[u]=depth;
        vis[u]=1;
    }
    else if(depth==mindis[u]) vis[u]++;
    if(nex[u]==u) return;
    for(int i=nex[u];i>u;i--)
        dfs(i,depth+1);
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=n;j>=i;j--)
                if(a[j]-a[i]<=m)
                {
                    nex[i]=j;
                    break;
                }
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                vis[j]=0,mindis[j]=2e18+5;
            dfs(i,0);
            for(int j=i+1;j<=n;j++)
                if(vis[j]==2)
                    ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
