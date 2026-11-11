#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, ans, mx = -1;
int md[220000];

bool check(int x) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if ((md[i]&x) == x) {
			cnt++;
		}
		if (cnt == m) {
			return true;
		}
	}
	return false;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> md[i];
		mx = max(mx, md[i]);
	}
	int l = 1, r = mx;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}