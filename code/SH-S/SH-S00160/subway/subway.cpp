#include <iostream>
#include <vector>
#include <queue>
using namespace std;
constexpr int MAXV = 2e9 + 5;
constexpr long long INF = 1e16 + 5;
struct Edge { int v, w; };
struct Data {
    int idx;
    long long val;
    bool operator<(Data other) const {
        return val > other.val;
    }
};
int c, n, m, d, q, w[500005], k, a, t, x, y;
vector<Edge> line[500005];
bool flag[505];
int v[505][505];
long long dis[505][505], ans;
vector<Edge> edges[505];
priority_queue<Data> pq;
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; ++i)
        scanf("%d", w + i);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            dis[i][j] = INF; v[i][j] = MAXV;
        }
        const int idx = i + m;
        scanf("%d", &k);
        for (int j = 1; j <= k; ++j) {
            scanf("%d%d", &a, &t);
            line[a].push_back({ i, t });
        }
    }
    for (int i = 1; i <= m; ++i)
        for (const Edge l1 : line[i])
            for (const Edge l2 : line[i])
                v[l1.v][l2.v] = min(v[l1.v][l2.v], l1.w + l2.w);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j && v[i][j] < MAXV)
                edges[i].push_back({ j, v[i][j] });
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            flag[j] = false;
        pq.push({ i, 0 });
        while (!pq.empty()) {
            const int cur = pq.top().idx;
            pq.pop();
            if (flag[cur]) continue;
            flag[cur] = true;
            for (const Edge e : edges[cur]) {
                if (dis[i][cur] + e.w < dis[i][e.v]) {
                    dis[i][e.v] = dis[i][cur] + e.w;
                    pq.push({ e.v, dis[i][e.v] });
                }
            }
        }
    }
    while (q--) {
        scanf("%d%d", &x, &y);
        ans = INF;
        for (const Edge l1 : line[x])
            for (const Edge l2 : line[y])
                ans = min(ans, dis[l1.v][l2.v] + l1.w + l2.w);
        printf("%lld\n", ans + w[x] + w[y]);
    }
    return 0;
}