#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 8;
int n, ans;
long long m, a[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    long long sum = 0;
    for (int i = n + 1, j = n; j >= 1; j--) {
        while (i > 1 && sum + a[j] - a[i - 1] <= m) sum += a[j] - a[--i];
        ans = max(ans, j - i + 1);
        sum -= (j - i + 1ll) * (a[j] - a[j - 1]);
    }
    printf("%d\n", ans);
    return 0;
}
