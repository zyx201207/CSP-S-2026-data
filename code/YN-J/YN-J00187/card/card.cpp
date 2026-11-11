#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5 * 1e5;
ll n, m;

ll a[N], b[N] = {}, c[N];
long z = 0;

int main() {
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		c[i] = a[i];
	}

	for (int i = 1; i <= n; i++) {

		if (i == 1) {
			z = i;
			a[z] = c[i];
			continue;
		}

		a[z] = c[i];

		for (int j = 1; j <= z; j++) {

			if (a[j] == a[z + 1]) {
				z = j;
			}

			if (j == z && a[j] != a[z + 1]) {
				z++;
				break;
			}
		}

		for (int k = 1; k <= z + 1; k++) {

			b[a[k]]++;
		}
	}

	for (int i = 2; i <= m; i++) {

		if (b[i]) {
			cout << b[i] << " ";
		}
	}

	cout << b[1];
	return 0;
}