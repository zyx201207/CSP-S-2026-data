#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long u64;
typedef long long i64;

u64 n, m;
i64 a[500010];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%llu%llu", &n, &m);
    for (u64 i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sort(a, a + n);
    u64 ans = 0;
    for (u64 p1 = 0, p2 = 0, ps = 0; p1 < n && p2 < n; p2++) {
        while (p1 < p2 && (p2 - p1) * a[p2] - ps > m)
            ps -= a[p1], p1++;
        ans = max(ans, p2 - p1 + 1);
        ps += a[p2];
    }
    printf("%llu\n", ans);
}
