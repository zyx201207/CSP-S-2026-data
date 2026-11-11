#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N], k = -1e12, n, m, d;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		long long sum = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (sum + (a[i] - a[j]) <= m) {
				sum += a[i] - a[j];
				d = i - j + 1;
			} else
				break;
		}
		if (d > k) {
			k = d;
		}
	}
	cout << k << endl;
	return 0;
}