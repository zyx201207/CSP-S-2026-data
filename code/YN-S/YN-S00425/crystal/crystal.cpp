#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005], d[500005], sumd[500005];
int n, m;

bool ck(int x) {
	for (int i = n; i >= x; i--) {
		int sum = 0, j = i;
		while (j >= i - x + 1) {
			sum += sumd[j + 1] - sumd[i + 1];
			j--;
		}
		if (sum <= m) {
			return 1;
		}
	}
	return 0;
}

signed main() {
	ios::sync_with_stdio(0);
	cout.tie(0), cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int flag = 1, f1 = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i) {
			flag = 0;
		}
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
		if (i >= 3 && d[i] != d[i - 1]) {
			f1 = 0;
		}
	}
	for (int i = n; i >= 1; i--) {
		sumd[i] = sumd[i + 1] + d[i];
	}
	int ans = 0;
	if (flag) {
		for (int i = 1; i <= n - 1; i++) {
			if (m - i > 0) {
				m -= i;
				ans++;
			} else {
				break;
			}
		}
		if (ans < 1) {
			ans = 1;
		}
	} else if (f1) {
		int c = abs(a[2] - a[1]);
		for (int i = 1; i <= n - 1; i++) {
			if (m <= 0) {
				break;
			} else {
				m -= i * c;
				ans++;
			}
		}
		if (ans < 1) {
			ans = 1;
		}
	} else {
		int l = 1, r = n;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (ck(mid)) {
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
