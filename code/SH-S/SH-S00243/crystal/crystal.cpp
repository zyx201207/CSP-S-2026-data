#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, ans; ll m; ll a[500009], s[500009];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d %lld", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", a + i);
    sort(a + 1, a + n + 1); for(int i = 1; i <= n; i++) s[i] = a[i] + s[i - 1];
    ans = 1; for(int i = 2; i <= n; i++) {
        int l = 1, r = i;
        while(l <= r) { int mid = l + r >> 1; if(s[i] - s[i - mid] + m >= mid * a[i]) l = mid + 1; else r = mid - 1; }
        ans = max(ans, r);
    }
    printf("%d\n", ans);
    return 0;
}