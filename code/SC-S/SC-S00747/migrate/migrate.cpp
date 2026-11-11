#include <cstdio>
#define db(x...) fprintf(stdout, x)
typedef long long ll;
const int N = 2000005;
ll x[N], d;
int n;
int nxt[N];
ll s[N];
int f[N], g[N], h[N];
int cnt[N], cnt2[N];
struct Node {
    int val, cnt, id;
};
Node dl[N];
int head, tail;
int s2[N];
void solve() {
    scanf("%d%lld", &n, &d);
    for(int i = 1; i <= n; i++) scanf("%lld", &x[i]);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        f[i] = g[i] = h[i] = 0;
        cnt[i] = 0;
        cnt2[i] = 1;
        s[i] = 0;
        s2[i] = 0;
    }
    nxt[n] = n;
    for(int i = n - 1; i >= 1; i--) {
        nxt[i] = nxt[i + 1];
        while(x[nxt[i]] - x[i] > d) nxt[i]--;
        // db("%d : %d\n", i, nxt[i]);
    }
    if(n <= 5000) {
        for(int i = n; i >= 1; i--) {
            head = 1, tail = 0;
            dl[++tail] = {0, 1, i};
            for(int j = i - 1; j >= 1; j--) {
                if(nxt[j] == j) break;
                while(head <= tail && dl[head].id > nxt[j]) head++;
                int f = dl[head].val + 1;
                int g = dl[head].cnt;
                for(int k = 1; k <= 2; k++) {
                    if(head + k <= tail && dl[head + k].val == dl[head].val) g += dl[head + k].cnt;
                }
                // db("%d %d %d  %d %d\n", i, j, f, dl[head].id, nxt[j]);
                if(g == 2) ans++;//, db("%d %d\n", j, i);
                if(g > 2) g = 3;
                dl[++tail] = {f, g, j};
                // for(int k = head; k <= tail; k++) db("(%d %d %d) ", dl[k].val, dl[k].cnt, dl[k].id);
                // db("\n");
            }
        }
        printf("%lld\n", ans);
        return ;
    }
    for(int i = 1; i <= n; i++) {
        if(nxt[i] == i || nxt[i] == i + 1) continue;
        if(nxt[nxt[i]] == nxt[nxt[i] - 1] && nxt[nxt[i]] != nxt[nxt[i] - 2]) {
            f[i] = nxt[nxt[i]];
            s2[nxt[i]]++;
            s2[nxt[i] - 1]++;
            // db("%d %d\n", i, f[i]);
        }
    }
    for(int i = n; i >= 1; i--) {
        if(f[i]) {
            g[i] = i;
            h[i] = nxt[i] - i + 1;
        } else g[i] = g[nxt[i]], h[i] = h[nxt[i]] + (s2[i] == 0);
        if(g[i] && s2[i] == 0) {
            cnt[g[i]]++;
            // db("%d -> %d\n", i, g[i]);
        }
    }
    // db("%d\n", f[5]);
    for(int i = 1, j; i <= n; i = j + 1) {
        j = i;
        if(!f[i]) continue;
        int k = f[i];
        j = nxt[i] - 1;
        int lst = i;
        // int th = 1, tth = f[i];
        int tcnt = cnt[i];
        for(int t = i + 1; t <= k; t++) {
            if(!f[t]) continue;
            j = nxt[t] - 1;
            k = f[t];
            if(f[lst] != f[t]) ans += tcnt, tcnt = 0;
            tcnt += cnt[t];
            lst = t;
            // th = 1, tth = f[t];
        }
        ans += (ll)tcnt * h[k];
        // db("%d %d %d : %lld  %d %d\n", i, j, k, (ll)tcnt * h[k], tcnt, h[k]);
    }
    for(int i = 1; i <= n; i++) {
        if(f[i]) {
        } else cnt2[nxt[i]] += cnt2[i];
    }
    // db("asdf %lld\n", ans);
    for(int i = 1; i <= n; i++) {
        if(nxt[i] == i || nxt[i] == i + 1) continue;
        if(nxt[nxt[i]] == nxt[nxt[i] - 1] && nxt[nxt[i]] != nxt[nxt[i] - 2]) {
            s[nxt[nxt[i] - 2] + 1] += cnt2[i];
            s[nxt[nxt[i] - 1]] -= cnt2[i];
        } else {
            s[nxt[nxt[i] - 2] + 1] += cnt2[i];
            s[nxt[nxt[i] - 1] + 1] -= cnt2[i];
        }
    }
    for(int i = 1; i <= n; i++) {
        s[i] += s[i - 1];
        ans += s[i];
        // db("%d : %lld\n", i, s[i]);
    }
    printf("%lld\n", ans);
}
int main() {
    // xyy
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    scanf("%d%d", &c, &T);
    while(T--) solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}