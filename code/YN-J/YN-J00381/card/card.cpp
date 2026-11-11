#include <bits/stdc++.h>
using namespace std;

int n, m, ans[500005] = {}, p[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> p[i];
	}

	for (int i = 1; i <= n; i++) {

		for (int j = i; j <= n; j++) {

			ans[p[i]]++;
		}

		for (int j = i; j <= n - 1; j++) {

			for (int k = j; k <= n; k++) {

				if (p[j] == p[k]) {
					for (int l = j; l <= k; l++) {

						ans[p[l]]--;
					}
				}
			}
		}
	}

	for (int i = 1; i <= m; i++) {

		cout << ans[i] << ' ';
	}

	return 0;
}