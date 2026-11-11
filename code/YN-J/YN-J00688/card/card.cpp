#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;



int a[N] = {0}, b[N] = {0}, w[N], cnt[N] = {0};

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= m; i++) {

		w[i] = m;
	}

	for (int i = 1; i <= n; i++) {

		for (int q = i; q <= n; q++) {

			b[q] = a[i];

			for (int p = 1; p <= q; p++) {

				if (b[q] == b[p]) {
					for (int j = p; j <= q; j++) {

						b[j] = 0;
					}
				}
			}

			if (b[q] == w[i]) {
				cnt[w[i]]++;
			}
		}
	}

	for (int i = 1; i <= m; i++) {

		cout << cnt[i];
	}

	return 0;
}