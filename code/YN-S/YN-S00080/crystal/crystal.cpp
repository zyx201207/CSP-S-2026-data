#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long n, m, ans = 0, sum = 0, suml = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int sl;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (long long i = 1; i <= n; i++) {
		long long p = i, mx = 0, num = 0;
		while (p > 0) {
			p--;
			mx += a[i] - a[p];
			num++;
			if (mx > m) {
				break;
			}
		}
		ans = max(ans, num);
	}
//	for (long long i = 1; i <= n; i++) {
//		sum += a[i] * i;
//		if (sum < m) {
//			suml = i;
//		}
//	}
	cout << ans;
	return 0;
}
