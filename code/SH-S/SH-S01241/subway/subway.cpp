#include <bits/extc++.h>

using namespace std;

ifstream fin("subway.in");
ofstream fout("subway.out");

using iiu = istream_iterator<uint>;
using p2u = pair<uint, uint>;

template<class T>
T& chmin(T &x, T y) { return x = min(x, y); }

const uint N = 5e2 + 5, M = 5e5 + 5;

uint c, n, m, d, q, w[M];
ulong dis[N][N], ans;
vector<p2u> trt[M];

int main() {
    fin >> c >> n >> m >> d >> q, copy_n(iiu(fin), m, w + 1);
    for (uint i = n, k; i-- && fin >> k; fill_n(dis[i], n, LONG_MAX), dis[i][i] = 0)
        for (uint j = k, a, t; j--; fin >> a >> t, trt[a].emplace_back(i, t));
    for (uint i = m; i; --i)
        for (uint j = 0, lin = trt[i].size(); ++j < lin;)
            for (uint k = -1, x, y, z; ++k < j; chmin<ulong>(dis[x = trt[i][j].first][y = trt[i][k].first], z = trt[i][j].second + trt[i][k].second), chmin<ulong>(dis[y][x], z));
    for (uint i = -1; ++i < n;)
        for (uint j = -1; ++j < n;)
            for (uint k = -1; ++k < n; chmin(dis[j][k], dis[j][i] + dis[i][k]));
    for (uint x, y; ans = -1, q-- && fin >> x >> y; fout << w[x] + ans + w[y] << '\n')
        for (auto [a, ta] : trt[x])
            for (auto [b, tb] : trt[y]) chmin(ans, ta + dis[a][b] + tb);
}