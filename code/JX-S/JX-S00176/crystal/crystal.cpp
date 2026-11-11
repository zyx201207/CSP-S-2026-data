#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n;
ll m, a[N], sum[N];
inline bool check (int x) {
    for (int i = x; i <= n; i++) {
        if (a[i] * x - (sum[i] - sum[i - x]) <= m) return true;
    }
    return false;
}
int main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int l = 1, r = n, mid, ans = 1;
    while (l <= r) {
        mid = l + r >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    printf("%d", ans);
    return 0;
}