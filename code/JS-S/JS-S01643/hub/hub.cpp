#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fir first
#define sec second
#define pii pair<int,int>
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define pb push_back
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
int n,k,mx[1000010],pmx[1000010],tmx[1000010],rt=0,dp[1000010],dep[1000010];
int m,p[1000010],tid;
vector<int>g[1000010];
vector<int>t[1000010];
void dfs1(int u,int f)
{
    mx[u]=0,pmx[u]=inf;
    for(auto v:g[u])if(v^f)
    {
        dep[v]=dep[u]+1;
        dfs1(v,u);
        if(mx[v]+1>mx[u])pmx[u]=mx[u],mx[u]=mx[v]+1;
        else chmax(pmx[u],mx[v]+1);
    }
}
void dfs2(int u,int f,int fmx)
{
    tmx[u]=max(fmx,mx[u]);

    if(!rt||tmx[u]<tmx[rt])rt=u;
    for(auto v:g[u])if(v^f)
    {
        int nmx=max(fmx,(mx[v]+1==mx[u]?pmx[u]:mx[u]));
        dfs2(v,u,nmx+1);
    }
}
void dfs3(int u,int f,int x)
{
    dp[u]=1;
    for(auto v:g[u])if(v^f)
    {
        dfs3(v,u,x);
        if(mx[v]+1>x)dp[u]+=dp[v];
    }
}
void dfs4(int u,int f,int rt,int d,int x)
{
    if(d>x)return;
    t[rt].pb(u);
    for(auto v:g[u])if(v^f)
    {
        int nd=max(d,(mx[v]==mx[u]+1?pmx[u]:mx[u]))+1;
        dfs4(v,u,rt,nd,x);
    }
}
bool check(int x)
{
    // cout<<"check:"<<x<<endl;
    dfs3(rt,0,x);
    // for(int i=1;i<=n;i++)cout<<"  dp["<<i<<"]="<<dp[i]<<endl;
    if(dp[rt]<=k)return 1;
    for(auto i:g[rt])t[i].clear();
    for(auto v:g[rt])dfs4(v,rt,v,1,x);
    //no p[1]
    for(int i=2;i<=m;i++)
    {
        int u=p[i];
        for(auto v:t[u])if(dp[v]<=k&&x-dep[v]>=mx[p[1]]+1)
        {
            // cout<<"!!"<<i<<" "<<u<<" "<<v<<" "<<x-dep[v]<<" "<<mx[p[1]]+1<<endl;
            return 1;
        }
    }
    // cout<<",,,,,"<<endl;
    //no p[2]
    int mn=inf;
    for(auto v:t[p[1]])if(dp[v]<=k)
    {
        if(x-dep[v]>=mx[p[2]]+1)return 1;
        chmin(mn,dp[v]);
    }
    for(int i=3;i<=m;i++)
    {
        int u=p[i];
        for(auto v:t[u])if(dp[v]<=k-mn&&x-dep[v]>=mx[p[2]]+1)return 1;
    }
    // cout<<"?????"<<endl;
    //p[1] and p[2]
    int mn1=inf,mn2=inf;
    for(auto v:t[p[1]])if(dp[v]<=k)chmin(mn1,dp[v]);
    for(auto v:t[p[2]])if(dp[v]<=k)chmin(mn2,dp[v]);
    // cout<<",,"<<mn1<<" "<<mn2<<endl;
    for(auto v:t[p[1]])if(dp[v]<=k-mn2&&x-dep[v]>=mx[p[3]]+1)return 1;
    for(auto v:t[p[2]])if(dp[v]<=k-mn1&&x-dep[v]>=mx[p[3]]+1)return 1;
    return 0;
}
bool cmp(int x,int y){return mx[x]>mx[y];}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs1(1,0);
    rt=0;
    dfs2(1,0,0);
    dep[rt]=0;
    dfs1(rt,0);
    // cout<<"!!!rt="<<rt<<endl;
    m=0;
    for(auto v:g[rt])p[++m]=v;
    p[m+1]=p[m+2]=0;
    mx[0]=-1;
    sort(p+1,p+m+1,cmp);
    int l=0,r=n-1,ans;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(check(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<'\n';
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>tid>>t;
    while(t--)solve();
    return 0;
}
/*
Are you going to Scarborough Fair?
*/