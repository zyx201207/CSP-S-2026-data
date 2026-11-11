#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll c,n,m,d,q,cnt;
ll t[500005];
vector <ll> s,val;
struct node{
    ll v,w;
    bool operator<(node z1) const
    {
        return w > z1.w;
    }
};
vector <node> g[500005];
priority_queue <node> qu;
int vis[500005],f[500005];
ll dis[500005];
void dijskra(int s)
{
    for (int i = 1;i <= cnt;i ++) dis[i] = 1e16;
    for (int i = 1;i <= cnt;i ++) vis[i] = 0;
    dis[s] = 0;
    qu.push({s,0});
    while(!qu.empty())
    {
        int u = qu.top().v;
        qu.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = 0;i < g[u].size();i ++)
        {
            int v = g[u][i].v;
            int w = g[u][i].w;
            if (dis[v] > dis[u]+w)
            {
                dis[v] = dis[u]+w;
                qu.push({v,dis[v]});
            }

        }

    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i ++)
    {
        cin >> t[i];
    }
    cnt = m;
    for (int i = 1;i <= n;i ++)
    {
        s.clear();
        val.clear();
        int k;
        cin >> k;
        for (int j = 1;j <= k;j ++)
        {
            ll u,tt;
            cin >> u >> tt;
            s.push_back(u);
            val.push_back(tt);

        }
        for (int j = 0;j < k;j ++)
        {
            int u = s[j],tt = val[j];
            g[u].push_back({++cnt,tt});
            g[cnt].push_back({u,tt});
            if (j == 0) continue;
            int v = s[j-1];

            g[cnt].push_back({cnt-1,0});
            g[cnt-1].push_back({cnt,0});
        }
    }
    while(q --)
    {
        int x,y;
        cin >> x >> y;
        dijskra(x);
        cout << dis[y]+t[x]+t[y] << '\n';
    }
    return 0;
}
