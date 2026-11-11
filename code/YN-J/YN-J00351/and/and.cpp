#include <iostream>
#include <cmath>
using namespace std;
int n;

int mn(int a[], int i, int m) {
	if (m <= 0) {
		return a[i - 2] & a[i - 1];
	} else if (m == 1) {
		return a[i];
	}

	return (a[i] & a[i + 1])&mn(a, i + 2, m - 2);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int m, a[200001];

	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < i; j++) {

			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}

	cout << mn(a, 0, m);
	return 0;
}
