#include <bits/stdc++.h>

using namespace std;

int c, n, m, d, q;
vector<int> w;
vector<long long> dis;
vector<vector<pair<int, int>>> g;

void bfs(int s) {
    queue<int> que;
    que.push(s);

    fill(dis.begin(), dis.end(), LLONG_MAX);
    dis[s] = 0;

    while (que.size()) {
        int u = que.front();
        que.pop();

        for (const pair<int, int>& p : g[u]) {
            int v = p.first, w = p.second;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                que.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;

    w.assign(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }

    vector<int> a;
    vector<long long> t;
    g.assign(m + 1, {});
    for (int i = 0, k; i < n; i++) {
        cin >> k;

        a.assign(k, 0);
        t.assign(k, 0);
        for (int i = 0; i < k; i++) {
            cin >> a[i] >> t[i];
        }

        for (int l = 0; l < k; l++) {
            for (int r = l + 1; r < k; r++) {
                g[a[l]].push_back({a[r], t[l] + t[r]});
                g[a[r]].push_back({a[l], t[l] + t[r]});
            }
        }
    }

    dis.assign(m + 1, 0);
    while (q--) {
        int x, y;
        cin >> x >> y;
        bfs(x);
        cout << (dis[y] + w[x] + w[y]) << "\n";
    }

    return 0;
}
