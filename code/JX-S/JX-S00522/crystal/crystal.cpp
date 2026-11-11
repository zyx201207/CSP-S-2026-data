#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 7;
int n;
ll m;
ll a[N], pre[N];
int solve(int i) {
    int l = 1, r = i;
    int res = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if((i - mid + 1) * a[i] - pre[i] + pre[mid - 1] <= m) {
            res = i - mid + 1;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
        ans = max(ans, solve(i));
    }
    printf("%d\n", ans);
}
