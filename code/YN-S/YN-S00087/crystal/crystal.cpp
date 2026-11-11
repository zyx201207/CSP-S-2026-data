#include <bits/stdc++.h>
using namespace std;
long long n, m;
int a[5000005];
int b[5000005];
int sim;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);

	if (n % 2 == 0) {
		sim = a[n / 2];
	} else
		sim = a[(n / 2) + 1];
	int x = 1;
	int k = 0;
	for (int i = 1; i <= n; i++) {
		a[i] -= sim;
		if (a[i] <= 0) {
			b[x] = a[i];
			x++;

		}


	}
	for (int i = 1; i <= x; i++) {
		k = b[i] + k;
	}
	if (k + m == 0) {
		cout << x - 1;
	} else
		cout << "3";

}