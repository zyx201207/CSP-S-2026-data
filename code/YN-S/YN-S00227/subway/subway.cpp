#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10, MAXM = 5E5 + 10;
int c, n, m, d, q, w[MAXN], a[MAXN][MAXM], t[MAXN][MAXM], k[MAXN], r;

unordered_map <int, int> step[MAXM];

int get_pos(int u, int type) {
    /*
    0:地铁口
    1:站厅
    2:站台
    */
    switch (type) {
        case 0:
            return u;
        case 1:
            return m + u;
        case 2:
            return m + m + step[u][u];
    }
    return -1;
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> c >> n >> m >> d >> q;
    for (int i = 0; i < m; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
    }
    return 0;
}
