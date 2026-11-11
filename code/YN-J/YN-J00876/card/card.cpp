#include <bits/stdc++.h>
using namespace std;
const int N = 2e3;
int t[N], b[N], t1[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> b[i];
	}

	int cnt;

	while (cnt++) {
		if (cnt >= n) {
			break;
		}

		int a[N];
		int c = 1;

		for (int k = cnt; k <= n; k++) {

			if (t1[b[k]] < 1) {
				t1[b[k]] = 1;
				a[c] = b[k];
				c++;
			} else {
				for (int i = 1; i <= n; i++) {

					if (a[i] == b[k]) {
						a[i] = -1;
						t1[a[i]] = 0;
						break;
					} else {
						a[i] = -1;
						t1[a[i]] = 0;
					}
				}

				a[c] = b[k];
				t1[b[k]] = 1;
				c++;
			}
		}

		for (int i = 1; i <= n; i++) {

			t[b[i]] += t1[b[i]];
			t1[b[i]] = 0;
		}


	}

	for (int i = 1; i <= n; i++) {

		if (t[b[i]] != -1) {
			cout << t[b[i]] << " ";
			t[b[i]] = -1;
		}
	}

	return 0;
}
