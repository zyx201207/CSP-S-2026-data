#include <bits/stdc++.h>

namespace Solution {
    constexpr int N = 5e5+503;
    constexpr long long inf = 0x7f7f7f7f7f7f7f7f;
    int c, n, m, d, q, w[N];

    std::vector <std::pair <int,int>> g[N];
    void link(int u, int v, int w) { g[u].emplace_back(v,w), g[v].emplace_back(u,w); }

    namespace Subtask8 {
        struct node {
            int u; long long dis;
            node(int u = 0, long long d = 0ll) : u(u), dis(d) {}
            bool operator<(const node& b) const { return dis > b.dis; }
        };
        long long dis[N];
        bool vis[N];
        std::priority_queue <node> Q;
        void Dijkstra(int s) {
            memset(dis,0x7f,sizeof(dis)), memset(vis,0,sizeof(vis));
            dis[s] = 0ll;
            while (Q.size()) Q.pop();
            Q.push(node(s,0ll));
            while (Q.size()) {
                auto A = Q.top(); int u = A.u; long long d = A.dis; Q.pop();
                if (vis[u]) continue;
                vis[u] = 1;
                for (auto A : g[u]) {
                    int v = A.first, w = A.second;
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        Q.push(node(v,dis[v]));
                    }
                }
            }
        }
        void Subtask8() {
            scanf("%d%d%d%d",&n,&m,&d,&q);
            for (int i = 1; i <= m; i++) scanf("%d",&w[i]);
            for (int i = 1, k; i <= n; i++) {
                scanf("%d",&k);
                for (int j = 1, a, t; j <= k; j++) {
                    scanf("%d%d",&a,&t);
                    link(a,m+i,t);
                }
            }
            while (q--) {
                int s, t;
                scanf("%d%d",&s,&t);
                Dijkstra(s);
                printf("%lld\n",dis[t] + w[s] + w[t]);
            }
        }
    }

    namespace Subtask11 {
        void Subtask11() {}
    }

    namespace Subtask19 {
        int dis[N], que[N<<1];
        bool vis[N];
        int bfs(int s, int t) {
            memset(vis,0,sizeof(vis)), memset(dis,0x7f,sizeof(dis));
            int L = 0, R = 0;
            que[R++] = s, dis[s] = 0;
            while (L < R) {
                int u = que[L++];
                if (vis[u]) continue;
                vis[u] = 1;
                if (u == t) return dis[u];
                for (auto A : g[u]) {
                    int v = A.first, w = A.second;
                    if (dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, que[R++] = v;
                }
            }
        }
        void Subtask19() {
            int T = -1;
            scanf("%d%d%d%d",&n,&m,&d,&q);
            for (int i = 1; i <= m; i++) scanf("%d",&w[i]);
            for (int i = 1, k; i <= n; i++) {
                scanf("%d",&k);
                for (int j = 1, a, t; j <= k; j++) {
                    scanf("%d%d",&a,&t);
                    link(a,m+i,t);
                    if (T == -1) T = t;
                }
            }
            while (q--) {
                int s, t;
                scanf("%d%d",&s,&t);
                long long ans = 1ll * bfs(s,t) * T + w[s] + w[t];
                printf("%lld\n",ans);
            }
        }
    }

    namespace Subtask21 {
        long long wg[2][N];
        int bel(int p) {
            if (wg[1][p] != inf && wg[2][p] != inf) return 3;
            else if (wg[1][p] != inf) return 1;
            else return 2;
        }
        void Subtask21() {
            memset(wg,0x7f,sizeof(wg));
            scanf("%d%d%d%d",&n,&m,&d,&q);
            for (int i = 1; i <= m; i++) scanf("%d",&w[i]);
            for (int i = 1, k; i <= n; i++) {
                scanf("%d",&k);
                for (int j = 1, a, t; j <= k; j++) {
                    scanf("%d%d",&a,&t);
                    wg[i][a] = 1ll * t;
                }
            }
            long long mi = inf;
            for (int i = 1; i <= m; i++) if (bel(i) == 3) mi = std::min(mi,wg[1][i]+wg[2][i]);
            while (q--) {
                int s, t;
                scanf("%d%d",&s,&t);
                if (bel(s) == 3 && bel(t) == 3) {
                    long long ans = std::min(wg[1][s]+wg[1][t],wg[2][s]+wg[2][t]) + w[s] + w[t];
                    printf("%lld\n",ans);
                } else if (bel(s) == 3 && bel(t) != 3) {
                    int id = bel(t);
                    long long ans = wg[id][s] + wg[id][t] + w[s] + w[t];
                    printf("%lld\n",ans);
                } else if (bel(s) != 3 && bel(t) == 3) {
                    int id = bel(s);
                    long long ans = wg[id][s] + wg[id][t] + w[s] + w[t];
                    printf("%lld\n",ans);
                } else if (bel(s) == bel(t)) {
                    int id = bel(s);
                    long long ans = wg[id][s] + wg[id][t] + w[s] + w[t];
                    printf("%lld\n",ans);
                } else if (bel(s) != bel(t)) {
                    long long ans = wg[bel(s)][s] + wg[bel(t)][t] + mi + w[s] + w[t];
                    printf("%lld\n",ans);
                }
            }
        }
    }

    void Solve() {
        scanf("%d",&c);
        if (c <= 8) Subtask8::Subtask8();
        else if (c <= 11) Subtask11::Subtask11();
        else if (c <= 19) Subtask19::Subtask19();
        else if (c <= 21) Subtask21::Subtask21();
    }
}

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    Solution::Solve();
}