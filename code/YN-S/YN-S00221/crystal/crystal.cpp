#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, s, cnt, ans, a[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++) {

		s += a[i];
		cnt++;

		if (cnt * a[i] - s > m) {
			ans = max(ans, cnt - 1);
			s -= a[i - cnt + 1];
			cnt--;
		}
	}

	cout << ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/