#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    long long m;
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)sum[i]= sum[i - 1] + a[i];
    int r = 1;
    int ans = 0;
    for (int l = 1; l <= n; l++) {
        r = max(r, l);
        while (r < n && 1LL * (r - l + 2) * a[r + 1] - (sum[r + 1] - sum[l - 1]) <= m) r++;
        ans = max(ans, r - l + 1);
    }
    printf("%d", ans);
    return 0;
}
