#include <bits/stdc++.h>
using namespace std;

int n, m, re[500005], shu[300005], dan[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> re[i];
	}

	int a = 1;

	while (a <= n) {
		memset(shu, 0, sizeof(shu));

		int b = a;

		while (b <= n) {
			if (shu[re[b]] != 0) {

				int nans = shu[re[b]];

				for (int i = nans; i <= b; i++) {

					for (int j = a; j <= n; j++) {

						if (shu[re[j]] == i) {
							shu[re[j]] = 0;
							break;
						}
					}
				}
			}

			shu[re[b]] = b;
			b++;

		}

		for (int i = 1; i <= m; i++) {

			if (shu[i] != 0) {
				dan[i]++;
			}
		}

		a++;
	}

	for (int i = 1; i <= m; i++) {

		cout << dan[i] << " ";
	}

	return 0;
}