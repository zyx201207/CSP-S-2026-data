#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m, a[N], pre[N], ans;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i];
        long long l = 1, r = i - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (pre[i - 1] - pre[mid - 1] + m < (i - mid) * a[i]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        ans = max(ans, i - r + 1);
    }
    cout << ans;
    return 0;
}
