#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 7;
int n, m, ans, now, a[N];
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1, j = 1; i <= n; i ++) {
        j = max(j, i);
        while (j < n && now + a[i] - a[j + 1] <= m)
            j ++, now += a[i] - a[j];
        ans = max(ans, j - i + 1);
        now -= (j - i) * (a[i] - a[i + 1]);
    }
    cout << ans;
    return 0;
}
/*
剑旗爵，是我赢了
*/
