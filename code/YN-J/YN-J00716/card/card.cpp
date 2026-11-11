#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, a[110000], b[110000], cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		a[i - 1] = 0;
		for (int j = 1; j <= n; j++) {
			int sum = 0;
			sum += a[i];
			if (sum == i) {
				cout << sum << " ";
			}
		}
	}
	return 0;
}