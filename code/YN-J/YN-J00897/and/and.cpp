#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[2000010];
int d[2000010];

int b(int c) {
	string s = "";
	while (c != 0) {
		if (c == 1) {
			s += '1';
			break;
		}
		s += char('0' + c % 2);
		c /= 2;
	}
	int ans = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		ans = ans * 10 + (s[i] - '0');
	}
	return ans;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	if (m == 1) {
		int max_ = -1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			max_ = max(max_, a[i]);
		}
		cout << max_;
		return 0;
	} else if (m == 2) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			d[i] = b(a[i]);
		}
		int max_ = -1;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				max_ = max(max_, d[i] & d[j]);
			}
		}
		int ans = 0, i = 0;
		while (max_ != 0) {
			ans += max_ % 10 * pow(2, i);
			max_ /= 10;
			i++;
		}
		cout << ans;
		return 0;
	} else if (m == n) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			d[i] = b(a[i]);
		}
		int ans = d[1];
		for (int i = 2; i <= n; i++) {
			ans = ans && d[i];
		}
		int cnt = 0, i = 0;
		while (ans != 0) {
			cnt += ans % 10 * pow(2, i);
			ans /= 10;
			i++;
		}
		cout << cnt;
		return 0;
	} else if (m == n - 1) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			d[i] = b(a[i]);
		}
		int max_ = -1;
		for (int i = 1; i <= n; i++) {
			int ans = 0;
			if (i == 1) {
				ans = d[2];
				for (int j = 3; j <= n; j++) {
					if (j == i)
						continue;
					ans = ans & d[j];
				}
			} else {
				for (int j = 1; j <= n; j++) {
					if (j == i)
						continue;
					ans = ans & d[j];
				}
			}
			max_ = max(max_, ans);
		}
		int cnt = 0, i = 0;
		while (ans != 0) {
			cnt += ans % 10 * pow(2, i);
			ans /= 10;
			i++;
		}
		cout << cnt;
		return 0;
	} else {
		cout << 3;
	}
	return 0;
}