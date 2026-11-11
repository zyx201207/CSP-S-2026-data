#include <stdio.h>
#include <string.h>
#include <unordered_set>
int n;
long long d;
long long x[2000001];
long long cnt[2000001];
int depth[2000001];
void solve(void) {
    scanf("%d %lld", &n, &d);
    int ans = 0;
    for (int i = 0; i < n; ++i) scanf("%lld", &x[i]);
    for (int st = 0; st < n; ++st) {
        memset(depth, 0x3f, sizeof(int) * (n + 1));
        memset(cnt, 0, sizeof(int) * (n + 1));
        depth[st] = 0;
        cnt[st] = 1;
        std::unordered_set<int> now, nxt;
        now.insert(st);
        while (!now.empty()) {
            for (int i : now) {
                for (int j = i + 1; j < n && x[j] - x[i] <= d; ++j) {
                    if (depth[i] + 1 < depth[j]) {
                        depth[j] = depth[i] + 1;
                        cnt[j] = cnt[i];
                        nxt.insert(j);
                    } else if (depth[i] + 1 == depth[j]) {
                        cnt[j] += cnt[i];
                    }
                }
            }
            now.swap(nxt);
            nxt.clear();
        }
        for (int i = st + 1; i < n; ++i) ans += (cnt[i] == 2);
    }
    printf("%d\n", ans);
}
int main(void) {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    scanf("%d %d", &c, &t);
    while (t--) solve();
    return 0;
}