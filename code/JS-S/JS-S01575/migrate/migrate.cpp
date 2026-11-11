#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
const ll oo = 1e18;
int n; ll d, ans, x[N], dis[N], cnt[N];
vector<int> e[N];
void dijkstra(int s) {
    priority_queue<pair<ll, int>> pq;
    for (int i = 1; i <= n; ++i) dis[i] = oo, cnt[i] = 1;
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto v : e[u]) {
            if (dis[v] > dis[u] + 1) {
                cnt[v] = 1;
                dis[v] = dis[u] + 1;
                pq.push({-dis[v], v});
            } else if (dis[v] == dis[u] + 1) {
                cnt[v]++;
                pq.push({-dis[v], v});
            }
        }
    }
}
void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (x[j] - x[i] <= d) {
                e[i].push_back(j);
                e[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        dijkstra(i);
        for (int j = i + 1; j <= n; ++j) ans += (cnt[j] == 2);
    }
    cout << ans << endl;
    ans = 0;
    for (int i = 1; i <= n; ++i) e[i].clear();
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c, t; cin >> c >> t;
    while (t--) solve();
    return 0;
}
// 40
