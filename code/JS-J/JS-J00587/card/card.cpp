#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, s[500005], k[500005];
signed main() {
    //freopen("card.in", "r", stdin);
    //freopen("card.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &s[i]);
    }
    for (int i = 1; i <= m; ++i) {
        printf("%lld ", n);
    }
    return 0;
}
