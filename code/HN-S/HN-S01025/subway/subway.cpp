#include <bits/stdc++.h>
#define int long long
using namespace std;
using A2 = array<int, 2>;
ifstream fin("subway.in");
ofstream fout("subway.out");
const int N = 505, M = 5e5 + 5, INF = 1e18;
struct node {
    int id, w;
};
int T, n, m, d, q, a[M], dis[N][N];
vector<node> g[M];
void init() {
    fill(dis[0], dis[n + 1], INF);
    for (int i = 1; i <= n; i++) 
        dis[i][i] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < g[i].size(); j++) 
            for (int k = j + 1; k < g[i].size(); k++) {
                int x = g[i][j].id, y = g[i][k].id, w1 = g[i][j].w, w2 = g[i][k].w;
                dis[x][y] = dis[y][x] = min(dis[x][y], w1 + w2);
            } 
}
void floyd() {
    for (int k = 1; k <= n; k++) 
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) 
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
signed main() {
    fin >> T >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) 
        fin >> a[i]; 
    for (int i = 1, k, x, y; i <= n; i++) {
        fin >> k;
        while (k--) {
            fin >> x >> y; 
            g[x].push_back({i, y});
        }
    }
    init();
    floyd();
    while (q--) {
        int x, y, ans = INF;
        fin >> x >> y;
         for (int i = 0; i < g[x].size(); i++) 
            for (int j = 0; j < g[y].size(); j++) {
                int id1 = g[x][i].id, id2 = g[y][j].id, w1 = g[x][i].w, w2 = g[y][j].w;
                ans = min(ans, a[x] + a[y] + dis[id1][id2] + w1 + w2);
            }
        fout << ans << '\n';
    }
    return 0;
}

/*
背负着火影之名我不能输
luogu UID: 1449703

上善若水，人杰地灵

Rocketcar
*/