#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;

int n;
ll m, ans, a[N], sum[N];


int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];

    for (ll i = 1, aim, tot, cur, l, r, mid, len; i <= n; i++) {
        cur = a[i];
        l = 1, r = i, mid, len = -1;
        while (l <= r) {
            mid = (l + r) >> 1;
            aim = cur * mid;
            tot = sum[i] - sum[i - mid];
            if (m >= aim - tot) {
                len = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (len != -1) ans = max(ans, len);
    }

    cout << ans;

    return 0;
}
