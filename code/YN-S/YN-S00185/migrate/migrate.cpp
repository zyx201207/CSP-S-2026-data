#include <bits/stdc++.h>
using namespace std;
int a[10000];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (a[i] <= n + m) {

			}
			for (int i = n; i <= m; i++) {
				for (int j = n; j <= m; j++) {
					if (a[i] >= n - m) {
						a[i]++;
					}
					cout << a[i] << endl;
				}
			}

		}
	}


	return 0;
}