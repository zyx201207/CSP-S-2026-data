#include <bits/stdc++.h>
long long n, m, q, c, d, a, w[500005], tot, dis[505][505];
std::vector<std::pair<long long, long long>> con[500005];
int main() {
    std::ios::sync_with_stdio(0), std::cin.tie(0), freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout), std::cin >> c >> n >> m >> d >> q, memset(dis, 0x3f, sizeof dis);
    for (long long i = 1; i <= m; ++i)
        std::cin >> w[i];
    for (long long i = 1; i <= n; ++i) {
        std::cin >> c, ++tot, dis[i][i] = 0;
        for (long long j = 1; j <= c; ++j)
            std::cin >> d >> a, con[d].emplace_back(tot, a);
    }
    for (long long i = 1; i <= m; ++i)
        for (std::pair<long long, long long> j : con[i])
            for (std::pair<long long, long long> k : con[i])
                if (j.first != k.first)
                    dis[j.first][k.first] = dis[k.first][j.first] = std::min(dis[j.first][k.first], j.second + k.second);
    for (long long k = 1; k <= n; ++k)
        for (long long i = 1; i <= n; ++i)
            for (long long j = 1; j <= n; ++j)
                dis[i][j] = std::min(dis[i][k] + dis[j][k], dis[i][j]);
    while (q--) {
        std::cin >> c >> d, a = dis[0][0];
        for (std::pair<long long, long long> i : con[c])
            for (std::pair<long long, long long> j : con[d])
                a = std::min(a, dis[i.first][j.first] + i.second + j.second);
        std::cout << a + w[c] + w[d] << '\n';
    }
    return 0;
}
