#include <bits/stdc++.h>
using namespace std;
long a[500001];
long f[500001];
long long n, m;
long opp(long x) {
    long l = x - 1, r = n, mid, ans = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] * (mid - x + 1) - f[mid] + f[x - 1] <= m) {
            l = mid + 1;
            ans = mid - x + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        long tot = opp(i);
        if (tot > ans) {
            ans = tot;
        }
    }
    cout << ans << endl;
    return 0;
}
