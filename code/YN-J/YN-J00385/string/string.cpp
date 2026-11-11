#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	int ans = 0;
	int sum;
	char zm[50] = {};
	char a[10086];
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < 2 * n; i += 2) {
		zm[i - 1] = a[i];
	}
	for (int i = 0; i < 2 * n; i++) {
		if ( (a[i] >= 'a')
		        && (a[i] <= 'z')) {

			a[i] = a[i - 2];
		}
	}
	for (int i = 0; i < n; i++) {

		if ((zm[i] == zm[n - i]) && (a[i] == a[n - i])) {
			ans = 0;
		}

	}
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum % 2 != 0) {
			for (int i = 0; i < n; i++) {
				if ((a[i] >= sum / 2) || (a[i] + a[i + 1] >= sum / 2)) {
					if (a[i - 1] == a[i + 1]) {
						ans = 0;
					} else if (a[i + 1] > a[i - 1]) {
						ans = a[i + 1] + 1;
					} else {
						ans = a[i - 1] + 1;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}

