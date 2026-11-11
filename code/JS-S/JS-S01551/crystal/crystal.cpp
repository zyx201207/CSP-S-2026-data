#include <bits/stdc++.h>
using namespace std;
int n;
long long m, ans, a[500010];
int check(int x) {
    int t = 0;
    for (int i = 1; i <= x; i++) t += (a[x] - a[i]);
    if (t <= m) return x;
    else return -1;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2, t = check(mid);
        if (t >= 0) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}
