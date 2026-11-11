#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005];

int zcxl() {
	int x = a[1], xans = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == x) {
			xans++;
		} else {
			if (xans > ans) {
				ans = xans;
				xans = 0;
			} else {
				xans = 0;
				x = a[i + 1];
			}
		}
	}
	return ans;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int sum = 0, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int mid = sum / n;
//	cout << "mid:" << mid << "\n";
	while (m > 0) {
		for (int i = 1; i <= n; i++) {
			if (a[i] < mid) {
				a[i]++;
				m--;
			}
//			cout << a[i] << " ";
		}
		ans = zcxl();
//		cout << " ans:" << ans << "\n";
		if (ans <= m) {
//			cout << "ans<=m: ";
			int cc = 0;
			for (int i = 1; i <= m; i++) {
				if (a[i] < mid + 1) {
					a[i]++;
					m--;
					cc++;
				}
			}
//			for (int i = 1; i <= n; i++) {
//				cout << a[i] << " ";
//			}
//			cout << "mid:" << mid << "\n";
			int xans = zcxl();
			if (xans < ans) {
				for (int i = 1; i <= cc; i++) {
					a[i]--;
				}
				break;
			} else {
				ans = xans;
//				cout << " ans:" << ans;
//				mid++;
			}
//			cout << "\n";
		}
	}
	cout << ans;
	return 0;
}