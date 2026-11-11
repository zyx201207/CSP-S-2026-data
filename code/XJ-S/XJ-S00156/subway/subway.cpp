#include <algorithm>
#include <iostream>
#include <cstring>
#include <numeric>
#include <vector>
#include <queue>
#include <cmath>
using std::cin;
using std::cout;
using ll = long long;

const int N = 505, M = 5e5 + 5;
int mother_of_wood_stick;
int n, m, d, Q;
ll w[M];
std::vector<std::pair<int, ll>> to[M], e[N];

ll dis[N][N];
std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<>> q;

void dijkstra(int s) {
    q.emplace(0, s);
    dis[s][s] = 0;

    while(!q.empty()) {
        const auto [d, u] = q.top();
        q.pop();

        if (d > dis[s][u])
            continue;

        for (const auto &[v, w] : e[u]) {
            ll nd = d + w;
            if (dis[s][v] == -1 || nd < dis[s][v])
                dis[s][v] = nd;
            q.emplace(nd, v);
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> mother_of_wood_stick;
    cin >> n >> m >> d >> Q;

    for (int i = 1; i <= m; ++i)
        cin >> w[i];
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1, a, t; j <= k; ++j) {
            cin >> a >> t;
            to[a].emplace_back(i, t);
        }
    }

    for (int i = 1; i <= m; ++i) {
        int cnt = to[i].size();

        for (int j = 0; j < cnt; ++j) {
            const auto &[u, x] = to[i][j];
            for (int k = j + 1; k < cnt; ++k) {
                const auto &[v, y] = to[i][k];
                e[u].emplace_back(v, x + y);
                e[v].emplace_back(u, x + y);
            }
        }
    }

    memset(dis, -1, sizeof dis);
    for (int i = 1; i <= n; ++i)
        dijkstra(i);

    while (Q--) {
        int x, y;
        cin >> x >> y;

        ll ans = LLONG_MAX;
        for (int i = 0; i < to[x].size(); ++i) {
            const auto &[u, p] = to[x][i];
            for (int j = 0; j < to[y].size(); ++j) {
                const auto &[v, q] = to[y][j];
                ans = std::min(ans, dis[u][v] + p + q);
            }
        }

        cout << ans + w[x] + w[y] << '\n';
    }
}