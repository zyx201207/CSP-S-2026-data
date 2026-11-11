#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m, a[500005];
bool check(int x) {
    ll s = 0;
    for (int i = 1; i < x; i++)
        s += a[x] - a[i];
    if (s <= m)
        return 1;
    for (int i = x + 1; i <= n; i++) {
        s -= a[i - 1] - a[i - x];
        s += (a[i] - a[i - 1]) * (x - 1);
        if (s <= m)
            return 1;
    }
    return 0;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    int l = 0, r = n + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (check(m))
            l = m;
        else
            r = m;
    }
    printf("%d\n", l);
}
