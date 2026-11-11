#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[1000005], cha[1000005], ans, arr[1000005];

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	for (ll i = 1; i <= n; i++)
		cha[i] = a[1] - a[i];
	for (ll i = 1; i <= n; i++) {
		arr[i] = arr[i - 1] + cha[i];
		if (arr[i] > m && (!ans)) {

			ans = i - 1;
//			cout << i - 1 << " ";
		}
	}
	for (ll i = 2; i <= n; i++) {
		ll py = cha[i];
		ll l = i, r = n;
		while (l < r) {
			ll mid = (l + r + 1) >> 1;
			if (arr[mid] - arr[i - 1] - py * (mid - i + 1) <= m)
				l = mid;
			else
				r = mid - 1;
		}
		ans = max(ans, l - i + 1);
//		cout << l - i + 1 << " ";
	}
	cout << ans;
}