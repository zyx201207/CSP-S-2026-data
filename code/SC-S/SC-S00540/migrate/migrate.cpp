#include <bits/stdc++.h>
#define int long long
struct Code {
    Code () {
        freopen ("migrate.in", "r", stdin);
        freopen ("migrate.out", "w", stdout);
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
const int N = 2e6 + 10, inf = 2e18;
int p[N], tp;
int c, T, n, d, x[N];
int cnt[N], D[N], sd[N];
// namespace bf {
//     struct 
// }
int chk (int u, int v) { return x[v] - x[u] <= d; }
signed main () {
    scanf ("%lld%lld", &c, &T);
    while (T--) {
        scanf ("%lld%lld", &n, &d);
        rep (i, 1, n) scanf ("%lld", &x[i]);
        if (11 <= c && c <= 12) {
            int M = d / (x[2] - x[1]);
            if (!M) printf ("0\n");
            else printf ("%lld\n", max (0ll, n - 2 * M + 1));
            continue;    
        }
        x[n + 1] = inf;
        int ans = 0;
        rep (s, 1, n) {
            tp = 0;
            p[++tp] = s, D[tp] = x[s], sd[tp] = -inf;
            int V = 0;
            rep (i, s + 1, n) {
                if (x[i] - x[i - 1] > d) {
                    V = i;
                    break;
                } 
                if (x[i + 1] - x[p[tp]] > d) {
                    p[++tp] = i, D[tp] = x[i], sd[tp] = -inf;
                } else sd[tp] = D[tp], D[tp] = x[i];
            }
            if (!V) p[tp + 1] = n + 1;
            else p[tp + 1] = V;
            // if (s == 1) {
            //     printf ("p = %lld\n", p[tp + 1]);
            //     rep (i, 1, tp) printf ("%lld ", p[i]);
            //     printf ("\n");
            // }
            rep (i, s, n) cnt[i] = 0;
            rep (i, 3, tp) {
                if (x[p[i]] - D[i - 2] <= d && x[p[i]] - sd[i - 2] <= d) {
                    cnt[p[i]] = 2;
                } else if (x[p[i]] - D[i - 2] <= d) cnt[p[i]]++;
            }
            rep (i, 1, tp) cnt[p[i]] += cnt[p[i - 1]];
            rep (i, 1, tp)
                rep (j, p[i] + 1, p[i + 1] - 1)
                    cnt[j] = cnt[p[i]];
            rep (i, 2, tp) {
                rep (u, p[i] + 1, p[i + 1] - 1) {
                    if (x[u] - D[i - 1] <= d && x[u] - sd[i - 1] <= d)
                        cnt[u] += 2;
                    else if (x[u] - D[i - 1] <= d) cnt[u]++;
                }
            }
            // if (s == 1) {
            //     rep (i, 1, tp) printf ("%lld ", p[i]);
            //     printf ("\n");
            //     rep (i, 1, n) printf ("%lld ", cnt[i]);
            //     printf ("\n");
            // }
            rep (i, s, n)
                if (cnt[i] == 1)
                    ans++;
        }
        printf ("%lld\n", ans);
    }
    return 0;
}