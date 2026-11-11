#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template<typename T>
bool chmin(T &a, const T &b) {
    return a > b ? a = b, true : false;
}
constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;
struct Edge {
    int v;
    i64 w;
};
constexpr int N = 500;
i64 f[N+5][N+5];
signed main() {
    // !!!!!!!!!
    freopen("subway.in", "r", stdin); //!!!!!!!!
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<int> w(m+1);
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    vector<vector<Edge>> g(n+1); // g[xian] ting
    vector<vector<Edge>> tg(m+1); // g[ting] xian
    //cerr << "aaaa\n";
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        g[i].reserve(k);
        for (int j = 1; j <= k; j++) {
            int v; i64 w;
            cin >> v >> w;
            g[i].push_back({v, w});
            tg[v].push_back({i, w});
        }
        //cerr << i << '\n';
        sort(g[i].begin(), g[i].end(), [](Edge a, Edge b) {
            return a.v < b.v;
        });
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            int ii = 0, jj = 0; i64 dis = INF;
#define GOOD (ii < g[i].size() && jj < g[j].size())
#define I g[i][ii]
#define J g[j][jj]
            while (true) {
                while (GOOD && I.v < J.v) ii++;
                while (GOOD && I.v > J.v) jj++;
                if (!GOOD) break;
                if (I.v != J.v) continue;
                chmin(dis, I.w + J.w);
                ii++, jj++;
            }
            f[i][j] = f[j][i] = dis;
            //if (dis != INF) cerr << i << ' ' << j << ' ' << dis << '\n';
        }
    }
    //cerr << "floyd\n";
    //memset(f, 0x3f, sizeof f);
    //for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                chmin(f[i][j], f[i][k] + f[k][j]);
    //for (int i = 1; i <= n; i++)
    //    for (int j = 1; j <= n; j++)
    //        //assert(f[i][j] == f[j][i]);
    //        cerr << i << ' ' << j << ' ' << f[i][j] << ' ' << f[j][i] << '\n';
    while (q--) {
        int x, y; cin >> x >> y;
        i64 ans = INF;
        for (Edge zx : tg[x]) {
            for (Edge zy : tg[y]) {
                //assert(f[zx.v][zy.v] == f[zy.v][zx.v]);
                chmin(ans, f[zx.v][zy.v] + zx.w + zy.w);
            }
        }
        //assert(ans != INF);
        cout << ans + w[x] + w[y] << '\n';
    }
}
