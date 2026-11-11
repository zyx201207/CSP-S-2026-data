#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, _, n;
ll d, a[2000005];
void solve() {
    scanf("%d%lld", &n, &d);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    if (n == 1) {
        puts("0");
        return;
    }
    if (c == 13 || c == 14) {
        printf("%lld\n", 1LL * (n - 1) * (n - 2) / 2);
        return;
    }
    if (c == 11 || c == 12) {
        ll x = d / (a[2] - a[1]);
        --n;
        ll ans = n / x * (x - 1) + n % x - x + 1;
        if (!(n % x))
            ++ans;
        printf("%lld\n", ans);
    }
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &_);
    for (; _--; )
        solve();
}
