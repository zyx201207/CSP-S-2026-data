#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    int len,x;
    bool operator <(const node& b) const
    {
        return len > b.len;
    }
};

vector<int> v[500010];
map<int,int> t[510];
vector<int> a[510];
vector<int> g[510];
vector<int> d[510];
int dis[510][510];
int w[500010];
bool vis[510];
int k[510];
int n;

void dijkstra(int s)
{
    priority_queue<node> q;
    q.push({0,s});
    memset(vis,0,sizeof(vis));
    memset(dis[s],0x3f,sizeof(dis[s]));
    dis[s][s] = 0;
    while (!q.empty())
    {
        int x = q.top().x;
        q.pop();
        if (vis[x])
        {
            continue;
        }
        vis[x] = true;
        for (int i = 0;i < g[x].size();i++)
        {
            int y = g[x][i];
            int z = d[x][i];
            if (dis[s][y] > dis[s][x] + z)
            {
                dis[s][y] = dis[s][x] + z;
                q.push({dis[s][y],y});
            }
        }
    }
}

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,m,D,Q;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&D,&Q);
    for (int i = 1;i <= m;i++)
    {
        scanf("%lld",&w[i]);
    }
    for (int i = 1;i <= n;i++)
    {
        scanf("%lld",&k[i]);
        for (int j = 1;j <= k[i];j++)
        {
            int aa,tt;
            scanf("%lld%lld",&aa,&tt);
            a[i].push_back(aa);
            t[i][aa] = tt;
            for (int x = 0;x < v[aa].size();x++)
            {
                int y = v[aa][x];
                g[i].push_back(y);
                d[i].push_back(tt + t[y][aa]);
                g[y].push_back(i);
                d[y].push_back(tt + t[y][aa]);
            }
            v[aa].push_back(i);
        }
    }
    for (int i = 1;i <= n;i++)
    {
        dijkstra(i);
    }
    while (Q--)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        int ans = 1e18;
        for (int i = 0;i < v[x].size();i++)
        {
            int s = v[x][i];
            for (int j = 0;j < v[y].size();j++)
            {
                int e = v[y][j];
                ans = min(ans,dis[s][e] + t[s][x] + t[e][y] + w[x] + w[y]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
