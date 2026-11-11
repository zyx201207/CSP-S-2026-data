#include <bits/stdc++.h>
using namespace std;
int c, t;
long long a[1000005];
long long stp[1000005];
long long f[1000005];
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d %d", &c, &t);
    while(t--) {
        memset(a, 0, sizeof(a));
        memset(stp, 0, sizeof(stp));
        memset(f, 0, sizeof(f));
        long long n, d;
        scanf("%lld %lld", &n, &d);
        for(int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        long long l = 1, ans = 0;
        for(int k = 1; k <= n; k++) {
            memset(stp, 0, sizeof(stp));
            memset(f, 0, sizeof(f));
            l = k;
            f[k] = 1;
            for(int i = k + 1; i <= n; i++) {
                while(a[l] + d < a[i]) {
                    l++;
                }
                stp[i] = stp[l] + 1;
                f[i]++;
                for(int j = l + 1; j < i; j++) {
                    if(stp[j] + 1 == stp[i]) {
                        f[i]++;
                    }
                }
                if(f[i] == 2) {
                    ans++;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
