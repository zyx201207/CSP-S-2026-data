#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
ll n, m, ans, a[N], s[N];

bool check(ll l, ll r) {
	return a[r] * (r - l + 1LL) <= m + s[r] - s[l - 1];
}

ll calc(ll t) {
	ll l = 1, r = n, mid;
	while (l < r) {
		mid = (l + r) >> 1;
		if (check(mid, t))
			r = mid;
		else
			l = mid + 1;
	}
	return t - r + 1;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; ++i)
		ans = max(ans, calc(i));
	cout << ans << endl;
	return 0;
}