#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;

int n, m, a[N], ans;

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int res = m, lft = 1;
    for (int i = 2; i <= n; i++) {
        int cs = (i - 1 - lft + 1) * (a[i] - a[i - 1]);
        while (res < cs && lft <= i) {
            res += (a[i - 1] - a[lft]);
            lft++;
            cs = (i - 1 - lft + 1) * (a[i] - a[i - 1]);
        }
        res -= cs;
        ans = max(ans, i - lft + 1);
    }
    cout << ans << '\n';
    return 0;
}