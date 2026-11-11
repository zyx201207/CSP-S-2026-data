#include<bits/stdc++.h>
using namespace std;
#define N (500000)
#define ll long long

int n; ll m;
ll a[N + 5], sum[N + 5];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = 0;
    for (int r = 1, l = 1; r <= n; ++r) {
        while (l < r && a[r] * (r - l + 1) - sum[r] + sum[l - 1] > m) { ++l; }
        ans = max(ans, r - l + 1);
    }
    printf("%d\n", ans);
    return 0;
}
