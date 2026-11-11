#include <bits/stdc++.h>
using namespace std;

int n, m, ans, a[200010];

int main () {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m, ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 29; i >= 0; i--) {
        int res = ans + (1 << i), cnt = 0;
        for (int j = 1; j <= n; j++)
            if ((a[j] & res) == res)
                cnt++;
        if (cnt >= m)
            ans = res;
    }
    cout << ans << '\n';
    return 0;
}
