#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], sum[N][2005], ans = -1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i][1] = max(sum[n - 1][1], a[i]);
	}
	if (m == 1) {
		cout << a[n];
		return 0;
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					ans = max(ans, a[i] & a[j]);
				} 
			}
		}
		cout << ans;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			if (i > j) {
				sum[i][j] = max(sum[i][j], sum[i - 1][j - 1] & a[i]);
				sum[i][j] = max(sum[i - 1][j], sum[i][j]);
			}
		}
	}
	for (int i = m; i <= n; i++) {
		ans = max(ans, sum[i][m]);
	}
	cout << ans << endl;
	return 0;
}
