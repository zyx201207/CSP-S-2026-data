#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 50;
ll a[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    ll m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll ans = 1;
    for (ll i = a[1]; i <= a[n]; ++i) {
        ll sum = 0;
        int j = 1;
		ll result = 0;
        for (; j <= n; ++j) {
            if (i < a[j]) break;
            sum += i - a[j];
			if (sum <= m) result = sum;
			else break;
        }
        if (result <= m) {
            ans = max(ans, ll(j - 1));
            if (result == m) break;
        }
    }
    cout << ans;
    return 0;
}
