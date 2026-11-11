#include <bits/stdc++.h>
using namespace std;
long long a[20005];
string  b[20005];
long long sum;
long long fb, xb;

int pd(int  n, int y) {
	if (a[n] == 0 && a[y] == 0) {
		return 0;
	} else if (a[n] == 0) {
		pd(n + 1, y);
	}


	else if (a[y] == 0) {
		pd(n, y + 1);
	} else {
		if (a[n] > a[y]) {
			if (b[y] != b[n]) {
				sum += a[y];
				a[n] -= a[y];
				a[y] = 0;

				pd(n, y + 1);
				return 0;
			} else {
				a[n] -= a[y];
				a[y] = 0;
				pd(n, y + 1);
				return 0;
			}
		} else if (a[n] == a[y]) {
			if (b[y] != b[n]) {
				sum += a[y];
				a[n] -= a[y];
				a[y] = 0;
				pd(n + 1, y + 1);
				return 0;
			} else {
				a[n] = 0;
				a[y] = 0;
				pd(n + 1, y + 1);
				return 0;


			}
		} else {
			if (b[y] != b[n]) {
				sum += a[n];
				a[y] -= a[n];
				a[n] = 0;
				pd(n + 1, y);
				return 0;
			} else {
				a[y] -= a[n];
				a[n] = 0;
				pd(n + 1, y);
				return 0;
			}
		}
	}
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long big = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		big += a[i];
	}
	pd(1, n);
	if (big % 2 == 1 && sum != 0) {
		cout << sum - 1 ;
		return 0;
	} else {
		cout << sum;
		return 0;
	}

	return 0;
}