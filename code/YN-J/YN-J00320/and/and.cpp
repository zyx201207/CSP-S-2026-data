#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	long long n, m, ans, a[N], mx = -1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int j = 0; j <= n - m; j++) {
		for (int i = n - j; i > n - j - m; i--) {
			if (i == n - j) {
				ans = a[i];
				continue;
			}
			ans = ans & a[i];
			if (ans == 0) {
				break;
			}
		}
		mx = max(ans, mx);
	}
	cout << mx;
	return 0;
}
