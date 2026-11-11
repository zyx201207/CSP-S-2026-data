#include<bits/stdc++.h>
using namespace std;
int ans,c,n,m,d,q,w[500005],k[500005],a[505][5005],vis[50005],t[505][5005],aa[5005][505];
void dfs(int u,int v,int lu,int res)
{
    if(u==v)
    {
        if(res+t[lu][v]<ans)ans=res+t[lu][v];
        return;
    }
    for(int i=1;i<=n;++i)
    {
        if(aa[u][i])
        {
            for(int j=1;j<=k[i];++j)
            {
                int vv=a[i][j];
                if(vis[vv])continue;
                if(vv!=u)
                {
                    vis[vv]=1;
                    if(i==lu)dfs(vv,v,i,res);
                    else dfs(vv,v,i,res+t[lu][u]+t[i][u]);
                    vis[vv]=0;
                }
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1;i<=n;++i)
    {
         cin>>k[i];
         for(int j=1;j<=k[i];++j)
         {
             cin>>a[i][j]>>t[i][j];
             aa[a[i][j]][i]=1;
         }
    }
    int u,v;
    while(q--)
    {
        cin>>u>>v;
        ans=1e9;
        vis[u]=1;
        for(int i=1;i<=n;++i)
        {
            if(aa[u][i])
            {
                for(int j=1;j<=k[i];++j)
                {
                    if(vis[a[i][j]])continue;
                    vis[a[i][j]]=1;
                    dfs(a[i][j],v,i,t[i][u]);
                    vis[a[i][j]]=0;
                }
            }
        }
        vis[u]=0;
        ans=ans+w[u]+w[v];
        cout<<ans<<'\n';
    }
    return 0;
}
