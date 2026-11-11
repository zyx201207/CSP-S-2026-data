#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 500 + 10, M = 5e5 + 10;

int C, n, m, d, q;
LL w[M], dis[N][N];
struct Sub {
    int id; LL t;
};
vector<Sub> sub[M];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> C >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while(k--) {
            int a; LL t;
            cin >> a >> t;
            sub[a].push_back({i, t});
        }
    }
    for(int i = 1; i <= n; i++) memset(dis[i], 0x3f, sizeof dis[i]);
    for(int i = 1; i <= m; i++)
        for(Sub x : sub[i]) for(Sub y : sub[i])
            dis[x.id][y.id] = dis[y.id][x.id] = min(dis[x.id][y.id], x.t + y.t);
    for(int i = 1; i <= n; i++) dis[i][i] = 0;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while(q--) {
        int a, b;
        cin >> a >> b;
        LL res = 1e18;
        for(Sub x : sub[a]) for(Sub y : sub[b])
            res = min(res, dis[x.id][y.id] + x.t + w[a] + y.t + w[b]);
        cout << res << "\n";
    }
    return 0;
}