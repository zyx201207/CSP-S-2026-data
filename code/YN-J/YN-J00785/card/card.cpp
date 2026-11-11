#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, a[N], co = 1, q[N], q1[N], qj[N];
int t[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];

		if (t[a[i]] = 0) {
			t[a[i]] = 1;
			q[a[i]] = 1;
		} else {
			q[a[i]]++;
		}

		if (a[i] < a[i - 1]) {
			co++;
		}
	}

	if (co == 1) {
		for (int i = 1; i <= m; i++) {

			q1[i] = q1[i - 1] + q[i];
			cout << q1[i] << ' ';
		}
	} else {
		for (int h = 1; h <= n; h++) {

			for (int i = 1; i <= n; i++) {

				for (int j = 1; j < i; j++) {

					if (q[j] = a[i]) {
						for (int k = j; k <= i; k++) {

							q[k] = 0;
						}
					}
				}

				qj[i] = a[i];
			}

			for (int i = 1; i <= n; i++) {

				t[qj[i]]++;
				t[0] = 0;
			}
		}

		for (int i = 1; i <= n; i++) {

			q1[i] = q1[i - 1] + t[i];
			cout << q1[i] << ' ';
		}
	}

	return 0;
}