#include <bits/stdc++.h>

using namespace std;
long long n, m;
const long long N = 5e5 + 10;
long long a[N], sum[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for(long long i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for(long long i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    long long ans = 0;
    for(long long i = 1; i <= n; i++) {
        long long l = 1, r = i - 1;
        while(l < r) {
            long long mid = (l + r) >> 1;
            long long need = (i - mid) * a[i] - (sum[i - 1] - sum[mid - 1]);
            if(need > m) l = mid + 1;
            else r = mid;
        }
        // if(i - l + 1 == 5) printf("%lld %lld\n", i, l);
        ans = max(ans, i - l + 1);
    }
    printf("%lld\n", ans);
}
//for p