#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define int long long
int n, m, a[N], s[N], ans;
int solve(int x) {
    int l = 1, r = x, mid, res;
    while(l <= r) {
        mid = (l + r) >> 1;
        int t = a[x] * (x - mid + 1) - s[x] + s[mid - 1];
        if(t <= m) r = (res = mid) - 1;
        else l = mid + 1;
    }
    return (x - res + 1);
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
    for(int i = 1;i <= n;i++) ans = max(ans, solve(i));
    cout << ans << endl;
    return 0;
}
