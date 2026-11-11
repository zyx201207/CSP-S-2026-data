#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
int n, m;
ll a[500005];
ll sum[500005];
ll ans;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i) {
        sum[i] += sum[i - 1] + a[i];
        ll c = -1;
        int l = 1, r = i, mid;
        while (l <= r) {
            mid = l + r >> 1;
            if (a[i] * (i - mid) - (sum[i - 1] - sum[mid - 1]) <= m) {
                r = mid - 1;
                c = i - mid + 1;
            } else {
                l = mid + 1;
            }
        }
        ans = max(ans, c);
    }
    printf("%lld\n", ans);
    return 0;
}
