#include <bits/stdc++.h>
using namespace std;

int t_2(int a) {
	int c = 0, i = 1;

	while (a != 0) {
		int b = a % 2;
		c += b * i;
		i *= 10;
		a /= 2;

	}

	return c;
}

int t_10(int a) {
	int b = 0, c = 0;

	while (a != 0) {

		c += (a % 10) * pow(2, b);
		b++;
		a /= 10;
	}

	return c;
}

int cmp (int a, int b) {
	int i = 10, e = 0;
	int c = t_2(a), d = t_2(b);

	while (min(c, d) != 0) {
		if ((c % 10 == 1) &&
		        (d % 10 == 1))
			e += 1 * i / 10;
		else
			e *= 10;
		i *= 10;
		c /= 10;
		d /= 10;


	}

	return t_10(e);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n + 5] = {0};
	int s;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];

	}

	int b[n + 5] = {0};

//	for (int i = 0; i < n; i++) {
//
//		int h = 0;
//
//		for (int j = 1; j <= n; j++) {
//
//
//
////			b[i]=max(a[j],a[j-1]);
//			if (a[j] >= a[j - 1]) {
//				b[i] = a[j];
//				h = j;
//
//			}
//		}
//
//		a[h] = 0;
//
//
//	}
//
//	for (int i = 0; i < n; i++)
//
//		cout << b[i];
	cout << cmp(15, 12);




	return 0;
}
