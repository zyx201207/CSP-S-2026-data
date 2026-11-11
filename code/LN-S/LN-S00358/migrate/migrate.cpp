#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pii;
const int N = 2e6 + 7;
const ll INF = 1e18;
ll c, t;
ll n, d;
ll a[N], cnt[N], dis[N];
vector <ll> G[N];
void dijkstra(ll s) {
    priority_queue <pii> q;
    for(int i = 1;i <= n;++i) {
        dis[i] = INF;
    }
    dis[s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        ll u = q.top().second;
        q.pop();
        for(auto v : G[u]) {
            if(dis[v] == dis[u] + 1) {
                cnt[v]++;
            } else if(dis[v] > dis[u] + 1) {
                cnt[v] = 1;
                dis[v] = dis[u] + 1;
                q.push({-dis[v], v});
            }
        }
    }
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> t;
    while(t--) {
        cin >> n >> d;
        for(int i = 1;i <= n;++i) {
            cin >> a[i];
            G[i].clear();
            cnt[i] = 0;
        }
        for(int i = 1;i <= n;++i) {
            for(int j = i + 1;j <= n;++j) {
                if(a[j] - a[i] <= d) {
                    G[i].push_back(j);
                }
            }
        }
        ll ans = 0;
        dijkstra(1);
        for(int i = 1;i <= n;++i) {
            if(cnt[i] == 2) {
                ++ans;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
