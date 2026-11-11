#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;


ll n, m, a[N], need[N];

bool check(ll length) {
	ll j;
	bool flag = false;
	for (ll i = 1;i <= n - length + 1;i++) {
		j = i + length - 1;
		if ((need[j] - need[i - 1] - (a[j] - a[i-1]) * (i-1)) <= m) {
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (ll i = 1;i <= n;i++) {
		need[i] = need[i-1] + (a[i] - a[i-1]) * (i-1);
	}
	ll l = 1, r = n, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
