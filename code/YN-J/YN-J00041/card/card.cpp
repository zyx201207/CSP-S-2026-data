#include <bits/stdc++.h>
using namespace std;







int a[500010], pos[300010] = {0}, tot[300010] = {0};

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		fill(pos + 1, pos + m + 1, 0);
		for (int j = i; j <= n; j++) {

			if (!pos[a[j]]) {
				pos[a[j]] = j;
			} else {
				for (int k = pos[a[j]] + 1; k < j; k++) {
					int op = a[k];
					if ( pos[op] >= pos[a[j]] + 1 && pos[op] < j) {
						pos[op] = 0;
					}

				}
			}

		}
		for (int j = 1; j <= n; j++) {
			if (pos[j])
				tot[j]++;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << tot[i] << " ";
	return 0;
}