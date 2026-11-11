#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
const int N = 5e5 + 10;
int n;
ll m, a[N], sum[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int res = 1;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i, mid, ans;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        res = max(res, i - ans + 1);
    }
    cout << res << '\n';
    return 0;
}
