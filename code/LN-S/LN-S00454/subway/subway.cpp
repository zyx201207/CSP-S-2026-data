#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define inf 1e18
#define ls (2 * k)
#define rs (2 * k + 1)
using namespace std;
// subway
const int mod = 1e9 + 7;
const int N = 500 + 5, M = 5e5 + 5;
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
mt19937_64 rng(time(0));

int Case, n, m, d, q;
int v[M], dis[N][N];
vector < pair<int, int> > E[M];

inline void solve(){
    cin >> Case >> n >> m >> d >> q;
    for(int i = 1;i <= m; i++) cin >> v[i];
    for(int i = 1, len;i <= n; i++){
        cin >> len;
        for(int j = 1, x, y;j <= len; j++){
            cin >> x >> y;
            E[x].push_back({i, y});
        }
        for(int j = 1;j <= n; j++)
            if(i != j) dis[i][j] = inf;
    }
    for(int i = 1;i <= m; i++){
        int up = (int)E[i].size();
        for(int x = 0;x < up; x++){
            int u = E[i][x].first, w1 = E[i][x].second;
            for(int y = x + 1;y < up; y++){
                int v = E[i][y].first, w2 = E[i][y].second;
                dis[u][v] = min(dis[u][v], w1 + w2);
                dis[v][u] = min(dis[v][u], w1 + w2);
            }
        }
    }
    for(int k = 1;k <= n; k++)
        for(int i = 1;i <= n; i++)
            for(int j = 1;j <= n; j++){
                if(dis[i][k] == inf || dis[k][j] == inf) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
    for(int o = 1, x, y;o <= q; o++){
        cin >> x >> y;
        int ans = inf;
        for(auto u : E[x])
            for(auto v : E[y])
                ans = min(ans, dis[u.first][v.first] + u.second + v.second);
        cout << ans + v[x] + v[y] << "\n";
    }
    return ;
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int tc = 1;
    while(tc--) solve();
    
    return 0;
}