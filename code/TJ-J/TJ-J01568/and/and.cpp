#include <bits/stdc++.h>
using namespace std;
int a[10000001];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, t, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		sort(a + 1, a + n + 1);
		cout << a[n];
		return 0;
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				t = a[i] & a[j];
				ans = max(t, ans);
			}
		}
		cout << ans;
		return 0;
	}
	if (m == n) {
		ans = a[1];
		for (int i = 2; i <= n; i++) {
			ans = (ans & a[i + 1]);
		}
		cout << ans;
	}
	return 0;
}