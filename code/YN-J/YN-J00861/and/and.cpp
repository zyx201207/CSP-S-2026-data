#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("add.in", "r", stdin);
	freopen("add.out", "w", stdout);
	long long n, m, a[1000005], b = 0, sum;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		b = a[i];
		cin >> a[i];
		for (int j = 1; j <= m; j++) {
			sum = min(a[j], b);
			cout << sum;
			break;
		}
	}
	return 0;
}