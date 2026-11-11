#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[100002], b[100001], ans;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= m; i++) {

		for (int j = 1; j <= n; j++) {

			b[i] = max(b[i], a[j]);
		}

		for (int j = 1; j <= n; j++) {

			if (b[i] == a[j]) {
				a[j] = -1e9;
				break;
			}
		}

		if (i == 1) {
			ans = b[i];
		} else {
			ans = ans & b[i];
		}
	}

	cout << ans;
	return 0;
}
