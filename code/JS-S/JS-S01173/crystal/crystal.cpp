#include <bits/stdc++.h>
#define int long long
#define fi first 
#define se second
#define pb push_back
using namespace std;
const int N = 5e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3f;
int read() {
    int g = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        g = g * 10 + (ch ^ 48);
        ch = getchar();
    }
    return g * f;
}
int n, m, a[N], sum[N], ans;
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int r = 1;
    for (int i = 1; i <= n; i++) {
        while (a[r] * (r - i + 1) - sum[r] + sum[i - 1] <= m && r <= n) r++;
        r--;
        ans = max(ans, r - i + 1);
    }
    printf("%lld\n", ans);
    return 0;
}