#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5;

ll n, m, ans;
ll a[N], dif[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		///dif[i]=a[i]-a[i-1];
	}

	sort(a + 1, a + n + 1);
	if (n <= 5000) {
		for (ll i = 1; i <= n; i++) {
			ll sum = 0, now = i;
			for (ll j = i + 1; j <= n; j++) {
				sum += (a[j] - a[j - 1]) * (j - i);
				if (sum > m)
					break;
				else
					now = j;
			}
			ans = max(ans, now - i + 1);
		}
		cout << ans;
	}

	else {
		ll p = abs(a[1] - a[2]);
		ll l = 0, r = m;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if (p * mid * (mid + 1) / 2 > m)
				r = mid;
			if (p * mid * (mid + 1) / 2 == m) {
				l = mid;
				break;
			}
			if (p * mid * (mid + 1) / 2 < m)
				l = mid + 1;
		}
		cout << l + 1;
	}



	return 0;
}