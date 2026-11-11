#include <bits/stdc++.h>
using namespace std;
int a[500005], b[300005], c[500005];

int main( ) {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		c[i] = a[i];
	}

	for (int y = 1; y <= n; y++) {


		for (int i = y; i <= n; i++) {

			for (int j = i + 1; j <= n; j++) {

				if (c[i] == c[j]) {
					for (int z = i; z < j; z++) {

						c[z] = 0;
					}
				}



			}
		}

		for (int z = y; z <= n; z++) {

			if (c[z] != 0)
				b[c[z]]++;
		}

		for (int z = 1; z <= n; z++) {

			c[z] = a[z];
		}

	}

	for (int z = 1; z <= m; z++) {

		cout << b[z] << " ";
	}





	return 0;
}
