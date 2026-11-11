#include <algorithm>
#include <cstdio>
#include <vector>

#define gc getchar_unlocked
#define fi first
#define se second
#define pb push_back
#define mod(x) (x -= x >= Q ? Q : 0)

using namespace std;

typedef long long ll;

struct IO {
    IO () {
        freopen("subway.in", "r", stdin);
        freopen("subway.out", "w", stdout);
    }
    ~IO () {
        fclose(stdin);
        fclose(stdout);
    }
} io;

const int N = 505;
const int M = 5e5 + 5;
const ll inf = 1e18 + 7;

struct Edge { int v, w; } ;

int c, n, m, d, q;
int k[N], w[M];
ll f[N][N];
vector < Edge > G[M];

template < typename Tp >
void read (Tp &x) {
    x = 0;
    char c = gc();
    while (c < '0' || c > '9') c = gc();
    while (c <= '9' && c >= '0')
        x = x * 10 + c - '0', c = gc();
}

int main () {
    // zyt
    read(c), read(n), read(m), read(d), read(q);
    for (int i = 1; i <= m; i++) read(w[i]);
    for (int i = 1; i <= n; i++) {
        read(k[i]);
        for (int j = 1; j <= k[i]; j++) {
            int a, t;
            read(a), read(t);
            G[a].pb({ i, t });
        }
        for (int j = 1; j <= n; j++)
            f[i][j] = inf;
        f[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (Edge e1 : G[i]) {
            for (Edge e2 : G[i]) {
                if (e1.v == e2.v) continue;
                f[e1.v][e2.v] = min(f[e1.v][e2.v], (ll)e1.w + e2.w);
                f[e2.v][e1.v] = min(f[e2.v][e1.v], (ll)e1.w + e2.w);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    while (q--) {
        int u, v;
        read(u), read(v);
        ll ans = inf;
        for (Edge e1 : G[u]) {
            for (Edge e2 : G[v]) {
                ans = min(ans, f[e1.v][e2.v] + e1.w + e2.w);
            }
        }
        printf("%lld\n", ans + w[u] + w[v]);
    }
    return 0;
}