#include <iostream>
#include <algorithm>
using namespace std;
int n, a[500005];
long long m;
int ans;
long long sum[500005];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i];
    int l = 1, r = 1;
    while (r <= n) {
        while (sum[r] - sum[l - 1] + m < 
            1ll * (r - l + 1) * a[r]) ++l;
        ans = max(ans, r - l + 1);
        ++r;
    }
    printf("%d\n", ans);
    return 0;
}