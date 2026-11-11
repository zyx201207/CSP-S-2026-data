#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long int n = 0, m = 0, e = 0;
	cin >> n;

	long long int a[100001] = {0};
	char c[500001] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		m += a[i];
	}

	long long int i_s = 1;
	long long int i = 1, j = 0, temp_s = m, temp = n;
	int z1 = 0, z2 = 0;
	z1 = a[i_s];
	z2 = a[temp];
	while (j != m / 2) {
		i_s++;
		temp_s--;
		if (c[i] == c[temp]) {
			z1--;
			z2--;
			if (z1 == 0) {
				z1 = a[i_s];
				i++;
			} else if (z2 == 0) {
				z2 = a[temp_s];
				temp--;
			}
		} else {
			e++;
		}
		j++;
	}
	cout << e;
	return 0;
}