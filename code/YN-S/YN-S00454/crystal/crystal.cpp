#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, md[550000], ans, sum = 0;

bool check(int x) {
	if (x == 1) {
		return true;
	}
	int sum = 0;
	for (int i = 1; i <= n - x + 1; i++) {
		for (int j = i; j < i + x; j++) {
			sum += abs(md[(i + i + x) / 2] - md[j]);
		}
		if (sum <= m) {
			return true;
		}
	}
	return false;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> md[i];
	}
	if (n <= 5000) {
		sort(md + 1, md + n + 1);
		int l = 1, r = n;
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
	} else {
		for (int i = 1; i <= n; i++) {
			sum += (md[2] - md[1]) * i / 2;
			if (sum > m) {
				cout << i - 1 << '\n';
				return 0;
			}
		}
		cout << n << '\n';
	}
	return 0;
}