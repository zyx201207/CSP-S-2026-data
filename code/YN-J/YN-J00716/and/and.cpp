#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, sum = 14 ;
	cin >> n >> m;
	long a[110];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = n - 1; i >= n - m; i--) {
		sum = sum & a[i];
	}
	cout << sum;
	return 0;
}