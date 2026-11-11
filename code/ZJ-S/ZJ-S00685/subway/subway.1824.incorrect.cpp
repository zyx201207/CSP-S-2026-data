#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long u64;
typedef long long i64;

u64 c, n, m, d, q, w[500010], k[510], dis[501010];
vector<u64> a[510], t[510];
vector<pair<u64, u64>> lns[500010];
bitset<501010> FF;

/*struct graph {
    u64 ecnt, head[501010];
    
    struct edge {
        u64 v, w, next;
    }e[500010 * 2];

    struct pack {
        u64 u, d;

        pack(u64 u, u64 d): u(u), d(d) {}

        bool operator<(const pack &other) const {
            return d > other.d;
        }
    };

    void add(u64 u, u64 v, u64 w) {
        // fprintf(stderr, "added edge %llu -> %llu weight %llu\n", u, v, w);
        ecnt++;
        e[ecnt] = {v, w, head[u]};
        head[u] = ecnt;
    }

    void dijkstra(u64 s, u64 tcnt) {
        memset(dis, 0x3f, sizeof dis);
        dis[s] = 0;
        priority_queue<pack> q;
        q.emplace(s, 0);
        while (!q.empty() && tcnt) {
            pack x = q.top();
            q.pop();
            if (x.d > dis[x.u])
                continue;
            if (FF[x.u])
                tcnt--, FF[x.u] = false;
            for (u64 j = head[x.u]; j; j = e[j].next)
                if (x.d + e[j].w < dis[e[j].v])
                    dis[e[j].v] = x.d + e[j].w, q.emplace(e[j].v, dis[e[j].v]);
        }
    }
}g;*/

u64 GG[510][510];

struct question {
    u64 x, y, i, ans;
}qs[100010];

bool cmp1(const question &lhs, const question &rhs) {
    return lhs.x < rhs.x;
}

bool cmp2(const question &lhs, const question &rhs) {
    return lhs.i < rhs.i;
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%llu%llu%llu%llu%llu", &c, &n, &m, &d, &q);
    for (u64 i = 1; i <= m; i++)
        scanf("%llu", &w[i]);
    /*u64 TTT = 0;
    bool is_B = true;*/
    for (u64 i = 1; i <= n; i++) {
        scanf("%llu", &k[i]);
        a[i].push_back(0);
        t[i].push_back(0);
        for (u64 j = 1, aij, tij; j <= k[i]; j++)
            scanf("%llu%llu", &aij, &tij) /*, (TTT && (tij == TTT || (is_B = false, true)) || (TTT = tij, true)) */, a[i].push_back(aij), t[i].push_back(tij);
    }
    // fprintf(stderr, "%s", is_B ? "detected special B\n" : "nothing\n");
    for (u64 i = 1; i <= q; i++)
        scanf("%llu%llu", &qs[i].x, &qs[i].y), qs[i].i = i;
    for (u64 i = 1; i <= n; i++)
        for (u64 j = 1; j <= k[i]; j++) {
//            g.add(m + i, a[i][j], t[i][j]);
//            g.add(a[i][j], m + i, t[i][j]);
            lns[a[i][j]].emplace_back(i, t[i][j]);
        }
    memset(GG, 0x3f, sizeof GG);
    for (u64 i = 1; i <= n; i++)
        GG[i][i] = 0;
    for (u64 i = 1; i <= m; i++)
        for (u64 j = 0; j < lns[i].size(); j++)
            for (u64 k = j + 1; k < lns[i].size(); k++) {
                u64 tu = lns[i][j].first;
                u64 tv = lns[i][k].first;
                u64 tw = lns[i][j].second + lns[i][k].second;
                GG[tu][tv] = min(GG[tu][tv], tw);
                GG[tv][tu] = min(GG[tv][tu], tw);
            }
    for (u64 k = 1; k <= n; k++)
        for (u64 i = 1; i <= n; i++)
            for (u64 j = 1; j <= n; j++)
                GG[i][j] = min(GG[i][j], GG[i][k] + GG[k][j]);
    sort(qs + 1, qs + q + 1, cmp1);
    for (u64 i = 1; i <= q;) {
        u64 s = qs[i].x;
        /*u64 i2 = i;
        // FF.reset();
        while (i2 <= q && qs[i2].x == s) {
            FF[qs[i2].y] = true;
            i2++;
        }
        g.dijkstra(s, i2 - i);*/
        while (i <= q && qs[i].x == s) {
            // qs[i].ans = dis[qs[i].y] + w[qs[i].x] + w[qs[i].y];
            qs[i].ans = 0x3f3f3f3f3f3f3f3full;
            for (auto SS: lns[s])
                for (auto TT: lns[qs[i].y])
                    qs[i].ans = min(qs[i].ans, GG[SS.first][TT.first] + w[qs[i].x] + w[qs[i].y]);
            i++;
        }
    }
    sort(qs + 1, qs + q + 1, cmp2);
    for (u64 i = 1; i <= q; i++)
        printf("%llu\n", qs[i].ans);
}
