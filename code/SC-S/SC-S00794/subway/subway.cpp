#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e3 + 10, M = 5e5 + 10;
int c, n, m, d, qc;
int w[M], k[N];
vector<int> a[N], t[N];
vector<pair<int, int> > G[M];
unordered_map<int, int> onr[N];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > q;
int dis[M];

int dijkstra(int s, int e) {
    q.emplace(0, s);
    dis[s] = 0;

    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();

        if (d != dis[u]) continue;

        for (int i = 1; i <= n; i++)
            if (onr[i][u])
                for (int j = 1; j <= k[i]; j++)
                    if (a[i][j] != u) {
                        int v = a[i][j], w = onr[i][u] + t[i][j];
                        if (dis[v] > dis[u] + w) {
                            dis[v] = dis[u] + w;
                            q.emplace(dis[v], v);
                        }
                    }
    }

    return dis[e];
}

int dijkstra2(int s, int e) {
    q.emplace(0, s);
    dis[s] = 0;

    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();

        if (d != dis[u]) continue;

        for (const auto& [v, w] : G[u])
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.emplace(dis[v], v);
            }
    }

    return dis[e];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> qc;
    for (int i = 1; i <= m; i++) cin >> w[i];

    bool f = true;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        a[i] = t[i] = vector<int> (k[i] + 10);
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
            onr[i][a[i][j]] = t[i][j];
        }

        if (k[i] > 2) f = false;
    }

    if (f) {
        for (int i = 1; i <= n; i++)
            if (k[i] == 2) {
                G[a[i][1]].emplace_back(a[i][2], t[i][1] + t[i][2]);
                G[a[i][2]].emplace_back(a[i][1], t[i][1] + t[i][2]);
            }

        while (qc--) {
            memset(dis, inf, sizeof dis);

            int x, y;
            cin >> x >> y;
            cout << dijkstra2(x, y) + w[x] + w[y] << '\n';
        }

        return 0;
    }

    while (qc--) {
        memset(dis, inf, sizeof dis);

        int x, y;
        cin >> x >> y;
        cout << dijkstra(x, y) + w[x] + w[y] << '\n';
    }

    return 0;
}
