#include <bits/stdc++.h>
using namespace std;

int a[5100];
int c[3100];
int q[3100];
int w[3100];


int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i ++) {

		cin >> a[i];

	}


	for (int i = 1; i <= n + 1; i ++) {

		for (int j = i; j <= n; j ++) {

			if (w[a[j]] != 0) {
				for (int k = w[a[j]]; k < j; k++) {

					q[k] --;
				}
			}

			q[a[j]] ++;
			w[a[j]] = j;
		}

		for (int j = i; j <= n; j ++) {



			if (q[a[j]] != 0)
				c[a[j]] ++;
			q[a[j]] = 0;
			w[a[j]] = 0;
		}


	}

	for (int i = 1; i <= m; i ++ )

		cout << c[i] << ' ';

	return 0;
}