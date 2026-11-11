#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template <typename T>
using vec = vector<T>;

const int C = 5e5 + 5;

int c, n, m, d, q, w[C];
vector<pair<int, int>> O[C + 505];
vector<pair<int, int>> G[505];
ll F[505][505];

struct Node {
    int u;
    ll d;
    bool operator<(const Node &o) const {
        return d > o.d;
    }
};
priority_queue<Node> hp;

void Dijkstra(int s) {
    F[s][s] = 0;
    hp.push({s, 0});
    while (!hp.empty()) {
        int u = hp.top().u;
        ll dis = hp.top().d;
        hp.pop();
        if (dis > F[s][u])
            continue;
        int v0, w0;
        for (auto e : G[u]) {
            tie(v0, w0) = e;
            if (F[s][u] + w0 < F[s][v0]) {
                F[s][v0] = F[s][u] + w0;
                hp.push({v0, F[s][v0]});
            }
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
    for (int v = 1; v <= m; v++) {
        scanf("%d", &w[v]);
    }

    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        vector<int> a(k + 1), t(k + 1);
        for (int j = 1; j <= k; j++) {
            scanf("%d %d", &a[j], &t[j]);
            O[a[j]].push_back({i, t[j]});
            cout << a[j] << '\n';
        }
    }

    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            F[u][v] = 1e18;
        }
    }

    for (int i = 1; i <= m; i++) {
        int v1, v2, w1, w2;
        for (auto e1 : O[i]) {
            for (auto e2 : O[i]) {
                tie(v1, w1) = e1;
                tie(v2, w2) = e2;
                if (v1 == v2) continue;
                G[v1].push_back({v2, w1 + w2});
                G[v2].push_back({v1, w1 + w2});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        Dijkstra(i);
    }

    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        ll p = 1e18;
        int v1, v2, w1, w2;
        for (auto e1 : O[x]) {
            for (auto e2 : O[y]) {
                tie(v1, w1) = e1;
                tie(v2, w2) = e2;
                p = min(p, w1 + F[v1][v2] + w2);
            }
        }
        printf("%lld\n", w[x] + p + w[y]);
    }

    return 0;
}