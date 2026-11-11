#include <bits/stdc++.h>
using namespace std;
int game[500010];
int card[500010];
int sum[300020];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, a = 1 ;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)

		cin >> card[i];

	while (a <= n) {


		for (int i = a; i <= n; i++) {

			game[i] = card[i];

			for (int j = 1; j <= i; j++) {

				if (game[i] == game[j]) {
					for (int p = j; p < i; p++)

						game[p] = 0;
				}
			}

			if (i == n) {
				for (int j = 1; j <= n; j++) {

					for (int q = 1; q <= n; q++) {

						if (game[q] == j)
							sum[j]++;
					}


				}
			}
		}

		for (int i = a; i <= n; i++) {

			game[i] = 0;
		}

		a++;
	}

	for (int i = 1; i <= m; i++)

		cout << sum[i] << " ";

	return 0;
}