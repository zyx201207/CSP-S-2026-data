#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M = 5e5 + 10, N = 1005;
struct node {
    int id, w;
};
int c, n, m, d, q;
int w[M], dis[N][N];
vector<node>e[N], pos[N];
signed main() {
    freopen("subway.in", "r", stdin);//44 pts
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) {
        cin >> w[i];
    }
    for (int i = 1; i <= m + n; ++i) {
        for (int j = 1; j <= m + n; ++j) {
            dis[i][j] = 1e18;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int id, t;
            cin >> id >> t;
            dis[i + m][id] = dis[id][i + m] = min(dis[i + m][id], t);
        }       
    }
    for (int k = 1; k <= m + n; ++k) {
        for (int i = 1; i <= m + n; ++i) {
            for (int j = 1; j <= m + n; ++j) {
                dis[j][i] = dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        int ans = w[x] + w[y];
        cout << dis[x][y] + ans << '\n';
    }
    return 0;
}
