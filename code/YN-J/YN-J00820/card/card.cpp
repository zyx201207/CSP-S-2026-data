#include <bits/stdc++.h>
using namespace std;
int n, m, a[5000050], b[5000050], j, cnt[5000050];

void pai(int k) {
	for (int i = j; i <= n; i++) {

		if (a[i] == k) {
			for (int e = a[i]; e <= n; e++) {

				a[e] = 0;
			}

			a[i] = k;
			break;
		}
	}

	a[n - j + 1] = k;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (j = 1; j <= n; j++) {

		for (int t = j; t <= n; t++) {

			pai(a[t]);
		}
	}

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= m; j++) {

			if (a[i] == j)
				cnt[j]++;
		}
	}

	for (int i = 1; i <= m; i++)

		cout << cnt[i];
	return 0;
}
