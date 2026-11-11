#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL Maxn = 500 + 5;
const LL Maxm = 5e5 + 5;
const LL Inf = 1e18;

LL W[Maxm];
struct node {
    LL rd, t;
};
vector<node> Z_rd[Maxm];

LL Mind[Maxn][Maxn];

void init_m(LL n) {
    for (LL i = 1; i <= n; ++i) {
        for (LL j = i + 1; j <= n; ++j) {
            Mind[i][j] = Mind[j][i] = Inf;
        }
    }
    return;
}

void Floyd(LL n) {
    for (LL k = 1; k <= n; ++k) {
        for (LL i = 1; i <= n; ++i) {
            for (LL j = 1; j <= n; ++j) {
                Mind[i][j] = min(Mind[i][j], Mind[i][k] + Mind[k][j]);
            }
        }
    }
    return;
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL c, rd_n, z_m, z_d, q;
    cin >> c >> rd_n >> z_m >> z_d >> q;
    for (LL i = 1; i <= z_m; ++i) {
        cin >> W[i];
    }
    LL k, a, t;
    for (LL i = 1; i <= rd_n; ++i) {
        cin >> k;
        for (LL j = 1; j <= k; ++j) {
            cin >> a >> t;
            Z_rd[a].push_back({i, t});
        }
    }

    init_m(rd_n);
    LL ra = 0, rb = 0, ta = 0, tb = 0;
    for (LL i = 1; i <= z_m; ++i) {
        for (LL j = 0; j < Z_rd[i].size(); ++j) {
            for (LL k = j + 1; k < Z_rd[i].size(); ++k) {
                ra = Z_rd[i][j].rd;
                rb = Z_rd[i][k].rd;
                ta = Z_rd[i][j].t;
                tb = Z_rd[i][k].t;
                Mind[ra][rb] = min(Mind[ra][rb], ta + tb);
                Mind[rb][ra] = min(Mind[rb][ra], ta + tb);
            }
        }
    }

    Floyd(rd_n);

    LL x, y, res = Inf;
    while (q--) {
        cin >> x >> y;
        for (auto aelem : Z_rd[x]) {
            for (auto belem : Z_rd[y]) {
                ra = aelem.rd;
                rb = belem.rd;
                res = min(res, Mind[ra][rb] + W[x] + W[y] + aelem.t + belem.t);
            }
        }

        cout << res << '\n';
    }


    return 0;
}
