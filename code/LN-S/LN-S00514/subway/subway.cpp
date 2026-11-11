#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PLL = pair<ll, ll>;

vector<ll> w;
vector<PLL> g[500100];


ll dij(const ll &x, const ll &y);

const ll INF_x = 1e16;
ll c, n, m, d, q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    w.resize(m+1,0);
    for(ll i = 1; i <= m; i++){
        cin >> w[i];
        for(ll j = 0; j <= m; j++){
            g[i].emplace_back(INF_x, 0);
        }
    }
    for(ll i = 1; i <= n; i++){
        ll k = 0;
        cin >> k;
        vector<ll> a(k+1,0);
        vector<ll> t(k+1,0);
        for(ll j = 1; j <= k; j++) cin >> a[j] >> t[j];
        for(ll u = 1; u <= k; u++){
            for(ll v = u; v <= k; v++){
                if(u == v) continue;
                ll a1 = a[u];
                ll a2 = a[v];
                ll cost = t[u] + t[v];
                if(g[a1][a2].first >= cost){
                    g[a1][a2] = make_pair(cost,a2);
                    g[a2][a1] = make_pair(cost,a1);
                }
            }
        }
    }
    while(q--){
        ll x = 0;
        ll y = 0;
        cin >> x >> y;
        cout << dij(x, y) << '\n';
    }
    return 0;
}

ll dij(const ll &x, const ll &y){
    ll ans = w[x] + w[y];
    vector<bool> vis(m, 0);
    vector<ll> dist(m+1,INF_x);
    priority_queue<PLL, vector<PLL>, greater<PLL>> q;
    q.emplace(0, x);
    while(!q.empty()){
        auto cur = q.top();
        ll w_n = cur.first;
        ll u_n = cur.second;
        if(vis[u_n]) continue;
        if(u_n == y) ans += w_n;
        q.pop();
        dist[u_n] = w_n;
        vis[u_n] = 1;
        for(auto edge : g[u_n]){
            ll w_0 = edge.first;
            ll to_0 = edge.second;
            if(dist[u_n] + w_0 < dist[to_0]){
                dist[to_0] = dist[u_n] + w_0;
                q.emplace(dist[to_0], to_0);
            }
        }
    }
    return ans;
}

