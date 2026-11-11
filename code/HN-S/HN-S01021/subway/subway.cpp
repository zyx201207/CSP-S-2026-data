#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
int c, n, m, d, q, k, s, t, a[M], b[N][N], ans;
struct Node {
    int v, w;
};
vector<Node> vec[M];
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++ i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++ i) {
        cin >> k;
        for (int j = 1; j <= n; ++ j) {
            b[i][j] = 100000000000000000;
        }
        b[i][i] = 0;
        for (int j = 1, x, t; j <= k; ++ j) {
            cin >> x >> t;
            vec[x].push_back((Node){i, t});
        }
    }
    for (int i = 1; i <= m; ++ i) {
        for (int j = 0; j < vec[i].size(); ++ j) {
            for (int k = j + 1; k < vec[i].size(); ++ k) {
                int x = min(vec[i][j].v, vec[i][k].v);
                int y = max(vec[i][j].v, vec[i][k].v);
                b[x][y] = min(b[x][y], vec[i][j].w + vec[i][k].w);
                b[y][x] = min(b[y][x], vec[i][j].w + vec[i][k].w);
            }
        }
    }
    for (int k = 1; k <= n; ++ k) {
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
            }
        }
    }
    while (q --) {
        cin >> s >> t;
        ans = 100000000000000000;
        for (int i = 0; i < vec[s].size(); ++ i) {
            for (int j = 0; j < vec[t].size(); ++ j) {
                ans = min(ans, b[vec[s][i].v][vec[t][j].v] + vec[s][i].w + vec[t][j].w);
            }
        }
        cout << ans + a[s] + a[t] << '\n';
    }
    return 0;
}
