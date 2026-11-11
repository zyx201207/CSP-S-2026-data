#include <algorithm>
#include <fstream>
#include <vector>

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

std::ifstream fin("migrate.in");
std::ofstream fout("migrate.out");

namespace solve {
void solve_sq() {
    uint n;
    ll d;

    fin >> n >> d;

    std::vector<ll> v(n);

    for (size_t i = 0; i < n; i++) {
        fin >> v[i];
    }

    std::vector<std::vector<uint>> lfar(n, std::vector<uint>(20)),
        rfar(n, std::vector<uint>(20));

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < 20; j++) {
            lfar[i][j] = rfar[i][j] = i;
        }
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (v[j] - v[i] <= d) {
                lfar[j][0] = std::min<uint>(lfar[j][0], i);
                rfar[i][0] = std::max<uint>(rfar[i][0], j);
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (size_t j = 1; j < 20; j++) {
            rfar[i][j] = rfar[rfar[i][j - 1]][j - 1];
        }
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 1; j < 20; j++) {
            lfar[i][j] = lfar[lfar[i][j - 1]][j - 1];
        }
    }

    auto step = [&](uint x, uint cnt, bool dir) {
        const auto &nxt = (dir ? rfar : lfar);

        for (int i = 20 - 1; i >= 0; i--) {
            if ((cnt >> i) & 1) {
                x = nxt[x][i];
            }
        }

        return x;
    };

    auto dis = [&](uint x, uint y) {
        if (x > y) {
            std::swap(x, y);
        }

        if (x == y) {
            return 0u;
        }

        uint d = 0;

        for (int i = 20 - 1; i >= 0; i--) {
            uint cnxt = rfar[x][i];
            if (cnxt >= y) {
                continue;
            }
            x = cnxt;
            d += (1u << i);
        }

        return d + 1;
    };

    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n));
    std::vector<std::vector<bool>> vis(n, std::vector<bool>(n));

    auto calulate = [&](auto self, uint x, uint y) -> bool {
        if (vis[x][y]) {
            return dp[x][y];
        }

        vis[x][y] = true;

        auto cdis = dis(x, y);

        if (cdis > n) {
            return dp[x][y] = false;
        }

        if (cdis == 1) {
            return dp[x][y] = false;
        }

        if (cdis == 2) {
            uint a = rfar[x][0], b = lfar[y][0];

            if (a - b + 1 != 2) {
                return dp[x][y] = false;
            }
            return dp[x][y] = true;
        }

        auto md = step(x, cdis - 1, true);
        if (md == lfar[y][0]) {
            return dp[x][y] = self(self, x, md);
        }
        md = step(y, cdis - 1, false);

        if (md == rfar[x][0]) {
            return dp[x][y] = self(self, md, y);
        }

        return dp[x][y] = false;
    };

    ull ans = 0;

    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            ans += calulate(calulate, i, j);
        }
    }

    fout << ans << "\n";
}

const ll INF = 4000000000000000000;

void solve_special() {
    uint n;
    ll d;
    fin >> n >> d;

    std::vector<ll> v(n);

    for (size_t i = 0; i < n; i++) {
        fin >> v[i];
    }

    v.insert(v.begin(), -INF);
    v.push_back(INF);

    ull cnt = 0;

    uint ai = 0, bi = 0, ci = 0, di = 0;

    for (size_t i = 1; i + 2 < v.size(); i++) {
        ll r1 = v[i] + d + 1;
        ll l1 = v[i - 1] + d + 1;

        ll l2 = v[i + 1] - d;
        ll r2 = v[i + 2] - d;

        if (l1 <= v[i + 1]) {
            l1 = v[i + 1] + 1;
        }

        if (r2 >= v[i]) {
            r2 = v[i];
        }

        while (ai < v.size() && v[ai] < l1) {
            ++ai;
        }

        while (bi < v.size() && v[bi] < r1) {
            ++bi;
        }

        while (ci < v.size() && v[ci] < l2) {
            ++ci;
        }

        while (di < v.size() && v[di] < r2) {
            ++di;
        }

        if (ai >= bi || ci >= di) {
            continue;
        }

        cnt += ull(bi - ai) * (di - ci);
    }

    fout << cnt << "\n";
}

void solve(uint c) {
    if (c <= 10) {
        solve_sq();
    }
    else {
        solve_special();
    }
}
} // namespace solve

int main() {
    uint c, t;
    fin >> c >> t;
    while (t--) {
        solve::solve(c);
    }
    fout << std::flush;
}

