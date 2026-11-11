#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long int x[31];
int a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	for (int i = 1; i <= 30; i++) {
		x[i] = pow(2, i);
	}
	int n, m;
	cin >> n >> m;
	int b[m + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int y = 1;
	int g[n + 1] = {0}, k[n + 1] = {0};
	for (int i = 1; i <= n; i++) {
		int k[31] = {0};
		for (int j = 1; j <= 30; j++) {
			if (a[i] == x[j + 1] - 1) {
				k[0] = a[i];
				break;
			}
			if (a[i] < x[j])
				break;
			if (a[i] % x[j] > x[j + 1])
				continue;
			k[j] = a[i] % x[j];
		}
		sort(k, k + 31);
		g[i] = k[31];
		k[i] = g[i];
	}
	sort(k + 1, k + 1 + n);
	for (int i = n; i >= 1; i--) {
		if (m <= 0)
			break;
		for (int j = 1; j <= n; j++) {
			if (m <= 0)
				break;
			if (g[j] == k[i]) {
				cout << a[j];
				m--;
			}
		}

	}
	return 0;
}