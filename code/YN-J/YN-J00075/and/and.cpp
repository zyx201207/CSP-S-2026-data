#include <bits/stdc++.h>
using namespace std;

unsigned long long m, n, max1, x, y;
unsigned long long a[20001], b[20001];
bool  d[20001];

unsigned long long find(int m, unsigned long long be, unsigned long long t);

void find(int m) {

	if (m == 1) {
		return;
	}

	for (unsigned long long i = 0; i < n; i++) {

		for (unsigned long long j = 0; j < n; j++) {

			if ((a[i] & a[j]) > max1 && d[j] == 0 && i != j) {
				max1 = a[i] & a[j];
				x = j;
			}
		}

		y = i;

		d[x] = 1;

		b[i] = find(m - 1, y, max1);
		max1 = 0;

		for (unsigned long long j = 0; j < n; j++) {

			d[j] = 0;
		}
	}

}

unsigned long long find(int m, unsigned long long be, unsigned long long t) {
	if (m == 1) {
		return t;
	}

	max1 = 0;

	for (unsigned long long j = 0; j < n; j++) {

		if (d[j] == 0 && (t & a[j]) > max1 && j != be) {
			max1 = t & a[j];
			x = j;
		}
	}

	b[x] = 1;
	t = find(m - 1, be, t);
	return max1;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (unsigned long long i = 0; i < n; i++) {

		cin >> a[i];
	}

	find(m);

	for (unsigned long long i = 0; i < n; i++) {

		if (max1 < b[i]) {
			max1 = b[i];
		}
	}

	cout << max1;
}
