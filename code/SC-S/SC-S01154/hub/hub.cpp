#include <bits/stdc++.h>

using namespace std;
long long c, T, n, K;
const long long INF = 1e18;
const long long N = 2e6 + 10;
vector<long long> a[N];
long long cs[N], to[N];
void find(long long x, long long f) {
    to[x] = 1;
    for(long long v : a[x]) {
        if(v == f || cs[v] == 0) continue;
        find(v, x);
    }
}
long long len[N];
void fb(long long x, long long f) {
    for(long long v : a[x]) {
        if(v == f || cs[v]) continue;
        fb(v, x); len[x] = max(len[x], len[v]);
    }
    len[x] = len[x] + 1; return;
}
long long ans = INF;
void dfs(long long x) {
    if(x > n) {
        long long siz = 0;
        for(long long i = 1; i <= n; i++) siz = siz + cs[i];
        // cerr << siz << " " << K << "\n";
        if(siz != K) return;
        for(long long i = 1; i <= n; i++) to[i] = 0;
        long long cnt = 0;
        for(long long i = 1; i <= n; i++) {
            if(!to[i] && cs[i]) find(i, 0), cnt++;
        }
        // cerr << cnt << "\n";
        if(cnt > 2) return;
        long long maxn = 0;
        for(long long i = 1; i <= n; i++) {
            for(long long i = 1; i <= n; i++) len[i] = 0;
            if(cs[i]) {
                fb(i, 0), maxn = max(maxn, len[i] - 1);
                // if(cs[2] && cs[4]) {
                //     printf("%d %d\n", i, len[i]);
                // }
            }
        }
        // if(maxn == 1) {
        //     for(int i = 1; i <= n; i++) printf("%d ", cs[i]);
        //     printf("\n");
        // }
        ans = min(ans, maxn); return;
    }
    cs[x] = 1; dfs(x + 1);
    cs[x] = 0; dfs(x + 1);
}
void work() {
    scanf("%lld%lld", &n, &K);
    for(long long i = 1; i <= n; i++) a[i].clear();
    for(long long i = 1; i < n; i++) {
        long long u, v; scanf("%lld%lld", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    ans = INF;
    dfs(1); printf("%lld\n", ans);
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%lld%lld", &c, &T);
    while(T--) work();
}