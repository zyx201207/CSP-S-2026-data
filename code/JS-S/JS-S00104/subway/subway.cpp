#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e4+10,maxm = maxn*505;
int c,n,m,d,q,x,y;
int w[maxn],k[505],a[505][maxn],t[505][maxn];
int ver[maxm],head[maxn],nxt[maxm],val[maxm],cnt;
int dis[maxn];
bool vis[maxn],fa,fb;
void add(int u,int v,int w)
{
    ver[++cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
struct node
{
    int xi,di;
    bool operator<(const node& b) const
    {
        return di > b.di;
    }
};
void dijkstra(int x)
{
    fill(dis+1,dis+m+1,1e18);
    fill(vis+1,vis+m+1,0);
    priority_queue<node> q;
    dis[x] = 0;
    q.push({x,0});
    while(!q.empty())
    {
        int u = q.top().xi;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u];i;i = nxt[i])
        {
            int v = ver[i],w = val[i];
            if(dis[u]+w < dis[v])
            {
                dis[v] = dis[u]+w;
                if(!vis[v]) q.push({v,dis[v]});
            }
        }
    }
}
void solve1()
{
    int f[505][505];
    for(int i = 1;i < 505;i++)
    {
        for(int j = 1;j < 505;j++)
        {
            if(i == j) f[i][j] = 0;
            else f[i][j] = 1e18;
        }
    }
    for(int i = 1;i <= n;i++) if(k[i]==2)
    {
        f[a[i][1]][a[i][2]] = min(f[a[i][1]][a[i][2]],t[i][1]+t[i][2]);
        f[a[i][2]][a[i][1]] = min(f[a[i][2]][a[i][1]],t[i][1]+t[i][2]);
    }
    for(int k = 1;k <= m;k++)
        for(int i = 1;i <= m;i++)
            for(int j = 1;j <= m;j++)
                f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
    while(q--)
    {
        cin >> x >> y;
        cout << f[x][y]+w[x]+w[y] << '\n';
    }
}
void solve2()
{
    dijkstra(1);
    while(q--)
    {
        cin >> x >> y;
        cout << abs(dis[y]-dis[x])+w[x]+w[y] << '\n';
    }
}
void solve3()
{
    while(q--)
    {
        cin >> x >> y;
        dijkstra(x);
        cout << dis[y]+w[x]+w[y] << '\n';
    }
}
signed main()
{
    //rp++ orz
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++)
    {
        cin >> k[i];
        if(k[i] > 2) fa = 1;
        for(int j = 1;j <= k[i];j++)
        {
            cin >> a[i][j] >> t[i][j];
            if(t[i][j] != t[1][1]) fb = 1;
        }
        for(int j = 1;j <= k[i];j++)
            for(int s = j+1;s <= k[i];s++)
            {
                add(a[i][j],a[i][s],t[i][j]+t[i][s]);
                add(a[i][s],a[i][j],t[i][j]+t[i][s]);
            }
    }
    if(!fa) solve1();
    else if(!fb) solve2();
    else solve3();
    return 0;
}
