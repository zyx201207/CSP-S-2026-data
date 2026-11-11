#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll c, T;
ll n, d;
const int N = 2e6+5;
ll a[N];
ll ans = 0;

inline void solve1() {
	ll dist = a[2] - a[1];
	ll j;
	ans = 0;
	for (int i = 1; i <= n; i++) {
		j = i + (dist) / d;
		++j;
		if (j <= n && (dist / d) == 2) {
			++ans;
		}
	}
	cout << ans << '\n';
}
ll po[5005];
ll yuanda[5005];

inline void solve2() {
	ans = 0;
	for (int i = 0; i < n + 3; i++)
		po[i] = yuanda[i] = LLONG_MAX;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (abs(a[i] - a[j]) <= d) {
				po[i] = min(po[i], (1ll * j));
				yuanda[i] = po[i];
				yuanda[i] = min(yuanda[i], yuanda[j]);
				break;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (abs(i - po[i]) != 2)
			continue;
		if (abs(i - yuanda[i]) <= 2)
			continue;
//		cout << "fgf:" << i << " " << yuanda[i - 1] << " " << yuanda[i - 1] << " " << yuanda[i] << '\n';
		ans += max((i - (yuanda[i - 1] + po[i - 1] - po[i - 2]) - 2), 0ll);
	}
	cout << ans << '\n';
}

inline void solve() {
	cin >> n >> d;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (c == 11 || c == 12)
		solve1();
	else
		solve2();
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> T;
	while (T--)
		solve();
	return 0;
}
