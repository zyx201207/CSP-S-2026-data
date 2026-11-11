#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<int> fa;
void init(int n)
{
    fill(fa.begin(),fa.end(),0);
    for(int i=1;i<=n;++i) fa[i]=i;
}
int find_root(int x)
{
    return fa[x]==x?x:fa[x]=find_root(fa[x]);
}
void join(int x,int y)
{
    int xr=find_root(x),yr=find_root(y);
    if(xr!=yr) fa[xr]=yr;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        vector<vector<int>> gra(n+1);
        vector<vector<bool>> vis(n+1,vector<bool>(n+1));
        vector<int> deg(n+1);
        fa.assign(n+1,0);
        for(int i=1;i<n;++i)
        {
            int u,v;
            cin>>u>>v;
            vis[u][v]=1;
            vis[v][u]=1;
            gra[u].emplace_back(v);
            gra[v].emplace_back(u);
        }
        int root=0;
        for(int i=1;i<=n;++i)
        {
            if(deg[i]==1) 
            {
                root=i;
                break;
            }
        }
        for(int i=1;i<=n;++i) 
        {
            if(!deg[i])
            {
                root=i;
                break;
            }
        }
        vector<int> dep(n+1);
        vector<int> top(n+1);
        vector<int> siz(n+1);
        vector<int> FA(n+1);
        vector<int> son(n+1);
        auto dfs1=[&](auto&& self1,int u,int f)->void
        {
            dep[u]=dep[f]+1;
            FA[u]=f;
            for(auto v:gra[u])
            {
                if(v==f) continue;
                self1(self1,v,u);
                siz[u]+=siz[v];
                if(siz[son[u]]<siz[v]) son[u]=v;
            }
        };
        auto dfs2=[&](auto&& self2,int u,int p)->void
        {
            top[u]=p;
            if(son[u]) self2(self2,son[u],p);
            for(auto v:gra[u])
            {
                if(v==FA[u]||v==son[u]) continue;
                self2(self2,v,v);
            }
        };
        auto LCA=[&](int x,int y)->int
        {
            while(top[x]!=top[y])
            {
                if(dep[top[x]]<dep[top[y]]) swap(x,y);
                x=FA[top[x]];
            }
            if(dep[x]>dep[y]) swap(x,y);
            return x;
        };
        dfs1(dfs1,root,0);
        dfs2(dfs2,root,root);
        int ans=1e18;
        for(int phi=0;phi<(1<<n);++phi)
        {
            init(n);
            int cnt=__builtin_popcount(phi);
            if(cnt!=k) continue;
            vector<int> kp;
            vector<bool> qwq(n+1);
            for(int i=1;i<=n;++i) 
            {
                if((1<<(i-1))&phi) 
                {
                    kp.emplace_back(i);
                    qwq[i]=true;
                }
            }
            for(int i=0;i<k;++i)
            {
                for(int j=0;j<k;++j)
                {
                    if(vis[kp[i]][kp[j]]) join(kp[i],kp[j]);
                }
            }
            set<int> st;
            for(auto v:kp) st.insert(find_root(v));
            if(st.size()>2) continue;
            int res=0;
            for(int i=1;i<=n;++i)
            {
                if(qwq[i]) continue;
                int tot=1e18;
                for(auto v:kp) tot=min(tot,dep[i]+dep[v]-2*dep[LCA(i,v)]);
                res=max(res,tot); 
            } 
            ans=min(ans,res);
        }
        cout<<ans<<'\n';
    }
}