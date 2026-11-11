#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, maxn;
long long a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	if (m == 1) {
		cout << maxn;
	} else if (m == 2) {
		for (long long i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				long long k = a[i] & a[j];
				ans = max(ans, k);
			}
		}
		cout << ans;
	} else if (m == 3) {
		for (long long i = 1; i <= n; i++) {
			for (long long j = i + 1; j <= n; j++) {
				for (long long l = j + 1; l <= n; l++) {
					long long k = a[i] & a[j] & a[l];
					ans = max(ans, k);
				}
			}
		}
		cout << ans;
	}
	return 0;
}