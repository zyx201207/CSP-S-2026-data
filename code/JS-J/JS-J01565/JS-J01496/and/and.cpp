#include "bits/stdc++.h"
#define ll long long
using namespace std;

const int N = 2e5 + 5;
ll n, m, a[N], dp[2100][2100];

inline ll read() {
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i ++) {
        a[i] = read();
    }
    sort(a + 1, a + n + 1);
    if (n <= 2000) {
        for (int i = 1; i <= n; i ++) {
            dp[i][1] = a[i];
        }
        ll ans = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = 2; j <= m; j ++) {
                dp[i][j] = max(dp[i - 1][j - 1] & a[i], dp[i - 1][j]);
            }
            ans = max(ans, dp[i][m]);
        }
        printf("%lld", ans);
    } else {
        ll ans = a[n];
        for (int i = 1; i <= m; i ++) {
            ans &= a[n - i + 1];
        }
        printf("%lld", ans);
    }
}
