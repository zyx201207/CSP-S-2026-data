#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 10;

int n;
long long m;
long long a[N];
long long b[N];
long long sum[N];

int ans = 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    sort(a + 1, a + n + 1);
    ans = 1;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i - 1, t = -1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if ((i - mid) * a[i] - (sum[i] - sum[mid - 1]) <= m) {
                r = mid - 1;
                t = mid;
            } else {
                l = mid + 1;
            }
        }
        ans = max(ans, i - t + 1);
    }
    cout << ans << endl;
    return 0;
}
