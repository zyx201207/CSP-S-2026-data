#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f
const ll N = 1e2 + 5;
ll c;
ll tst;
ll n;
ll k;
ll ans;
ll dis[N];
bitset <N> vis;
vector <ll> g[N];
inline void openfile(string s)
{
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
inline void dfs(ll u,const vector <ll> &cnd)
{
    vis[u] = true;
    for(auto v : g[u])
        if(!vis[v] && binary_search(cnd.begin(),cnd.end(),v))
            dfs(v,cnd);
}
inline bool check(const vector <ll> &cnd)
{
    ll cnt = 0;
    vis.reset();
    for(auto i : cnd)
    {
        if(!vis[i])
        {
            if(++cnt > 2)
                return false;
            dfs(i,cnd);
        }
    }
    return true;
}
inline ll solve(const vector <ll> &cnd)
{
    vis.reset();
    queue <ll> q;
    for(auto i : cnd)
    {
        q.push(i);
        dis[i] = 0;
    }
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        for(auto v : g[u])
        {
            if(!vis[v])
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return *max_element(dis,dis + n);
}
int main()
{
    openfile("hub");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c >> tst;
    while(tst--)
    {
        ans = INF;
        cin >> n >> k;
        for(ll i = 0;i < n;++i)
            g[i].clear();
        for(ll i = 1;i < n;++i)
        {
            ll u = 0;
            ll v = 0;
            cin >> u >> v;
            u--;
            v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(ll msk = 0;msk < (1ll << n);++msk)
        {
            if(__builtin_popcountll(msk) != k)
                continue;
            vector <ll> cnd;
            for(ll i = 0;i < n;++i)
                if((msk >> i) & 1)
                    cnd.push_back(i);
            if(check(cnd))
                ans = min(ans,solve(cnd));
        }
        cout << ans << "\n";
    }
    return 0;
}
