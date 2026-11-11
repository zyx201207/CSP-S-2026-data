#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500010;
int n;
ll m, a[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    ll mx = 0;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]), mx = max(mx, a[i]);
    sort(a + 1, a + n + 1);
    if (n <= 5000) {
        int ma = 1;
        for (int k = n; k >= 0; k--) {
            ll mm = m;
            int ans = 1;
            for (int i = k - 1; i > 0; i--) {
                if (a[k] - a[i] <= mm)
                    ans++, mm -= a[k] - a[i];
                else
                    break;
            }
            ma = max(ma, ans);
        }
        printf("%d\n", ma);
        return 0;
    }
    int ans = 1;
    for (int i = n - 1; i; i--)
        if (m >= a[n] - a[i])
            m -= a[n] - a[i], ans++;
    printf("%d\n", ans);
    return 0;
}
