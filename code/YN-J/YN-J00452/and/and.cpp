#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (m == 1) {
		int res = -123;
		for (int i = 1; i <= n; i++)
			res = max(res, a[i]);
		cout << res;
	} else if (m == 2) {
		int res = -123;
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				res = max(res, (a[i] & a[j]));
			}
		}
		cout << res;
	} else if (m == n) {
		int res = a[1];
		for (int i = 2; i <= n; i++)
			res &= a[i];
		cout << res;
	} else if (n <= 20) {
		int N = (1 << n) - 1, res = -123;
		for (int i = 1; i <= N; i++) {
			int ans = -1;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					if (ans == -1) {
						ans = a[j + 1];
					} else
						ans &= a[j + 1];
				}
			}
			res = max(res, ans);
		}
		cout << res;
	} else {
		int res = -123;
		for (int i = 1; i <= n; i++)
			res = max(res, a[i]);
		cout << res;
	}
	return 0;
}