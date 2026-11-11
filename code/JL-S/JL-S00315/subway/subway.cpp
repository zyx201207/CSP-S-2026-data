#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair <int, int>

int c, n, m, D, q;
int s, e;
int t[500100];
int d[500100];

vector <pii> g[500100];

void dijkstra () {
    priority_queue <pii, vector <pii>, greater <pii>> pq;
    fill(d, d + m + n + 1, INT_MAX);
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        if (d[t.second] < t.first) {
            continue;
        }
        for (auto p : g[t.second]) {
            if (p.second + t.first < d[p.first]) {
                d[p.first] = p.second + t.first;
                pq.push({d[p.first], p.first});
            }
        }
    }

}

signed main () {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> D >> q;
    for (int i = 1; i <= m; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++) {
        int a, b;
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> a >> b;
            g[i + m].push_back({a, b});
            g[a].push_back({i + m, b});
        }
    }
    while (q--) {
        cin >> s >> e;
        dijkstra();
        cout << d[e] + t[s] + t[e] << "\n";
    }
    return 0;
}
