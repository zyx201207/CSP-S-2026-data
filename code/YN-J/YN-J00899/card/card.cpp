#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 10;
int n, m, a[N], b[N], c[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)

		cin >> a[i];

	for (int i = 1; i <= n; i++) {

		for (int l = 1; l <= n; l++)

			c[i] = a[i];

		for (int j = i; j <= n; j++) {

			for (int k = j - 1; k >= i; k--) {

				if (c[j] == c[k]) {
					for (int o = k; o < j; o++) {

						c[o] = 0;
					}
				}
			}
		}

		for (int j = 1; j <= n; j++)

			if (c[j] != 0)
				b[c[j]]++;
	}

	for (int i = 1; i < m; i++)

		cout << b[i] << " ";
	cout << b[m];
	return 0;
}
