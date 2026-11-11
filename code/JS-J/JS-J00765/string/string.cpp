#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;
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
int n, a[N], ans;
char c[N];
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read(), cin >> c[i];
    int l = 1, r = n;
    while (l <= r) {
        if (c[l] != c[r]) {
            ans += min(a[l], a[r]);
        } 
        if (a[l] < a[r]) a[r] -= a[l], l++;
        else if (a[l] > a[r]) a[l] -= a[r], r--;
        else l++, r--;
    }
    printf("%lld\n", ans);
    return 0;
}