#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll m, a[500005], s[500005];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    int l = 1, r = 1, ans = -1;
    while (r <= n) {
        if ((r - l + 1) * a[r] - (s[r] - s[l - 1]) <= m) {
            ans = max(ans, r - l + 1);
            //printf("%d\n", ans);
            ++r;
        }
        else while ((r - l + 1) * a[r] - (s[r] - s[l - 1]) > m) ++l;
    }
    printf("%d\n", ans);
    return 0;
}
