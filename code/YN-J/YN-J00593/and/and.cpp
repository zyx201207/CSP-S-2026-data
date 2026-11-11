#include <bits/stdc++.h>
using namespace std;
int a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, ans = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)

		cin >> a[i];

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {

			ans = max(ans, a[i] & a[j]);
		}
	}

	if (m == n) {
		ans = 0;

		for (int i = 0; i < n; i++) {

			ans = ans & a[i];
		}

		cout << ans;
		return 0;
	}

	if (m == 1) {
		ans = 0;

		for (int i = 0; i < n; i++) {

			ans = max(ans, a[i]);
		}

		cout << ans;
		return 0;
	}

	cout << ans;
}