#include <bits/stdc++.h>
#define int long long
#define Pii pair<int, int>
#define Fr first
#define Sc second
#define lowbit(x) (x & (-x))

using namespace std;

const int kMaxN = 5e5 + 5, kMaxM = 505, INF = 1e18;

int n, m, D, q; //n线路数 m站台数 
int w[kMaxN];
int dis[kMaxM][kMaxM];
vector<Pii> G[kMaxN], E[kMaxN];

void solve() {
    cin >> n >> m >> D >> q;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j) dis[i][j] = INF;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        for (int j = 1; j <= x; j++) {
            int a, b; cin >> a >> b;
            E[j].push_back({a, b});
            G[a].push_back({i, b});
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            for (int k = j + 1; k < G[i].size(); k++) {
                int x = G[i][j].Fr, y = G[i][k].Fr, w = G[i][j].Sc + G[i][k].Sc;
                dis[x][y] = dis[y][x] = min(dis[x][y], w);
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
    for (int t = 1; t <= q; t++) {
        int a, b, ans = INF; cin >> a >> b;
        for (int i = 0; i < G[a].size(); i++) {
            for (int j = 0; j < G[b].size(); j++) {
                int x = G[a][i].Fr, y = G[b][j].Fr, w = G[a][i].Sc + G[b][j].Sc;
                ans = min(ans, w + dis[x][y]);
            }
        }
        cout << ans + w[a] + w[b] << '\n';
    }
}

signed main() {
    ios:: sync_with_stdio(0), cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int T = 1;
    cin >> T;
    solve();
    return 0;
}
/*
ulimit -s 1024000 && cd "/home/noilinux/HN-S01000/subway" && g++ subway.cpp -o subway -Wall -O2 && ./subway 
*/