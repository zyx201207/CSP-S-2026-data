

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PLL = pair<ll, ll>;

int c, t;
int n, d;
vector<ll> x;
vector<ll> g[2001000];

const ll INF_x = 1e16;
ll dij(const ll &x, const ll &y){
    ll cnt = 0;
    vector<bool> vis(n, 0);
    vector<ll> dist(n+1,INF_x);
    priority_queue<PLL, vector<PLL>, greater<PLL>> q;
    q.emplace(0, x);
    while(!q.empty()){
        auto cur = q.top();
        ll w_n = cur.first;
        ll u_n = cur.second;
        if(vis[u_n]) continue;
        q.pop();
        dist[u_n] = w_n;
        vis[u_n] = 1;
        for(int i = 1; i <= n; i++){
            ll w_0 = g[u_n][i];
            ll to_0 = i;
            if(dist[u_n] + w_0 > d) continue;
            else if(dist[u_n] + w_0 < dist[to_0]){
                cnt = 0;
                dist[to_0] = dist[u_n] + w_0;
                q.emplace(dist[to_0], to_0);
            }
            else{
                cnt++;
                dist[to_0] = dist[u_n] + w_0;
                q.emplace(dist[to_0], to_0);
            }
        }
    }
    return cnt;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("migrate.in", "r", stdin);
    //freopen("migrate.out", "w", stdout);
    cin >> c >> t;

    while(t--){
        n = 0;
        d = 0;
        cin >> n >> d;
        x.resize(n+1,0);
        for(ll i = 1; i <= n; i++){
            cin >> x[i];
            g[i].resize(n,INF_x);
        }
        for(ll u = 1; u <= n; u++){
            for(ll v = u; v <= n; v++){
                if(u == v) continue;
                ll cost = abs(x[u] - x[v]);
                if(g[u][v] >= cost){
                    g[u][v] = cost;
                    g[u][v] = cost;
                }
            }
        }
        ll ans = 0;
        for(ll u = 1; u <= n; u++){
            for(ll v = u; v <= n; v++){
                if(u == v) continue;
                if(dij(u, v) == 2) ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}


