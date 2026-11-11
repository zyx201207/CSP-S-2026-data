#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 10,maxv = 510;
int c,n,m,d,q,w[maxn],k[maxv];
vector<int> a[maxv];
vector<int> tim[maxv];
bool vis[maxn];
vector<pair<int,int> > t[maxn];
int dis[maxn];
inline void add(int u,int v,int w)
{
    t[u].push_back({v,w});
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q1;
inline void dij(int s)
{
    for(int i = 1;i <= m;i++)
    {
        dis[i] = 1e14;
        vis[i] = 0;
    }
    dis[s] = 0;
    q1.push({0,s});
    while(!q1.empty())
    {
        auto x = q1.top();
        q1.pop();
        int u = x.second;
        vis[u] = 1;
        for(auto i : t[u])
        {
            int v = i.first,w = i.second;
            if(vis[v])
                continue;
            if(dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q1.push({dis[v],v});
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> n >> m >> d >> q; 
    for(int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    bool vis1 = 1;
    for(int i = 1;i <= n;i++)
    {
        cin >> k[i];
        if(k[i] > 2)
            vis1 = 0;
        for(int j = 1;j <= k[i];j++)
        {
            int x,y;
            cin >> x >> y;
            a[i].push_back(x);
            tim[i].push_back(y);
            for(int h = 0;h < j - 1;h++)
            {
                add(a[i][j - 1],a[i][h],tim[i][j - 1] + tim[i][h]);
                add(a[i][h],a[i][j - 1],tim[i][j - 1] + tim[i][h]);
            }
        }
    }
    //cout << 1 << "\n";
    //return 0;
    while(q--)
    {
        int u,v;
        cin >> u >> v;
        dij(u);
        cout << dis[v] + w[u] + w[v] << "\n";
    }
    return 0;
}