#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[500005];

signed main() {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)

		cin >> a[i];
	sort (a + 1, a + n + 1);

	for (int i = 2; i <= n; i++) {

		for (int j = 1; j < i; j++) {

			for (int k = a[j]; k <= a[i]; k++) {

				a[j]++;
				m--;

				if (m == 0) {
					cout << i;
					return 0;
				}
			}
		}
	}

	cout << 1;
	return 0;
}