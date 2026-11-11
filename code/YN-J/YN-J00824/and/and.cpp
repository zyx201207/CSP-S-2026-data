#include <bits/stdc++.h>
using namespace std;
int n, m, a[200040], ans;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n - 1);
	ans = a[n - 1];
	for (int i = n - 2; i > n - m - 1; i--) {
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}
