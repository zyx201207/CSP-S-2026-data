#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxm = 500005;
const int maxn = 505;
const int INF = (1ll << 62) - 1;

struct edge
{
    int v,w;
    edge() = default;
    edge(int a,int b):v(a),w(b){}
};
struct ed
{
    int u,v,w;
    ed() = default;
    ed(int a,int b,int c):u(a),v(b),w(c){}
    bool operator < (const ed &b) const
    {
        return w < b.w;
    }
};
struct DSU
{
    vector<int> fa;
    DSU() = default;
    DSU(int n)
    {
        fa.resize(n + 10);
        for(int i = 1;i <= n + 5;i++) fa[i] = i;
    }
    int get(int x)
    {
        return fa[x] == x ? x : fa[x] = get(fa[x]);
    }
    bool check(int u,int v)
    {
        return get(u) == get(v);
    }
    void merge(int u,int v)
    {
        fa[get(u)] = get(v);
    }
};
int c,n,m,d,q;
int w[maxm];
// vector<ed> edges[maxn];
vector<ed> edges;
vector<ed> MST;
DSU solve;
vector<edge> g[maxm];
int dis[maxn][maxn];
// unordered_map<unordered_map<int,int>,int> ans_cache;

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    solve = DSU(n + m + 10);
    for(int i = 1;i <= m;i++) cin>>w[i];
    for(int i = 1;i <= n;i++)
    {
        int k;
        cin>>k;
        for(int j = 1;j <= k;j++)
        {
            int a,t;
            cin>>a>>t;
            edges.emplace_back(i,a,t);
        }
    }
    sort(edges.begin(),edges.end());
    for(auto [u,v,w] : edges)
    {
        if(solve.check(u,n + v)) continue;
        solve.check(u,n + v);
        MST.emplace_back(u,v,w);
    }
    for(auto [u,v,w] : MST)
    {
        g[v].emplace_back(u,w);
    }
    for(int i = 0;i < maxn;i++) for(int j = 1;j < maxn;j++) dis[i][j] = i == j ? 0 : INF;
    for(int i = 1;i <= m;i++)
    {
        for(int j = 0;j < g[i].size();j++)
        {
            for(int k = j + 1;k < g[i].size();k++)
            {
                dis[g[i][j].v][g[i][k].v] = g[i][j].w + g[i][k].w;
                dis[g[i][k].v][g[i][j].v] = g[i][j].w + g[i][k].w;
            }
        }
    }
    for(int k = 1;k <= n;k++)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }
    // cerr<<"\033[91m"<<dis[1][2]<<"\033[0m";
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        // if(ans_cache[x][y])
        // {
        //     cout<<ans_cache[x][y]<<"\n";
        //     continue;
        // }
        int ans = INF;
        for(auto [v1,w1] : g[x])
        {
            for(auto [v2,w2] : g[y])
            {
                ans = min(ans,dis[v1][v2] + w1 + w2);
            }
        }
        // ans_cache[x][y] = ans + w[x] + w[y];
        // ans_cache[y][x] = ans + w[x] + w[y];
        cout<<ans + w[x] + w[y]<<"\n";
    }
}