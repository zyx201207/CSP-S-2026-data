#include <bits/stdc++.h>
using namespace std;
int a[1001];
int n, m;
int ans[1001];
int b[1001][1001];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	int max1 = -1;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		max1 = max(max1, a[i]);
	}

	int m1 = m;

	while (m1--) {
		for (int i = 1; i <= n; i++) {

			for (int j = 1; j < i; j++) {

				if (a[i] == a[j]) {
					int x = j;
					int y = i;

					for (int k = x; k < y; k++) {

						a[k] = 0;
					}
				}
			}

			ans[a[i]]++;
		}
	}

	for (int i = m; i >= 1; i--)

		cout << ans[i] << " ";
	return 0;
}
