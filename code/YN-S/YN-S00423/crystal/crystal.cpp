#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, ans = 0;
	cin >> n >> m;
	vector<int>a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a.begin() + 1, a.end());
	if (n % 2 == 1) {
		int gl = a[ceil(n / 2.0)];
		for (int i = 1; i <= n; i++) {
			if (a[i] == gl)
				ans++;
		}
		sort(a.begin() + 1, a.end());
		for (int i = ceil(n / 2.0) - 1; i >= 1; i--) {
			if (m == 0)
				break;
			if (a[i] == gl)
				continue;
			if (gl - a[i] <= m) {
				a[i] = gl;
				ans++;
				m -= gl - a[i];
			} else if (gl - a[i] > m) {
				a[i] += m;
				m = 0;
			}
		}
	} else {
		int gl = a[n / 2.0], gl2 = a[n / 2.0 + 1];
		if (gl == gl2) {
			for (int i = 1; i <= n; i++) {
				if (a[i] == gl)
					ans++;
			}
			sort(a.begin() + 1, a.end());
			for (int i = n / 2.0 - 1; i >= 1; i--) {
				if (m == 0)
					break;
				if (a[i] == gl)
					continue;
				if (gl - a[i] <= m) {
					a[i] = gl;
					ans++;
					m -= gl - a[i];
				} else if (gl - a[i] > m) {
					a[i] += m;
					m = 0;
				}
			}
		} else {
			int ans2 = 0, mm = m;
			for (int i = 1; i <= n; i++) {
				if (a[i] == gl)
					ans++;
			}
			sort(a.begin() + 1, a.end());
			for (int i = n / 2.0 - 1; i >= 1; i--) {
				if (m == 0)
					break;
				if (a[i] == gl)
					continue;
				if (gl - a[i] <= m) {
					ans++;
					m -= gl - a[i];
				} else if (gl - a[i] > m) {
					m = 0;
				}
			}
			for (int i = 1; i <= n; i++) {
				if (a[i] == gl2)
					ans2++;
			}
			sort(a.begin() + 1, a.end());
			for (int i = n / 2.0 ; i >= 1; i--) {
				if (mm == 0)
					break;
				if (a[i] == gl2)
					continue;
				if (gl2 - a[i] <= mm) {
					ans2++;
					mm -= gl2 - a[i];
				} else if (gl2 - a[i] > mm) {
					mm = 0;
				}
			}
			ans = max(ans, ans2);
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

