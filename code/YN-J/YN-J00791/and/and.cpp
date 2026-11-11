#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n, m;
int q[N];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		q [i] = q[i - 1] & a[i];
	}
	if (m == n) {
		int sum = a[1];
		for (int i = 2; i <= n; i++) {
			sum &= a[i];
		}
		cout << sum;
	}
	if (m == 1) {
		int ans = LLONG_MIN;
		for (int i = 1; i <= n; i++) {
			ans = max(a[i], ans);
		}
		cout << ans;
	} else if (m == 2) {
		int ans = LLONG_MIN;
		for (int i = 1; i <= n; i++) {
			int sum = i;
			for (int j = 1; j <= n; j++) {
				sum = a[i];
				if (j != i) {
					sum = sum & a[j];
					cout << sum << ' ';
					ans = max(sum, ans);
				}
				cout << ans;
			}
		}
		cout << ans;
	} else if (m == (n - 1)) {
		int ans = LLONG_MIN;
		int sum = a[2];
		for (int i = 2; i <= n; i++) {
			sum &= a[i];
		}
		ans = max(ans, sum);
		sum = a[1];
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (j != i) {
					sum &= a[j];
				}
			}
			sum = max(ans, sum);
		}
		cout << ans;
	} else {
		int ans = LLONG_MIN;
		for (int i = 1; i <= n; i++) {
			ans = max(ans, a[i]);
		}
		cout << ans;
	}
	return 0;
}
