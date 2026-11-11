#include <bits/stdc++.h>
using namespace std;
long long n, a[200050], lc, rc, l, r, minn, ans;
char c[200050];
int main () {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf ("%lld", &n);
    for (int i = 1; i <= n; i ++) scanf ("%lld %c", &a[i], &c[i]);
    l = 1, r = n, lc = rc = 0;
    while (l < r) {
        if (!lc) lc = a[l];
        if (!rc) rc = a[r];
        minn = min(lc, rc);
        if(c[l] ^ c[r]) ans += minn;
        lc -= minn, rc -= minn;
        if (!lc) l ++;
        if (!rc) r --;
    }
    printf ("%lld\n", ans);
}