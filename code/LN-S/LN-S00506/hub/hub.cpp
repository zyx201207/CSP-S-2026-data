#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int c,t,n,k,ans = 0x3f3f3f3f;
int sel[N],f[N][30],dep[N];
vector<int>g[N];
struct disjoint_set_union
{
    int fa[N];
    void init(int mx){for(int i = 1;i<=mx;i++)fa[i]=i;}
    int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
    void merge(int u,int v){fa[find(u)]=find(v);}
}tr;
void pdfs(int u,int fa)
{
    f[u][0] = fa;
    for(int i = 1;i<=20;i++)f[u][i]=f[f[u][i-1]][i-1];
    for(int v:g[u])if(v!=fa)dep[v]=dep[u]+1,pdfs(v,u);
}
int lca(int u,int v)
{
    if(dep[u]<dep[v])swap(u,v);
    for(int i = 20;i>=0;i--)if(dep[f[u][i]]>=dep[v])u=f[u][i];
    if(u==v)return u;
    for(int i = 20;i>=0;i--)if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
    return f[u][0];
}
int dis(int u,int v)
{
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
void dfs(int c,int ccnt)
{
    if(ccnt>k)return;
    if(c==n+1)
    {
        if(ccnt<k)return;
        tr.init(n);set<int>st;st.clear();
        for(int i = 1;i<=n;i++)if(sel[i])
            for(int j:g[i])if(sel[j])
                tr.merge(j,i);
        for(int i = 1;i<=n;i++)if(sel[i])st.insert(tr.find(i));
        if(st.size()>2)return;
        int mxd = -1;
        for(int i = 1;i<=n;i++)
        {
            int mnd = 0x3f3f3f3f;
            for(int j = 1;j<=n;j++)if(sel[j])mnd=min(dis(i,j),mnd);
            mxd = max(mxd,mnd);
        }
        ans = min(ans,mxd);
        return;
    }
    sel[c]=1;
    dfs(c+1,ccnt+1);
    sel[c]=0;
    dfs(c+1,ccnt);
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i = 1,u,v;i<n;i++)cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
        pdfs(1,1),dfs(1,0);
        cout<<ans<<"\n";
        for(int i = 1;i<=n;i++)g[i].clear();
        memset(f,0,sizeof(f)),memset(dep,0,sizeof(dep));
        memset(sel,0,sizeof(sel)),ans=0x3f3f3f3f;
    }
    return 0;
}