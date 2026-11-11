#include <bits/stdc++.h>
#define lt long long
using namespace std;

const int N = 5 * 1e5 + 10;
lt n, a[N], sum[N], m;

inline lt read() {
    lt x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || '9' < ch) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline lt stf(lt l, lt r) {
    lt sm = sum[r] - sum[l - 1];
    lt pt = a[r] * (r - l + 1);
    return pt - sm;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1);
    lt mn = a[1] - 1;
    for (int i = 1; i <= n; i++) a[i] -= mn;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    lt l = 1, r = 1, ans = 0;
    while (l <= n) {
        while (r < n && stf(l, r) <= m) r++;
        while (r > l && stf(l, r) > m) r--;
        ans = max(ans, r - l + 1LL);
        l++;
    }
    printf("%lld", ans);
    return 0;
}
