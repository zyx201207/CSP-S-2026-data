#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	int len;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	len = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] == len) {
			b[len]++;
		}
	}
	for (int i = 0; i < m; i++) {
		cout << b[i] << " ";
	}
	return 0;
}