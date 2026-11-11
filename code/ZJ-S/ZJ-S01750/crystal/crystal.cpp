/*
start at 15:08
finish at 15:11
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500500;
int n, m, ans;
int a[N], s[N];
int get(int l, int r) {return (r - l + 1) * a[r] - s[r] + s[l - 1];}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
    for (int i = 1, j = 1; i <= n; ++i) {
        while (get(j, i) > m) ++j;
        ans = max(ans, i - j + 1);
    }
    printf("%lld\n", ans);
    return 0;
}