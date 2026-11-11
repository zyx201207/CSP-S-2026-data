#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
const int M = 5e5;
int C, n, m, d, Q, w[M + 10];

struct Edge {
    int to, l;
    Edge (int _to, int _l) {
        to = _to, l = _l;
    }
};
vector<Edge> g[N + 10];
vector<int> node;

struct Info {
    long long d;
    int id;
    Info (long long _d, int _id) {
        d = _d, id = _id;
    }
    bool operator > (const Info &x) const {
        return this -> d > x.d;
    }
};
priority_queue<Info, vector<Info>, greater<Info>> q;
long long dist[N + 10];
bool vis[N + 10];
long long Dijkstra(int s, int t) {
    q = priority_queue<Info, vector<Info>, greater<Info>>();
    q.push(Info(0, s));
    for (auto i : node) {
        vis[i] = false;
        dist[i] = 1e18;
    }
    dist[s] = 0;
    while (!q.empty()) {
        int x = q.top().id;
        q.pop();
        if (vis[x]) {
            continue;
        }
        vis[x] = true;
        for (auto i : g[x]) {
            if (dist[x] + i.l < dist[i.to]) {
                dist[i.to] = dist[x] + i.l;
                q.push(Info(dist[i.to], i.to));
            }
        }
    }
    return dist[t];
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &C, &n, &m, &d, &Q);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= n; i++) {
        int len;
        scanf("%d", &len);
        int last_x;
        for (int j = 1; j <= len; j++) {
            int x, y;
            scanf("%d%d", &x, &y);
            g[i * m + x].push_back(Edge(x, y));
            g[x].push_back(Edge(i * m + x, y));
            node.push_back(i * m + x);
            node.push_back(x);
            if (j != 1) {
                g[i * m + x].push_back(Edge(i * m + last_x, 0));
                g[i * m + last_x].push_back(Edge(i * m + x, 0));
                node.push_back(i * m + x);
                node.push_back(i * m + last_x);
            }
            last_x = x;
        }
    }
    while (Q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        long long ans = w[x] + w[y] + Dijkstra(x, y);
        printf("%lld\n", ans);
    }
    return 0;
}
