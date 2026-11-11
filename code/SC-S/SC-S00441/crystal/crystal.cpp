#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e6 + 7;
ll n, m;
ll a[N];
ll sum[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for (ll i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	for (ll i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
	}
	
	bool ko = true;
	ll tp = 0;
	for (ll i = 2; i < n; ++i) {
		tp = a[i] - a[i - 1];
		if (a[i] - a[i - 1] != a[i + 1] - a[i]) {
			ko = false;
			break;
		}
	}
	
	if (ko) {
		ll ans = 1;
		for (ll i = n - 1; i >= 1; --i) {
			m = m - (n - i) * tp;
			if (m >= 0) {
				++ans;
			} else {
				break;
			}
		}
		cout << ans << '\n';
		return 0;
	}
	
	for (ll i = n; i >= 1; --i) {
		for (ll l = 1; l + i - 1 <= n; ++l) {
			ll r = l + i - 1;
			ll tmp = a[r] * (r - l + 1);
			ll cha = tmp - (sum[r] - sum[l - 1]);
			if (cha <= m) {
				cout << i << '\n';
				return 0;
			}
		}
	}
	
	return 0;
}