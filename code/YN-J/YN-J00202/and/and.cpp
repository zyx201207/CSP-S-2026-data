#include <bits/stdc++.h>
using namespace std;
int n, a[20005], maxn = -1e9, m, maxm;
bool x[20005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	memset(x, false, 20005);

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= n - 1; i++) {

		for (int j = i + 1; j <= n; j++) {

			maxn = max(maxn, a[i] & a[j]);
		}
	}

	for (int i = 1; i <= n - 1; i++) {

		for (int j = i + 1; j <= n; j++) {

			if (a[i]&a[j] == maxn) {
				x[i] = true;
				x[j] = true;
			}
		}
	}



	if (m > 2) {
		for (int j = 1; j <= m - 2; j++) {

			maxm = maxn;
			maxn = -10;

			for (int i = 1; i <= n; i++) {

				if (!x[i]) {
					maxn = max(maxn, maxm & a[i]);

					if (maxn == maxm & a[i]) {
						x[i] = true;
					}

				}
			}
		}

	}

	cout << maxn;
	return 0;
}