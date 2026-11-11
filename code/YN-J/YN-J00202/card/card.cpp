#include <bits/stdc++.h>
using namespace std;
int n, m, a[30005], b[50005], desk[50005], c[30005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> b[i];
	}

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= n; j++) {

			desk[j] = 0;
		}

		for (int j = i; j <= n; j++) {

			desk[j] = b[j];


			a[desk[j]]++;

			if (a[desk[j]] > 1) {
				for (int z = 1; z < j; z++) {

					desk[z] = 0;
					a[desk[z]] = 0;
				}

				a[desk[j]] = 1;
			}
		}


		for (int j = 1; j <= n; j++) {

			c[desk[j]]++;
		}
	}

	for (int i = 1; i <= m; i++) {

		cout << c[i] << ' ';
	}

	return 0;
}