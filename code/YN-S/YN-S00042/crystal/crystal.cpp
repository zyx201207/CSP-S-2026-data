#include <bits/stdc++.h>
using namespace std;

int n;
unsigned long long m, max1;
long long a[50001], z, t;
long long b[50001], c[50001];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {

		t = m;

		z = a[i];

		for (int j = 0; j < n; j++) {

			b[j] = a[j] - z;

			if (b[j] < 0) {
				b[j] = -b[j];
			}





		}

		sort(b, b + n );



		for (int j = 0; j < n ; j++) {

			t = t - b[j];


			if (t >= 0) {



				c[i]++;
			}
		}



	}

	for (int i = 0; i < n; i++) {

		if (max1 < c[i]) {
			max1 = c[i];
		}
	}

	cout << max1;
	return 0;
}