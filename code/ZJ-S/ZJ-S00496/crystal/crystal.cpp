#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e5 + 10;
ll n, m, a[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll ans = 0;
	for (ll i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (ll i = 1; i <= n; i++) {
		ll l = i, r = n, pos = -1;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if ((a[mid] * (mid - i + 1) - (s[mid] - s[i - 1])) <= m) {
				pos = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (pos != -1) ans = max(ans, pos - i + 1);
	}
	cout << ans << '\n';
	return 0; 
}
