#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 510, M = 5e5 + 10;
int C, Q, D, n, m, f[N][N], w[M];
struct Node {
    int v, w;
};
vector<Node> e[M];
void Floyd() {
    for (int i = 1;i <= n;i ++) f[i][i] = 0;
    for (int k = 1;k <= n;k ++) {
        for (int i = 1;i <= n;i ++) {
            for (int j = 1;j <= n;j ++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
    memset(f, 0x3f, sizeof f);
    cin >> C >> n >> m >> D >> Q;
    for (int i = 1;i <= m;i ++) cin >> w[i];
    int x, y, z;
    for (int i = 1;i <= n;i ++) {
        cin >> z;
        while (z --) {
            cin >> x >> y;
            e[x].push_back({i, y});
        }
    } 
    for (int t = 1;t <= m;t ++) {
        for (int i = 0;i < e[t].size();i ++) {
            x = e[t][i].v;
            for (int j = i + 1;j < e[t].size();j ++) {
                y = e[t][j].v;
                f[x][y] = f[y][x] = min(f[x][y], e[t][i].w + e[t][j].w);
            }
        }
    }
    Floyd(); int s, t;
    while (Q --) {
        cin >> s >> t; int ans = f[0][0];
        for (int i = 0;i < e[s].size();i ++) {
            x = e[s][i].v;
            for (int j = 0;j < e[t].size();j ++) {
                y = e[t][j].v;
                ans = min(ans, f[x][y] + e[s][i].w + e[t][j].w + w[s] + w[t]);
            }
        } cout << ans << "\n";
    }
}