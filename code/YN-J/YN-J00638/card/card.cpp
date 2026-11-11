#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long a[300005];
	long long yx[500005];
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		cin >> yx[i];
	}

	for (int i = 0; i < n; i++) {

		long long b[300005];

		for (int j = 1; j <= m; j++) {

			b[j] = -1;
		}


		for (int j = i; j < n; j++) {

			if (b[yx[j]] != -1) {

				for (int r = 1; r <= m; r++) {

					if (b[r] > b[yx[j]])
						b[r] = -1;
				}
			}

			b[yx[j]] = j;
		}

		for (int j = 1; j <= m; j++) {

			if (b[j] != -1)
				a[j]++;
		}
	}

	for (int j = 1; j <= m; j++) {

		cout << a[j] << ' ';
	}

	return 0;
}