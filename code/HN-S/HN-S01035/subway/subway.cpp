#include <bits/stdc++.h>

using namespace std;

const int MaxN = 505, MaxM = 5e5 + 5;

int c, n, m, d, q, w[MaxM];
long long dis[MaxN][MaxN];
vector<array<int, 2>> vec[MaxM];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1, k, a, t; i <= n; i++) {
        for (cin >> k; k; k--) {
            cin >> a >> t;
            vec[a].push_back({i, t});
        }
        dis[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0, ij, tj; j < vec[i].size(); j++) {
            for (int k = j + 1, ik, tk; k < vec[i].size(); k++) {
                ij = vec[i][j][0], tj = vec[i][j][1];
                ik = vec[i][k][0], tk = vec[i][k][1];
                dis[ij][ik] = min(dis[ij][ik], 0LL + tj + tk);
                dis[ik][ij] = min(dis[ik][ij], 0LL + tj + tk);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int x, y; q; q--) {
        cin >> x >> y;
        long long ret = 8e18;
        for (int i = 0, ix, tx; i < vec[x].size(); i++) {
            for (int j = 0, iy, ty; j < vec[y].size(); j++) {
                ix = vec[x][i][0], tx = vec[x][i][1];
                iy = vec[y][j][0], ty = vec[y][j][1];
                ret = min(ret, dis[ix][iy] + tx + ty);
            }
        }
        cout << ret + w[x] + w[y] << '\n';
    }
    return 0;
}