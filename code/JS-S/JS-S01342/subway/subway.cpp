#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <bitset>

using ll=long long;

constexpr int maxn=505, maxm=5e5+10, maxsumk=5e5+10;

struct {
    int to;
    ll w;
    int nxt;
} edges[maxsumk<<1];

int head[maxn+maxm], tot;

void add(int u, int v, ll w) {
    edges[++tot]={v, w, head[u]};
    head[u]=tot;
}

#define subway(i) m+i

int n, m, tmp, d, q;

ll w[maxm];

ll to[maxn][maxn];

ll dis[maxn][maxn];

void Dijkstra(ll *dis, int start) {
    std::memset(dis, 0x7f, sizeof(::dis[0]));
    dis[start]=0;
    std::bitset<maxn> vis;
    std::priority_queue<std::pair<ll, int> > q;
    q.push({0, start});
    while(!q.empty()) {
        int u=q.top().second; q.pop();
        if(vis[u]) continue;
        vis.set(u);
        for(int v=1; v<=n; v++) {
            if(dis[v] > dis[u]+to[u][v]) {
                q.push({-(dis[v]=dis[u]+to[u][v]), v});
            }
        }
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> tmp >> n >> m >> d >> q;
    for(int i=1; i<=m; i++) std::cin >> w[i];
    for(int i=1; i<=n; i++) {
        int k; std::cin >> k;
        for(ll a, t; k--; ) {
            std::cin >> a >> t;
            add(subway(i), a, t);
            add(a, subway(i), t);
        }
    }
    std::memset(to, 0x3f, sizeof to);
    for(int i=1; i<=n; i++) to[i][i]=0;
    for(int i=1; i<=m; i++) {
        for(int u, j=head[i]; j; j=edges[j].nxt) {
            u=edges[j].to-m;
            for(int v, k=head[i]; k; k=edges[k].nxt) {
                v=edges[k].to-m;
                to[u][v]=std::min(to[u][v], edges[j].w+edges[k].w);
            }
        }
    }
    // for(int i=1; i<=n; i++) Dijkstra(dis[i], i);
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) to[i][j]=std::min(to[i][j], to[i][k]+to[k][j]);
        }
    }
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=n; j++) std::cout << dis[i][j] << ' ';
    //     std::cout << '\n';
    // }
    for(int x, y; q--; ) {
        std::cin >> x >> y;
        ll ans=1e18;
        for(int v, i=head[x]; i; i=edges[i].nxt) {
            v=edges[i].to-m;
            for(int u, j=head[y]; j; j=edges[j].nxt) {
                u=edges[j].to-m;
                ans=std::min(ans, to[u][v]+edges[i].w+edges[j].w);
            }
        }
        std::cout << ans+w[x]+w[y] << '\n';
    }
}
