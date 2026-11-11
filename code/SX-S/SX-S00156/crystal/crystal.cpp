#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n + 4];
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int sum = 1;
	for (int i = 1; i <= n; i++) {
		int k ;
		k += a[i];
		int s = k * 1.0 / 6;
		if (s - a[i] + s - a[i] == m) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}
