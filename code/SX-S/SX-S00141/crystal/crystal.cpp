#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, a1, a2, a3, a4, a5, ans = 0;
	cin >> n >> m >> a1 >> a2 >> a3 >> a4 >> a5;
	for (int i = 1; i <= n ; i++) {
		if (a1 + i == a2) {
			ans += 1;
		} else if (a2 + i == a3) {
			ans += 1;
		} else if (a3 + i == a4) {
			ans += 1;
		} else if (a4 + i == a5) {
			ans += 1;
		} else {
			break;
		}
	}
	cout << ans + 1;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	return 0;
}
