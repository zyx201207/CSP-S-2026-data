#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
const int N = 5e5+5;
ll a[N];
ll s[N];
ll m;
ll ans = 0;

bool check(ll x, ll f) {
	if ((1ll * (f - x + 1) * a[f]) - (s[f] - s[x - 1]) <= m)
		return 1;
	else
		return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}

	ll l, r, mid;
	for (int i = 1; i <= n; i++) {
		l = 0, r = i;
		while (r - l > 1) {
			mid = (l + r) >> 1;
			if (check(mid, i))
				r = mid;
			else
				l = mid;
		}
		ans = max(ans, (1ll * (i - r + 1)));
	}
	ans = max(1ll, ans);
	cout << ans << '\n';
	return 0;
}