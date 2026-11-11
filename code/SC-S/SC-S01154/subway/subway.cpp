#include <bits/stdc++.h>

using namespace std;
long long c, n, m, d, q;
const long long INF = 1e18;
const long long N = 505, M = 5e5 + 10;
long long val[M];
struct Node { long long to, val; };
vector<Node> hv[M];
long long cro[N];
vector<Node> sub[N];
long long ed[N][N];
long long dis[N][N], vis[N];
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
    for(long long i = 1; i <= m; i++) scanf("%lld", &val[i]);
    for(long long i = 1; i <= n; i++) {
        scanf("%lld", &cro[i]);
        for(long long j = 1; j <= cro[i]; j++) {
            long long pl, w; scanf("%lld%lld", &pl, &w);
            hv[pl].push_back({i, w});
            sub[i].push_back({pl, w});
        }
    }
    for(long long i = 1; i <= n; i++)
        for(long long j = 1; j <= n; j++)
            ed[i][j] = INF;
    for(long long i = 1; i <= n; i++) {
        for(auto [v, w] : sub[i]) {
            for(auto [tos, ws] : hv[v]) {
                if(i == tos) continue;
                ed[i][tos] = min(ed[i][tos], w + ws);
                ed[tos][i] = min(ed[tos][i], w + ws);
            }
        }
    }
    for(long long s = 1; s <= n; s++) {
        for(long long i = 0; i <= n; i++)
            dis[s][i] = INF, vis[i] = 0;
        dis[s][s] = 0;
        while(1) {
            long long u = 0;
            for(long long i = 1; i <= n; i++)
                if(dis[s][i] < dis[s][u] && !vis[i]) u = i;
            if(!u) break;
            vis[u] = 1;
            for(long long i = 1; i <= n; i++) {
                if(i == u) continue;
                if(dis[s][i] > dis[s][u] + ed[u][i])
                    dis[s][i] = dis[s][u] + ed[u][i];
            }
        }
    }
    while(q--) {
        long long s, t; scanf("%lld%lld", &s, &t);
        long long ans = INF;
        for(auto [u, ws] : hv[s])
            for(auto [v, wt] : hv[t])
                ans = min(ans, ws + wt + dis[u][v]);
        printf("%lld\n", ans + val[s] + val[t]);
    }
}
//for p