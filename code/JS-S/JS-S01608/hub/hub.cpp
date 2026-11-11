#include<iostream>
#include<cstdio>
#include<utility>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;

int c,t,n,k,f[25][1000005],dep[1000005],fa[1000005];
vector<int> g[1000005];
int ans;
int find(int x)
{
    if(fa[x]==x)    return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    fa[find(x)]=find(y);
}
pair<int,int> e[1000005];
void dfs(int u,int pre)
{
    dep[u]=dep[pre]+1;
    f[0][u]=pre;
    for(auto &v:g[u])
    {
        if(v!=pre)  dfs(v,u);
    }
}
int lca(int x,int y)
{
    if(dep[x]>dep[y])   swap(x,y);
    for(int i=20;i>=0;i--)
    {
        if(dep[f[i][y]]>=dep[x])    y=f[i][y];
    }
    if(x==y)    return x;
    for(int i=20;i>=0;i--)
    {
        if(f[i][x]!=f[i][y])    x=f[i][x],y=f[i][y];
    }
    return f[x][0];
}
int dis(int x,int y)
{
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}
vector<int> v;
bool vis[1000005];
void dfs2(int d,int pre)
{
    if(d==k+1)
    {
        for(int i=1;i<=n;i++)   fa[i]=i;
        for(int i=1;i<n;i++)
        {
            if(vis[e[i].first] && vis[e[i].second]) merge(e[i].first,e[i].second);
        }
        unordered_map<int,int> mp;
        for(auto &x:v)  mp[find(x)]++;
        if(mp.size()>2) return ;
        int maxx=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])  continue;
            int minn=INT_MAX;
            for(auto &x:v)
            {
                minn=min(minn,dis(i,x));
            }
            maxx=max(maxx,minn);
        }
        ans=min(ans,maxx);
        return ;
    }
    for(int i=pre+1;i<=n;i++)
    {
        v.push_back(i);
        vis[i]=1;
        dfs2(d+1,i);
        v.pop_back();
        vis[i]=0;
    }
}

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>c>>t>>n>>k;
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            e[i]={u,v};
        }
        dfs(1,0);
        for(int i=1;i<=20;i++)
        {
            for(int j=1;j<=n;j++)   f[i][j]=f[i-1][f[i-1][j]];
        }
        ans=INT_MAX;
        dfs2(1,0);
        cout<<ans<<'\n';
        for(int i=1;i<=n;i++)   g[i].clear();
    }
    return 0;
}
