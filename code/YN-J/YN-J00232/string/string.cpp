#include <bits/stdc++.h>
using namespace std;
long long n, a[1000005], ant = 0, ll = 0;
char b[1000005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		ll = ll + a[i];
	}
	string c[10005], d, x;
	int j = 1;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= a[i]; k++) {
			c[j] = b[i];
			j++;
		}
	}
	d = c[1] + c[2];
	for (int i = 1; i <= n + 1; i++) {
		d = d + c[i + 2];
	}
	for (int i = 1; i <= ll; i++) {
		x[i - 1] = d[ll - i];
	}
	for (int i = 0; i <= ll; i++) {
		if (d[i] != x[i]) {
			ant++;
		}
	}
	cout << ant / 2;
	return 0;
}
