#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Node {
    int to;
    ll l;
    Node(int _to, ll _l) {
        to = _to, l = _l;
    }
};

int testid, n, m, d, q, w[500010], a[500010];
ll dist[510][510];
vector<Node> g[500010];
vector<pair<int, int>> t[510], st[500010];

void dijsktra(int i) {
    for (int j = 1; j <= n; j++)
        dist[i][j] = 1ll << 60;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    dist[i][i] = 0;
    for (int j = 1; j <= n; j++)
        q.push({dist[i][j], i});
    for (; !q.empty(); ) {
        auto zip = q.top();
        int y = zip.first, x = zip.second;
        q.pop();
        if (y > dist[i][x])
            break;
        for (auto p : g[x])
            if (dist[i][x] + p.l < dist[i][p.to]) {
                dist[i][p.to] = dist[i][x] + p.l;
                q.push({dist[i][p.to], p.to});
            }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &testid, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        t[i].resize(k + 10);
        for (int j = 1; j <= k; j++)
            scanf("%d%d", &t[i][j].first, &t[i][j].second),
            st[t[i][j].first].push_back({i, j});
    }
    for (int i = 1; i <= m; i++) {
        int l = st[i].size();
        for (int j = 0; j < l; j++)
            for (int k = j + 1; k < l; k++) {
                int tmp1 = st[i][j].first, tmp2 = st[i][j].second;
                int tmp3 = st[i][k].first, tmp4 = st[i][k].second;
                g[tmp3].push_back(Node(tmp1, t[tmp1][tmp2].second + t[tmp3][tmp4].second)),
                g[tmp1].push_back(Node(tmp3, t[tmp1][tmp2].second + t[tmp3][tmp4].second));
            }
    }
    for (int i = 1; i <= n; i++)
        dijsktra(i);
    for (; q--; ) {
        int x, y;
        scanf("%d%d", &x, &y);
        ll ans = 1ll << 60;
        for (auto i : st[x])
            for (auto j : st[y])
                ans = min(ans, w[x] + t[i.first][i.second].second + dist[i.first][j.first] + t[j.first][j.second].second + w[y]);
        printf("%lld\n", ans);
    }
    return 0;
}
