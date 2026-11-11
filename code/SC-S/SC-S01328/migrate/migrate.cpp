#include <bits/stdc++.h>
#define Mem(a,b) memset((a),(b),sizeof((a)))
#define pb push_back
#define eb emplace_back
using i64 = long long;
using uint = unsigned int;
using ui64 = unsigned long long;
using i128 = __int128;
using namespace std;
constexpr int N = 2e6 + 15, mod = 998244353;
constexpr i64 inf = 1e18;

int n;
i64 x[N], d;
int l[N], r[N];
vector<int> g[N];
int deg[N], dd[N], len[N];
i64 cnt[N];

inline void topo(int s) {
    for (int i = 1; i <= n; ++ i) deg[i] = dd[i], len[i] = 1e9;
    queue<int> q;
    cnt[s] = len[s] = 1;
    for (int i = 1; i <= n; ++ i) if (!deg[i]) q.emplace(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!-- deg[v]) q.emplace(v);
            len[v] = min (len[u] + 1, len[v]);
        }
    }
    while (!q.empty()) q.pop();
    for (int i = 1; i <= n; ++ i) deg[i] = dd[i];
    for (int i = 1; i <= n; ++ i) if (!deg[i]) q.emplace(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!-- deg[v]) q.emplace(v);
            if (len[v] == len[u] + 1) cnt[v] += cnt[u];
        }
    }
}

inline void solve () {
    scanf ("%d%lld", &n, &d);
    for (int i = 1; i <= n; ++ i) g[i].clear(), len[i] = dd[i] = deg[i] = cnt[i] = 0;
    for (int i = 1; i <= n; ++ i) scanf ("%lld", &x[i]);
    for (int i = 1; i <= n; ++ i) {
        l[i] = lower_bound (x + 1, x + n + 1, x[i] - d) - x;
        r[i] = upper_bound (x + 1, x + n + 1, x[i] + d) - x - 1;
    }
    for (int i = 1; i <= n; ++ i) {
        for (int j = max(i + 1, l[i]); j <= r[i]; ++ j) {
            g[i].eb(j);
            ++ dd[j];
        }
    }
    i64 ans = 0;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) cnt[j] = 0;
        topo(i);
        // for (int j = 1; j <= n; ++ j) printf ("%lld ", cnt[j]);
        // puts ("");
        for (int j = i + 1; j <= n; ++ j) {
            if (cnt[j] == 2) ++ ans;
        }
    }
    printf ("%lld\n", ans);
}

#define filename "migrate"

int main () {
#ifdef filename
    freopen (filename ".in", "r", stdin);
    freopen (filename ".out", "w", stdout);
#endif
    int c, T_T;
    scanf ("%d%d", &c, &T_T);
    while (T_T --) solve ();
    return 0;
}