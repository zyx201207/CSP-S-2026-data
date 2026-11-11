#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int w[N];
int k[N];
int u[N],w2[N];
struct node
{
    int to,w;
    bool operator < (const node&tmp )const
    {
        return w < tmp.w;
    }
};
priority_queue<node>pq;
vector<node>g[N];
int vis[N];
int d[N];
const int inf = 1e18;
int c,n,m,v,q;
void dijkstra(int s,int t)
{
    for(int i = 1;i <= N;i++)
    {
        d[i] = inf;
        vis[i] = 0;
    }
    while(!pq.empty())
    {
        pq.pop();
    }
    d[s] = 0;
    pq.push({s,0});
    while(!pq.empty())
    {
        node f = pq.top();
        pq.pop();
        if(vis[f.to])
        {
            continue;
        }
        vis[f.to] = 1;
        int u = f.to;
        for(node v : g[u])
        {
            if(d[v.to] > d[u] + v.w)
            {
                d[v.to] = d[u] + v.w;
                pq.push({v.to,d[v.to]});
                //cout << v.to << " " << d[v.to] << endl;
            }
        }
    }
    cout << d[t] << endl;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> v >> q;
    for(int i = 1;i <= m;i++)
    {
        cin >> w[i];
        g[i].push_back({i + 500,w[i]});
        g[i + 500].push_back({i,w[i]});
        //cout << i << " " << i + 500 << endl;
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> k[i];
        for(int j = 1;j <= k[i];j++)
        {
            cin >> u[j] >> w2[j];
            g[u[j] + (i + 1) * 500].push_back({u[j] + 500,w2[j]});
            g[u[j] + 500].push_back({u[j] + (i + 1) * 500,w2[j]});
            //cout << u[j] + 500 << " " << u[j] + (i + 1) * 500 << endl;
        }
        for(int j = 1;j < k[i];j++)
        {
            g[u[j] + (i + 1) * 500].push_back({u[j + 1] + (i + 1) * 500,0});
            g[u[j + 1] + (i + 1) * 500].push_back({u[j] + (i + 1) * 500,0});
            //cout << u[j] + (i + 1) * 500 << " " << u[j + 1] + (i + 1) * 500 << endl;
        }
    }
    while(q-->0)
    {
        int u,v;
        cin >> u >> v;
        dijkstra(u,v);
    }
    return 0;
}
