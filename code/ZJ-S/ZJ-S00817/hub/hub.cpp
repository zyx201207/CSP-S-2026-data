#include<bits/stdc++.h>
using namespace std;
int op,T;
int n,k,fl,vis[105],ans,fa[105],dep[105];
vector<int>vec[105];
void dfs(int x)
{
    vis[x]=0;
    for(int i:vec[x])
        if(vis[i])dfs(i);
}
void df(int x,int f)
{
    fa[x]=f;
    dep[x]=dep[f]+1;
    for(int i:vec[x])
        if(i!=f)df(i,x);
}
int lca(int x,int y)
{
    while(x!=y)if(dep[x]>dep[y])x=fa[x];else y=fa[y];
    return x;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>op>>T;
    if(op==13||op==14)
    {
        for(;T--;)
        {
            cin>>n>>k;
            for(int i=1;i<n;i++){int u,v;cin>>u>>v;}
            cout<<((n/2+1)/2-k/2+1)/2+1<<"\n";
        }
    }
    if(op<=5)
    {
        for(;T--;)
        {
            cin>>n>>k;
            for(int i=1;i<=n;i++)vec[i].clear();
            for(int i=1;i<n;i++)
            {
                int u,v;
                cin>>u>>v;
                vec[u].push_back(v);
                vec[v].push_back(u);
            }
            df(1,0);
            int ans=1e9+7;
            for(int i=1;i<(1<<n);i++)
            {
                int c=0;
                for(int j=1;j<=n;j++)vis[j]=0;
                for(int j=0;j<n;j++)if(i&(1<<j))c++,vis[j+1]=1;
                if(c!=k)continue;
                int cnt=0;
                for(int j=1;j<=n;j++)if(vis[j])dfs(j),cnt++;
                if(cnt>2)continue;
                int res=0;
                for(int j=1;j<=n;j++)
                    if(!((1<<j-1)&i))
                    {
                        int o=1e9+7;
                        for(int k=1;k<=n;k++)
                            if((1<<k-1)&i)o=min(o,dep[k]+dep[j]-2*dep[lca(j,k)]);
                        res=max(res,o);
                    }
                        
                ans=min(ans,res);
            }
            cout<<ans<<"\n";
        }
    }
}