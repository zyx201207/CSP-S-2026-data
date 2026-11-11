#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll ans=1e18;
vector<int> e[1000005];
bool f[1000005];
int a[1000005],de[1005],dis[1005][1005],fa[1005][25];
void dfs2(int u,int fat)
{
    // cout<<u<<" "<<fat<<"\n";
    fa[u][0]=fat;
    de[u]=de[fat]+1;
    for(auto v:e[u])
        if(v!=fat) dfs2(v,u);
}
int lca(int u,int v)
{
    if(de[u]<de[v]) swap(u,v);
    for(int i=25;i>=0;i--)
        if(de[fa[u][i]]>=de[v]) u=fa[u][i];
    if(u==v) return u;
    for(int i=25;i>=0;i--)
        if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
void dfs(int dep,int lst)
{
    if(dep>k)
    {
        ll cur=0;
        for(int i=1;i<=n;i++)
        {
            ll s=1e18;
            for(int j=1;j<=k;j++)
                s=min(s,1ll*dis[a[j]][i]);
            cur=max(cur,s);
        }
        ans=min(ans,cur);
        if(ans==1)
        {
            // for(int i=1;i<=k;i++)
            //     cout<<a[i]<<" ";
            // cout<<"\n";
            for(int i=1;i<=n;i++)
            {
                ll s=1e18;
                for(int j=1;j<=k;j++)
                {
                    s=min(s,1ll*dis[a[j]][i]);
                    // cout<<a[j]<<" "<<i<<" "<<dis[a[j]][i]<<"\n";
                }
                // cout<<s<<"\n";
                cur=max(cur,s);
            }
        }
    }
    else
    {
        for(int i=lst+1;i<=n;i++)
            if(f[i]==0)
            {
                f[i]=1;
                a[dep]=i;
                dfs(dep+1,i);
                f[i]=0;
            }
    }
}
void work()
{
    cin>>n>>k;
    ans=1e18;
    for(int i=1;i<=n;i++)
        e[i].clear(),f[i]=0,de[i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=25;j++)
            fa[i][j]=0;
    for(int u,v,i=1;i<n;i++)
    {
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    de[0]=0;
    dfs2(1,0);
    // for(int i=1;i<=n;i++)
    //     cout<<de[i]<<" ";
    // cout<<"\n";
    // for(int i=1;i<=n;i++)
    //     cout<<fa[i][0]<<" ";
    // cout<<"\n";
    for(int i=1;i<=n;i++)
        for(int j=1;j<=2;j++)
            fa[i][j]=fa[fa[i][j-1]][j-1];
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=0;j<=2;j++)
    //         cout<<fa[i][j]<<" ";
    //     cout<<"\n";
    // }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=de[i]+de[j]-2*de[lca(i,j)];
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //         cout<<dis[i][j]<<" ";
    //     cout<<"\n";
    // }
    dfs(1,0);
    cout<<ans<<"\n";
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--) work();
    return 0;
}