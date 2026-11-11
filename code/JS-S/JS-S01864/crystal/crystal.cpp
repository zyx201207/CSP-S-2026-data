#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    long long ans = 0, sum = 0;
    for(int i = 1; i <= n; i++) {
        ans += a[n] - a[i];
        sum += a[i];
    }
    if(ans <= m) {
        printf("%lld\n", n);
    } else {
        long long l = 1, r = n;
        while(ans > m) {
            long long x = (a[r] - a[l]), y = (r - l) * (a[r] - a[r - 1]);
            double p = 1.0 * sum / (r - l + 1);
            if(p - a[l] <= a[r] - p) {
                r--;
                ans -= y;
                sum -= a[r];
            } else {
                l++;
                ans -= x;
                sum -= a[l];
            }
            //cout << l << " " << r << " " << ans << endl;
        }
        printf("%lld\n", r - l + 1);
    }
    return 0;
}
