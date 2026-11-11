#include <algorithm>
#include <fstream>
#include <vector>

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

std::ifstream fin("crystal.in");
std::ofstream fout("crystal.out");

namespace solve {
void solve() {
    uint n;
    ll m;
    fin >> n >> m;

    std::vector<ll> v(n);

    for (size_t i = 0; i < n; i++) {
        fin >> v[i];
    }

    std::sort(v.begin(), v.end());

    /**
     * maybe it just buhuibao.
     *
     * 1e12 * 5e5 < 1e18
     */

    uint l = 0;
    ll used = 0;

    uint ans = 1;

    for (uint i = 1; i < n; i++) {
        used += ll(i - l) * (v[i] - v[i - 1]);

        while (used > m && l < i) {
            used -= v[i] - v[l];
            ++l;
        }

        ans = std::max<uint>(ans, i + 1 - l);
    }

    fout << ans << "\n";
}
} // namespace solve

int main() {
    solve::solve();
    fout << std::flush;
}

/**
 * 阅读样例和数据范围。
 *
 * let me see.
 *
 * seems greedy. use 2 ptrs;
 *
 * mei ju yi xia hebing dao na ge shu.
 *
 * we use the biggest ones that is smaller than x.
 *
 * xiaoxin long long;
 */