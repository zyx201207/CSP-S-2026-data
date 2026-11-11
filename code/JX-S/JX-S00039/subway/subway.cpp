#include <bits/stdc++.h>
using namespace std;

constexpr int N = 505, M = 5e5 + 5;
constexpr long long INF = 4e18;

int a[M];
long long mns[N][N];
vector<pair<int, int>> b[N], c[M];

int main () {

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q, x, y, z;
    cin >> n >> n >> m >> q >> q;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> x;
        for (int j = 1; j <= x; j++) {
            cin >> y >> z;
            b[i].emplace_back(y, z);
            c[y].emplace_back(i, z);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            mns[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto &j : b[i]) {
            x = j.first; y = j.second;
            for (auto &k : c[x]) {
                int id = k.first, z = k.second;
                if (i < id) mns[i][id] = min(mns[i][id], 1ll * y + z);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= k; i++) {
            for (int j = k; j <= n; j++) {
                mns[i][j] = min(mns[i][j], mns[i][k] + mns[k][j]);
            }
        }
    }
    while (q--) {
        cin >> x >> y;
        long long ans = 4e18;
        for (auto &i : c[x]) {
            int idx = i.first, cx = i.second;
            for (auto &j : c[y]) {
                int idy = j.first, cy = j.second;
                ans = min(ans, cx + mns[min(idx, idy)][max(idx, idy)] + cy);
            }
        }
        cout << ans + a[x] + a[y] << '\n';
    }
    return 0;
}

// ming yun yi ran zhu ding
// nu li jie zai dang jin

// qi xiao le, ba n,m de yi si kan fan le
// cheng gong lang fei shi ji fen zhong
