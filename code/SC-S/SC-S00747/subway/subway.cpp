#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long ll;
namespace fio {
    #define SZ (1 << 20)
    char in[SZ];
    int pin = SZ;
    char gc() {
        if(pin == SZ) fread(in, SZ, sizeof(char), stdin), pin = 0;
        return in[pin++];
    }
    void read(int &x) {
        x = 0;
        char t;
        while((t = gc()) < '0') ;
        while(t >= '0') {
            x = (x << 1) + (x << 3) + t - '0';
            t = gc();
        }
    }
    void read(ll &x) {
        x = 0;
        char t;
        while((t = gc()) < '0') ;
        while(t >= '0') {
            x = (x << 1) + (x << 3) + t - '0';
            t = gc();
        }
    }
}
using fio::read;
const int N = 505, M = 500005, D = 25;
const ll INF = 1000000000000000000;
struct Edge1 {
    int v;
    ll w;
};
Edge1 e[M][D];
int cnt[M];
ll w[M];
ll dis[N][N];
int c, n, m, d, q;
int main() {
    // xyy
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    read(c);
    read(n);
    read(m);
    read(d);
    read(q);
    for(int i = 1; i <= m; i++) read(w[i]);
    for(int i = 1; i <= n; i++) {
        int k;
        read(k);
        for(int j = 1; j <= k; j++) {
            int a;
            ll t;
            read(a);
            read(t);
            e[a][++cnt[a]] = {i, t};
            // e[a].emplace_back((Edge1){i, t});
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= cnt[i]; j++) {
            Edge1 x = e[i][j];
            for(int k = j + 1; k <= cnt[i]; k++) {
                Edge1 y = e[i][k];
                dis[x.v][y.v] = std::min(dis[x.v][y.v], x.w + y.w);
                dis[y.v][x.v] = std::min(dis[y.v][x.v], x.w + y.w);
            }
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--) {
        int u, v;
        read(u);
        read(v);
        ll ans = INF;
        for(int j = 1; j <= cnt[u]; j++) {
            Edge1 x = e[u][j];
            for(int k = 1; k <= cnt[v]; k++) {
                Edge1 y = e[v][k];
                ans = std::min(ans, dis[x.v][y.v] + x.w + y.w);
            }
        }
        printf("%lld\n", ans + w[u] + w[v]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}