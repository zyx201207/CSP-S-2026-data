#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> G[200010];
int fa[200010][20],dep[200010];
void dfs(int x,int f)
{
    fa[x][0] = f;
    dep[x] = dep[f]  + 1;
    for(int i = 1;i <= 19;i ++)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for(auto to : G[x])
    {
        if(to == f) continue;
        dfs(to,x);
    }
}
int lca(int u,int v)
{
    if(dep[u] < dep[v]) swap(u,v);
    for(int i = 19;i >= 0;i --)
    {
        if(dep[fa[u][i]] >= dep[v])
        {
            u = fa[u][i];
        }
    }
    if(u == v) return u;
    for(int i = 19;i >= 0;i --)
    {
        if(fa[u][i] != fa[v][i])
        {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}
bool vis[200010];
void dfs2(int mk,int u,int f)
{
    vis[u] = true;
    for(auto to : G[u])
    {
        if(u == f || vis[to]) continue;
        if((1 << (to - 1)) & mk) dfs2(mk,to,u);
    }
}
int dis(int u,int v)
{
    return dep[u] +dep[v] - 2 * dep[lca(u,v)];
}
void solve()
{
    cin >> n >> k;
    for(int i = 1;i <= 30;i ++) G[i].clear();
    for(int i = 1;i <= 30;i ++) vis[i] = false;
    for(int i = 1;i <= 30;i ++)
    {
        for(int j = 0;j <= 19;j ++) fa[i][j] = 0;
        dep[i] = 0;
    }
    for(int i = 1;i <= n - 1;i ++)
    {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    int ans = 0x7f7f7f7f;
    for(int mk = 0;mk <= (1 << n) - 1;mk ++)
    {
        for(int j = 0;j < 10;j ++) vis[j + 1] = true;
        int cnt = 0;
        for(int j = 0;j < 10;j ++)
        {
            if((mk >> j) & 1)
            {
                vis[j + 1] = false;
                cnt++;
            }        
        }
        if(cnt != k) continue;
        int res= 0;
        for(int i = 0;i < 10;i ++)
        {
            if(!vis[i+ 1])
            {
                dfs2(mk,i +1,0);
                res++;
            }
        }
        if(res > 2) continue;
        int ress = 0;
        for(int i = 0;i < 10;i ++)
        {
            int res = 0x7f7f7f7f;
            for(int j = 0;j < 10;j ++)
            {
                if((mk >> j) & 1)
                {
                    res = min(res,dis(i + 1,j + 1));
                }
            }
            ress = max(ress,res);
        }
        ans = min(ans,ress);
    }   
    cout<<ans<<endl;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--) solve();
    return 0;
}