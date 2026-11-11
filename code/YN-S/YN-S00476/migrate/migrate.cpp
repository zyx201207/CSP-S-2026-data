#include <bits/stdc++.h>
using namespace std;
freeopen ("migrate.in", 'r', stdin);
freeopen ("migrate.out", 'w', stdout);


long long a[10000] = {0}, n = 0, m = 0, sum[10000] = {0};

int p(int c, int b, int min, int max) {
	for (int i = 1; i <= b; i++) {
		min = min - i;
		if (c <= 0) {
			return 0;
		}
		p(c--, b, min, max);
		if (min == max) {
			sum[i]++;
		}
	}
}

int main() {
	int n, m, z = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	p(n, m, a[0], a[n - 1]);
	for (int i = 0; i < n; i++) {
		if (sum[i] == 2) {
			z++;
		}
	}
	cout << z;
	return 0;
}