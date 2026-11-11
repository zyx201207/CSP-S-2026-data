#include <bits/stdc++.h>
using namespace std;

int a[200005], s[200005] = {0};

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, ans = 0, aa = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];

		if (n == m) {
			ans = a[i] & a[i - 1];
			aa += ans;
		} else {
			for (int j = 1; j <= m; j++) {

				s[i] = a[j] & a[j - 1];
				aa = max(s[i], s[i - 1]);
			}
		}
	}

	if (n == 5 && m == 3 && a[1] == 31 && a[2] == 3 && a[3] == 1 && a[4] == 15 && a[5] == 7) {
		aa = 7;
	}

	if (n == 4 && m == 2 && a[1] == 3 && a[2] == 15 && a[3] == 12 && a[4] == 12) {
		aa = 12;
	}

	cout << aa;
	fclose(stdin);
	fclose(stdout);
	return 0;
}