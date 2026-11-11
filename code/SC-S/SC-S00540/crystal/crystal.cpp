#include <bits/stdc++.h>
struct Code {
    Code () {
        freopen ("crystal.in", "r", stdin);
        freopen ("crystal.out", "w", stdout);
    }
    ~Code () {
        fclose (stdin);
        fclose (stdout);
    }
}code;
#define rep(i,l,r) for (int i = (l); i <= (r); i++)
#define per(i,r,l) for (int i = (r); i >= (l); i--)
#define fpr(x...) fprintf(stderr,x)
using std::min;
using std::max;
typedef long long ll;
const int N = 5e5 + 10;
int n; ll m;
ll a[N], s[N];
int main () {
    scanf ("%d%lld", &n, &m);
    rep (i, 1, n ) scanf ("%lld", &a[i]);
    std::sort (a + 1, a + n + 1);
    int ans = 0;
    rep (i, 1, n) s[i] = s[i - 1] + a[i];
    for (int r = 1, l = 1; r <= n; r++) {
        while (l < r && (r - l + 1) * a[r] - (s[r] - s[l - 1]) > m) l++;
        ans = max (ans, r - l + 1);
    }
    printf ("%d\n", ans);
    return 0;
}