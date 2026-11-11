#include <bits/stdc++.h>
using namespace std;
char a[200005];
char b[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int x;
	char y;
	int len = 0;
	int k = 1;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		len = len + x;
		for (int j = 1; j <= x; j++) {
			a[k] = y;
			k++;
		}

	}
	int u = 1;
	for (int i = len ; i > 0; i--) {
		b[u] = a[i];
		u++;
	}
	int len2 = len / 2;
	int ci = 0;
	for (int i = 1; i <= len2; i++) {
		if (a[i] != b[i]) {
			ci++;
		}
	}
	cout << ci;

	return 0;
}