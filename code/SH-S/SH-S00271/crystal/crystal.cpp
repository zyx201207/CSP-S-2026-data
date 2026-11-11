#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll n, m;
ll a[500009], f[500009];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1] + a[i];
		ll l = 1, r = i;
		while (l < r) {
			ll mid = l + (r - l) / 2;
			if ((i - mid + 1) * a[i] - (f[i] - f[mid - 1]) <= m)
				r = mid;
			else
				l = mid + 1;
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans;
	return 0;
}