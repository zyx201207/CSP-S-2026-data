#include <bits/stdc++.h>
using namespace std;
long long g;
long long s;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	int e = 0;
	int x = n;

	for (int i = 0 ; i < n; i++) {

		long long a;
		cin >> a;
		g[i] == a;
	}

	for (int z = 0; z <= n; z++) {

		for (int i = z; i < n; i++) {

			s = {};
			s[i] += g[i];
			x--;

			for (int j = 0; j <= i; j++) {

				if (s[i] == s[j]) {
					for (int d = 0; d < i; d++) {

						for (int r = 0; r < i; r++) {

							s[r] = s[r + 1];
						}
					}
				}
			}

			for (int o = 0; o < m; o++) {

				int k = s[z];

				if (s[r] == k) {
					e++;
				}

				cout << e << " ";
			}

			if (x == 0) {
				break;
			}
		}
	}



	return 0;
}
