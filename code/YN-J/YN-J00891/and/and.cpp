#include <bits/stdc++.h>
using namespace std;

int a[100000] = {0};
int ma = 0;



int main() {
	int n, m;
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int q = 1; q <= n; q++) {
		cin >> a[q];
	}
	sort(a + 1, a + 1 + n);
	if (m == 2) {

		for (int q = n; q >= 1; q--) {
			for (int w = q - 1; w >= 1; w--) {
				ma = max(ma, a[q] & a[w]);
			}
		}
	}

	if (m == 1) {
		cout << a[n];
	}
	if (m == n) {
		int x = a[n];
		for (int q = n; q >= 1; q--) {
			x = x & a[q];

		}
		cout << x;
	}
}




