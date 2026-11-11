#include <iostream>
#include <vector>
#include <unordered_map>
#define pii pair<int, int>
#define INF 1000000000000000000
using namespace std;

int read() {
    int x = 0, c = getchar();
    while (!isdigit(c)) {
        c = getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + (c & 15), c = getchar();
    }
    return x;
}

int c, n, m, d, q, w[500001];
vector<int> li[501];
unordered_map<int, int> sta[500001];

namespace Sub1 {
    long long f[1001][1001];
    void solve() {
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                f[i][j] = INF;
            }
            f[i][i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int u : li[i]) {
                for (int v : li[i]) {
                    if (u != v) {
                        f[u][v] = sta[u][i] + sta[v][i];
                    }
                }
            }
        }
        for (int p = 1; p <= m; ++p) {
            for (int u = 1; u <= m; ++u) {
                for (int v = 1; v < u; ++v) {
                    f[v][u] = f[u][v] = min(f[u][v], f[u][p] + f[p][v]);
                }
            }
        }
        while (q--) {
            int u = read(), v = read();
            printf("%lld\n", f[u][v] + w[u] + w[v]);
        }
    }
}

void solve() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(), n = read(), m = read(), d = read(), q = read();
    for (int i = 1; i <= m; ++i) {
        w[i] = read();
    }
    for (int i = 1; i <= n; ++i) {
        int t = read();
        for (int j = 1; j <= t; ++j) {
            int p = read(), x = read();
            li[i].push_back(p), sta[p][i] = x;
        }
    }
    Sub1::solve();
}

int main() {
    solve();
    return 0;
}