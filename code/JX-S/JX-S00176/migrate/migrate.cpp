#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
using namespace std;
const int N = 2e6 + 5;
bool vis[N];
ll ans, d, x[N];
vector<int> vec[N];
int c, T, n, f[N], pre[N], cnt[N];
inline int find1 (int i) {
    int l = i, r = n, mid, res = i;
    while (l <= r) {
        mid = l + r >> 1;
        if (x[mid] - x[i] <= d) res = mid, l = mid + 1;
        else r = mid - 1;
    }
    return res;
}
inline int find2 (int i) {
    int l = 1, r = i, mid, res = i;
      while (l <= r) {
        mid = l + r >> 1;
        if (x[i] - x[mid] <= d) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    return res;  
}
int main () {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while (T--) {
        scanf("%d%lld", &n, &d), ans = 0;
        FOR(i, 1, n) scanf("%lld", &x[i]), cnt[i] = 1, vis[i] = 0;
        FOR(i, 1, n) f[i] = find1(i), pre[i] = find2(i), vec[i].clear();
        FOR(i, 1, n) if (i != pre[i]) vec[pre[i]].push_back(i);
        for (int i = n; i; i--) if (f[i] != i) cnt[i] += cnt[f[i]];
        for (int i = 1, now, to, tot; i <= n; i++) if (!vis[i]) {
            now = i, to = f[i], tot = 0;
            while (now != to) {
                tot++;
                vis[now] = true;
                if (to - 1 != now) {
                    int tmp = 0, nxt = 0;
                    for (int t : vec[to - 1]) {
                        if (t != to) {
                            if (f[t] != nxt) nxt = f[t];
                            if (f[t] == nxt) tmp++;
                            if (f[to] == t && tmp == 1) ans += (ll)tot * cnt[t];
                            else ans += tot;
                        }
                    }
                }
                if (pre[f[to]] != to) break;
                now = to, to = f[now];
                
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}