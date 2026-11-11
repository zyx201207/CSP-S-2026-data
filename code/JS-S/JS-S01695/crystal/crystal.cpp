#include "bits/stdc++.h"
using namespace std;
#define ll long long

const int N = 5e5 + 5;
ll a[N], n, m, ans, b[N];

inline ll read() {
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i ++) {
        a[i] = read();
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++) {
        b[i] += b[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i ++) {
        ll L = 0, R = i;
        while (L + 1 < R) {
            ll M = (L + R) / 2;
            if (a[i] * (i - M) - (b[i - 1] - b[i - (i - M) - 1]) <= m) {
                R = M;
            }else {
                L = M;
            }
        }
        ans = max(ans, i - L);
    }
    printf("%lld", ans);
}
