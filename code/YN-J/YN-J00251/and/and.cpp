#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, greater<int>());
	if (m == 1) {
		cout << a[1];
	} else if (m == 2 && n <= 2000) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					int s = (a[i] & a[j]);
					ans = max(ans, s);
				}
			}
		}
		cout << ans;
	} else if (m == n) {
		int ans = a[1];
		for (int i = 2; i <= n; i++) {
			int s = (ans & i);
			ans = s;
		}
		cout << ans;
	} else {
		int ans = a[1];
		for (int i = 2; i <= m; i++) {
			ans = (ans & a[i]);
		}
		cout << ans;
	}


	return 0;
}
