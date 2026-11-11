#include <bits/stdc++.h>
using namespace std;
int a[500005], c[500005], d[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, g = 0;
	cin >> n >> m;
	int r = n;

	for (int i = 0; i < n; i++)

		cin >> a[i];

	while (n--) {
		memset(c, 0, sizeof(c));
		vector<int> b;

		for (int i = g; i < r; i++) {

			if (c[a[i]] == 0) {
				b.push_back(a[i]);
				c[a[i]] = 1;
			} else {
				int f = 0;

				for (int j = 0; j < b.size(); j++) {

					if (b[j] == a[i]) {
						f = 1;
					}

					if (f == 1)
						b[j] = 0;
				}

				b.push_back(a[i]);
				c[a[i]] = 1;
			}
		}

		for (int j = 1; j <= m; j++) {

			for (int i = 0; i < b.size(); i++) {

				if (b[i] == j) {
					d[j]++;
				}

			}
		}

		g++;
	}

	for (int i = 1; i <= m; i++)

		cout << d[i] << ' ';
}