#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n, m, a[N], s = 1, ans = 1;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    iostream::sync_with_stdio(false);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    sort(&a[1], &a[n + 1]);
    for (ll i = 1; i <= n; i++) {
        m -= (i - s + 1) * (a[i + 1] - a[i]);
        ans = max(ans, i - s + 1);
        while (m < 0) {
            m += a[i + 1] - a[s];
            s++;
        }
    }
    cout << ans << endl;
    return 0;
}