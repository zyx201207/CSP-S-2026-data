// 100pts
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int kMaxN = 505/* 线路数量 */, kMaxM = 5e5 + 5/* 站点数量 */;

int c, n, m, d, q, w[kMaxM], dis[kMaxN][kMaxN];
vector<pair<int, int> > ggbond[kMaxM]; // 去哪个线路，时间多少

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for(int i = 1, k; i <= n; i++) {
        cin >> k;
        while(k--) {
            int a, t;
            cin >> a >> t;
            ggbond[a].push_back({i, t});
        }
    }
    fill(dis[0], dis[n + 1], 1e18);
    for(int i = 1; i <= n; i++) dis[i][i] = 0;
    for(int i = 1; i <= m; i++) {
        for(auto p : ggbond[i]) { // size <= d <= 20
            int u = p.first, t1 = p.second;
            for(auto p2 : ggbond[i]) {
                int v = p2.first, t2 = p2.second;
                dis[u][v] = min(dis[u][v], t1 + t2);
            }
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--) {
        int x, y, res = 1e18;
        cin >> x >> y;
        for(auto p : ggbond[x]) { 
            int u = p.first, t1 = p.second;
            for(auto p2 : ggbond[y]) {
                int v = p2.first, t2 = p2.second;
                res = min(res, dis[u][v] + t1 + t2);
            }
        }
        cout << w[x] + w[y] + res << '\n';
    }
    return 0;
}

// ulimit -s 102400 && g++ -Wall -Wextra -O2 -std=c++14 subway.cpp -o subway && time ./subway