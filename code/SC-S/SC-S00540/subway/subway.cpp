#include <bits/stdc++.h>
struct Code {
    Code () {
        freopen ("subway.in", "r", stdin);
        freopen ("subway.out", "w", stdout);
    }
    ~Code () {
        fclose (stdin);
        fclose (stdout);
    }
}code;
#define rep(i,l,r) for (int i = (l); i <= (r); i++)
#define per(i,r,l) for (int i = (r); i >= (l); i--)
#define fpr(x...) fprintf(stderr,x)
using std::min;
using std::max;
typedef long long ll;
const int N = 510, M = 5e5 + 10;
const ll inf = 1e18;
ll d[N][N];
int w[M], n, m, c, D, q;
int a[M], t[M];
struct Node {
    int x, w;
};
std::vector <Node> p[M];
int main () {
    scanf ("%d%d%d%d%d", &c, &n, &m, &D, &q);
    rep (i, 1, m) scanf ("%d", &w[i]);
    rep (i, 1, n) {
        int k;
        scanf ("%d", &k);
        rep (j, 1, k) {
            scanf ("%d%d", &a[j], &t[j]);
            p[a[j]].push_back ({ i, t[j] });
        }
    }
    rep (i, 1, n)
        rep (j, 1, n)
            if (i != j) d[i][j] = inf;
    rep (i, 1, m) {
        for (auto [u, x] : p[i]) {
            for (auto [v, y] : p[i]) {
                d[u][v] = min (d[u][v], (ll) x + y);
            }
        }
    }
    rep (k, 1, n)
        rep (i, 1, n)
            rep (j, 1, n)
                d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
    rep (i, 1, q) {
        int s, t;
        scanf ("%d%d", &s, &t);
        ll ans = inf;
        for (Node x : p[s])
            for (Node y : p[t]) {
                // if (d[x.x][y.x] + w[s] + w[t] + x.w + y.w == 13)
                //     printf ("%d %d  %d %d\n", x.w, y.w, w[s], w[t]);
                ans = min (ans, d[x.x][y.x] + w[s] + w[t] + x.w + y.w);
            }
        printf ("%lld\n", ans);
    }
    return 0;
}