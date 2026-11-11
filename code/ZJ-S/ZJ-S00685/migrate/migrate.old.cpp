#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long u64;
typedef long long i64;

u64 c, t, n, f[5010][5010], cnt[5010][5010];
i64 x[2000010], d;

void solve() {
    scanf("%llu%lld", &n, &d);
    for (u64 i = 1; i <= n; i++)
        scanf("%lld", &x[i]);
    memset(f, 0x3f, sizeof f);
    memset(cnt, 0, sizeof cnt);
    for (u64 i = 1; i <= n; i++)
        f[i][i] = 0, cnt[i][i] = 1;
    for (u64 p1 = 1, p2 = 1; p1 <= n && p2 <= n; p2++) {
        while (x[p1] + d < x[p2])
            p1++;
        for (u64 j = 1; j < p1; j++) {
            for (u64 k = p1; k < p2; k++) {
                u64 tf = f[j][k] + 1;
                if (tf < f[j][p2]) {
                    f[j][p2] = tf;
                    cnt[j][p2] = cnt[j][k];
                } else if (tf == f[j][p2])
                    cnt[j][p2] += cnt[j][k];
            }
        }
        for (u64 j = p1; j < p2; j++)
            f[j][p2] = 1, cnt[j][p2] = 1;
    }
    u64 ans = 0;
    for (u64 i = 1; i <= n; i++)
        for (u64 j = i + 1; j <= n; j++)
            ans += cnt[i][j] == 2;
    printf("%llu\n", ans);
}

int main() {
    // freopen("migrate.in", "r", stdin);
    // freopen("migrate.out", "w", stdout);
    scanf("%llu%llu", &c, &t);
    while (t--)
        solve();
}
