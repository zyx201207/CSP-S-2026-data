#include <bits/stdc++.h>
using namespace  std ;
int a[100];
int b[100];

int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n1;
	cin >> n1;

	for (int i = 1; i <= n1; i++) {

		int n, x = 1;
		int q = 1;
		cin >> n;
		int sum = 0;

		while (n != 0) {
			a[x] = n % 2;
			n /= 2;
			x++;
		}

		for (int j = 1; j <= x - 1; j++) {

			int hkt = q * a[j];
			q = q * 10;
			sum += hkt;
		}

		b[i] = sum;
	}

	int mx = 0;

	for (int i = 1; i <= n1; i++) {

		if (i >= 2) {
			if ((b[i]  and  b[i - 1]) > mx) {
				mx = (b[i]  and  b[i - 1]);
			}
		}

	}

	cout << mx;





	return 0 ;
}
