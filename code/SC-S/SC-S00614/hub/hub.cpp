#include<bits/stdc++.h>
using namespace std;

int c,T,n,k,vis[1000001],h[1000001],fa[1000001],dis[1000001],tvis[1000001],ans;
vector<int>Map[1000001];
vector<array<int,2>>edge;
vector<int>vec;

void dfs_find(int u,int f,int&x)
{
    fa[u]=f;
    h[u]=h[f]+1;
    if(h[u]>h[x])
        x=u;
    for(auto&v:Map[u])
        if(!vis[v]&&v!=f)
            dfs_find(v,u,x);
}

array<int,3>find(int u)
{
    int x=0,y=0,len;
    dfs_find(u,0,x);
    dfs_find(x,0,y);
    len=h[y]-1;
    for(int i=0;i<len>>1;i++)
        y=fa[y];
    if(len&1)
        return{y,fa[y],len};
    return{y,0,len};
}

void Dfs(int u)
{
    if(tvis[u])
        return;
    tvis[u]=1;
    for(int v:Map[u])
        if(vis[v]&&!tvis[v])
            Dfs(v);
}

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>k;
        edge.clear();
        for(int i=1;i<=n;i++)
            Map[i].clear(),
            vis[i]=0;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            Map[u].push_back(v);
            Map[v].push_back(u);
            edge.push_back({u,v});
        }
        ans=n;
        for(int i=1;i<1<<n;i++)
        {
            if(__builtin_popcount(i)!=k)
                continue;
            vec.clear();
            for(int j=1;j<=n;j++)
                tvis[j]=vis[j]=0;
            for(int j=1;j<=n;j++)
                if((i>>j-1)&1)
                    vis[j]=1,
                    dis[j]=0,
                    vec.push_back(j);
            int cnt=0;
            for(int j=1;j<=n;j++)
                if(!tvis[j]&&vis[j])
                    ++cnt,
                    Dfs(j);
            if(cnt>2)
                continue;
            int h=0,Ans=0;
            while(h<vec.size())
            {
                int u=vec[h++];
                Ans=dis[u];
                for(int v:Map[u])
                    if(!vis[v])
                        vis[v]=1,
                        dis[v]=dis[u]+1,
                        vec.push_back(v);
            }
            ans=min(ans,Ans);
        }
        cout<<ans<<"\n";
    }
}