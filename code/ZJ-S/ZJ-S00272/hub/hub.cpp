#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = (1ll << 62) - 1;
const int maxn = 1000006;

int c,T;
vector<int> edges[maxn];
int n,k;
int ans;
int dis[maxn];

vector<int> S;

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
bool check()
{
    DSU dsu(n + 10);
    for(int u : S)
    {
        for(int v : edges[u])
        {
            if(*lower_bound(S.begin(),S.end(),v) == v) dsu.merge(u,v);
        }
    }
    set<int> st;
    for(int i : S) st.emplace(dsu.get(i));
    return st.size() == 2;
}
int calc()
{
    fill(dis,dis+maxn,INF);
    queue<int> que;
    for(int i : S)
    {
        dis[i] = 0;
        que.emplace(i);
    }
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        for(int v : edges[u])
        {
            if(dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                que.emplace(v);
            }
        }
    }
    int res = 0;
    for(int i = 1;i <= n;i++) res = max(res,dis[i]);
    return res;
}
void dfs()
{
    if(S.size() == k)
    {
        // cerr<<"\033[92msfsf sdf";
        if(check())
        {
            // cerr<<"\033[93msadfsadfsdfs";
            ans = min(ans,calc());
        }
        return;
    }
    for(int i = (S.empty() ? 1 : S.back() + 1);i <= n;i++)
    {
        S.emplace_back(i);
        dfs();
        S.pop_back();
    }
}
void init()
{
    for(int i = 0;i < maxn;i++)
    {
        edges[i].clear();
        dis[i] = INF;
    }
    n = k = 0;
    ans = INF;
}

signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
        init();
        cin>>n>>k;
        for(int i = 1;i < n;i++)
        {
            int u,v;
            cin>>u>>v;
            edges[u].emplace_back(v);
            edges[v].emplace_back(u);
        }
        // cerr<<"\033[91msadfsadfsdf";
        dfs();
        cout<<ans<<"\n";
    }
}