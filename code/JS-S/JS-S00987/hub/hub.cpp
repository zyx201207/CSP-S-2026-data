#include <algorithm>
#include <fstream>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

std::ifstream fin("hub.in");
std::ofstream fout("hub.out");

namespace solve {
void solve() {
    uint n, k;
    fin >> n >> k;

    std::vector<std::pair<uint, uint>> e;
    std::vector<std::vector<uint>> g(n);

    for (size_t i = 0; i + 1 < n; i++) {
        uint u, v;
        fin >> u >> v;
        --u, --v;
        e.push_back({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }

    uint ans = n + 1;

    for (size_t stat = 0; stat < 1u << n; stat++) {
        if (__builtin_popcountll(stat) != k) {
            continue;
        }

        std::vector<bool> used(n);

        std::queue<uint> q;
        std::vector<uint> dis(n, n + 1);

        for (size_t i = 0; i < n; i++) {
            if ((stat >> i) & 1) {
                used[i] = true;
                q.push(i);
                dis[i] = 0;
            }
        }

        uint cur = k;

        for (size_t i = 0; i < n - 1; i++) {
            if (used[e[i].first] && used[e[i].second]) {
                --cur;
            }
        }

        if (cur > 2) {
            continue;
        }

        while (!q.empty()) {
            auto f = q.front();
            q.pop();

            for (auto &&i : g[f]) {
                if (used[i]) {
                    continue;
                }
                used[i] = true;
                dis[i] = dis[f] + 1;
                q.push(i);
            }
        }

        ans = std::min(ans, *std::max_element(dis.begin(), dis.end()));
    }

    fout << ans << "\n";
}
} // namespace solve

int main() {
    uint c, t;
    fin >> c >> t;
    while (t--) {
        solve::solve();
    }
    fout << std::flush;
}

/**
 * 阅读样例和数据范围。
 *
 * 好像完蛋了。
 *
 * 1h remain.
 *
 * 首先二分是显然的。
 *
 * 相当于，在每个点距离小于 x 的必有一个点。
 *
 * 大概就是。
 *
 * 然后你发现，一个 bool 是浪费的。
 *
 * 对于一个方案，我们希望:
 *
 * 1 如果存在不满足，那么不满足最前。
 * 2 如果不存在，那么最近的一个最浅。
 *
 * 不对阿，可能同时有不满足和关键点怎么办。
 *
 * 全错了。还有一个性质是最多两块。
 *
 * 感觉多比少好阿。
 *
 * 15pts 跑路了。
 */