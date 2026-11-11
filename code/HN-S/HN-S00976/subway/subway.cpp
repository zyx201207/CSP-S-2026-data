#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int M = 505;
const int N = 5e5 + 5;
int T, n, m, d, x, y, k, Q, tot, ans;
int w[N], dis[M][M];
struct Node {
    int v, w;
} ;
vector<Node> g[N];

inline void Floyd() {
    for(int k = 1 ; k <= n ; ++ k)
        for(int i = 1 ; i <= n ; ++ i)
            for(int j = 1 ; j <= n ; ++ j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    return ;
}

signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios_base :: sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T >> n >> m >> d >> Q;
    for(int i = 1 ; i <= m ; ++ i)
        cin >> w[i];
    for(int i = 1 ; i <= n ; ++ i) {
        cin >> tot;

        for(int j = 1 ; j <= tot ; ++ j) {
            cin >> x >> k;
            g[x].pb({i, k});
        }
    }

    // for(int i = 1 ; i <= m ; ++ i) {
    //     for(auto [x, w] : g[i])
    //         cerr << i << ' ' << x << ' ' << w << '\n';
    // }

    for(int i = 1 ; i <= n ; ++ i)
        for(int j = 1 ; j <= n ; ++ j)
            if(i != j) dis[i][j] = 1e18;

    for(int i = 1 ; i <= m ; ++ i) {
        for(int j = 0 ; j < (int)g[i].size() ; ++ j) {
            for(int k = j + 1 ; k <= (int)g[i].size() ; ++ k) {
                auto [x, w1] = g[i][j];
                auto [y, w2] = g[i][k];
                dis[x][y] = min(dis[x][y], w1 + w2);
                dis[y][x] = min(dis[y][x], w1 + w2);
            }
        }
    }

    Floyd();

    // for(int i = 1 ; i <= m ; ++ i) {
    //     for(auto [x, w] : g[i])
    //         cerr << i << ' ' << x << ' ' << w << '\n';
    // }

    // cerr << '\n';

    // for(int i = 1 ; i <= n ; ++ i) {
    //     for(int j = 1 ; j <= n ; ++ j) {
    //         cerr << i << ' ' << j << ' ' << dis[i][j] << '\n';
    //     }
    //     // cerr << '\n';
    // }

    while(Q --) {
        cin >> x >> y;

        ans = 1e18;

        for(auto [i, w1] : g[x])
            for(auto [j, w2] : g[y])
                ans = min(ans, w1 + w2 + dis[i][j]);

        cout << ans + w[x] + w[y] << '\n';
    }

    return 0;
}