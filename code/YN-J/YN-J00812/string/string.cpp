#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long a[100000];
	char b[100000];
	long long n;
	cin >> n;

	int s = 0;
	long long z = 0;
	int r = 0;
	int e = 1;
	int p = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
		cin >> b[i];
	}


	for (int i = 0; i < n; i++) {
		if (p + 1 >= n) {

			break;
		}
		if (r == 1) {
			i -= 1;
		}
		if (b[i] != b[n - e]) {
			if (a[i] > a[n - e]) {
				z += a[n - e];
				a[i] -= z;
				r = 1;
				e += 1;
				p += 1;
			} else if (a[i] < a[n - e]) {
				z += a[i];
				a[n - e] -= z;
				p += 1;
				r = 0;
			} else {

				z += a[n - e];
				r = 0;
				e += 1;
				p += 2;

			}
		} else {
			if (a[i] > a[n - e]) {
				a[i] -= a[n - e];
				r = 1;
				e += 1;
				p += 1;
			} else if (a[i] < a[n - e]) {
				a[n - e] -= a[i];
				p += 1;
				r = 0;
			} else {

				r = 0;
				e += 1;
				p += 2;
			}
		}
	}
	cout << z;


	fclose(stdin);
	fclose(stdout);
	return 0;
}