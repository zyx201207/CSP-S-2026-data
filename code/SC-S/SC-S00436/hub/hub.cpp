#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=1e6+10;
vector<int> g[N];
int dep[N],f[N][30];
int ans=1e18;
int a[N];
bool vis[N];int n,k;
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    f[u][0]=fa;
    for(int i=1;i<=20;i++) f[u][i]=f[f[u][i-1]][i-1];
    for(int i=0;i<(int)g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa) continue;
        dfs(v,u);
    }
}
int lca(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=20;i>=0;i--)
    {
        if(dep[u]-dep[v]>=(1<<i)) u=f[u][i];
    }
    // cout<<"u:"<<u<<" v:"<<v<<'\n';
    if(u==v) return u;
    for(int i=20;i>=0;i--)
    {
        if(f[u][i]==f[v][i]) continue;
        u=f[u][i];
        v=f[v][i];
    }
    return f[u][0];
}
void dfss(int u)
{
    vis[u]=1;
    for(int i=0;i<(int)g[u].size();i++)
    {
        int v=g[u][i];
        if(vis[v]) continue;
        if(!a[v]) continue;
        dfss(v); 
    }
}
bool check()
{
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=(a[i]);
    if(cnt!=k) return false;
    for(int i=1;i<=n;i++) vis[i]=0;
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i])
        {
            if(!vis[i]) dfss(i),cnt++;
        }
        // for(int i=1;i<=n;i++) cout<<vis[i]<<' ';
        // cout<<'\n';
    }
    if(cnt>2) return false;
    return true;
}
int dis(int x,int y)
{
    // if(a[2]==1&&a[7]==1&&a[9]==1) cout<<x<<' '<<y<<' '<<lca(x,y)<<'\n';
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}
int calc()
{
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        int mn=1e18;
        if(a[i]) continue;
        for(int j=1;j<=n;j++)
        {
            if(!a[j]) continue;
            int t=dis(i,j);
            mn=min(mn,t);
            // if(a[2]==1&&a[7]==1&&a[9]==1)
            // {
            //     cout<<i<<"-"<<j<<" "<<t<<'\n';
            // }
        }
        // if(a[2]==1&&a[7]==1&&a[9]==1)cout<<"i:"<<mn<<'\n';
        mx=max(mx,mn);
    }
    // if(mx==1)
    // {
    //     for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    //     cout<<'\n';
    //     for(int i=1;i<=n;i++)
    //     {
    //         int mn=1e18;
    //         if(a[i]) continue;
    //         for(int j=1;j<=n;j++)
    //         {
    //             if(!a[j]) continue;
    //             int t=dis(i,j);
    //             mn=min(mn,t);
    //                 cout<<i<<"-"<<j<<" "<<t<<'\n';
    //         }
    //         cout<<"i:"<<mn<<'\n';
    //         mx=max(mx,mn);
    //     }
    // }
    return mx;
}
void dfsx(int step)
{
    if(step>n)
    {
        if(check()) ans=min(calc(),ans);
        return ;
    }
    a[step]=0;
    dfsx(step+1);
    a[step]=1;
    dfsx(step+1);
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++) g[i].clear();
        // for(int i=1)
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        // cout<<"---\n";
        dfs(1,0);
        // cout<<lca(3,4)<<'\n';
        // return 0;
        // a[2]=a[3]=a[9]=1;
        // cout<<check()<<'\n';
        // return 0;
        if(c<=3)
        {
            ans=1e18;
            dfsx(1);
            cout<<ans<<'\n';
            // for(int i=1;i<=n;i++) a[i]=0;
        }
        if(c==7)
        {

        }
    }
    return 0;
}
// 0 1
// 10 3
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 3 7
// 3 8
// 7 9
// 9 10