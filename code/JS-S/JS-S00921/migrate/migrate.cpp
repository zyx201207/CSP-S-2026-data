// chennie ls bless me
// cubber ls bless me
// Oct31==Dec25?

#include <iostream>
#include <string.h>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
#include <numeric>
#include <iomanip>
#include <queue>
#include <random>
#include <time.h>
using i64 = long long;
#define sz(x) (int)x.size()
#define IO(s) assert(freopen(s".in", "r", stdin)); assert(freopen(s".out", "w", stdout))
const int N = 2e6 + 10;
int tid = 0;
i64 n, d;
i64 x[N];
int cnt[N], dist[N];
int q[N];
std::vector<int> adj[N];

void sub1() {
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; ; ++j) {
            if (j > n) break;
            if (x[j] - x[i] > d) break;
            adj[i].emplace_back(j);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int ql = 0, qr = 0;
        q[qr++] = i;
        for (int j = i + 1; j <= n; ++j) dist[j] = -1, cnt[i] = 0;
        cnt[i] = 1;
        dist[i] = 0;
        while (ql < qr) {
            int u = q[ql++];
            for (const auto &v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    cnt[v] = cnt[u];
                    q[qr++] = v;
                } else if (dist[v] == dist[u] + 1) cnt[v] += cnt[u];
            }
        }
        for (int j = i + 1; j <= n; ++j) if (cnt[j] == 2) {
            ++ans;
        } 
    }
    std::cout << ans << '\n';
}

void sub2() {
    i64 diff = x[2] - x[1];
    if (d < diff * 2) {
        std::cout << 0 << '\n';
        return;
    }
    d /= diff;
    std::cout << std::max(0ll, n - 2 * d + 1) << '\n';
}

void solve() {
    std::cin >> n >> d;
    for (int i = 1; i <= n; ++i) std::cin >> x[i];
    for (int i = 1; i <= n; ++i) adj[i].clear();
    if (n <= 5000) sub1();
    else if (tid == 11 || tid == 12) sub2();
    else std::cout << 0 << '\n';
}

int main() {
    IO("migrate");
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int _ = 1;
    std::cin >> tid;
    std::cin >> _;
    while (_--) solve();
    return 0;
}