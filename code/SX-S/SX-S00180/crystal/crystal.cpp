#include <bits/stdc++.h>
#define int long long
const int N = 5e5+5;
using namespace std;
int n, m, a[N], c[N], s[N], ans;

bool check(int mid, int id) {
	int sum = s[id] - s[id - mid + 1] - (a[id] - a[id - mid + 1]) * (id - mid);
	if (sum <= m)
		return 1;
	else
		return 0;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		c[i] = a[i] - a[i - 1];
		s[i] = s[i - 1] + (i - 1) * c[i];
	}

	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (check(mid, i)) {
				ans = max(ans, mid);
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
	}
	cout << ans;
	return 0;
}
