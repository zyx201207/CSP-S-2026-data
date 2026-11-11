// crystal.cpp
#include <bits/stdc++.h>
using namespace std;
int n, ans;
long long m;
bool fl;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    long long a[n+5], d[n+5], s[n+5];
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a,a+1+n);
    for (int i = n; i >= 1; i--) {
        if (ans >= i) break;
        fl = 0;
        memset(d, 0, sizeof d), memset(s, 0, sizeof s);
        for (int j = i; j >= 1; j--) {
            d[j] = a[i]-a[j];
            s[j] = s[j+1]+d[j];
            if (s[j] > m) {
                ans = max(ans, i-j+1), fl = 1;
                break;
            }
        }
        if (!fl) {
            ans = i;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}
