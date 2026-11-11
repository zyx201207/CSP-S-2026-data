#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 5e5 + 10;
int n, ans;
long long m, a[maxn], s[maxn];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1, j = 0; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
        while (a[i] * (i - j) - (s[i] - s[j]) > m) j++;
        ans = max(ans, i - j);
    }
    printf("%d", ans);
    return 0;
}
