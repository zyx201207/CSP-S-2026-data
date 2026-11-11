#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long m;
long long a[N], sum[N];
bool check (int mid) {
    for (int i = mid; i <= n; i++) {
        int l = i - mid + 1, r = i;
        long long res = 1ll * mid * a[i] - (sum[r] - sum[l - 1]);
        if (res <= m) return true;
    }
    return false;
}
int main () {
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int l = 1, r = n, res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check (mid)) l = mid + 1, res = mid;
        else r = mid - 1;
    }
    cout << res << "\n";
    return 0;
}
