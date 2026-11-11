#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int n, l, r, a[N], ans = 0, mn;
char s[N];

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n; l = 1, r = n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> s[i];
    while (l < r) {
        mn = min(a[l], a[r]); a[l] -= mn, a[r] -= mn;
        if (s[l] != s[r])
            ans += mn;
        if (a[l] == 0)
            l++;
        if (a[r] == 0)
            r--;
    }
    cout << ans << '\n';
    return 0;
}
// 9:12, /fn, l <= r -> l < r