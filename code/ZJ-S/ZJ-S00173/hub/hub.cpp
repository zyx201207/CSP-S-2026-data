#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define gc getchar_unlocked
#define debug(num) printf("%s:%lld\n",#num,num)
inline int read()
{
    int x = 0,f = 1;
    char ch = gc();
    while(!isdigit(ch))
    {
        if(ch == '-') f = -1;
        ch = gc();
    }
    while(isdigit(ch))
    {
        x = (x<<3)+(x<<1)+(ch^'0');
        ch = gc();
    }
    return x*f;
}
constexpr int maxn = 1e6+10;
int n,k;
vector<int> gra[maxn];
int fa[maxn];
int d[maxn];
bool vis[maxn];
void init()
{
    for(int i = 1;i<=n;++i)
    {
        fa[i] = i;
        vis[i] = 0;
    }
}
int fr(int x){return fa[x] == x?x:fa[x] = fr(fa[x]);}
void join(int u,int v)
{
    int xr = fr(v),yr = fr(u);
    if(fa[xr]!=yr) fa[xr] = yr;
}
void dfs1(int u,int p,int mask)
{
    int msku = 1<<(u-1);
    for(int v:gra[u])
    {
        if(v == p)continue;
        int mskv = 1<<(v-1);
        if((msku&mask)&&(mskv&mask))
        {
            join(u,v);
        }
        dfs1(v,u,mask);
    }
}
void getd(int u,int p,int mask)
{
    int msku = 1<<(u-1);
    d[u] = LLONG_MAX>>1;
    if((msku&mask)) d[u] = 0;
    for(int v:gra[u])
    {
        if(v == p) continue;
        getd(v,u,mask);
        d[u] = min(d[u],d[v]+1);
    }
}
void brute()
{
    int ans = LLONG_MAX>>1;
    for(int i = 0;i<(1<<n);++i)
    {
        int tt = 0;
        int t = i;
        while(t)
        {
            if(t&1) ++tt;
            t>>=1;
        }
        if(tt == k)
        {
            init();
            dfs1(1,0,i);
            for(int j = 1;j<=n;++j)
            {
                int mskj = 1<<j-1;
                int r = fr(j);
                if(mskj&i) vis[r] = 1;
            }
            int cnt = 0;
            for(int j = 1;j<=n;++j)
            {
                cnt += vis[j];
            }
            if(cnt>2) continue;
            int mx = 0;
            for(int j = 1;j<=n;++j)
            {
                getd(j,0,i);
                mx = max(mx,d[j]);
            }
            ans = min(ans,mx);
        }
    }
    printf("%lld\n",ans);
}
constexpr int inf = LLONG_MAX>>1;
constexpr int maxsub1 = 1e5+10;
constexpr int step = 5e2;
int dis[maxsub1];
void dfs(int u,int p,int s)
{
    dis[u] = min(dis[u],dis[p]+1);
    if(u == s) dis[u] = 0;
    for(int v:gra[u])
    {
        if(v == p) continue;
        dfs(v,u,s);
    }
}
void sub1()
{
    int ans = inf;
    for(int circle = 1;circle<=step;++circle)
    {
        fill(dis+1,dis+n+1,inf);
        int k1 = rand()%n+1,k2 = rand()%n+1;
        while(k1 == k2) k2 = rand()%n+1;
        dfs(k1,0,k1);
        dfs(k2,0,k2);
        int mx = 0;
        for(int i = 1;i<=n;++i)
        {
            mx = max(mx,dis[i]);
        }
        ans = min(ans,mx);
    }
    printf("%lld\n",ans);
}
void solve()
{
    n = read(),k = read();
    for(int i = 1;i<n;++i)
    {
        int u = read(),v = read();
        gra[u].emplace_back(v);
        gra[v].emplace_back(u);
    }
    if(k == 2&&n>10)
    {
        sub1();
    }
    else
    {
        brute();
    }
    for(int i = 1;i<=n;++i)
    {
        gra[i].clear();
    }
}
signed main()
{
    srand(time(0));
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c = read(),t = read();
    while(t--)
    {
        solve();
    }
    return 0;
}