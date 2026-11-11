#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005];
bool c[500005];
bool d[300005];
long long b[300005];
long long da[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (long long i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (long long i = 1; i <= n; i++) {

		memset(b, 0, sizeof(b));
		memset(c, false, sizeof(c));
		memset(d, false, sizeof(d));

		for (long long j = i; j <= n; j++) {

			if (b[a[j]] != 0 && c[b[a[j]]] != true) {

				for (long long k = b[a[j]]; k < j; k++) {

					c[k] = true;
				}
			}

			b[a[j]] = j;
		}

		for (long long j = i; j <= n; j++) {

			if (c[j] == false && d[a[j]] == false) {
				d[a[j]] = true;
				da[a[j]]++;
			}
		}
	}

	for (long long i = 1; i <= m; i++) {

		cout << da[i] << " ";
	}

	return 0;
}
