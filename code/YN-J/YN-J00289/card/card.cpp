#include <bits/stdc++.h>
using namespace std;
int lst[300010], Z[500010], ans[300010], A[500010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> A[i];

		if (lst[A[i]] != 0) {
			Z[lst[A[i]]] = i;
		}

		lst[A[i]] = i;
	}

//	if (n <= 5000) {
	for (int i = 1; i <= n; i++) {

		for (int j = i; j <= n; j++) {

			ans[A[j]]++;

			if (Z[j] != 0) {
				j = Z[j];
			}
		}
	}

	for (int i = 1; i <= m; i++) {

		cout << ans[i] << ' ';
	}

//	}


	return 0;
}
