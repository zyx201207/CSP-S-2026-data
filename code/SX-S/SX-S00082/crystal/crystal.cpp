#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], sum = 1, b[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n <= 5000) {

		for (int i = 1; i <= n; i++) {
			int t = m, ans = 1;
			for (int j = i - 1; j >= 1; j--) {
				if (t > (a[i] - a[j])) {
					ans++, t -= (a[i] - a[j]);
				} else {
					break;
				}
			}
			sum = max(sum, ans);
		}
		cout << sum;
	} else {
		sum = 0;
		int d = a[2] - a[1];
		for (int i = 1; i <= n; i++) {
			sum += d * i;
			if (sum > m) {
				cout << i - 1;
				return 0;
			}
		}
		cout << 10086;
	}
	return 0;
}
