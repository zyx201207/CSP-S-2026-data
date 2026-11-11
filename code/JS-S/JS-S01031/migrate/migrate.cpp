#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll,ll> pll;
#define INF 0x3f3f3f3f3f3f3f3f
const ll N = 5e6 + 5;
ll c;
ll tst;
ll n;
ll k;
ll ans;
ll a[N];
ll cnt[N];
ll dis[N];
vector <ll> g[N];
inline void openfile(string s)
{
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
inline void bfs(ll s)
{
    fill(cnt + 1,cnt + n + 1,0ll);
    fill(dis + 1,dis + n + 1,INF);
    queue <ll> q;
    q.push(s);
    dis[s] = 0;
    cnt[s] = 1;
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
        for(auto v : g[u])
        {
            if(dis[v] == dis[u] + 1)
                cnt[v] += cnt[u];
            else if(dis[v] > dis[u] + 1)
            {
                cnt[v] = cnt[u];
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}
int main()
{
    openfile("migrate");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c >> tst;
    while(tst--)
    {
        ans = 0;
        cin >> n >> k;
        for(ll i = 1;i <= n;++i)
            g[i].clear();
        for(ll i = 1;i <= n;++i)
            cin >> a[i];
        for(ll i = 1;i < n;++i)
        {
            for(ll j = i + 1;j <= n && a[j] - a[i] <= k;++j)
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
        for(ll i = 1;i <= n;++i)
        {
            bfs(i);
            ans += count(cnt + 1,cnt + n + 1,2ll);
        }
        ans >>= 1;
        cout << ans << "\n";
    }
    return 0;
}
