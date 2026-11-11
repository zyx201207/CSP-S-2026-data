#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
int n;
ll m, a[N];

bool check(ll x) {
	ll cnt = 0;

	for (int i = 1; i < x; i++) {

		if (a[i] != a[x])
			cnt = cnt + a[x] - a[i];
	}

	if (cnt <= m)
		return true;
	else
		return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);
	ll l = 1, r = n, ans = 0;;

	while (l <= r) {
		ll mid = (r - l) / 2 + l;

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