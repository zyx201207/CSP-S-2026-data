#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c, t, n;
ll d;
ll a[2000005];

int main() {

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    // 10 pts easy
    // How incapable of I that I can't get more points!

    scanf("%d %d", &c, &t);
    while(t--) {
        memset(a, 0, sizeof(a));
        scanf("%d %lld", &n, &d);
        for(int i=0; i<n; i++) {
            scanf("%lld", &a[i]);
        }
        ll x = a[1] - a[0];
        ll l = (d/x) * 2 - 1;
        if(d < 2 * x) {
            puts("0");
        } else {
            printf("%lld\n", max(0ll, n-l));
        }
    }
    return 0;
}
