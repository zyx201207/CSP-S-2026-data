#include <bits/stdc++.h>
using namespace std;

struct Edge {
    long long to, w;
};

vector<vector<Edge>> g;

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<long long> w(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    vector<vector<long long>> a(n + 1);
    vector<vector<long long>> t(n + 1);
    vector<long long> k(n + 1);
    vector<long long> station_num(m + 1, 1);
    long long total = m;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        total += k[i];
        a[i].resize(k[i] + 1);
        t[i].resize(k[i] + 1);
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
            station_num[a[i][j]]++;
        }
    }
    g.resize(total + 1);
    vector<long long> pre(m + 1, 0);
    for (int i = 2; i <= m; i++) {
        pre[i] = pre[i - 1] + station_num[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        pre[i] += 1;
    }
    vector<long long> cnt(m + 1, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k[i]; j++) {
            g[pre[a[i][j]]].push_back({pre[a[i][j]] + cnt[a[i][j]], t[i][j]});
            g[pre[a[i][j]] + cnt[a[i][j]]].push_back({pre[a[i][j]], t[i][j]});
            if (j < k[i]) {
                g[pre[a[i][j]] + cnt[a[i][j]]].push_back({pre[a[i][j + 1]] + cnt[a[i][j + 1]], 0});
                g[pre[a[i][j + 1]] + cnt[a[i][j + 1]]].push_back({pre[a[i][j]] + cnt[a[i][j]], 0});
            }
            cnt[a[i][j]]++;
        }
    }
    vector<vector<long long>> dist(total + 1, vector<long long>(total + 1, 0x3fffffffffffffff));
    for (int i = 1; i <= total; i++) {
        for (auto xxx : g[i]) {
            long long to = xxx.to;
            long long w = xxx.w;
            dist[i][to] = min(dist[i][to], w);
            dist[to][i] = min(dist[to][i], w);
        }
    }
    for (int i = 1; i <= total; i++) {
        dist[i][i] = 0;
    }
    for (int k = 1; k <= total; k++) {
        for (int i = 1; i <= total; i++) {
            for (int j = 1; j <= total; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        long long ans = dist[pre[x]][pre[y]] + w[x] + w[y];
        cout << ans << "\n";
    }
    return 0;
}
