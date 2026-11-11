#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long u64;
typedef long long i64;

u64 c, n, m, d, q, w[500010], k[510], dis[501010];
vector<u64> a[510], t[510];

struct graph {
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

    void dijkstra(u64 s) {
        memset(dis, 0x3f, sizeof dis);
        dis[s] = 0;
        priority_queue<pack> q;
        q.emplace(s, 0);
        while (!q.empty()) {
            pack x = q.top();
            q.pop();
            if (x.d > dis[x.u])
                continue;
            for (u64 j = head[x.u]; j; j = e[j].next)
                if (x.d + e[j].w < dis[e[j].v])
                    dis[e[j].v] = x.d + e[j].w, q.emplace(e[j].v, dis[e[j].v]);
        }
    }
}g;

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
    // freopen("subway.in", "r", stdin);
    // freopen("subway.out", "w", stdout);
    scanf("%llu%llu%llu%llu%llu", &c, &n, &m, &d, &q);
    for (u64 i = 1; i <= m; i++)
        scanf("%llu", &w[i]);
    for (u64 i = 1; i <= n; i++) {
        scanf("%llu", &k[i]);
        a[i].push_back(0);
        t[i].push_back(0);
        for (u64 j = 1, aij, tij; j <= k[i]; j++)
            scanf("%llu%llu", &aij, &tij), a[i].push_back(aij), t[i].push_back(tij);
    }
    for (u64 i = 1; i <= q; i++)
        scanf("%llu%llu", &qs[i].x, &qs[i].y), qs[i].i = i;
    for (u64 i = 1; i <= n; i++)
        for (u64 j = 1; j <= k[i]; j++) {
            g.add(m + i, a[i][j], t[i][j]);
            g.add(a[i][j], m + i, t[i][j]);
        }
    sort(qs + 1, qs + q + 1, cmp1);
    for (u64 i = 1; i <= q;) {
        u64 s = qs[i].x;
        g.dijkstra(s);
        while (i <= q && qs[i].x == s) {
            qs[i].ans = dis[qs[i].y] + w[qs[i].x] + w[qs[i].y];
            i++;
        }
    }
    sort(qs + 1, qs + q + 1, cmp2);
    for (u64 i = 1; i <= q; i++)
        printf("%llu\n", qs[i].ans);
}
