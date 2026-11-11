#include <bits/stdc++.h>
using namespace std;
int c,T;
int n,k;
const int maxn=1e6+5;
vector<int> e[maxn];
int fa[maxn];
inline void init()
{
    for (int i=1;i<=n;i++) fa[i]=i;
}
inline int find(int x)
{
    if (x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
inline void uni(int x,int y)
{
    if (find(x)==find(y)) return;
    fa[find(x)]=find(y);
}
int vis[maxn];
unordered_map<int,int> mp;
int dis[maxn];
inline void dfs(int u,int f)
{
    if (u==f) dis[u]=0;
    dis[u]=min(dis[u],dis[f]+1);
    for (auto v:e[u])
    {
        if (v==f) continue;
        dfs(v,u);
    }
}
int ans=0x7f7f7f7f;
inline void solve()
{
    for (int i=1;i<(1<<n);i++)
    {
        if (__builtin_popcount(i)!=k) continue;
        init();
        for (int j=0;j<=n;j++) vis[j]=0;
        mp.clear();
        int siz=0;
        for (int j=0;j<n;j++)
            if ((i>>j)&1) vis[j+1]=1;
        for (int j=1;j<=n;j++)
            for (auto v:e[j]) 
                if (vis[v] and vis[j]) uni(v,j);
        for (int j=1;j<=n;j++)
        {
            if (vis[j] and !mp[find(j)])
            {
                mp[find(j)]=1;
                ++siz;
            }
        }
        if (siz>2) continue;
        for (int j=1;j<=n;j++) dis[j]=0x7f7f7f7f;
        for (int j=1;j<=n;j++)
            if (vis[j]) dfs(j,j);
        int r=0;
        for (int i=1;i<=n;i++) r=max(r,dis[i]);
        ans=min(ans,r);
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> c >> T;
    while (T--)
    {
        ans=0x7f7f7f7f;
        cin >> n >> k;
        for (int i=1;i<=n;i++) e[i].clear();
        for (int i=1,u,v;i<n;i++)
        {
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        solve();
        cout << ans << '\n';
    }
    return 0;
}