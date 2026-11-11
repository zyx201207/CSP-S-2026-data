#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long a[n + 3];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long sum = 1;
	sort(a + 1, a + n + 1);
	while (a[1] != a[3] && a[2] != a[3]) {
		if (a[1] != a[3] && a[2] != a[3]) {
			long long c = a[3] - a[1];
			long long s = a[3] - a[2];
			if (c + s <= m) {
				a[1] = a[3];
				a[2] = a[3];
			} else {
				cout << 1;
				return 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i + 1]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}