#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e6 + 5;
ll x[maxn];
vector<pair<int, ll>> adj[maxn];
ll dist[maxn];
int cnt[maxn];

void dijkstra(int n, int s) {
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
            else if (dist[v] = dist[u] + w) {
                cnt[v]++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("migrate1.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--) {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        for (int u = 1; u <= n; u++) {
            for (int v = u + 1; v <= n; v++) {
                if (abs(x[u] - x[v]) <= d) {
                    adj[u].push_back({v, x[u] - x[v]});
                    adj[v].push_back({u, x[u] - x[v]});
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            dijkstra(n, i);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += cnt[i];
        cout << ans /  2 << "\n";
    }
    return 0;
}
