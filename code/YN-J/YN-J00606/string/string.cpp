#include <bits/stdc++.h>
using namespace std;

int n, a[200005] = {0}, m = 0, zh = 0;
char b[200005], c[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> b[i];
		zh += a[i];
	}
	int dz = a[0];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < a[i]; j++) {
			c[j + dz] = b[i];
		}
		dz += a[i];
	}
	int j = 0;
	char d = b[1];
	for (int i = 2; i <= n; i++) {
		if (d == b[i]) {
			j++;
		}
	}
	for (int i = 0; i < zh / 2; i++) {
		if (c[i] != c[zh - 1 - i]) {
			m++;
		}
	}
	cout << m;

	return 0;
}