#include<bits/stdc++.h>

using namespace std;

long long n, a[200005];
char c[200005];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%lld", &n);
    long long l = 0, k = 0, ans = 0, p = 1;
    bool ok = true;
    for (long long i = 1; i <= n; i++) {
        scanf("%lld%s", &a[i], &c[i]);
        l += a[i];
        if (i == 1)
            continue;
        if (c[i] != c[i - 1])
            ok = false;
    }
    if (ok) {
        printf("0\n");
        return 0;
    }
    k = l / 2;
    long long o = l / 2;
    for (long long i = 1; i <= l / 2; i++) {
        if (i > a[p]) {
            p++;
        }
        if (l + 1 - i > a[k]) {
            k += a[l + 1 - i];
        }
        if (c[i] != c[l + 1 - i])
            ans += 1;
    }
    printf("%lld\n", ans);
    return 0;
}
