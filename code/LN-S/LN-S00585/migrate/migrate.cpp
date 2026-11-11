#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;

const int N = 2000005;

int n;
LL d;
LL x[N];
int f[N], sz[N];
int bound[N];

int dp(int st) {
    f[st] = 0;
    bound[0] = st;
    sz[st] = 1;
    int hh = st;
    int res = 0;
    for (int i = st + 1; i <= n; i ++ ) {
        while (hh <= i - 1 && x[i] - x[hh] > d) hh ++ ;
        if (hh >= i) break;
        f[i] = f[hh] + 1;
        bound[f[i]] = i;
        int contribute = bound[f[i] - 1] - hh + 1;
        if (contribute >= 3) sz[i] = 3;
        if (contribute == 2) {
            if (sz[hh] >= 2) sz[i] = 3;
            else sz[i] = 2, res ++ ;
        }
        if (contribute == 1) {
            sz[i] = sz[hh];
            res += (sz[i] == 2);
            if (sz[i] > 2) break;
        }
    }

    return res;
}

int solve() {
    scanf("%d%lld", &n, &d);
    for (int i = 1; i <= n; i ++ ) scanf("%lld", &x[i]);

    LL res = 0;
    for (int i = 1; i < n; i ++ ) {
        res += dp(i);
    }

    printf("%lld\n", res);
    return 0;
}

int solve2() {
    scanf("%d%lld", &n, &d);
    for (int i = 1; i <= n; i ++ ) scanf("%lld", &x[i]);

    LL D = x[2] - x[1];
    LL p = d / D;
    if (p <= 1) puts("0");
    else printf("%lld\n", max(0ll, n - (2 * p - 1)));

    return 0;
}

int solve3() {
    scanf("%d%lld", &n, &d);
    for (int i = 1; i <= n; i ++ ) scanf("%lld", &x[i]);
    x[n + 1] = 0x3f3f3f3f3f3f3f3f;

    LL res = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (x[i] + d >= x[n]) break;
        int rr = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
        int mid = rr - 1, ll = rr - 2;
        if (mid == i) continue;
        int midend = upper_bound(x + 1, x + n + 1, x[mid] + d) - x - 1;
        int lend = upper_bound(x + 1, x + n + 1, x[ll] + d) - x - 1;
        res += midend - lend;
    }
    printf("%lld\n", res);

    return 0;
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, T;
    scanf("%d%d", &c, &T);
    while (T -- ) {
        if (c == 11 || c == 12) solve2();
        else if (c == 13 || c == 14) solve3();
        else solve();
    }

    return 0;
}