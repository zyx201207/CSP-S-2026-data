#include <bits/stdc++.h>
using namespace std;
int a[200000];
int n, m;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		sort(a + 1, a + n + 1);
		cout << a[n];
	} else if (m == 2) {
		int ans = INT_MIN;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
	} else if (m == n) {
		cout << 0;
	} else {
		sort(a + 1, a + n + 1);
		cout << a[n - m + 1];
	}
}