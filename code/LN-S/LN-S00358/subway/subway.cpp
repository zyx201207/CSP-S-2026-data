#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pii;
const int N = 6e5 + 7;
const ll INF = 1e18;
ll c, n, m, d, q;
vector <pii> G[N];
ll dis[N];
bool vis[N];
ll w[N], a[N], t[N];

void dijkstra1(ll s) {
    priority_queue <pii> q;
    for(int i = 1;i <= (n + 1) * m;++i) {
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        ll u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto [v, w] : G[u]) {
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
            }
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;++i) {
        cin >> w[i];
    }
    for(int i = 1;i <= n;++i) {
        ll k;
        cin >> k;
        for(int j = 1;j <= k;++j) {
            cin >> a[j] >> t[j];
        }
        for(int j = 1;j <= k;++j) {
            for(int x = 1;x <= k;++x) {
                G[a[j]].push_back({a[x], t[j] + t[x]});
                G[a[x]].push_back({a[j], t[j] + t[x]});
            }
        }
    }
    while(q--) {
        ll s, t;
        cin >> s >> t;
        dijkstra1(s);
        cout << dis[t] + w[s] + w[t] << "\n";
    }
    return 0;
}
