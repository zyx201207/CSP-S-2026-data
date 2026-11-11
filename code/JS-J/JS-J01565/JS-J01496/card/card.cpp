#include "bits/stdc++.h"
#define ll long long
using namespace std;

const int N = 2e5 + 5;
ll n, m, a[N], appear[N], ans[N], rem[N], val[N];

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
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i ++) {
        a[i] = read();
    }

    for (int i = n; i >= 1; i --) {
        appear[a[i]] = max(appear[a[i]], (long long)i);
        rem[a[i]] ++;
    }
    for (int i = 1; i <= n; i ++) {
        int x = i;
        if (val[a[x]]) continue;
        val[a[x]] = 1;
        while (x <= n) {
            ans[a[x]] += rem[a[i]];
            x = appear[a[x]] + 1;
        }
    }
    for (int i = 1; i <= m; i ++) {
        printf("%lld ", ans[i]);
    }
}