/**
 * 阅读样例和数据范围。
 *
 * Tracker Paths P?
 *
 * 不是吧三个图论题。
 *
 * 首先考虑图论建模。
 *
 * 自然是和最段路有关。我们希望查询到有恰好两条最短路的点对。
 *
 * 首先根据最段路理论，有一个引力。
 *
 * 就是这两条最段路长什么样子。
 *
 * 感觉肯定是共享前缀/后缀。
 *
 * 然后中间全部不共享点。
 *
 * 否则，我们就有 2*2 = 4 条最段路了。
 *
 * 另一方面，最段路本身是容易使用倍增求出的。
 *
 * 因而看上去，这个东西可能是有单调性的。
 *
 * 需要验证以下。
 *
 * 感觉有很强的性质阿。写完拍子来看一下。
 *
 * 3h remain.
 *
 * 好吧。我们来看一下暴力怎么做。
 *
 * 暴力可以是，直接最段路树。
 *
 * sample 1 告诉我们可能不单调。
 *
 * 接下来考虑平方做法。
 *
 * 如何快速判断这个？
 *
 * 考虑等差数列的特殊性质。实际上是每次跳最远的。
 *
 * 但是你可以选择跳一次近的。之后继续跳远。
 *
 * 实际上，看上去一旦你不是整除，那么你就必然有很多条。
 *
 * 因为假设是 k k k k x 你可以随便交换。
 *
 * 除非恰好长度为 2。或者，整除。当然整除是唯一的。
 *
 * 因此我们只需要判断长度为 2 的可能性即可。
 *
 * 或许可以考虑 u -> v 最远和 v -> u 最远？
 *
 * 这样我们可以得到一个前缀或者后缀。
 *
 * 实际上是找到了一个最小的路径和最大的路径。
 *
 * 目标是找到是否有中间的路径。
 *
 * 烧等，是否所有此类可能都是从 1 -> 3 -> 4 1 -> 2 -> 4 开始的。
 *
 * 我们中庸之道以下。
 *
 * 考察公共路径上的 1 1 2 2 3 3 4 4。必然存在一个 i -> i + 1 是交错的。
 *
 * 假设是，ai bi aj bj
 *
 * 那么。我们把 bi 接入 aj。距离更小，显然合法。
 *
 * 那么这是一条不同的路径！
 *
 * 为什么 1 2 4 1 3 4 不行。
 *
 * 因为不存在。等下，真的一定存在吗。
 *
 * 对阿。不一定。
 *
 * 1236 1456
 *
 * 烧等。那为什么不 4 -> 6？
 *
 * 对啊。实际上只需要分类讨论前 2 条是怎么作的即可。
 *
 * 我们总是可以找到第三条。
 *
 * 好吧，接下来是主要部分。
 *
 * 这玩意咋判阿。
 *
 * 我们只需要检查相邻四个点吗。
 *
 * 好吧，简单来说，就是尽可能往远处。
 *
 * 然后如果交集恰好 2 个，那就对完了。否则错完了。
 *
 * 那么实际上一定是相邻的两对。
 *
 * 这个只是长度为 2 的可能。还需要注意判掉长度为 1 的。
 *
 * 感觉判断掉自己，感觉就全判断完了。
 *
 * 好的，那么更长的情况怎么办。共享前后缀之类的。
 *
 * 首先到这里这个东西肯定是唯一的。
 *
 * 我们考虑处理出走若干步的最近和最远。
 * 我们希望交集最多是 2。
 *
 * 对吗。
 *
 * 好吧，我们来看看我们新的特殊性质。
 *
 * 我们的特殊性质 B 就解决了。
 *
 * 接下来是特殊性质 C。
 *
 * 看上去意味着最段路不会太长。
 *
 * 看上去你可以枚举长度。
 *
 * 不对啊，你两个拼在一起就全挂了。
 *
 * 看上去要求此类情况只能出现一次。实际上看上去是二维数点。
 *
 * 相邻四个点，如果满足条件，那么选出所有 a, b, c, d
 *
 * a 到不了，b c 可达。
 *
 * b c 可达，d 到不了。
 *
 * 给这种的加上 1。如果可以同时到达相邻 3 个点，那么肯定是不行的。
 *
 * 唯一的定义是任意步长交集是 1。
 *
 * 哦实际上你关心最远的即可。
 *
 * 最近的看上去就是无所谓。
 *
 * 我有没有平方做法来这。
 *
 * 我觉得我改跑路了。
 *
 * 40pts 阿。我没有平方做法。
 *
 * 我们一直倍增，或许可以。
 *
 * 我们或许应该检讨以下。
 *
 * 就是说啊，如果最后一步是相同的，那么我们可以直接这样去做。
 *
 * 否则，我们或许可以区间 dp 一下？
 *
 * 我们其实可以判断是否一致的对吧。
 *
 * 这大概就是平方做法。
 */