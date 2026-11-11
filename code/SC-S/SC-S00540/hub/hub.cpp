#include <bits/stdc++.h>
struct Code {
    Code () {
        freopen ("hub.in", "r", stdin);
        freopen ("hub.out", "w", stdout);
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
const int N = 1e6 + 10;
std::vector <int> e[N];
int c, tid, n, k;
void chk (int &x, int y) { x = min (x, y); }

namespace bf {

const int N = 1e3 + 10;
int f[N][N], dep[N], sz[N], tmp[N], h[N], g[N][N], Tmp[N];
std::vector <int> T[N];
int MN[N];
void dfs (int u, int from) {
    sz[u] = 1, h[u] = 0;
    T[u].clear ();
    T[u].push_back (u);
    f[u][1] = 0, f[u][0] = N;
    g[u][1] = 0, g[u][0] = N;
    rep (i, 2, k) f[u][i] = g[u][i] = N;

    for (int v : e[u]) {
        if (v == from) continue;
        dep[v] = dep[u] + 1; 
        dfs (v, u);
        h[u] = max (h[u], h[v] + 1);

        rep (i, 0, min (sz[u] + sz[v], k)) tmp[i] = N;
        rep (i, 0, min (sz[u], k)) {
            chk (tmp[i], max (f[u][i], h[v] + 1));
            for (int j = 1; j <= sz[v] && i + j <= k; j++)
                chk (tmp[i + j], max ({ f[u][i], f[v][j], 1 }));
        }

        rep (j, 0, sz[v]) {
            MN[j] = N;
            for (int x : T[v])
                chk (MN[j], max (f[x][j], dep[x] - dep[u] >> 1));
        }

        rep (i, 0, min (sz[u] + sz[v], k)) Tmp[i] = N;
        rep (i, 0, min (sz[u], k)) {
            chk (Tmp[i], max (g[u][i], h[v] + 1));
            for (int j = 1; j <= sz[v] && i + j <= k; j++) {
                chk (Tmp[i + j], max ({ g[u][i], g[v][j], 1 }));
                chk (Tmp[i + j], max ( f[u][i], MN[j] ));
            }
        }

        sz[u] += sz[v];
        rep (i, 0, sz[u])
            f[u][i] = tmp[i], g[u][i] = Tmp[i];
    }
}
int dis[N], x, y;
void find (int u, int from) {
    if (dis[u] > dis[x]) x = u;
    for (int v : e[u])
        if (v != from)
            dis[v] = dis[u] + 1, find (v, u);
}
int p[N], tp;
bool get (int u, int from) {
    p[++tp] = u;
    if (u == y) return 1;
    for (int v : e[u])
        if (v != from)
            if (get (v, u))
                return 1;
    tp--;
    return 0;
}
std::priority_queue <int> q, P;
int TOP () {
    while (q.size () && P.size () && q.top() == P.top())
        q.pop (), P.pop();
    return q.size () ? q.top() : 0;
}
int at[N];
void st (int u, int from, int x) {
    at[u] = x;
    for (int v : e[u])
        if (v != from)
            st (v, u, x);
}
void work () {
    rep (i, 1, n)
        rep (j, 0, n)
            f[i][j] = N;
    x = 1;
    dis[1] = 0, find (1, 0);
    y = x;
    dis[x] = 0, find (x, 0);
    tp = 0;

    get (x, 0);
    int rt = p[tp + 1 >> 1];
    dep[rt] = 0, dfs (rt, 0);

    // printf ("rt = %d\n", rt);

    for (int v : e[rt])
        st (v, rt, v);
    int ans = g[rt][k];

    // printf ("ans = %lld\n", ans);

    while (P.size ()) P.pop ();
    while (q.size ()) q.pop ();
    for (int v : e[rt]) q.push (h[v] + 1);
    rep (u, 1, n) {
        rep (v, 1, n) {
            if (u == rt || v == rt) continue;
            P.push (h[at[u]] + 1), P.push (h[at[v]] + 1);
            int MX = TOP ();
            q.push (h[at[u]] + 1), q.push (h[at[v]] + 1);

            // if (u == 2 && v == 4)
            //     printf ("MX = %d\n", MX);

            for (int i = 0; i <= sz[u] && i <= k && k - i <= sz[v]; i++) {
                chk (ans, max ({ f[u][i], f[v][k - i], dep[u] + dep[v] >> 1, MX }));
            }
        }
    }

    printf ("%d\n", ans);
}

}

namespace lian {
    int up (int x, int y) { return (x + y - 1) / y; }
    void work () {
        if (n - k == 1) printf ("1\n");
        else if ((n - k) % 4 <= 1)
            printf ("%d\n", (n - k) / 4);
        else printf ("%d\n", up (n - k, 4));
    }
}
int main () {
    scanf ("%d%d", &c, &tid);
    rep (_, 1, tid) {
        scanf ("%d%d", &n, &k);
        rep (i, 1, n) e[i].clear ();
        rep (i, 1, n - 1) {
            int u, v;
            scanf ("%d%d", &u, &v);
            e[u].push_back (v);
            e[v].push_back (u);
        }
        if (13 <= c && c <= 14) lian::work ();
        else bf::work ();
    }
    return 0;
}