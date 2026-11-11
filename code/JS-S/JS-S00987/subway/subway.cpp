#include <fstream>
#include <vector>

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

std::ifstream fin("subway.in");
std::ofstream fout("subway.out");

namespace solve {
const ull INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    uint tid, clines, cnodes, mdeg, q;

    fin >> tid >> clines >> cnodes >> mdeg >> q;

    std::vector<ull> bdis(cnodes);

    for (size_t i = 0; i < cnodes; i++) {
        fin >> bdis[i];
    }

    std::vector<std::vector<ull>> mdis(clines, std::vector<ull>(clines, INF));

    for (size_t i = 0; i < clines; i++) {
        mdis[i][i] = 0;
    }

    std::vector<std::vector<std::pair<uint, ull>>> plines(cnodes);

    for (size_t i = 0; i < clines; i++) {
        uint k;
        fin >> k;
        for (size_t j = 0; j < k; j++) {
            uint idx;
            ull cost;
            fin >> idx >> cost;
            --idx;
            plines[idx].push_back({i, cost});
        }
    }

    for (size_t i = 0; i < cnodes; i++) {
        for (size_t x = 0; x < plines[i].size(); x++) {
            for (size_t y = x + 1; y < plines[i].size(); y++) {
                uint u = plines[i][x].first, v = plines[i][y].first;
                ull cost = plines[i][x].second + plines[i][y].second;

                mdis[u][v] = std::min(mdis[u][v], cost);
                mdis[v][u] = std::min(mdis[v][u], cost);
            }
        }
    }

    for (size_t k = 0; k < clines; k++) {
        for (size_t i = 0; i < clines; i++) {
            for (size_t j = 0; j < clines; j++) {
                if (mdis[i][k] + mdis[k][j] < mdis[i][j]) {
                    mdis[i][j] = mdis[i][k] + mdis[k][j];
                }
            }
        }
    }

    while (q--) {
        uint x, y;
        fin >> x >> y;
        --x, --y;

        ull ans = bdis[x] + bdis[y];

        ull ans2 = INF;

        for (size_t i = 0; i < plines[x].size(); i++) {
            for (size_t j = 0; j < plines[y].size(); j++) {
                uint u = plines[x][i].first, v = plines[y][j].first;
                ull cost = plines[x][i].second + plines[y][j].second;

                ans2 = std::min<ull>(ans2, mdis[u][v] + cost);
            }
        }

        fout << ans + ans2 << "\n";
    }
}
} // namespace solve

int main() {
    solve::solve();
    fout << std::flush;
}

/**
 * 阅读样例和数据范围。
 *
 * ok. it seems that it's all src ssp.
 *
 * with N = 5e5.
 *
 * but M = 500;
 *
 * so we swap n and m;
 *
 * and use floyd;
 *
 * to caculate the 2 lines. then we
 *
 * enr the beg and end line;
 */