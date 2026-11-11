#include <bits/stdc++.h>
#define in(x) x = read()
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n, m, a[N], c[N], v[N], l, r, cnt, sum, ans = 1;

inline bool check(int mid) {
    cnt = sum = 0; memset(v, 0, sizeof v);
    for (int i = 1; i <= mid - 1; i++)
        cnt += c[i] * i; sum = cnt;
    for (int i = 2; i <= n - mid + 1; i++)
        for (int j = i - 1; j <= i + mid - 3; j++)
            v[i] += c[j];// , cout << i << ' ' << j << '\n'; cout << '\n';
    // for (int i = 2; i <= n - mid + 1; i++) {
    //     cout << v[i] << ' ';
    // } cout << '\n';
    // cout << 1 << ' ' << mid << ' ' << cnt << '\n';
    for (int i = 2, j = mid; j < n; i++, j++)
        cnt = cnt - v[i] + c[j] * (mid - 1), sum = min(cnt, sum);
        // cout << i << ' ' << j + 1 << ' ' << cnt << '\n';
    // cout << mid << ' ' << (cnt <= m) << ' ' << cnt << '\n';
    if (sum <= m) {
        ans = max(ans, mid);
        return true;
    }
    else
        return false;
}

signed main() {
    // ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m; l = 1, r = n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n - 1; i++)
        c[i] = a[i + 1] - a[i];// , cout << c[i] << ' ';
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid;
    }
    cout << ans << '\n';
    return 0;
}
