#include <bits/stdc++.h>
using namespace std;

unsigned long long n, m, t, x, y;
unsigned long long a[10001], b[10001], c[100001], d[100001];


int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (unsigned long long i = 0; i < n; i++) {

		cin >> a[i];
	}

	for (unsigned long long i = 0; i < n; i++) {

		x = t;


		for (unsigned long long j = 0; j < n; j++, x++) {

			if (x < n) {
				b[j] = a[x];
				y++;
			} else {
				b[j] = a[x - n];
				y++;
			}

			for (unsigned long long p = 0; p < y - 1; p++) {

				if (b[p] == b[j]) {
					y = y - p - 1;
				}
			}
		}

		for (unsigned long long i = 0; i < y; i++) {

			for (unsigned long long j = 1; j <= y; j++) {

				if (b[i] == j && d[j] == 0) {
					c[j]++;
					d[j] = 1;
				}
			}

		}

		for (unsigned long long j = 0; j < n; j++) {

			d[j] = 0;
		}

		t++;

	}

	for (unsigned long long i = 1; i <= m; i++) {

		cout << c[i] << " ";
	}
}