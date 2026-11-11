#include <bits/stdc++.h>
using namespace std;
long long n, m, ans;
long long a[500010];
bool f = 1;
int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
//	cout << endl << 'a';
	for (int i = 2; i <= n; i++) {
//		cout << 'a';
		if (a[i] - a[i - 1] == a[i - 1] - a[i - 2]) {
			f = 0;
		} else {
			f = 1;
			break;
		}
	}
//	cout << '\n';
	sort (a + 1, a + 1 + n);
//	cout << '\n';
	if (n <= 5000) {
		for (int k = 1; k <= n; k++) {
			long long sum = 0;
			long long cnt = m;
			for (int i = k - 1; i > 0; i--) {
				if (a[k] - a[i] <= cnt) {
					sum++;
					cnt -= a[k] - a[i];
				} else {
					break;
				}
			}
			sum ++;
			for (int i = sum + 1; i <= n; i++) {
				if (a[i] == a[sum]) {
					sum++;
				}
			}
			if (cnt % sum) {
				sum--;
			}
			ans = max (sum, ans);
		}
	} else if (f) {
		for (int k = 1; k <= n; k++) {
			long long sum = 0;
			long long cnt = m;

			if (cnt % sum) {
				sum--;
			}
			ans = max (sum, ans);
		}
		ans ++;
		for (int i = ans; i <= n; i++) {
			if (a[i] == a[ans]) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}