#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=5e5+20;
const int INF=LLONG_MAX/3;
int c,n,m,d,q,x,y,s,targett;
int w[N],k[N],dis[N];
bool vis[N];
vector<int> a[N],t[N];
vector<pair<int,int> > G[N];
inline void add(int l,int r,int w)
{
    G[l].pb({r,w});
    G[r].pb({l,w});
}
struct pts
{
    int w,v;
    bool operator<(const pts &other) const
    {
        return w > other.w;
    }
};
priority_queue<pts> PQ;
void dij()
{
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n+m;i++)
        dis[i] = INF;
    PQ.push({0,s});
    dis[s] = 0;
    while (!PQ.empty())
    {
        auto now = PQ.top();
        PQ.pop();
        int u=now.v;
        if (vis[u])
            continue;
        vis[u] = true;
        for (auto i:G[u])
        {
            int v=i.first,w=i.second;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                PQ.push({dis[v],v});
            }
        }
    }
}
int query(int l,int r)
{
    int res = 0;
    // 出站 入站
    res += w[l];
    res += w[r];
    s = n + l;
    targett = n + r;
    dij();
    return res + dis[targett];
}
signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++)
        cin >> w[i];
    for (int i=1;i<=n;i++)
    {
        cin >> k[i];
        for (int j=1;j<=k[i];j++)
        {
            cin >> x >> y;
            a[i].pb(x);
            t[i].pb(y);
        }
    }
    for (int i=1;i<=n;i++)
    {
        // for every subway line
        for (int j=1;j<=k[i];j++)
            add(i,n+a[i][j-1],t[i][j-1]);
    }
    while (q--)
    {
        cin >> x >> y;
        cout << query(x,y) << endl;
    }
    return 0;
}