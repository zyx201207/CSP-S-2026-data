#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> node;
typedef pair<int, int> pr;
const int INF = 1e9;
int c, n, m, d, q, k, x, y, k0, t;
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    vector<int> w(m + 1);
    vector<vector<node>> a(n + m + 1);
    auto add = [&](int u, int v, int w) {
        a[u].emplace_back(v, w), a[v].emplace_back(u, w);
    };
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 0; i < n; i++) {
        cin >> k0;
        for (int j = 1; j <= k0; j++)
            cin >> k >> t, add(m + i + 1, k, t);
    }
    for (int i = 1; i <= q; i++) {
        cin >> x >> y;
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        vector<int> dis(n + m + 1, INF);
        pq.emplace(dis[x] = 0, x);
        while (!pq.empty()) {
            auto d = pq.top().first, u = pq.top().second;
            pq.pop();
            if (d > dis[u]) continue;
            for (auto e : a[u]) {
                if (dis[e.first] > d + e.second) {
                    pq.emplace(dis[e.first] = d + e.second, e.first);
                }
            }
        }
        cout << dis[y] + w[x] + w[y] << '\n';
    }
    return 0;
}