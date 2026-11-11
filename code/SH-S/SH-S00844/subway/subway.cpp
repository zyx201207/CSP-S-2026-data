#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 510
#define M 500010
int w[M], k[N], dis[N][N], inf = 1e18;
vector<pair<int, int> >a[N], b[M];
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
    for(int i = 1; i <= m; i++) scanf("%lld", &w[i]);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &k[i]);
        for(int j = 1; j <= k[i]; j++) {
            int x, y; scanf("%lld%lld", &x, &y);
            a[i].push_back({x, y});
            b[x].push_back({i, y});
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) dis[i][j] = inf;
        dis[i][i] = 0;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < b[i].size(); j++) {
            for(int k = j + 1; k < b[i].size(); k++) {
                int a1 = b[i][j].first, a2 = b[i][k].first;
                int t1 = b[i][j].second, t2 = b[i][k].second;
                dis[a1][a2] = min(dis[a1][a2], t1 + t2);
                dis[a2][a1] = min(dis[a2][a1], t1 + t2);
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
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) printf("%lld %lld %lld\n", i, j, dis[i][j]);
    // }
    while(q--) {
        int x, y; scanf("%lld%lld", &x, &y);
        int base = w[x] + w[y], ans = inf;
        for(int i = 0; i < b[x].size(); i++) {
            for(int j = 0; j < b[y].size(); j++) {
                int a1 = b[x][i].first, a2 = b[y][j].first;
                int t1 = b[x][i].second, t2 = b[y][j].second;
                ans = min(ans, base + t1 + t2 + dis[a1][a2]);
                // printf("%lld %lld %lld %lld %lld %lld\n", a1, a2, t1, t2, base, dis[a1][a2]);
            }
        }
        printf("%lld\n", ans);
    }
}