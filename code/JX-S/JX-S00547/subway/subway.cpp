#include<bits/stdc++.h>
#define int long long
using namespace std;
int C, n, m, d, q, W[500005], f[505][505], c[505][505], v[505];
struct S{
    int t, w;
};
vector<S > s[500005], g[505];
void dj(int sx){
    for (int i = 1; i <= n; i ++) f[sx][i] = 0x3f3f3f3f3f3f3f3f, v[i] = 0;
    f[sx][sx] = 0;
    priority_queue<pair<int, int > > q;
    q.push({0, sx});
    while (!q.empty()){
        int x = q.top().second;
        q.pop();
        if (v[x]) continue;
        v[x] = 1;
        for (int i = 0; i < g[x].size(); i ++){
            int y = g[x][i].t, w = g[x][i].w;
            if (f[sx][y] > f[sx][x] + w){
                f[sx][y] = f[sx][x] + w;
                q.push({-f[sx][y], y});
            }
        }
    }
}
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    cin >> C >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++){
        cin >> W[i];
    }
    for (int i = 1; i <= n; i ++){
        int k;
        cin >> k;
        for (int j = 1; j <= k; j ++){
            int a, t;
            cin >> a >> t;
            s[a].push_back({i, t});
        }
    }
    memset(c, 0x3f, sizeof c);
    for (int i = 1; i <= m; i ++){
        for (int j = 0; j < s[i].size(); j ++){
            for (int k = j + 1; k < s[i].size(); k ++){
                int x = s[i][j].t, wx = s[i][j].w;
                int y = s[i][k].t, wy = s[i][k].w;
                c[x][y] = c[y][x] = min(c[x][y], wx + wy);
            }
        }
    }
    for (int i = 1; i <= n; i ++){
        for (int j = i; j <= n; j ++){
            if (c[i][j] != 0x3f3f3f3f3f3f3f3f){
                g[i].push_back({j, c[i][j]});
                g[j].push_back({i, c[i][j]});
            }
        }
    }
    for (int i = 1; i <= n; i ++){
        dj(i);
    }
    while (q --){
        int x, y, ans = 1e18;
        cin >> x >> y;
        for (int i = 0; i < s[x].size(); i ++){
            for (int j = 0; j < s[y].size(); j ++){
                int u = s[x][i].t, wx = s[x][i].w;
                int v = s[y][j].t, wy = s[y][j].w;
                ans = min(ans, wx + wy + f[u][v]);
            }
        }
        cout << ans + W[x] + W[y] << '\n';
    }

    return 0;
}
